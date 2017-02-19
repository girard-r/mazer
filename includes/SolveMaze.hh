#pragma once

# include "Maze.hh"
# include "ISolve.hh"
# include "Factory.hh"

class		SolveMaze
{
private :
  Maze*		_maze;
  ISolve*	_algorithm;
public :
  ~SolveMaze();
  SolveMaze(Maze*, std::string const&);
  void		solveMaze();
};
