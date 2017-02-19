#pragma once

# include "Maze.hh"

class		ISolve
{
public :
  virtual ~ISolve() {}
  virtual bool		solveMaze(Maze*) = 0;
  virtual ISolve*	clone() = 0;
};
