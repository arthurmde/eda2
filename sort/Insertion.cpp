#include "Insertion.hpp"
#include <iostream>
#include <climits>

Insertion::Insertion(){}

Insertion::~Insertion(){}

void Insertion::sort(vector<int> & array)
{
	for (int i = 1; i < (int)array.size(); ++i)
	{
		for (int j = i; j > 0 && array[j] < array[j-1]; --j)
			Insertion::swap(array, j, j-1);
	}
}