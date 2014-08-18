#include <iostream>
#include "Array.h"

using namespace std;

int main()
{
	Array array = Array(100, 10);

	array.print_array();
	array.print_index_table();

	return 0;
}