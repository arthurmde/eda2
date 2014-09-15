#include "List.hpp"
#include "Node.hpp"
#include <iostream>

using namespace std;

List::List()
{
	this->head = 0;
	this->tail = 0;
	this->list_size = 0;
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

	this->list_size++;
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

	this->list_size++;
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

	this->list_size--;
}

void List::swap(Node *first, Node *second)
{
	if(first == second)
		return;

	this->push_front(-1);
	this->push_back(-1);

	if(first->prev != second)
		first->prev->next = second;

	if(first->next != second)
		first->next->prev = second;

	if(second->prev != first)
		second->prev->next = first;

	if(second->next != first)
		second->next->prev = first;
	
	Node *temp = new Node(first->value);

	temp->next = first->next;
	temp->prev = first->prev;

	if(first->next == second)
	{
		first->next = second->next;
		first->prev = second;
		second->next = first;
		second->prev = temp->prev;
	}
	else if(first->prev == second)
	{
		first->prev = second->prev;
		first->next = second;
		second->prev = first;
		second->next = temp->next;
	}
	else
	{
		first->next = second->next;
		first->prev = second->prev;
		second->next = temp->next;
		second->prev = temp->prev;
	}

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
	for(Node* temp = this->head; i < this->list_size; temp = temp->next, i++)
	{
		cout << "[" << i << "] = " << temp->value << " | ";
	}
	cout << endl;
}

int List::size()
{
	return this->list_size;
}

int List::get_index(int value)
{
	if(!this->head)
		return -1;

	int index = 0;
	for(Node* node = this->head; node->next; node = node->next, index++)
	{
		if(node->value == value)
			return index;
	}

	if(this->tail->value == value)
		return this->list_size-1;

	return -1;
}

Node* List::get_node_by_index(int index)
{
	int i = 0;
	Node* current = this->head;

	for (i = 0; i < index && i < this->list_size; ++i, current = current->next);

	if(!current)
		return 0;

	return current;	
}

Node* List::get_head()
{
	return this->head;
}

Node* List::get_tail()
{
	return this->tail;
}