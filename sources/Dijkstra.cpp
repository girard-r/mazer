#include "Dijkstra.hh"

Dijkstra::Dijkstra(IHeuristic* heuristic)
  : _heuristic(heuristic)
{
}

Dijkstra::~Dijkstra()
{
}

int		Dijkstra::heuristic_cost(Cell *from, Cell *to)
{
  return (_heuristic->getCost(from, to));
}

/*
**
** A* algorithm i e Dijkstra with heuristics.
** The weight of each Node is calculated with this formula 
** f(n) = g(n) + h(n)
**
*/

bool		Dijkstra::solveMaze(Maze* maze)
{
  Cell		*start = maze->getCell(0, 0);
  Cell		*goal = maze->getCell(maze->getHeight() - 1, maze->getWidth() - 1);
  start->setGWeight(0);
  start->setFWeight(heuristic_cost(start, goal));
  _priorityQueue.insert(start);
  _path[start] = NULL;

  while (!_priorityQueue.isEmpty())
    {
      Cell *current = _priorityQueue.getMin();
      current->setVisited();
      if (current == goal) {
	writePath(goal);
	return true;
	//We reach the end
      }
      for (auto neighbor : current->getConnectedCells()) {
	if (neighbor->isVisited())
	  continue ;
	// the distance between two cells is 1 so we need to add 1 to g_weight
	int potential_g_weight = current->getGWeight() + 1;
	if (!_priorityQueue.find(neighbor))
	  {
	    _priorityQueue.insert(neighbor);
	  }
	else if (potential_g_weight >= neighbor->getGWeight()
		 && neighbor->getGWeight() != - 1)
	  {
	    continue ;
	  }
	_path[neighbor] = current;
	neighbor->setGWeight(potential_g_weight);
	neighbor->setFWeight(neighbor->getGWeight() + heuristic_cost(neighbor, goal));
      }
    }
  return false;
}

void		Dijkstra::writePath(Cell* goal)
{
  Cell *current = goal;
  while (_path[current] != NULL) {
    current->setFromPath();
    current = _path[current];
  }
  current->setFromPath();
}

ISolve*		Dijkstra::clone()
{
  return new Dijkstra(_heuristic);
}
