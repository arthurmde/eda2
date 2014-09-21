#ifndef NODE_HPP
#define NODE_HPP

class Node
{
	public:
		Node(int);
		~Node();

		int value;
		Node *left;
		Node *right;
};


#endif
