#include <iostream>
#include "Selection.hpp"
#include <vector>

using namespace std;

int main()
{
	Selection selection = Selection();

	vector<int> array;

	for(int i = 10; i >= 0; i--)
		array.push_back(i);

	selection.print_array(array);
	selection.sort(array);
	if(!selection.sorted(array))
		cout << endl << "Array not sorted" << endl;

	selection.print_array(array);

	return 0;
}
