#include "DepthFirst.hh"

DepthFirst::DepthFirst()
{
}

DepthFirst::~DepthFirst()
{
}

bool		DepthFirst::solveMaze(Maze* maze)
{
  /*
  ** DepthFirst search algorithm
  */
  Cell* start = maze->getCell(0, 0);
  Cell* goal = maze->getCell(maze->getHeight() - 1, maze->getWidth() - 1);
  if (DFS(start, goal))
    start->setFromPath();
  return start->isInPath();
}

bool		DepthFirst::DFS(Cell* current, Cell* goal)
{
  current->setVisited();
  if (current == goal)
    return true;
  for (auto neighbor : current->getConnectedCells())
    {
      if (!neighbor->isVisited()) {
	if (DFS(neighbor, goal)) {
	  neighbor->setFromPath();
	  return true;
	}
      }
    }
  return false;
}

ISolve*		DepthFirst::clone()
{
  return new DepthFirst();
}
