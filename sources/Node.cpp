/*
**
**  Author : Aurelien Girardeau
**
*/

#include "Node.hh"

Node::Node(std::string const& flag)
  : _flag(flag), _run(false)
{
}

Node::~Node()
{
}

Node*	Node::clone()
{
  Node*	newNode = new Node(_flag);
  std::vector<Node *>::iterator it;

  for (it = _children.begin(); it != _children.end(); ++it)
    {
      newNode->addChild((*it)->clone());
    }
  return newNode;
}

std::string const&		Node::getFlag() const
{
  return _flag;
}

void		Node::addValue(std::string const& value)
{
  _values.push(value);
}

void		Node::addChild(Node *child)
{
  _children.push_back(child);
}

void		Node::setActive()
{
  _run = true;
}


std::string const&	Node::getValue() const
{
  return _values.top();
}

void			Node::popValue()
{
  _values.pop();
}

bool			Node::isChild(std::string const& flag) const
{
  std::vector<Node *>::const_iterator	it;

  for (it = _children.begin(); it != _children.end(); ++it)
    {
      if ((*it)->getFlag() == flag)
	return true;
    }
  return false;
}

Node*			Node::getChild(std::string const& flag)
{
  std::vector<Node *>::iterator	it;

  for (it = _children.begin(); it != _children.end(); ++it)
    {
      if ((*it)->getFlag() == flag)
	return (*it);
    }
  return NULL;
}

std::vector<Node *>&	Node::getChildren()
{
  return _children;
}


size_t		Node::getSizeValues() const
{
  return _values.size();
}


bool		Node::isActive() const
{
  return _run;
}
