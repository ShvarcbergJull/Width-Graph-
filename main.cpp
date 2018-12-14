#include <iostream>
#include <fstream>
#include <locale.h>
#include "Graph.h"
#include "Node.h"
#include "Searce.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	
	const char* inFileName = "in.txt";//argv[0];
	Graph g = Graph(inFileName);
	BFS n = BFS(g);

	cout << "Введите точки, которые хотите проверить: ";
	Node* b = NULL;
	Node* e = NULL;
	int a, c;

	cin >> a >> c;
	cout << endl;

	for (node_iterator it = g.begin(); it != g.end(); it++)
	{
		if ((*it)->getName() == a)
			b = *it;
		if ((*it)->getName() == c)
			e = *it;
	}

	if (n.connected(b, e))
		cout << "Эти точки соеденены" << endl;
	else
		cout << "Эти точки не соеденены" << endl;

	system("pause");
	return 0;
}
