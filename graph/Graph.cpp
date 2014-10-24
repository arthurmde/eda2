#include "Graph.hpp"
#include <vector>
#include <string>
#include <sstream>

using namespace std;

Graph::Graph(){}

Graph::~Graph(){}

void
Graph::insert_node(Node* node)
{
	this->nodes.push_back(node);
}

//FIXME: Check node and link existence
void
Graph::insert_link(Node* a ,Node* b)
{
	a->insert_neighbor(b);
}

int
Graph::insert_link(int v1 ,int v2)
{
	Node *a, *b;
	a = this->get_node(v1);
	b = this->get_node(v2);
	if(!a)
	{
		a = new Node(v1);
		this->insert_node(a);
	}
	if(!b)
	{
		b = new Node(v2);
		this->insert_node(b);
	}
	this->insert_link(a,b);
	this->insert_link(b,a);
	return 0;
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
