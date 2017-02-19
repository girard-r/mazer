/*
**
**  Author : Aurelien Girardeau
**
*/

#include "Maze.hh"

/*
** Implementation of Cell
*/

Cell::Cell(int posX, int posY, bool visited)
  : _posX(posX),
    _posY(posY),
    _visited(visited),
    _gWeight(-1),
    _fWeight(-1),
    _isFromPath(false),
    _parent(NULL)
{
}

Cell::~Cell()
{
}


bool				Cell::isInPath() const
{
  return _isFromPath;
}

void				Cell::setFromPath(bool isPath)
{
  _isFromPath = isPath;
}

void				Cell::addConnectedCell(Cell* cell)
{
  _connectedCells.push_back(cell);
}

int				Cell::getPosX() const
{
  return _posX;
}

int				Cell::getPosY() const
{
  return _posY;
}

std::list<Cell*>&		Cell::getConnectedCells()
{
  return _connectedCells;
}

bool				Cell::isVisited()
{
  return _visited;
}

void				Cell::setVisited(bool visited)
{
  _visited = visited;
}

int				Cell::getGWeight() const
{
  return _gWeight;
}

void				Cell::setGWeight(int weight)
{
  _gWeight = weight;
}

int				Cell::getFWeight() const
{
  return _fWeight;
}

void				Cell::setFWeight(int weight)
{
  _fWeight = weight;
}


bool			Cell::operator>(Cell const& other)
{
  return _fWeight > other._fWeight;
}

bool			Cell::operator>=(Cell const& other)
{
  return _fWeight >= other._fWeight;
}

bool			Cell::operator<(Cell const& other)
{
  return _fWeight < other._fWeight;
}

bool			Cell::operator<=(Cell const& other)
{
  return _fWeight <= other._fWeight;
}

bool			Cell::operator==(Cell const& other)
{
  return (_posX == other._posX && _posY == other._posY);
}


Cell*			Cell::getParent() const
{
  return _parent;
}

void			Cell::setParent(Cell* parent)
{
  _parent = parent;
}

/*
**  Implementation of Maze
*/

Maze::Maze(int width, int height, bool visited)
  : _width(width), _height(height), _edgesSize(0)
{
  initGrid(visited);
}

Maze::~Maze()
{
  for (int y = 0; y < _height; ++y)
    {
      for (int x = 0; x < _width; ++x)
	{
	  delete(_grid[y][x]);
	}
    }
}

int				Maze::getWidth() const
{
  return _width;
}

int				Maze::getHeight() const
{
  return _height;
}

int				Maze::getEdgesSize() const
{
  return _edgesSize;
}

std::vector<Edge>&	Maze::getEdges()
{
  return _edges;
}

void				Maze::addEdge(int xA, int yA, int xB, int yB)
{
  Edge	newEdge = Edge(xA, yA, xB, yB);

  _edges.push_back(newEdge);
  _edgesSize += 1;
}

void				Maze::initGrid(bool visited)
{ 
  for (int y = 0; y < _height; y++)
    {
      std::vector<Cell*>	line;
      for (int x = 0; x < _width; x++)
	{
	  line.push_back(new Cell(x, y, visited));
	}
      _grid.push_back(line);
    }
}

bool				Maze::isVisited(int y, int x)
{
  return (_grid[y][x])->isVisited();
}

void				Maze::setVisited(int y, int x)
{
  (_grid[y][x])->setVisited();
}

void				Maze::connectCells(int yA, int xA, int yB, int xB)
{
  _grid[yA][xA]->addConnectedCell(_grid[yB][xB]);
  _grid[yB][xB]->addConnectedCell(_grid[yA][xA]);
  addEdge(xA, yA, xB, yB);
}

void				Maze::clear()
{
  for (int y = 0; y < _height; y++)
    {
      for (int x = 0; x < _width; x++)
	{
	  _grid[y][x]->setVisited(false);
	  _grid[y][x]->setFWeight(-1);
	  _grid[y][x]->setGWeight(-1);
	  _grid[y][x]->setParent(NULL);
	}
    }
}

std::list<Cell*>&		Maze::getConnectedCells(int y, int x)
{
  return _grid[y][x]->getConnectedCells();
}


Cell*				Maze::getCell(int y, int x)
{
  return _grid[y][x];
}
