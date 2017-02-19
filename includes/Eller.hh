#pragma once

# include <map>
# include <vector>
# include <algorithm>
# include "IGen.hh"

class		Eller : public IGen
{
private :
  std::mt19937		_randomEngine;
public :
  Eller();
  virtual ~Eller();
  virtual void		generateMaze(Maze *);
  virtual IGen*		clone();
  virtual void		seed(long seed);
};

class		State
{
private :
  int					_width;
  int					_nextSet;
  std::map<int, std::vector<int> >	_sets;
  std::map<int, int>			_cells;
  
public :
  State(int width, int nextSet = -1);
  ~State();
  State*	next();
  void		populate();
  bool		same(int, int);
  void		merge(int, int);
  void		add(int, int);
  std::map<int, std::vector<int> >&	getSets();
};
