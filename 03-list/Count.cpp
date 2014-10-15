#include "Count.hpp"
#include <iostream>
#include <climits>

Count::Count(){}

Count::~Count(){}

void Count::sort(vector<int> & array)
{
	int biggest = this->max_element(array)+1;
	vector<int>count_array(biggest, 0);
	biggest = count_array.size();

	for (int i = 0; i < (int)array.size(); ++i)
		count_array[array[i]] = count_array[array[i]] + 1;

	for (int i = 1; i < biggest; ++i)
		count_array[i] += count_array[i-1];

	vector<int> ordered(array.size(), 0);

	for (int i = array.size()-1 ; i >= 0; i--)
	{
		ordered[count_array[array[i]] - 1] = array[i];
		count_array[array[i]]--;
	}

	array = ordered;
}

int Count::min_element(vector<int> & array)
{
	int min = array[0];
	int size = array.size();

	for (int i = 1; i < size; ++i)
	{
		if(array[i] < min)
			min = array[i];
	}

	return min;
}

int Count::max_element(vector<int> & array)
{
	int max = array[0];
	int size = array.size();

	for (int i = 1; i < size; ++i)
	{
		if(array[i] > max)
			max = array[i];
	}

	return max;
}

string Count::name()
{
	return "Count";
}