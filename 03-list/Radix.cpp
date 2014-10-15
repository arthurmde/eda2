#include "Radix.hpp"
#include "Sort.hpp"
#include <iostream>
#include <climits>

using namespace std;

Radix::Radix(){}

Radix::~Radix(){}

void Radix::sort(vector<int> & array)
{
	int max = array[1];
	int digit = 1;

	for(unsigned int i=0; i<array.size(); i++)
	{
		if(max< array[i])
			max = array[i];
	}

	while(max/digit>0)
	{
		int bucket[10] = {0};

		vector<int> *aux_array = new vector<int>(array.size());

		for(unsigned int i=0; i<array.size(); i++)
			bucket[(array[i]/digit)%10]++;

		for(unsigned int i=1; i<10; i++)
			bucket[i] += bucket[i-1];

		for(int i=array.size()-1; i>=0; i--)
			aux_array->at(--bucket[(array[i]/digit)%10]) = array[i];

		for(unsigned int i=0; i<array.size(); i++)
			array[i] = aux_array->at(i);

		delete aux_array;
		digit*=10;
	}


}

string Radix::name()
{
	return "Radix";
}
