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
	this->neighbor.push_back(node);
}

vector<Node*>
Node::get_neighbors(void)
{
	return (this->neighbor);
}

int 
Node::get_value(void)
{
	return (this->value);
}
