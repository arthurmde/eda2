#include "matrix.h"
#include <iostream>
#include <cstdlib>
#include <unistd.h>

using namespace std;

void printv(const int vector[], const int size)
{
	int j;
	system("clear");
	for(int i=0 ; i<size ; i++)
	{
		j=vector[i];
		while(j>0)
		{
			cout << "   ";
			j--;
		}
		cout << vector[i] << endl;
	}
	usleep(80000);
}
