#pragma once

# include "IHeuristic.hh"

class		EuclideanH : public IHeuristic
{
public :
  EuclideanH();
  virtual ~EuclideanH();
  virtual int	getCost(Cell*, Cell*) const;
};
