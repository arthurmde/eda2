#include "Array.h"
#include <iostream>
#include <algorithm>
#include "Exceptions.h"

using namespace std;

Array::Array(int size, int gap, int initial_array[])
{
    for (int i = 0; i < size; ++i)
        this->array.push_back(initial_array[i]);

    this->gap = gap;

    this->make_index_table();
}

Array::Array(){}

Array::~Array(){}

void Array::make_index_table()
{
    this->index.clear();

    this->sort_array();

    int limit = this->index_size();

    for (int i = 0; i < limit; ++i)
    {
        pair <int, int> element;
        element.first = this->gap*i;
        element.second = this->array[this->gap*i];

        this->index.push_back(element);
    }
}

void Array::push_back(int key)
{
    this->array.push_back(key);
}

void Array::print_index_table()
{
    int limit = this->index.size();

    cout << endl << "My Array's Index Table with size = " << this->index.size() << ":" << endl;

    for (int i = 0; i < limit; ++i)
        cout << "[" << this->index[i].first << "] = " << this->index[i].second << endl;

    cout << endl;
}

void Array::print_array()
{
    cout << endl << "My Array with size = " << this->array.size() << ": ";

    for (unsigned int i = 0; i < this->array.size(); ++i)
        cout << "[" << this->array[i] << "] ";

    cout << endl;
}

int Array::find(int key)
{
    int primary_index = this->get_primary_index(key);

    cout << "primary_index = " << primary_index << endl;

    if(primary_index == -1)
        return -1;

    cout << "Primary index Key = " << this->array[primary_index] << endl;

    for (int i = primary_index; (i < primary_index+this->gap+1) && (i < (int)this->array.size()); ++i)
    {
        if(this->array[i] == key)
            return i;
    }

    return -1;
}

int Array::find_by_interpolation(int key)
{
    int start = 0;
    int end = this->array.size()-1;

    while(end >= start)
    {
        int middle =  start + ((end-start) * (key - this->array[start]) / (this->array[end]-this->array[start]));
        if(this->array[middle] == key)
            return middle;
        else if(this->array[middle] > key)
            end = middle - 1;
        else
            start = middle + 1;
    }

    return -1;
}

int Array::get_primary_index(int key)
{
    int limit = this->index.size();

    if(key < 0)
        return -1;

    for (int i = 1; i < limit; ++i)
    {
        if(key >= this->index[i-1].second && key < this->index[i].second)
            return this->index[i-1].first;
    }

    return this->index[limit-1].first;
}


int Array::remove(int key)
{
    int found = this->find(key);

    if(found == -1)
        throw key_not_found();

    this->array.erase(this->array.begin() + found);

    this->make_index_table();

    return found;
}

void Array::sort_array()
{
    if(!this->sorted())
        sort(this->array.begin(), this->array.end());
}

bool Array::sorted()
{
    for (int i = 1; i < (int)this->array.size(); ++i)
    {
        if(this->array[i] < this->array[i-1])
            return false;
    }

    return true;
}

int Array::insert(int key)
{
    int found = this->find(key);

    if(found != -1)
        throw element_already_exists();

    int position = get_better_index(key);

    this->array.emplace(this->array.begin()+position, key);

    this->make_index_table();

    return 0;
}

int Array::index_size()
{
    int size = this->array.size()/this->gap;

    if(this->array.size() % this->gap != 0)
        size++;
    return size;
}

int Array::get_better_index(int key)
{
    for (unsigned int i = 1; i < this->array.size(); ++i)
    {
        if(key < this->array[i])
            return i-1;
    }

    return this->array.size()-1;
}