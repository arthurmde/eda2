#include <iostream>
#include "Graph.hpp"

using namespace std;

int main(void)
{
	Graph grafico = Graph();

	int a,b;
	
	while(cin >> a >> b)
	{
		grafico.insert_edge(a,b,false);
	}

	cout << grafico.to_dot();

	return 0;
}
