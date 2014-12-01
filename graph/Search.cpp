#include "Search.hpp"

using namespace std;

Search::Search()
{
}

Search::~Search()
{
}

Graph *
Search::bfs(Graph* graph, int root)
{
	Node *node = graph->get_node(root);
	if(!node)
		return 0;

	return this->bfs(graph,node);
}

//TODO Manage NULL root
//TODO See others components
Graph *
Search::bfs(Graph* graph, Node *node)
{

	Graph *tree = new Graph(graph->is_bidirectional());
	create_visitor(graph->get_nodes());

	this->q.push(node);
	this->visit(node);
	while(!this->q.empty())
	{
		Node* u = this->q.front();
		this->q.pop();
		vector<Neighbor> neighbors = u->get_neighbors();
		for(vector<Neighbor>::iterator it = neighbors.begin();
				it != neighbors.end();
				it++)
			if(!is_visited((*it).neighbor))
			{
				int a,b;
				a = u->get_value();
				b = (*it).neighbor->get_value();
				tree->insert_edge(a,b);
				this->visit((*it).neighbor);
				q.push((*it).neighbor);
			}

		{
		}
	}

	return tree;
}

void
Search::create_visitor(vector<Node*> nodes)
{
	this->not_visited.clear();
	for(vector<Node*>::iterator it = nodes.begin(); it != nodes.end(); it++)
	{
		this->not_visited.insert(*it);
	}
}

void
Search::visit(Node* node)
{
	this->not_visited.erase(node);
}

bool
Search::is_visited(Node* node)
{
		return (this->not_visited.count(node) == 0);
}
