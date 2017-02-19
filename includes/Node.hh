/*
**
**  Author : Aurelien Girardeau
**
*/

#pragma once

# include <string>
# include <vector>
# include <stack>

class				Node
{
private :
  std::string			_flag;
  std::stack<std::string>	_values;
  std::vector<Node *>		_children;
  bool				_run;
public :
  Node(std::string const&);
  ~Node();
  Node*			clone();
  std::string const&	getFlag() const;
  void			addValue(std::string const&);
  void			addChild(Node *);
  void			setActive();
  bool			isActive() const;
  std::string const&	getValue() const;
  size_t		getSizeValues() const;
  void			popValue();
  bool			isChild(std::string const&) const;
  Node*			getChild(std::string const&);
  std::vector<Node *>&	getChildren();
};
