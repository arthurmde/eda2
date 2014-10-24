#include <iostream>
#include "Graph.hpp"

using namespace std;

int main(void)
{
	Graph grafico = Graph();

	int a,b;
	while(cin >> a >> b)
	{
		grafico.insert_link(a,b);
	}

	cout << grafico.to_dot();

	return 0;
}
