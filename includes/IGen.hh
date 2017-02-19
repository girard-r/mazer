#pragma once

# include <vector>
# include <random>
# include <chrono>
# include "Maze.hh"

class		IGen
{
public :
  virtual void	generateMaze(Maze *) = 0;
  virtual IGen*	clone() = 0;
  virtual void	seed(long seed) = 0;
  virtual ~IGen() {};
};
