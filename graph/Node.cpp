#include "Node.hpp"
#include <vector>

using namespace std;

Node::Node(){}

Node::Node(int value)
{
	this->value = value;
}

Node::~Node(){}

void
Node::insert_neighbor(Node *node)
{
	this->neighbors.push_back(node);
}

vector<Node*>
Node::get_neighbors(void)
{
	return (this->neighbors);
}

void
Node::remove_neighbor(Node* node)
{
	vector<Node*>::iterator it;

	for(it = this->neighbors.begin(); it != this->neighbors.end(); it++)
	{
		if((*it) == node)
		{
			break;
		}
	}

	if(it != this->neighbors.end())
	{
		this->neighbors.erase(it);
	}
}

int 
Node::get_value(void)
{
	return (this->value);
}

int
Node::degree(void)
{
	return this->neighbors.size();
}
