/*
**
**  Author : Aurelien Girardeau
**
*/

#include "SVGGenerator.hh"

SVGGenerator::SVGGenerator(Maze *maze)
  : _maze(maze)
{
}

SVGGenerator::~SVGGenerator()
{
  if (_root)
    deleteDomElements(_root);
}

void		SVGGenerator::deleteDomElements(DomElement *dom)
{
  std::vector<DomElement *>::iterator	it;

  for (it = dom->getChildren().begin(); it != dom->getChildren().end(); ++it)
    {
      deleteDomElements((*it));
    }
  delete dom;
}

void		SVGGenerator::run(std::string const& fileName)
{
  std::chrono::time_point<std::chrono::system_clock> start, end;
  start = std::chrono::system_clock::now();
  setRootDom();
  setRect();
  mazeToSvg();
  toFile(fileName);
  end = std::chrono::system_clock::now();
  int elapsed_milliseconds = std::chrono::duration_cast<std::chrono::milliseconds>(end-start).count();
  std::cout << "Saving Maze in svg file took : " << elapsed_milliseconds << " milliseconds" <<  std::endl;
}

void			SVGGenerator::setMaze(Maze* maze)
{
  _maze = maze;
}

void			SVGGenerator::mazeToSvg()
{
  std::vector<Edge>			edges = _maze->getEdges();
  std::vector<Edge>::const_iterator	it;

  for (it = edges.begin(); it != edges.end(); ++it)
    {
      double xA = static_cast<double>(it->getCoordA().first) \
	          / static_cast<double>(_maze->getWidth() - 1);
      double yA = static_cast<double>(it->getCoordA().second) \
	          / static_cast<double>(_maze->getHeight() - 1);
      double xB = static_cast<double>(it->getCoordB().first) \
	          / static_cast<double>(_maze->getWidth() - 1);
      double yB = static_cast<double>(it->getCoordB().second) \
	          / static_cast<double>(_maze->getHeight() - 1);
      DomElement* line = new DomElement("line");

      Cell *first = _maze->getCell(it->getCoordA().second, it->getCoordA().first);
      Cell *second = _maze->getCell(it->getCoordB().second, it->getCoordB().first);
      if (first->isInPath() && second->isInPath()) {
	line->addAttribute("stroke", "red");
      } else {
	line->addAttribute("stroke", "white");
      }
      line->addAttribute("stroke-width", "0.005");
      line->addAttribute("x1", Utils::doubleToString(xA));
      line->addAttribute("y1", Utils::doubleToString(yA));
      line->addAttribute("x2", Utils::doubleToString(xB));
      line->addAttribute("y2", Utils::doubleToString(yB));
      _root->addChild(line);
    }
}

void		SVGGenerator::setRootDom()
{
  _root = new DomElement("svg");
  _root->addAttribute("viewBox", "0 0 1 1");
  _root->addAttribute("width", "500");
  _root->addAttribute("height", "500");
  _root->addAttribute("xmlns", "http://www.w3.org/2000/svg");
}

void		SVGGenerator::setRect()
{
  DomElement*	rect = new DomElement("rect");

  rect->addAttribute("width", "1");
  rect->addAttribute("height", "1");
  rect->addAttribute("style", "fill: black");
  _root->addChild(rect);
}

void		SVGGenerator::toFile(std::string const& fileName)
{
  std::ofstream	file;

  file.open(fileName, std::ios::out);
  file << _root->toString();
  file.close();
}
