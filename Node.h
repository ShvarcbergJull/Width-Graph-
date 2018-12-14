#pragma once
#include "Graph.h"

class Node
{
	int name;
	std::set<Node*> neighbours;
	void addNeighbour(Node* neighbourd);
	void removeNeighbourd(Node* neighbourd);
public:
	Node(const int& aname) : name(aname)
	{
		name = aname;
	}
	const int& getName() const
	{
		return name;
	}
	std::set<Node*>::iterator nb_begin() const
	{
		return neighbours.begin();
	}
	std::set<Node*>::iterator nb_end()  const
	{
		return neighbours.end();
	}
	friend class Graph;
};
