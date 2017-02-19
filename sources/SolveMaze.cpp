#include <iostream>
#include "SolveMaze.hh"

SolveMaze::SolveMaze(Maze* maze, std::string const& choice)
  : _maze(maze)
{
  _algorithm = Factory::getSolveAlgorithm(choice);
}

SolveMaze::~SolveMaze()
{
  delete _algorithm;
}

void	SolveMaze::solveMaze()
{
  std::chrono::time_point<std::chrono::system_clock> start, end;
  start = std::chrono::system_clock::now();
  std::cout << "Maze " << (_algorithm->solveMaze(_maze) ? "is solved" : "can't be solved, no path exists") << std::endl;
  end = std::chrono::system_clock::now();
  int elapsed_milliseconds = std::chrono::duration_cast<std::chrono::milliseconds>(end-start).count();
  std::cout << "solving Maze took : " << elapsed_milliseconds << " milliseconds" <<  std::endl;
}
