/*
**
**  Author : Aurelien Girardeau
**
*/

#pragma once

# include <utility>

class		Edge
{
private :
  std::pair<int, int>		_coordA;
  std::pair<int, int>		_coordB;
public :
  Edge(int, int, int, int);
  ~Edge();
  std::pair<int, int> const&	getCoordA() const;
  std::pair<int, int> const&	getCoordB() const;
};
