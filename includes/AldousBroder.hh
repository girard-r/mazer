#pragma once

# include "IGen.hh"
# include "constants.h"

class			AldousBroder : public IGen
{
private :
  std::vector<int>	_dirX;
  std::vector<int>	_dirY;
  std::mt19937		_randomEngine;
public :
  AldousBroder();
  virtual ~AldousBroder();
  virtual void		generateMaze(Maze *);
  virtual IGen*		clone();
  virtual void		seed(long seed);
};
