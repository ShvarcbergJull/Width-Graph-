#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <set>
#include <queue>
#include <iterator>
#include "Graph.h"
#include "Node.h"
#include "Searce.h"

using namespace std;

Graph::Graph(const char* inFileName)
{
	FILE* file = fopen(inFileName, "rb");
	if (file == NULL)
	{
		perror("Ошибка открытия файла");
		return;
	}

	int i = 0;
	int s = -1, t = -1;
	char* a = new char[1];
	Node* so = NULL;
	Node* ta = NULL;
	while (!feof(file))
	{
		so = NULL;
		ta = NULL;
		fread(a, 1, 1, file);
		if (*a <'0' || *a > '9')
		{
			if (i == 1)
				i++;
			if (i == 3)
				i = 0;
			continue;
		}
		switch (i)
		{
		case 0:
			if (s == -1 || t == -1)
			{
				s = *a - '0';
				i++;
				break;
			}

			for (set<Node*>::iterator it = nodes.begin(); it != nodes.end(); it++)
			{
				if ((*it)->name == s)
					so = *it;
				if ((*it)->name == t)
					ta = *it;
			}
			if (so == NULL)
			{
				so = new Node(s);
				addNode(so);
			}
			if (ta == NULL)
			{
				ta = new Node(t);
				addNode(ta);
			}

			so->addNeighbour(ta);
			s = *a - '0';
			i++;
			break;
		case 1:
			s = s * 10 + (*a - '0');
			i++;
			break;
		case 2:
			t = *a - '0';
			i++;
			break;
		case 3:
			t = t * 10 + (*a - '0');
			i = 0;
			break;
		default:
			break;
		}
	}
	for (set<Node*>::iterator it = nodes.begin(); it != nodes.end(); it++)
	{
		if ((*it)->name == s)
			so = *it;
		if ((*it)->name == t)
			ta = *it;
	}
	if (so == NULL)
	{
		so = new Node(s);
		addNode(so);
	}
	if (ta == NULL)
	{
		ta = new Node(t);
		addNode(ta);
	}

	so->addNeighbour(ta);

	fclose(file);
}

void Graph::removeNode(Node* node)
{
	nodes.erase(node);
	for (set<Node*>::iterator it = nodes.begin(); it != nodes.end(); it++)
	{
		(*it)->removeNeighbourd(node);
	}
}

void Graph::addEdge(Node* begin, Node* end)
{
	if (nodes.find(begin) == nodes.end() || nodes.find(end) == nodes.end())
		return;
	begin->addNeighbour(end);
	end->addNeighbour(begin);
}

void Graph::addNode(Node* node)
{
	nodes.insert(node);
}

bool Graph::ser(Node* nd)
{
	if (nodes.find(nd) == nodes.end())
		return false;
	return true;
}

void Graph::removeEdge(Node* begin, Node* end)
{
	if (nodes.find(begin) == nodes.end() || nodes.find(end) == nodes.end())
		return;
	begin->removeNeighbourd(end);
	end->removeNeighbourd(begin);
}

void Node::addNeighbour(Node* node)
{
	neighbours.insert(node);
}

void Node::removeNeighbourd(Node* node)
{
	neighbours.erase(node);
}

bool BFS::connected(Node* begin, Node* end)
{
	queue<Node*> nodes;
	nodes.push(begin);
	set<Node*> visited;
	while (!nodes.empty())
	{
		Node* next = nodes.front();
		nodes.pop();
		if (end == next)
			return true;
		visited.insert(next);
		for (node_iterator it = next->nb_begin(); it != next->nb_end(); it++)
			if (visited.find(*it) == visited.end())
				nodes.push(*it);
	}
	return false;
}
