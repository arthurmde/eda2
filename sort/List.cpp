#include "List.hpp"
#include "Node.hpp"
#include <iostream>

using namespace std;

List::List()
{
	this->head = 0;
	this->tail = 0;
}

List::~List()
{
	while(this->head)
	{
		Node *temp = this->head;
		this->head = this->head->next;

		delete temp;
	}
}

void List::push_back(int value)
{
	Node *node = new Node(value);

	if(!this->head)
	{
		this->head = node;
		this->tail = node;
	}
	else
	{	
		this->tail->next = node;
		node->prev = this->tail;
		this->tail = node;
	}
}

void List::push_front(int value)
{
	Node *node = new Node(value);

	if(!this->head)
	{
		this->head = node;
		this->tail = node;
	}
	else
	{
		this->head->prev = node;
		node->next = this->head;
		this->head = node;
	}
}

void List::remove(int value)
{
	Node *temp = this->get_node(value);

	this->remove(temp);
}

void List::remove(Node* node)
{
	if(!node)
		return;

	if(node == this->head)
	{
		if(node->next)
		{
			this->head = node->next;
			this->head->prev = 0;
		}
		else
		{
			this->head = 0;
			this->tail = 0;
		}
	}
	else if(node == this->tail)
	{
		this->tail = node->prev;
		this->tail->next = 0;
	}
	else
	{
		node->prev->next = node->next;
		node->next->prev = node->prev;
	}

	delete node;
}

void List::swap(Node *first, Node *second)
{
	this->push_front(-1);
	this->push_back(-1);

	first->prev->next = second;
	first->next->prev = second;

	second->prev->next = first;
	second->next->prev = first;

	
	Node *temp = new Node(first->value);
	temp->next = first->next;
	temp->prev = first->prev;

	first->next = second->next;
	first->prev = second->prev;

	second->next = temp->next;
	second->prev = temp->prev;

	delete temp;
	this->pop_front();
	this->pop_back();
}

void List::pop_front()
{
	this->remove(this->head);
}

void List::pop_back()
{
	this->remove(this->tail);
}

Node* List::get_node(int value)
{
	for(Node* temp = this->head; temp; temp = temp->next)
	{
		if(temp->value == value)
			return temp;
	}

	return 0;
}

void List::print()
{
	int i = 0;

	cout << endl << "Printing List" << endl << endl;
	for(Node* temp = this->head; temp; temp = temp->next, i++)
	{
		cout << "[" << i << "] = " << temp->value << " | ";
	}
	cout << endl;
}
