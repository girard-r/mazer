/*
**
**  Author : Aurelien Girardeau
**
*/

#include "ArgsTree.hh"

ArgsTree::ArgsTree()
{
}

ArgsTree::~ArgsTree()
{
  deleteNodes();
}

void			ArgsTree::addRoot(Node *newRoot)
{
  _root.push_back(newRoot->clone());
}

void			ArgsTree::addChildTo(std::string const& flag, Node *child)
{
  addChildToRec(flag, child, _root);
}

void			ArgsTree::addChildToRec(std::string const& flag,
						Node* child,
						std::vector<Node*>& currentDepth)
{
  std::vector<Node*>::iterator	it;

  for (it = currentDepth.begin(); it != currentDepth.end(); ++it)
    {
      if ((*it)->getFlag() == flag)
	{
	  (*it)->addChild(child->clone());
	}
      addChildToRec(flag, child, (*it)->getChildren());
    }
}

void			ArgsTree::deleteNodes()
{
  deleteNodesRec(_root);
}

void			ArgsTree::deleteNodesRec(std::vector<Node *>& container)
{
  std::vector<Node *>::iterator	it;

  for (it = container.begin(); it != container.end(); ++it)
    {
      deleteNodesRec((*it)->getChildren());
      delete (*it);
    }
}

void			ArgsTree::dumpTree()
{
  dumpTreeRec(_root, 0);
}

void					ArgsTree::dumpTreeRec(std::vector<Node *>& currentDepth,
							      unsigned int depth)
{
  std::vector<Node*>::iterator		it;

  for (it = currentDepth.begin(); it != currentDepth.end(); ++it)
    {
      std::cout << addTab(depth) + (*it)->getFlag() << std::endl;
      dumpTreeRec((*it)->getChildren(), depth + 1);
    }
}

std::string const	ArgsTree::addTab(unsigned int n)
{
  std::string		toRet = "";
  
  for (unsigned int i = 0; i < n; ++i)
    {
      toRet += "\t";
    }
  return toRet;
}

Node*			ArgsTree::getRootNode(std::string const& flag)
{
  std::vector<Node *>::iterator	it;

  for (it = _root.begin(); it != _root.end(); ++it)
    {
      if ((*it)->getFlag() == flag)
	return (*it);
    }
  return NULL;
}

Node*			ArgsTree::getNextActiveNode()
{
  static Node*				activeNode = NULL;

  if (activeNode == NULL)
    activeNode = getActiveNodeIn(_root);
  else
    activeNode = getActiveNodeIn(activeNode->getChildren());
  return activeNode;
}

Node*		ArgsTree::getActiveNodeIn(std::vector<Node *>& container)
{
  std::vector<Node *>::iterator	it;

  for (it = container.begin(); it != container.end(); ++it)
    {
      if ((*it)->isActive())
	return (*it);
    }
  return NULL;
}
