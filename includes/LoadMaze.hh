/*
**
**  Author : Aurelien Girardeau
**
*/

#pragma once

# include "Maze.hh"
# include "Exceptions.hpp"

class		LoadMaze
{
private :
  Maze*		_maze;
public :
  LoadMaze();
  ~LoadMaze();
  void		loadFromBinary(std::string const&);
  Maze*		getMaze();
private :
  void		checkEdges(int, int, int, int);
};
