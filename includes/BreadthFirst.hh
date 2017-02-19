#pragma once

# include <queue>
# include "ISolve.hh"

class		BreadthFirst : public ISolve
{
private :
  std::queue<Cell*>	_queue;
public :
  BreadthFirst();
  virtual ~BreadthFirst();
  virtual bool		solveMaze(Maze*);
  virtual ISolve*	clone();
private :
  void			constructPath(Cell*);
};
