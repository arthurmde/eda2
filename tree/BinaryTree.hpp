#ifndef BINARYTREE_HPP
#define BINARYTREE_HPP

#include "Node.hpp"

class BinaryTree
{
	public:
		BinaryTree();
		~BinaryTree();
		void insert(int value);
		void remove(int value);
		void remove(Node* node);

		bool search(int value);
		//travessia
		void breadth_first();
		void preorder();
		void inorder();
		void postorder();

		
		void swap(Node *first, Node *second);
		void print();
		
		int size();
		int high();
		Node* get_root();
	private:
		Node* root;
		int tree_size;
		int tree_high;
};


#endif
