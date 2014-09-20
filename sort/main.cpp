#include <iostream>
#include <vector>
#include <ctime>

#include "Sort.hpp"
#include "Selection.hpp"
#include "Insertion.hpp"
#include "Shell.hpp"
#include "Count.hpp"
#include "Merge.hpp"
#include "Heap.hpp"
#include "InsertHeap.hpp"
#include "Quick.hpp"

#include "List.hpp"
#include "Node.hpp"

using namespace std;

int random_array[103] = {40, 102, 21, 83, 72, 65, 30, 26, 44, 93, 29, 51, 16, 87, 12, 28, 31, 77, 69, 91, 81, 23, 22, 88, 4, 49, 61, 39, 79, 74, 67, 38, 63, 14, 84, 100, 99, 18, 53, 97, 42, 92, 82, 95, 78, 56, 85, 58, 9, 1, 48, 34, 35, 76, 27, 17, 7, 45, 36, 54, 11, 25, 94, 90, 59, 64, 0, 15, 98, 20, 68, 32, 86, 24, 96, 75, 101, 71, 55, 41, 8, 33, 50, 2, 3, 19, 60, 66, 70, 46, 80, 89, 43, 37, 13, 5, 47, 52, 62, 6, 10, 73, 57};
// int random_array[8] = {3, 6, 4, 1, 3, 4, 1, 4};
void sort_array(Sort * sort_algorithm)
{
	cout << endl << "=========" << sort_algorithm->name() << " Sort============" << endl;

	vector<int> array(random_array, random_array + 50);

	sort_algorithm->print_array(array);
	sort_algorithm->sort(array);

	if(!sort_algorithm->sorted(array))
		cout << endl << "Array not sorted" << endl;
	else
		cout << endl << "Array succesfully sorted" << endl;

	sort_algorithm->print_array(array);
}

void quick_sort_array()
{
	List* list = new List();
	Quick* sort_algorithm = new Quick();

	cout << endl << "=========" << sort_algorithm->name() << " Sort============" << endl;

	for(int i = 0; i < 50; i++)
	{
		list->push_back(random_array[i]);
	}

	list->print();

	sort_algorithm->sort(list, list->get_head(), list->get_tail(), 0, list->size()-1);

	cout << endl << "Array succesfully sorted" << endl;
	
	list->print();

	delete list;
	delete sort_algorithm;
}

int main()
{
	Sort * selection = new Selection();
	Sort * insertion = new Insertion();
	Sort * shell = new Shell();
	Sort * count = new Count();
	Sort * heap = new Heap();
	Sort * insert_heap = new InsertHeap();
	Sort * merge = new Merge();


	sort_array(selection);
	sort_array(insertion);
	sort_array(shell);
	sort_array(count);
	sort_array(heap);
	sort_array(insert_heap);
	sort_array(merge);

	quick_sort_array();

	delete selection;
	delete insertion;
	delete shell;
	delete count;
	delete heap;
	delete merge;

	return 0;
}
