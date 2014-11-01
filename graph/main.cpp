#include <iostream>
#include <string>

#include "Graph.hpp"

using namespace std;

int main(void)
{
	Graph *graph;
	string type;
	int a,b;

	cin >> type;
	if(type=="bidirecional")
		graph = new Graph(true);

	else if(type=="unidirecional")
		graph = new Graph(false);

	else
		{
			cout << "Graph type wrong or missing." << endl;
			return -1;
		}
	
	while(cin >> a >> b)
	{
		graph->insert_edge(a,b);
	}

	cout << graph->to_dot();

	delete graph;
	return 0;
}
