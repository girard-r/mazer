/*
**
**  Author : Aurelien Girardeau
**
*/

#pragma once

# include <string>
# include <vector>
# include <iostream>
# include "Node.hh"

class		ArgsTree
{ 
private :
  std::vector<Node *>	_root;
public :
  ArgsTree();
  ~ArgsTree();
  void			addRoot(Node *);
  void			addChildTo(std::string const&, Node*);
  void			dumpTree();
  Node*			getRootNode(std::string const&);
  Node*			getNextActiveNode();
private :
  void			addChildToRec(std::string const&,
				      Node *,
				      std::vector<Node*>&);
  void			dumpTreeRec(std::vector<Node *>&, unsigned int);
  std::string const	addTab(unsigned int);
  Node*			getActiveNodeIn(std::vector<Node *>&);
  void			deleteNodes();
  void			deleteNodesRec(std::vector<Node *>&);
};
