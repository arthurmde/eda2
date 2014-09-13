#include "Node.hpp"

Node::Node(int value)
{
	this->value = value;
	this->next = 0;
	this->prev = 0;
}

Node::~Node(){}
