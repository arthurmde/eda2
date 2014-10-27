#include "Graph.hpp"
#include <vector>
#include <string>
#include <sstream>

using namespace std;

Graph::Graph(){}

Graph::~Graph(){}

void
Graph::insert_node(int value)
{
	Node *node = this->get_node(value);
	
	if(!node)
	{
		node = new Node(value);
		this->insert_node(node);
	}
}

void
Graph::insert_node(Node* node)
{
	this->nodes.push_back(node);
}

//FIXME: Check node and edge existence
void
Graph::insert_edge(Node* a ,Node* b)
{
	a->insert_neighbor(b);
}

int
Graph::insert_edge(int v1, int v2, bool bidirectional)
{
	this->insert_node(v1);
	this->insert_node(v2);

	this->insert_edge(v1,v2);

	if(bidirectional)
	{
		this->insert_edge(v2,v1);
	}

	return 0;
}

void
Graph::remove_edge(int a ,int b, bool bidirectional)
{
	Node *node_a = this->get_node(a);
	Node *node_b = this->get_node(b);

	if(node_a && node_b)
	{
		this->remove_edge(node_a, node_b);
		
		if(bidirectional)
		{
			this->remove_edge(node_b, node_a);
		}
	}
}

void
Graph::remove_edge(Node* a ,Node* b)
{
	a->remove_neighbor(b);
}

void
Graph::remove_node(int value)
{
	Node *node = this->get_node(value);

	if(!node)
	{
		return;
	}

	vector<Node*>::iterator node_it;
	
	for(vector<Node*>::iterator it=this->nodes.begin(); it!=nodes.end(); it++)
	{
		(*it)->remove_neighbor(node);

		if((*it) == node)
		{
			node_it = it;
		}
	}

	this->nodes.erase(node_it);
}

Node*
Graph::get_node(int value)
{
	Node *node = 0;
	for(vector<Node*>::iterator it=this->nodes.begin(); it!=nodes.end(); it++)
	{
		if((*it)->get_value()==value)
		{
			node = *it;
			break;
		}
	}

	return node;
}

string
Graph::to_dot(void)
{
	stringstream ss;
	string data;
	ss << "digraph G {" << endl;
	ss << "\t" << "// Use ./prog < input.txt | dot -Tpng -ograph.png" << endl;

	for(vector<Node*>::iterator it = this->nodes.begin();
			it!=this->nodes.end(); it++)
	{

		if((*it)->degree() == 0)
		{
				ss << "\t" << (*it)->get_value() << ";" << endl;
				continue;
		}

		vector<Node*>neighbors = (*it)->get_neighbors();

		for(vector<Node*>::iterator neigh = neighbors.begin();
				neigh!=neighbors.end(); neigh++)
		{
			ss << "\t"
				<<(*it)->get_value() << " -> " << (*neigh)->get_value()
			   	<< ";" << endl;
		}
	}

	ss << "}" << endl;
	data = ss.str();
	return data;
}

int
Graph::size(void)
{
	return this->nodes.size();
}

bool
Graph::empty(void)
{
	return (this->nodes.size() == 0);
}
