#include "Heap.hpp"
#include "HeapTree.hpp"
#include <iostream>
#include <climits>

Heap::Heap(){}

Heap::~Heap(){}

void Heap::sort(vector<int> & array)
{
	HeapTree *tree = new HeapTree(array);

	for (int i = array.size()-1; i >= 0; --i)
	{
		tree->swap(i, 0);
		array[i] = tree->remove_last();
		tree->heapify();
	}

	tree->print();

	delete tree;
}

string Heap::name()
{
	return "Heap";
}