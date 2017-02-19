#include "BreadthFirst.hh"

BreadthFirst::BreadthFirst()
{
}

BreadthFirst::~BreadthFirst()
{
}

bool		BreadthFirst::solveMaze(Maze* maze)
{
  // Using attribute Cell.fWeight for this algorithm
  Cell*		start = maze->getCell(0,0);
  Cell*		goal = maze->getCell(maze->getHeight() - 1,
				     maze->getWidth() - 1);

  start->setFWeight(0);
  _queue.push(start);
  while (!_queue.empty())
    {
      Cell* current = _queue.front();
      current->setVisited();
      if (current == goal) {
	constructPath(goal);
	return true;
      }
      _queue.pop();
      for (auto neighbor : current->getConnectedCells())
	{
	  if (!neighbor->isVisited())
	    {
	      neighbor->setFWeight(current->getFWeight() + 1);
	      neighbor->setParent(current);
	      _queue.push(neighbor);
	    }
	}
    }
  return false;
}

ISolve*		BreadthFirst::clone()
{
  return new BreadthFirst();
}

void		BreadthFirst::constructPath(Cell* from)
{
  while (from->getParent())
    {
      from->setFromPath();
      from = from->getParent();
    }
  from->setFromPath();
}
