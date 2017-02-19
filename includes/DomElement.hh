/*
**
**  Author : Aurelien Girardeau
**
*/

#pragma once

# include <string>
# include <map>
# include <vector>

class	DomElement
{
private :
  std::string				_name;
  std::map<std::string, std::string>	_attributes;
  DomElement*				_parent;
  std::vector<DomElement*>		_children;
public :
  DomElement(std::string const&);
  ~DomElement();
  void				addChild(DomElement *);
  void				addAttribute(std::string const&, std::string const&);
  std::string			toString(unsigned int tab = 0) const;
  void				setParent(DomElement *);
  std::vector<DomElement*>&	getChildren();
private :
  std::string	addTab(unsigned int) const;
};
