# include "AldousBroder.hh"

AldousBroder::AldousBroder()
{
  _dirX.push_back(0);
  _dirX.push_back(1);
  _dirX.push_back(0);
  _dirX.push_back(-1);
  _dirY.push_back(-1);
  _dirY.push_back(0);
  _dirY.push_back(1);
  _dirY.push_back(0);
}

AldousBroder::~AldousBroder()
{
}

void		AldousBroder::seed(long seed)
{
  _randomEngine.seed(seed);
  std::cout << "Aldous-Broder seeded with value : " << seed << std::endl;
}

IGen*		AldousBroder::clone()
{
  return new AldousBroder();
}

void		AldousBroder::generateMaze(Maze *maze)
{
  int	nonVisited = maze->getHeight() * maze->getWidth() - 1;
  int	x = _randomEngine() % maze->getWidth();
  int	y = _randomEngine() % maze->getHeight();
  maze->setVisited(y, x);

  while (nonVisited > 0)
    {
      e_dir	randomDir = static_cast<e_dir>(_randomEngine() % 4);

      int xNext = x + _dirX[randomDir];
      int yNext = y + _dirY[randomDir];
      if (xNext >= 0 && xNext < maze->getWidth()
	  && yNext >= 0 && yNext < maze->getHeight())
	{
	  if (!maze->isVisited(yNext, xNext))
	    {
	      maze->setVisited(yNext, xNext);
	      maze->connectCells(y, x, yNext, xNext);
	      nonVisited -= 1;
	    }
	  x = xNext;
	  y = yNext;
	}
    }
  std::cout << "Maze successfully generated using Aldous-Broder algorithm" << std::endl;
}
