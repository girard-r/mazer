#include <cmath>
#include "EuclideanH.hh"

EuclideanH::EuclideanH()
{
}

EuclideanH::~EuclideanH()
{
}

int		EuclideanH::getCost(Cell* from, Cell* to) const
{
  return std::sqrt(std::pow(to->getPosX() - from->getPosX(), 2)
		   + std::pow(to->getPosY() - from->getPosY(), 2));
}
