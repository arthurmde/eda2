#include "Selection.hpp"
#include <iostream>
#include <climits>

Selection::Selection(){}

Selection::~Selection(){}

void Selection::sort(vector<int> & array)
{
	for (int i = 0; i < (int)array.size(); ++i)
	{
		int index = i;

		for (int j = i+1; j < (int)array.size(); ++j)
		{
			if(array[j] < array[index])
				index = j;
		}

		if(i != index)
			Selection::swap(array, i, index);
	}
}