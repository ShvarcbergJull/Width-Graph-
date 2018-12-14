#pragma once
#include <set>
#include <iterator>
#include "Node.h"

typedef std::set<Node*>::iterator node_iterator;

class Graph
{
	std::set<Node*> nodes;
public:
	Graph(const char* inFileName);
	void addNode(Node* node);
	void removeNode(Node* node);
	void addEdge(Node* begin, Node* end);
	void removeEdge(Node* begin, Node* end);
	bool ser(Node* nd);
	node_iterator begin() const
	{
		return nodes.begin();
	}
	node_iterator end() const
	{
		return nodes.end();
	}
};
