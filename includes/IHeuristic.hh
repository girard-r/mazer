#pragma once
# include "Maze.hh"

class		IHeuristic
{
public :
  virtual ~IHeuristic() {}
  virtual int	getCost(Cell*, Cell*) const = 0;
};
