#include "Merge.hpp"
#include <iostream>
#include <climits>

using namespace std;

Merge::Merge(){}

Merge::~Merge(){}

void Merge::sort(vector<int> & array)
{
	vector<int> temp = this->merge_sort(array);

	for (int i = 0; i < (int) array.size(); ++i)
	{
		array[i] = temp[i];
	}
}

vector<int> Merge::merge_sort(vector<int> & array)
{
	if(array.size() == 1)
		return array;

	int middle = array.size()/2;
	vector<int> left (array.begin(), array.begin() + middle);
	vector<int> right (array.begin() + middle, array.end());

	left = this->merge_sort(left);
	right = this->merge_sort(right);

	return this->merge_vectors(left, right);
}

vector<int> Merge::merge_vectors(vector<int> & left, vector<int> & right)
{
	vector<int> merged;

	unsigned int i = 0, j = 0;
	
	for(i = 0, j = 0; i < left.size() && j < right.size();)
	{
		if(left[i] <= right[j])
		{
			merged.push_back(left[i]);
			i++;
		}
		else
		{
			merged.push_back(right[j]);
			j++;
		}
	}

	if(i == left.size() && j < right.size())
	{
		for (int k = j; k < (int)right.size(); ++k)
		{
			merged.push_back(right[k]);
		}
	}
	else if(i < left.size() && j == right.size())
	{
		for (int k = i; k < (int)left.size(); ++k)
		{
			merged.push_back(left[k]);
		}
	}

	return merged;
}

string Merge::name()
{
	return "Merge";
}