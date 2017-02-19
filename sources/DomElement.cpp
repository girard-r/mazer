/*
**
**  Author : Aurelien Girardeau
**
*/

#include "DomElement.hh"

DomElement::DomElement(std::string const& name)
  : _name(name), _parent(NULL)
{
}

DomElement::~DomElement()
{
}

void		DomElement::addChild(DomElement* child)
{
  _children.push_back(child);
  child->setParent(this);
}

std::vector<DomElement *>&	DomElement::getChildren()
{
  return _children;
}

void		DomElement::setParent(DomElement* parent)
{
  _parent = parent;
}

void		DomElement::addAttribute(std::string const& key, std::string const& value)
{
  _attributes[key] = value;
}

std::string	DomElement::toString(unsigned int tab) const
{
  std::map<std::string, std::string>::const_iterator	it;
  std::vector<DomElement*>::const_iterator		domIt;
  std::string						toReturn = "";

  toReturn += addTab(tab);
  toReturn += "<" + _name + " ";
  for (it = _attributes.begin(); it != _attributes.end(); ++it)
    {
      toReturn += it->first + "=" + "'" + it->second + "' ";
    }
  if (_children.empty())
    {
      toReturn += "/>\n";
    }
  else
    {
      toReturn += ">\n";
      for (domIt = _children.begin(); domIt != _children.end(); ++domIt)
	{
	  toReturn += (*domIt)->toString(tab + 1);
	}
      toReturn += addTab(tab);
      toReturn += "</" + _name + ">\n";
    }
  return toReturn;
}

std::string	DomElement::addTab(unsigned int tab) const
{
  std::string	toReturn = "";
  
  for (unsigned int i = 0; i < tab; ++i)
    {
      toReturn += "\t";
    }
  return toReturn;
}
