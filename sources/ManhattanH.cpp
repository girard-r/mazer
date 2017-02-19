#include "ManhattanH.hh"

ManhattanH::ManhattanH()
{
}

ManhattanH::~ManhattanH()
{
}

int		ManhattanH::getCost(Cell* from, Cell* to) const
{
  return (ABS(from->getPosX() - to->getPosX())
	  + ABS(from->getPosY() - to->getPosY()));
}
