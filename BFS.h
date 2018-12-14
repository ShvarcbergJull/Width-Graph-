#pragma once
#include "Graph.h"
class BFS
{
	Graph& graph;
public:
	BFS(Graph& agraph) : graph(agraph)
	{
		graph = agraph;
	}
	bool connected(Node* begin, Node* end);
	void print() const;
};
