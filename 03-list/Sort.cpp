#include "Sort.hpp"
#include <iostream>

Sort::Sort(){}

Sort::~Sort(){}

bool Sort::sorted(vector<int> & array)
{
	for (int i = 1; i < (int) array.size(); ++i)
	{
		if(array[i-1] > array[i])
			return false;
	}

	return true;
}

void Sort::print_array(vector<int> & array)
{
	cout << endl << "Printing Array" << endl;

	for (int i = 0; i < (int)array.size(); ++i)
	{
		cout << "[" << i << "] = " << array[i] << " | ";
	}

	cout << endl;
}

void Sort::swap(vector<int> & array, int first, int second)
{
	int temp = array[first];
	array[first] = array[second];
	array[second] = temp;
}