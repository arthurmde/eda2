#include <iostream>
#include <string>

#include "Graph.hpp"
#include "Search.hpp"

using namespace std;

int main(void)
{
	Graph *graph;
	Search searcher = Search();
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


//	Graph *tree;
//	tree = searcher.bfs(graph,1);
//	cout << graph->to_dot();
//	cout << tree->to_dot();
//	
//	Graph *inverse;
//	inverse = graph->get_inverse();
//	cout << inverse->to_dot();
	
	if(!graph->is_connected())
		cout << "Graph is not connected." << endl;
	else
	{
		cout << "Graph is connected." << endl;
		if(graph->is_strongly_connected())
			cout << "Graph is strongly connected." << endl;
		else
			cout << "Graph is not strongly connected." << endl;

	}
	//cout << graph->to_dot();

	delete graph;
	return 0;
}
