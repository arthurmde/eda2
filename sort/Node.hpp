#ifndef NODE_HPP
#define NODE_HPP

class Node
{
	public:
		int value;
		Node *next;
		Node *prev;
		Node(int);
		~Node();
};


#endif
