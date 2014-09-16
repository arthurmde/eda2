#include <iostream>
#include <vector>
#include <ctime>

#include "Sort.hpp"
#include "Radix.hpp"
#include "Count.hpp"

//int random_array[103] = {40, 102, 21, 83, 72, 65, 30, 26, 44, 93, 29, 51, 16, 87, 12, 28, 31, 77, 69, 91, 81, 23, 22, 88, 4, 49, 61, 39, 79, 74, 67, 38, 63, 14, 84, 100, 99, 18, 53, 97, 42, 92, 82, 95, 78, 56, 85, 58, 9, 1, 48, 34, 35, 76, 27, 17, 7, 45, 36, 54, 11, 25, 94, 90, 59, 64, 0, 15, 98, 20, 68, 32, 86, 24, 96, 75, 101, 71, 55, 41, 8, 33, 50, 2, 3, 19, 60, 66, 70, 46, 80, 89, 43, 37, 13, 5, 47, 52, 62, 6, 10, 73, 57};

using namespace std;

void sort_array(Sort * sort_algorithm, vector<int> &array)
{

	sort_algorithm->sort(array);

	if(!sort_algorithm->sorted(array))
	{
		cout << endl << "Array not sorted" << endl;
	}
//	sort_algorithm->print_array(array);
}

int main()
{
	Sort * radix = new Radix();
	int array_size, number;
//	vector<int> array(random_array, random_array + 8);
	vector<int> array;

	cin >> array_size;
	for(int i=0;i<array_size;i++)
	{
		cin >> number;
		array.push_back(number);
	}
	

	sort_array(radix,array);

	delete radix;

	return 0;
}
