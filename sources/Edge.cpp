/*
**
**  Author : Aurelien Girardeau
**
*/

#include "Edge.hh"

Edge::Edge(int xA, int yA, int xB, int yB)
  : _coordA(xA, yA), _coordB(xB, yB)
{
}

Edge::~Edge()
{}

std::pair<int, int> const&	Edge::getCoordA() const
{
  return _coordA;
}

std::pair<int, int> const&	Edge::getCoordB() const
{
  return _coordB;
}
