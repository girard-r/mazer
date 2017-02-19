#pragma once

# include "IHeuristic.hh"
# include "constants.h"

class		ManhattanH : public IHeuristic
{
public :
  ManhattanH();
  virtual ~ManhattanH();
  virtual int	getCost(Cell*, Cell*) const;
};
