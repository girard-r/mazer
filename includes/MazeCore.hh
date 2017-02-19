/*
**
**  Author : Aurelien Girardeau
**
*/

#pragma once

# include <string>
# include <map>
# include "ArgsTree.hh"
# include "Maze.hh"
# include "LoadMaze.hh"
# include "GenMaze.hh"
# include "SVGGenerator.hh"
# include "Utils.hh"
# include "Exceptions.hpp"
# include "SolveMaze.hh"

# define USAGE "USAGE ORDER : ./mazer --g [PARAMS] --sb [PARAMS] --sv \
[PARAMS]\nOR : --lb [PARAMS] --sv [PARAMS]\n--g [seed] [width] [height]\
 <-- Optional parameters, Generate Maze\n--sb [filename.maze] <-- Save \
maze in binary code into filename.maze\n--sv [filename.svg] <-- Save maze\
 in svg into filename.svg\n--lb [filename.maze] <-- Load Maze from binary \
file filename.maze"

class		MazeCore
{
  typedef void			(MazeCore::*ptr)(Node *);
private :
  ArgsTree			_container;
  std::map<std::string, ptr>	_occur;
  Maze*				_maze;
  GenMaze*			_generator;
  SVGGenerator*			_svgEngine;
  LoadMaze*			_loader;
  SolveMaze*			_solver;
public :
  MazeCore();
  ~MazeCore();
  void		init(int, char **);
  void		run();
private :
  void		constructMazeTree();
  void		fillMazeTree(int, char **);
  void		fillNodeArgs(Node*, int*, int, char **);
  void		processGenMaze(Node *);
  void		processLoadBinaryMaze(Node *);
  void		processSaveBinaryMaze(Node *);
  void		processSaveSvgMaze(Node *);
  void		processSolveMaze(Node *);
};
