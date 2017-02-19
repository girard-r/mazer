/*
**
**  Author : Aurelien Girardeau
**
*/

#pragma once

# include <vector>
# include <random>
# include <chrono>
# include <iostream>
# include <fstream>
# include <chrono>
# include "Maze.hh"
# include "constants.h"
# include "Factory.hh"

class		GenMaze
{
private :
  Maze*			_maze;
  IGen*			_algorithm;

public :
  GenMaze(Maze *,
	  std::string const&,
	  long seed = std::chrono::system_clock::now() \
	  .time_since_epoch() \
	  .count());
  ~GenMaze();

private :
  GenMaze();
  GenMaze(GenMaze const&);
  GenMaze&	operator=(GenMaze const&);

public :
  void		generateMaze();
  void		toBinaryFile(std::string const&);
};
