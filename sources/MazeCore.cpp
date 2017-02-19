/*
**
**  Author : Aurelien Girardeau
**
*/

#include "MazeCore.hh"

MazeCore::MazeCore()
  : _maze(NULL),
    _generator(NULL),
    _svgEngine(NULL),
    _loader(NULL),
    _solver(NULL)
{
}

MazeCore::~MazeCore()
{
  if (_maze)
    delete _maze;
  if (_generator)
    delete _generator;
  if (_svgEngine)
    delete _svgEngine;
  if (_loader)
    delete _loader;
  if (_solver)
    delete _solver;
}

void	MazeCore::init(int ac, char **av)
{
  _occur["--ga"] = &MazeCore::processGenMaze;
  _occur["--ge"] = &MazeCore::processGenMaze;
  _occur["--lb"] = &MazeCore::processLoadBinaryMaze;
  _occur["--sb"] = &MazeCore::processSaveBinaryMaze;
  _occur["--sv"] = &MazeCore::processSaveSvgMaze;
  _occur["--pm"] = &MazeCore::processSolveMaze;
  _occur["--pe"] = &MazeCore::processSolveMaze;
  _occur["--pb"] = &MazeCore::processSolveMaze;
  _occur["--pd"] = &MazeCore::processSolveMaze;
  constructMazeTree();
  fillMazeTree(ac, av);
}

void	MazeCore::constructMazeTree()
{
  Node	seedNodeA("--ga");
  Node	seedNodeE("--ge");
  Node	loadNode("--lb");
  Node	saveBinary("--sb");
  Node	saveSvg("--sv");
  Node	solveMazeManhattan("--pm");
  Node	solveMazeEuclidean("--pe");
  Node	solveMazeDepthFirst("--pd");
  Node	solveMazeBreadthFirst("--pb");

  _container.addRoot(&seedNodeA);
  _container.addRoot(&seedNodeE);
  _container.addRoot(&loadNode);
  _container.addChildTo("--ga", &saveBinary);
  _container.addChildTo("--ge", &saveBinary);
  _container.addChildTo("--ga", &solveMazeManhattan);
  _container.addChildTo("--ge", &solveMazeManhattan);
  _container.addChildTo("--ga", &solveMazeEuclidean);
  _container.addChildTo("--ge", &solveMazeEuclidean);
  _container.addChildTo("--ga", &solveMazeDepthFirst);
  _container.addChildTo("--ge", &solveMazeDepthFirst);
  _container.addChildTo("--ga", &solveMazeBreadthFirst);
  _container.addChildTo("--ge", &solveMazeBreadthFirst);
  _container.addChildTo("--pm", &saveBinary);
  _container.addChildTo("--pe", &saveBinary);
  _container.addChildTo("--pd", &saveBinary);
  _container.addChildTo("--pb", &saveBinary);
  _container.addChildTo("--sb", &saveSvg);
  _container.addChildTo("--lb", &saveSvg);
  _container.addChildTo("--lb", &solveMazeManhattan);
  _container.addChildTo("--lb", &solveMazeEuclidean);
  _container.addChildTo("--lb", &solveMazeDepthFirst);
  _container.addChildTo("--lb", &solveMazeBreadthFirst);
  saveSvg.addChild(&saveBinary);
  _container.addChildTo("--ga", &saveSvg);
  _container.addChildTo("--ge", &saveSvg);
  _container.addChildTo("--pm", &saveSvg);
  _container.addChildTo("--pe", &saveSvg);
  _container.addChildTo("--pd", &saveSvg);
  _container.addChildTo("--pb", &saveSvg);
}

void		MazeCore::fillMazeTree(int ac, char **av)
{
  Node*		actualNode;
  int		index = 1;

  if (ac > 1)
    {
      if (!(actualNode = _container.getRootNode(av[index++])))
	throw Exceptions::ArgumentException(av[index - 1], "is not a valid flag.");
      actualNode->setActive();
      fillNodeArgs(actualNode, &index, ac, av);
      while (index < ac)
	{
	  if (!(actualNode = actualNode->getChild(av[index++])))
	    throw Exceptions::ArgumentException(av[index - 1], \
		"is not a valid flag or is not at the right position.");
	  actualNode->setActive();
	  fillNodeArgs(actualNode, &index, ac, av);
	}
    }
  else
    std::cout << USAGE << std::endl;
}

void		MazeCore::fillNodeArgs(Node *node, int *index, int ac, char **av)
{
  int i = 0;
  
  for (i = *index; i < ac; ++i)
    {
      std::string  tmp(av[i]);
      if (tmp.find("--") == 0)
	{
	  *index = i;
	  return ;
	}
      else
	{
	  node->addValue(tmp);
	}
    }
  *index = i;
}

void		MazeCore::run()
{
  Node*		node = NULL;

  while ((node = _container.getNextActiveNode()))
    {
      (this->*_occur[node->getFlag()])(node);
    }
}

void		MazeCore::processGenMaze(Node *node)
{
  int		width = 100;
  int		height = 100;
  int		seed = 0;
  
  if (node->getSizeValues() < 4)
    {
      if (node->getSizeValues() > 1)
	{
	  height = Utils::stringToInt(node->getValue());
	  node->popValue();
	  width = Utils::stringToInt(node->getValue());
	  node->popValue();
	  _maze = new Maze(width, height);
	}
      else
	_maze = new Maze();
      if (node->getSizeValues() > 0)
	{
	  seed = Utils::stringToLong(node->getValue());
	  node->popValue();
	  _generator = new GenMaze(_maze, node->getFlag(), seed);
	}
      else
	{
	  _generator = new GenMaze(_maze, node->getFlag());
	}
      _generator->generateMaze();
    }
  else
    {
      throw Exceptions::ArgumentException(node->getFlag(),
					  "Wrong number of arguments.");
    }
}

void		MazeCore::processLoadBinaryMaze(Node *node)
{
  
  if (node->getSizeValues() == 1)
    {
      _loader = new LoadMaze();
      _loader->loadFromBinary(node->getValue());
      node->popValue();
      _maze = _loader->getMaze();
    }
  else
    {
      throw Exceptions::ArgumentException(node->getFlag(),
					  "Wrong number of arguments.");
    }
}

void		MazeCore::processSaveBinaryMaze(Node *node)
{
  if (node->getSizeValues() == 1)
    {
      _generator->toBinaryFile(node->getValue());
      node->popValue();
    }
  else
    {
      throw Exceptions::ArgumentException(node->getFlag(),
					  "Wrong number of arguments.");
    }
}

void		MazeCore::processSaveSvgMaze(Node *node)
{
  if (node->getSizeValues() == 1)
    {
      _svgEngine = new SVGGenerator(_maze);
      _svgEngine->run(node->getValue());
      node->popValue();
    }
  else
    {
      throw Exceptions::ArgumentException(node->getFlag().c_str(),
					  "Wrong number of arguments.");
    }
}

void		MazeCore::processSolveMaze(Node *node)
{
  _maze->clear();
  _solver = new SolveMaze(_maze, node->getFlag());
  _solver->solveMaze();
}
