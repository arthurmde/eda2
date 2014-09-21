#include "BinaryTree.hpp"
#include "Node.hpp"
#include <iostream>
#include <queue>

using namespace std;
		
		void insert(int value);
		void remove(int value);
		void remove(Node* node);


		bool search(int value);
		//travessia
		void breadth_first();
		void preorder();
		void inorder();
		void postorder();


		void print();

		
		int size();
		int high();
		Node* get_root();

BinaryTree::BinaryTree()
{
	this->root = 0;
	this->tree_size = 0;
	this->tree_high = 0;
}

BinaryTree::~BinaryTree()
{
	while(this->root)
	{
		this->remove(root->value);
	}
}

void BinaryTree::insert(int value)
{
	if(!this->root)
	{
		Node *node = new Node(value);
		this->root = node;
		this->tree_size++;
		this->tree_high++;
		return;
	}

	Node *node = this->root;
	Node *parent;

	while(node)
	{
		parent = node;

		if(value == node->value)
			return;
		else if(value < node->value)
			node = node->left;
		else
			node = node->right;
	}

	if(value < parent->value)
		parent->left = new Node(value);
	else
		parent->right = new Node(value);
	
	this->tree_size++;
}

bool BinaryTree::search(int value)
{
	if(!this->root)
		return false;

	Node *node = this->root;

	while(node)
	{
		if(value == node->value)
			return true;
		else if(value < node->value)
			node = node->left;
		else
			node = node->right;
	}

	return false;
}

void BinaryTree::breadth_first()
{
	queue<Node *> queue;
	Node *node = this->root;

	if(!node)
		return;

	queue.enqueue(node);

	while(!queue.empty())
	{
		node = queue.dequeue();
		//PRINTA ou VISITA NODE
		//this->visit(node);

		if(node->left)
			queue.enqueue(node->left);
		if(node->right)
			queue.enqueue(node->right);
	}
}

void BinaryTree::preorder(Node *node = this->root)
{
	if(node)
	{
		//this->visit(node);
		preorder(node->left);
		preorder(node->right);
	}
}

void BinaryTree::inorder(Node *node = this->root)
{
	if(node)
	{
		inorder(node->left);
		//this->visit(node);
		inorder(node->right);
	}
}

void BinaryTree::postorder(Node *node = this->root)
{
	if(node)
	{
		postorder(node->left);
		postorder(node->right);
		//this->visit(node);
	}
}


void BinaryTree::remove(int value)
{
	Node *temp = this->get_node(value);

	this->remove(temp);
}


void BinaryTree::print()
{
	int i = 0;

	cout << endl << "Printing BinaryTree" << endl << endl;
	for(Node* temp = this->head; i < this->BinaryTree_size; temp = temp->next, i++)
	{
		cout << "[" << i << "] = " << temp->value << " | ";
	}
	cout << endl;
}

int BinaryTree::size()
{
	return this->tree_size;
}

int BinaryTree::high()
{
	return this->tree_high;
}