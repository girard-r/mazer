/*
**
**  Author : Aurelien Girardeau
**
*/

#pragma once

# include <vector>
# include <list>
# include <iostream>
# include "Edge.hh"


class		Cell
{
private :
  int				_posX;
  int				_posY;
  std::list<Cell*>		_connectedCells;
  bool				_visited;
  int				_gWeight;
  int				_fWeight;
  bool				_isFromPath;
  Cell*				_parent;
public :
  Cell(int, int, bool);
  ~Cell();
  void			addConnectedCell(Cell*);
  int			getPosX() const;
  int			getPosY() const;
  std::list<Cell*>&	getConnectedCells();
  bool			isVisited();
  void			setVisited(bool visited = true);
  int			getGWeight() const;
  void			setGWeight(int);
  int			getFWeight() const;
  void			setFWeight(int);
  bool			operator>(Cell const&);
  bool			operator>=(Cell const&);
  bool			operator<(Cell const&);
  bool			operator<=(Cell const&);
  bool			operator==(Cell const&);
  void			setFromPath(bool isPath = true);
  bool			isInPath() const;
  Cell*			getParent() const;
  void			setParent(Cell*);
};

class	Maze
{
private :
  std::vector<std::vector<Cell*> >	_grid;
  int					_width;
  int					_height;
  int					_edgesSize;
  std::vector<Edge>			_edges;

public :
  Maze(int width = 100,
       int height = 100,
       bool visited = false);
  ~Maze();
  int				getWidth() const;
  int				getHeight() const;
  int				getEdgesSize() const;
  std::vector<Edge>&		getEdges();
  bool				isVisited(int, int);
  void				setVisited(int, int);
  void				connectCells(int, int, int, int);
  std::list<Cell*>&		getConnectedCells(int, int);
  void				addEdge(int, int, int, int);
  void				clear();
  Cell*				getCell(int, int);

private :
  Maze(Maze const&);
  Maze&				operator=(Maze const&);
  void				initGrid(bool visited = false);
};
