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
	Neighbor n;
	n.neighbor = node;
	n.weight = 1;
	this->neighbors.push_back(n);
}

void
Node::insert_neighbor(Node *node, int weight)
{
	Neighbor n;
	n.neighbor = node;
	n.weight = weight;
	this->neighbors.push_back(n);
}

void
Node::increase_neighbor(Node *node)
{
	Neighbor n;
	n.neighbor = node;

	if(this->has_neighbor(node))
	{
		//TODO Improve vector access
		for(vector<Neighbor>::iterator it = this->neighbors.begin();
				it != this->neighbors.end();
				it++)
		{
			if((*it).neighbor == node)
			{
				(*it).weight++;
				break;
			}
		}
	}
	else
	{
		n.weight = 1;
		this->neighbors.push_back(n);
	}
}

vector<Neighbor>
Node::get_neighbors(void)
{
	return (this->neighbors);
}

void
Node::remove_neighbor(Node* node)
{
	vector<Neighbor>::iterator it;

	for(it = this->neighbors.begin(); it != this->neighbors.end(); it++)
	{
		if((*it).neighbor == node)
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

bool
Node::has_neighbor(Node* node)
{
	bool result = false;

	for(vector<Neighbor>::iterator it = this->neighbors.begin();
			it != this->neighbors.end(); it++)
	{
		if((*it).neighbor == node)
		{
			result = true;
			break;
		}
	}

	return result;
}

