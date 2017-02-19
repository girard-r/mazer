/*
**
**  Author : Aurelien Girardeau
**
*/

#pragma once

# include <vector>
# include <fstream>
# include <chrono>
# include "Utils.hh"
# include "Maze.hh"
# include "DomElement.hh"

class	SVGGenerator
{
private :
  DomElement*		_root;
  Maze*			_maze;
public :
  SVGGenerator(Maze *);
  ~SVGGenerator();
  void			run(std::string const&);
  void			setMaze(Maze* maze);
private :
  void			setRootDom();
  void			setRect();
  void			mazeToSvg();
  void			toFile(std::string const&);
  void			deleteDomElements(DomElement *);
};
