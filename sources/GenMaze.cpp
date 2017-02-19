/*
**
**  Author : Aurelien Girardeau
**
*/

#include "GenMaze.hh"

GenMaze::GenMaze(Maze *maze, std::string const& choice, long seed)
  : _maze(maze)
{
  _algorithm = Factory::getGenAlgorithm(choice);
  _algorithm->seed(seed);
}

GenMaze::~GenMaze()
{
  delete _algorithm;
}

void		GenMaze::generateMaze()
{
  std::chrono::time_point<std::chrono::system_clock> start, end;
  start = std::chrono::system_clock::now();
  _algorithm->generateMaze(_maze);
  end = std::chrono::system_clock::now();
  int elapsed_milliseconds = std::chrono::duration_cast<std::chrono::milliseconds>(end-start).count();
  std::cout << "generating Maze took : " << elapsed_milliseconds << " milliseconds" <<  std::endl;
}

void					GenMaze::toBinaryFile(std::string const& fileName)
{
  std::ofstream				file;
  std::vector<Edge>			edges = _maze->getEdges();
  std::vector<Edge>::const_iterator	it;
  int					width = _maze->getWidth();
  int					height = _maze->getHeight();
  int					edgesSize = _maze->getEdgesSize();
  std::chrono::time_point<std::chrono::system_clock> start, end;
  start = std::chrono::system_clock::now();
  file.open(fileName, std::ios::out | std::ios::binary);
  file.write((char *)&width, sizeof(int));
  file.write((char *)&height, sizeof(int));
  file.write((char *)&edgesSize, sizeof(int));
  for (it = edges.begin(); it != edges.end(); ++it)
    {
      int xA = it->getCoordA().first;
      int yA = it->getCoordA().second;
      int xB = it->getCoordB().first;
      int yB = it->getCoordB().second;
      file.write((char *)&xA, sizeof(int));
      file.write((char *)&yA, sizeof(int));
      file.write((char *)&xB, sizeof(int));
      file.write((char *)&yB, sizeof(int));
    }
  file.close();
  end = std::chrono::system_clock::now();
  int elapsed_milliseconds = std::chrono::duration_cast<std::chrono::milliseconds>(end-start).count();
  std::cout << "Saving Maze in binary file took : " << elapsed_milliseconds << " milliseconds" <<  std::endl;
}
