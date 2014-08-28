#include <iostream>
#include "Array.h"
#include "CircularArray.h"
#include <ctime>

using namespace std;

int random_array[103] = {40, 102, 21, 83, 72, 65, 30, 26, 44, 93, 29, 51, 16, 87, 12, 28, 31, 77, 69, 91, 81, 23, 22, 88, 4, 49, 61, 39, 79, 74, 67, 38, 63, 14, 84, 100, 99, 18, 53, 97, 42, 92, 82, 95, 78, 56, 85, 58, 9, 1, 48, 34, 35, 76, 27, 17, 7, 45, 36, 54, 11, 25, 94, 90, 59, 64, 0, 15, 98, 20, 68, 32, 86, 24, 96, 75, 101, 71, 55, 41, 8, 33, 50, 2, 3, 19, 60, 66, 70, 46, 80, 89, 43, 37, 13, 5, 47, 52, 62, 6, 10, 73, 57};
int circular_array[10] = {4,5,6,7,8,9,0,1,2,3};

void question_04()
{

	cout << "Question N. 4" << endl << endl;
	int key_to_find = 12;
	int key_to_remove  = 30;
	int key_to_insert = 30;
	int size = 102;

	cout << "Test with random_array" << endl;

	Array test = Array(size, 10, random_array);

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
}


void question_05()
{
	cout << "Question N. 5" << endl << endl;

	int key_to_find = 8;
	int key_to_remove  = 5;

	CircularArray circular = CircularArray(10, circular_array);
	circular.print_array();
	
	int index = circular.find(key_to_find);

	if(index == -1)
		cout << "Key " << key_to_find << " not found" << endl;
	else
		cout << "The key " << key_to_find << " in circular is at position: " << index << endl;

	cout << endl << "Remove " << key_to_remove << " from circular array:" << endl;
	
	circular.remove(key_to_remove);
	circular.print_array();

	cout << endl << "Insert 5, 16, 11 and 17 in circular array:" << endl;

	circular.insert(5);
	circular.insert(16);
	circular.insert(11);
	circular.insert(17);
	circular.print_array();
}

void question_06()
{
	cout << "Question N. 6" << endl << endl;
	clock_t timer;
	int key_to_find = 12;

	Array array10 = Array();
	Array array25 = Array();
	Array array50 = Array();
	Array array100 = Array();
	Array array1000 = Array();
	Array array10000 = Array();
	Array array100000 = Array();

	for (int i = 0; i < 10; ++i)
		array10.push_back(i*3);

	for (int i = 0; i < 25; ++i)
		array25.push_back(i*3);

	for (int i = 0; i < 50; ++i)
		array50.push_back(i*3);

	for (int i = 0; i < 100; ++i)
		array100.push_back(i*3);

	for (int i = 0; i < 1000; ++i)
		array1000.push_back(i*3);

	for (int i = 0; i < 10000; ++i)
		array10000.push_back(i*3);

	for (int i = 0; i < 100000; ++i)
		array100000.push_back(i*3);


	cout << "Test with 10 elemens array" << endl;
	key_to_find = 3*5;

	timer = clock();
	int index = array10.find_by_interpolation(key_to_find);
	timer = clock() - timer;
	cout << endl << "It took " << timer << "clicks (" << ((double)timer)/CLOCKS_PER_SEC/1000<< "milliseconds)." << endl;
	
	if(index == -1)
		cout << "Key " << key_to_find << " not found" << endl;
	else
		cout << "The key " << key_to_find << " in test is at position: " << index << endl;


	cout << "Test with 25 elemens array" << endl;
	key_to_find = 3*23;

	timer = clock();
	index = array25.find_by_interpolation(key_to_find);
	timer = clock() - timer;
	cout << endl << "It took " << timer << "clicks (" << ((double)timer)/CLOCKS_PER_SEC/1000<< "milliseconds)." << endl;

	if(index == -1)
		cout << "Key " << key_to_find << " not found" << endl;
	else
		cout << "The key " << key_to_find << " in test is at position: " << index << endl;

	cout << "Test with 50 elemens array" << endl;
	key_to_find = 3*48;

	timer = clock();
	index = array50.find_by_interpolation(key_to_find);
	timer = clock() - timer;
	cout << endl << "It took " << timer << "clicks (" << ((double)timer)/CLOCKS_PER_SEC/1000<< "milliseconds)." << endl;

	if(index == -1)
		cout << "Key " << key_to_find << " not found" << endl;
	else
		cout << "The key " << key_to_find << " in test is at position: " << index << endl;

	cout << "Test with 100 elemens array" << endl;
	key_to_find = 3*98;
	
	timer = clock();
	index = array100.find_by_interpolation(key_to_find);
	timer = clock() - timer;
	cout << endl << "It took " << timer << "clicks (" << ((double)timer)/CLOCKS_PER_SEC/1000<< "milliseconds)." << endl;

	if(index == -1)
		cout << "Key " << key_to_find << " not found" << endl;
	else
		cout << "The key " << key_to_find << " in test is at position: " << index << endl;

	cout << "Test with 1000 elemens array" << endl;
	key_to_find = 3*998;
	
	timer = clock();
	index = array1000.find_by_interpolation(key_to_find);
	timer = clock() - timer;
	cout << endl << "It took " << timer << "clicks (" << ((double)timer)/CLOCKS_PER_SEC/1000<< "milliseconds)." << endl;

	if(index == -1)
		cout << "Key " << key_to_find << " not found" << endl;
	else
		cout << "The key " << key_to_find << " in test is at position: " << index << endl;

	cout << "Test with 10000 elemens array" << endl;
	key_to_find = 3*9998;
	
	timer = clock();
	index = array10000.find_by_interpolation(key_to_find);
	timer = clock() - timer;
	cout << endl << "It took " << timer << "clicks (" << ((double)timer)/CLOCKS_PER_SEC/1000<< "milliseconds)." << endl;

	if(index == -1)
		cout << "Key " << key_to_find << " not found" << endl;
	else
		cout << "The key " << key_to_find << " in test is at position: " << index << endl;

	timer = clock();
	for (int i = 0; i < 1000000000; ++i);
	timer = clock() - timer;
	cout << endl << "It took " << timer << "clicks (" << ((double)timer)/CLOCKS_PER_SEC/1000<< "milliseconds)." << endl;
}


int main()
{
	question_04();
	question_05();
	question_06();

	return 0;
}
