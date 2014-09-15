#include "Quick.hpp"
#include <iostream>
#include <climits>
#include <unistd.h>

Quick::Quick(){}

Quick::~Quick(){}

void Quick::sort(List* list, Node* left, Node* right, int begin, int end)
{
	if(!list)
		return;
	if(!list->get_head())
		return;
	if(left == right)
		return;
	if(end <= begin)
		return;

	Node *pivot = left;
	int new_begin = list->get_index(pivot->value);
	int new_end = list->get_index(right->value);

	while(true)
	{
		while(left->value < pivot->value)
		{
			left = left->next;
			begin++;
		}

		while(right->value > pivot->value)
		{
			right = right->prev;
			end--;
		}

		if(begin >= end)
			break;

		list->swap(left, right);
		
		if(left == pivot)
		{
			left = right->next;
			begin++;
			right = pivot;
		}
		else if(right == pivot)
		{
			right = left->prev;
			end--;
			left = pivot;
		}

		//sleep(2);
	}

	this->sort(list, list->get_node_by_index(new_begin), pivot->prev, new_begin, list->get_index(pivot->value)-1);
	this->sort(list, pivot->next, list->get_node_by_index(new_end), list->get_index(pivot->value)+1, new_end);
}

string Quick::name()
{
	return "Quick";
}