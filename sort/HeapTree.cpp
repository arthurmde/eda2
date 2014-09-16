#include "HeapTree.hpp"
#include <iostream>
#include <climits>
#include <cmath>
#include <vector>

HeapTree::HeapTree(vector<int> & array)
{
	this->heap = array;

	for (int i = (this->heap.size()-1)/2; i >= 0; i--)
		this->heapify(i);
}

HeapTree::~HeapTree(){}

void HeapTree::heapify(int index, int size)
{
	if(size == -1)
		size = this->heap.size();

	int left = this->left_child(index);
	int right = this->right_child(index);

	int largest = index;

	if(left < size && this->heap[left] > this->heap[index])
		largest = left;

	if(right < size && this->heap[right] > this->heap[largest])
		largest = right;

	if(largest != index)
	{
		this->swap(index, largest);
		this->heapify(largest);
	}
}

void HeapTree::up_heapify(int index)
{
	while(index > 0 && this->heap[index/2] < this->heap[index])
	{
		swap(index, index/2);
		index = index/2;
	}
}

void HeapTree::swap(int first, int second)
{
	int temp = this->heap[first];
	this->heap[first] = this->heap[second];
	this->heap[second] = temp;
}

int HeapTree::parent(int index)
{
	if(index == 0)
		return -1;

	return index/2;
}

int HeapTree::left_child(int index)
{
	if(2*index >= (int)this->heap.size())
		return -1;

	return 2*index;
}

int HeapTree::right_child(int index)
{
	if((2*index + 1) >= (int)this->heap.size())
		return -1;

	return (2*index) + 1;
}

int HeapTree::get_high()
{
	return (int)(log(this->heap.size()))/(log(2));
}

void HeapTree::print()
{
	cout << endl;

	for (int i = 0; i < (int)this->heap.size(); ++i)
	{
		cout << "[" << heap[i] << "] ";
	}

	cout << endl;
}

int HeapTree::remove_last()
{
	int back = this->heap.back();
	this->heap.pop_back();
	return back;
}

int HeapTree::remove()
{
	this->swap(0, this->heap.size()-1);
	int back = this->heap.back();
	this->heap.pop_back();
	this->heapify();
	return back;
}

void HeapTree::insert(int value)
{
	this->heap.push_back(value);
	this->up_heapify(this->heap.size()-1);
}