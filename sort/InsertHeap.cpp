#include "InsertHeap.hpp"
#include "HeapTree.hpp"
#include <iostream>
#include <climits>

InsertHeap::InsertHeap(){}

InsertHeap::~InsertHeap(){}

void InsertHeap::sort(vector<int> & array)
{
	vector<int> temp;
	HeapTree *tree = new HeapTree(temp);

	for (int i = 0; i < (int)array.size(); ++i)
	{
		tree->insert(array[i]);
	}

	for (int i = array.size()-1; i >= 0; --i)
	{
		array[i] = tree->remove();
	}

	tree->print();

	delete tree;
}

string InsertHeap::name()
{
	return "InsertHeap";
}