#include "Array.h"
#include <iostream>
#include <algorithm>

using namespace std;

Array::Array(int size, int gap)
{
    this->size = size;
    this->gap = gap;

    this->array = new int[this->size];
    this->index = new int[this->size/this->gap];

    for (int i = 0; i < this->size; ++i)
        this->array[i] = -1;

    this->make_index_table();
}

Array::Array(int size, int gap, int initial_array[])
{
    this->size = size;
    this->array = initial_array;

    this->gap = gap;
    this->index = new int[this->size/this->gap];

    this->make_index_table();
}

Array::~Array()
{
    delete [] this->array;
    delete [] this->index;
}

void Array::make_index_table()
{
    if(this->index)
        delete [] this->index;
    
    this->index = new int[this->size/this->gap];

    this->sort_array();

    for (int i = 0; i < this->size/this->gap; ++i)
    {
        this->index[i] = this->array[this->gap*i];
    }
}

void Array::print_index_table()
{
    int limit = this->size/this->gap;

    cout << endl;
    cout << "My Array's Index Table with size = " << limit << ": ";

    for (int i = 0; i < limit; ++i)
        cout << "[" << this->index[i] << "]";

    cout << endl;
}

void Array::print_array()
{
    cout << endl;
    cout << "My Array with size = " << this->size << ": ";

    for (int i = 0; i < this->size; ++i)
        cout << "[" << this->array[i] << "] ";

    cout << endl;
}

int Array::find(int key)
{
    int primary_index = this->get_primary_index(key);

    if(primary_index == -1)
        return -1;

    for (int i = primary_index; (i < primary_index+this->gap+1) && (i < this->size); ++i)
    {
        if(this->array[i] == key)
            return i;
    }

    return -1;
}

int Array::get_primary_index(int key)
{
    int limit = this->size/this->gap;

    for (int i = 1; i < limit; ++i)
    {
        if(key >= this->index[i-1] && key < this->index[i])
            return i;
    }

    return -1;
}

int Array::find_and_insert(int key)
{
/*    if(this->find(key) != -1)
        return this->find(key);

    if(this->find)


    return -1;*/

    return -1;
}

void Array::sort_array()
{
    sort(this->array, this->array+this->size);
}
