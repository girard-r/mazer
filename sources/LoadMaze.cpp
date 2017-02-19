/*
**
**  Author : Aurelien Girardeau
**
*/

#include <fstream>
#include "LoadMaze.hh"
#include "constants.h"

LoadMaze::LoadMaze()
  : _maze(NULL)
{
}

LoadMaze::~LoadMaze()
{
}

void					LoadMaze::loadFromBinary(std::string const& fileName)
{
  std::ifstream				file;
  int					height = 0;
  int					width = 0;
  int					edgesSize = 0;

  file.open(fileName, std::ios::in | std::ios::binary);
  file.read((char *)&width, sizeof(int));
  file.read((char *)&height, sizeof(int));
  file.read((char *)&edgesSize, sizeof(int));
  if (width <= 0 || height <= 0) {
    throw Exceptions::SizeException("Wrong width/height values read in the binary maze file.");
  }
  _maze = new Maze(width, height, true);
  for (int i = 0; i < edgesSize; ++i)
    {
      int xA = 0;
      int yA = 0;
      int xB = 0;
      int yB = 0;
      file.read((char *)&xA, sizeof(int));
      file.read((char *)&yA, sizeof(int));
      file.read((char *)&xB, sizeof(int));
      file.read((char *)&yB, sizeof(int));
      checkEdges(xA, yA, xB, yB);
      _maze->connectCells(yA, xA, yB, xB);
    }
  file.close();
}

void		LoadMaze::checkEdges(int xA, int yA, int xB, int yB)
{
  if (xA < 0
      || xB < 0
      || yA < 0
      || yB < 0
      || xA >= _maze->getWidth()
      || xB >= _maze->getWidth()
      || yA >= _maze->getHeight()
      || yB >= _maze->getHeight())
    throw Exceptions::SizeException("Edges coordinates must be positive / in the maze");
  if (xA == xB) {
    if (ABS(yB - yA) > 1) {
      throw Exceptions::SizeException("Edges must be aside");
    }
  } else {
    if (ABS(xB - xA) > 1) {
      throw Exceptions::SizeException("Edges must be aside");
    }
  }
}

Maze*		LoadMaze::getMaze()
{
  return _maze;
}
