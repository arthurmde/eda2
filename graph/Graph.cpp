#include "Graph.hpp"
#include <vector>
#include <string>
#include <sstream>

using namespace std;

Graph::Graph(bool bidirectional)
{
	this->is_bidirectional = bidirectional;
}

Graph::~Graph()
{
	while(!this->nodes.empty())
	{
		delete nodes.back();
		nodes.pop_back();
	}
}

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

void
Graph::insert_edge(Node* a ,Node* b)
{
	if(!a->has_neighbor(b))
		a->insert_neighbor(b);
}

int
Graph::insert_edge(int v1, int v2)
{
	Node *n1,*n2;

	this->insert_node(v1);
	this->insert_node(v2);

	n1 = get_node(v1);
	n2 = get_node(v2);

	this->insert_edge(n1,n2);

	if(this->is_bidirectional)
	{
		this->insert_edge(n2,n1);
	}

	return 0;
}

void
Graph::remove_edge(int a ,int b)
{
	Node *node_a = this->get_node(a);
	Node *node_b = this->get_node(b);

	if(node_a && node_b)
	{
		this->remove_edge(node_a, node_b);
		
		if(this->is_bidirectional)
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
	delete (*node_it);
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

	string graph_name = "G";
	string graph_type = "digraph";
	string link_type = "->";
	string instructions = "// Use ./prog < input.txt | dot -Tpng -ograph.png";

	if(this->is_bidirectional)
	{
		graph_type = "graph";
		link_type = "--";
	}

	ss << graph_type << " " << graph_name << " {"<< endl;
	ss << "\t" << instructions << endl;

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
			//FIXME This is the worst way to do not duplicate links
			if(this->is_bidirectional)
			{
				if(!(*neigh)->has_neighbor(*it) ||
						(*it)->get_value() < (*neigh)->get_value())
				{
					ss << "\t"
						<< (*it)->get_value() <<
						" " << link_type << " "
						<< (*neigh)->get_value()
						<< ";" << endl;
				}
			}
			else
			{
				ss << "\t"
					<< (*it)->get_value() <<
					" " << link_type << " "
					<< (*neigh)->get_value()
					<< ";" << endl;
			}
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
