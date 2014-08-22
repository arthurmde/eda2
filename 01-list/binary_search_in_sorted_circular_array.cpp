#include <iostream>

using namespace std;

int binary_search_in_sorted_circular_array(int vector[], int size, int key) 
{
  int start = 0;
  int end = size - 1;
 
  while (start <= end) 
  {
    int medium = start + ((end - start) / 2);

    if (vector[medium] == key) return medium;
 
    if (vector[start] <= vector[medium]) 
    {
      if (vector[start] <= key && key < vector[medium])
        end = medium - 1;
      else
        start = medium + 1;
    }

    else 
    {
      if (vector[medium] < key && key <= vector[end])
        start = medium + 1;
      else
        end = medium - 1;
    }
  }

  return -1;
}

int main()
{
    int array[10] = {4,5,6,7,8,9,0,1,2,3};

    cout << "RESULT: " << binary_search_in_sorted_circular_array(array, 10, 5) << endl;    

    return 0;
}


