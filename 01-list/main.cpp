#include <iostream>
#include "Array.h"

using namespace std;

int random_array[103] = {40, 102, 21, 83, 72, 65, 30, 26, 44, 93, 29, 51, 16, 87, 12, 28, 31, 77, 69, 91, 81, 23, 22, 88, 4, 49, 61, 39, 79, 74, 67, 38, 63, 14, 84, 100, 99, 18, 53, 97, 42, 92, 82, 95, 78, 56, 85, 58, 9, 1, 48, 34, 35, 76, 27, 17, 7, 45, 36, 54, 11, 25, 94, 90, 59, 64, 0, 15, 98, 20, 68, 32, 86, 24, 96, 75, 101, 71, 55, 41, 8, 33, 50, 2, 3, 19, 60, 66, 70, 46, 80, 89, 43, 37, 13, 5, 47, 52, 62, 6, 10, 73, 57};

int main()
{
	Array array = Array(100, 10);

	array.print_array();
	array.print_index_table();

	cout << "Second test with random_array" << endl;

	Array second_test = Array(103, 10, random_array);

	second_test.print_array();
	second_test.print_index_table();

	return 0;
}