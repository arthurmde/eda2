#include <iostream>
#include "Array.h"
#include "CircularArray.h"

using namespace std;

int random_array[103] = {40, 102, 21, 83, 72, 65, 30, 26, 44, 93, 29, 51, 16, 87, 12, 28, 31, 77, 69, 91, 81, 23, 22, 88, 4, 49, 61, 39, 79, 74, 67, 38, 63, 14, 84, 100, 99, 18, 53, 97, 42, 92, 82, 95, 78, 56, 85, 58, 9, 1, 48, 34, 35, 76, 27, 17, 7, 45, 36, 54, 11, 25, 94, 90, 59, 64, 0, 15, 98, 20, 68, 32, 86, 24, 96, 75, 101, 71, 55, 41, 8, 33, 50, 2, 3, 19, 60, 66, 70, 46, 80, 89, 43, 37, 13, 5, 47, 52, 62, 6, 10, 73, 57};
int circular_array[10] = {4,5,6,7,8,9,0,1,2,3};

int main()
{
	int key_to_find = -140;
	int key_to_remove  = 30;
	int key_to_insert = 30;

	cout << "Test with random_array" << endl;

	Array test = Array(59, 10, random_array);

	test.print_array();
	test.print_index_table();

	int index = test.find(key_to_find);

	if(index == -1)
		cout << "Key " << key_to_find << " not found" << endl;
	else
		cout << "The key " << key_to_find << " in test is at position: " << index << endl;

	cout << endl << "Remove " << key_to_remove << " from array:" << endl;
	
	test.remove(key_to_remove);
	test.print_array();
	test.print_index_table();

	cout << endl << "Insert " << key_to_insert << " in array:" << endl;

	test.insert(key_to_insert);
	test.print_array();
	test.print_index_table();


	CircularArray circular = CircularArray(10, circular_array);
	circular.print_array();
	
	index = circular.find(8);

	if(index == -1)
		cout << "Key " << 8 << " not found" << endl;
	else
		cout << "The key " << 8 << " in circular is at position: " << index << endl;

	cout << endl << "Remove " << 5 << " from circular array:" << endl;
	
	circular.remove(5);
	circular.print_array();

	cout << endl << "Insert 5, 16, 11 and 17 in circular array:" << endl;

	circular.insert(5);
	circular.insert(16);
	circular.insert(11);
	circular.insert(17);
	circular.print_array();

	return 0;
}