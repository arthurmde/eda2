#ifndef LIST_HPP
#define LIST_HPP

#include "Node.hpp"

class List
{
	public:
		List();
		~List();
		void push_back(int value);
		void push_front(int value);
		void remove(int value);
		void remove(Node* node);
		void pop_front();
		void pop_back();
		void swap(Node *first, Node *second);
		void print();
		Node* get_node(int value);
		Node* get_node_by_index(int index);
		int size();
		int get_index(int value);
		Node* get_head();
		Node* get_tail();
	private:
		Node* head;
		Node* tail;
		int list_size;
};


#endif
