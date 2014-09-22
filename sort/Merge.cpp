#include "Merge.hpp"
#include <iostream>
#include <climits>
#include <unistd.h>
#include <cstdlib>

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

	system("clear");

	cout << endl << "Working into array:" << endl;
	this->print_array(array);

	sleep(2);

	int middle = array.size()/2;
	vector<int> left (array.begin(), array.begin() + middle);
	vector<int> right (array.begin() + middle, array.end());

	cout << endl << "Breaking it into the following arrays:" << endl;
	cout << endl << "Left:" << endl;
	this->print_array(left);
	cout << endl << "Right:" << endl;
	this->print_array(right);

	sleep(3);

	left = this->merge_sort(left);
	right = this->merge_sort(right);

	return this->merge_vectors(left, right);
}

vector<int> Merge::merge_vectors(vector<int> & left, vector<int> & right)
{
	vector<int> merged;

	unsigned int i = 0, j = 0;

	system("clear");

	cout << endl << "Merging two arrays:" << endl;
	cout << endl << "First:" << endl;
	this->print_array(left);
	cout << endl << "Second:" << endl;
	this->print_array(right);
	
	sleep(2);

	for(i = 0, j = 0; i < left.size() && j < right.size();)
	{
		cout << endl << "Merging the value in the resulting array: " << endl;

		sleep(1);

		if(left[i] <= right[j])
		{
			cout << "Taking the value " << left[i] << " from first array" << endl;
			merged.push_back(left[i]);
			i++;
		}
		else
		{
			cout << "Taking the value " << right[j] << " from second array" << endl;
			merged.push_back(right[j]);
			j++;
		}
		
		sleep(2);
		this->print_array(merged);
	}

	if(i == left.size() && j < right.size())
	{
		cout << endl << "Moving the rest of the second array into the resulting array:" << endl;

		for (int k = j; k < (int)right.size(); ++k)
		{
			sleep(1);
			cout << "Taking the value " << right[k] << " from second array" << endl;

			merged.push_back(right[k]);
		}

		this->print_array(merged);
	}
	else if(i < left.size() && j == right.size())
	{
		cout << endl << "Moving the rest of the first array into the resulting array:" << endl;

		for (int k = i; k < (int)left.size(); ++k)
		{
			sleep(1);
			cout << "Taking the value " << right[k] << " from first array" << endl;

			merged.push_back(left[k]);
		}

		this->print_array(merged);
	}

	cout << endl << endl << "Resulting array in this step: " << endl;
	this->print_array(merged);

	sleep(4);

	return merged;
}

string Merge::name()
{
	return "Merge";
}