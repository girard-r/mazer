#pragma once

# include "ISolve.hh"

class		DepthFirst : public ISolve
{
public :
  DepthFirst();
  virtual ~DepthFirst();
  virtual bool		solveMaze(Maze*);
  virtual ISolve*	clone();
private :
  bool			DFS(Cell*, Cell*);
};
