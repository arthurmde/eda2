#include "Array.h"

#include <iostream>

using namespace std;

Array::Array(int size)
{
    this->size = size;

    this->array = new int[this->size];

    for (int i = 0; i < this->size; ++i)
        this->array[i] = -1;
}

Array(int size, int initial_array[])
{
    this->size = size;
    this->array = initial_array;
}

Array::~Array()
{
    delete [] this->array;
}
