#include "Shell.hpp"
#include <iostream>
#include <climits>

Shell::Shell(){}

Shell::~Shell(){}

void Shell::sort(vector<int> & array)
{
	int height = 1;
	int size = array.size();

	while(height < size/3)
		height = 3*height + 1;

	while(height >= 1)
	{
		for (int i = height; i < size; ++i)
		{
			for (int j = i; j >= height && array[j] < array[j-height]; j -= height)
				Shell::swap(array, j, j-height);
		}

		height = height/3;
	}
}

string Shell::name()
{
	return "Shell";
}