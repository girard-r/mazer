#pragma once

# include <map>
# include "Maze.hh"
# include "ISolve.hh"
# include "Heap.tpp"
# include "IHeuristic.hh"

template class Heap<Cell>;

class		Dijkstra : public ISolve
{
  Heap<Cell>	_priorityQueue;
  std::map<Cell*, Cell*>	_path;
  IHeuristic*			_heuristic;
  
public :
  Dijkstra(IHeuristic*);
  virtual ~Dijkstra();
  virtual bool		solveMaze(Maze*);
  virtual ISolve*	clone();
private :
  int	heuristic_cost(Cell*, Cell*);
  void	writePath(Cell*);
};
