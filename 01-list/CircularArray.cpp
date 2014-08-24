#include "CircularArray.h"
#include <iostream>
#include <climits>
#include "Exceptions.h"

using namespace std;

CircularArray::CircularArray(int size, int initial_array[])
{
    for (int i = 0; i < size; ++i)
        this->array.push_back(initial_array[i]);

    this->start = get_start_index();

    if(!this->sorted())
        throw circular_array_not_sorted();
}

CircularArray::~CircularArray(){}

void CircularArray::print_array()
{
    cout << endl << "My Circular Array with size = " << this->array.size() << ": ";

    for (unsigned int i = 0; i < this->array.size(); ++i)
        cout << "[" << this->array[i] << "] ";

    cout << endl;
}

//binary_search
int CircularArray::find(int key)
{
    int begin = 0;
    int end = this->array.size() - 1;

    while (begin <= end) 
    {
        int medium = begin + ((end - begin) / 2);

        if (this->array[medium] == key)
            return medium;

        if (this->array[begin] <= this->array[medium]) 
        {
            if (this->array[begin] <= key && key < this->array[medium])
                end = medium - 1;
            else
                begin = medium + 1;
        }

        else 
        {
            if (this->array[medium] < key && key <= this->array[end])
                begin = medium + 1;
            else
                end = medium - 1;
        }
    }

    return -1;
}

int CircularArray::remove(int key)
{
    int found = this->find(key);

    if(found == -1)
        throw key_not_found();

    this->array.erase(this->array.begin() + found);

    this->get_start_index();

    return found;
}

bool CircularArray::sorted()
{
    this->start = get_start_index();

    for (int i = this->start+1, j = 0; j < (int)this->array.size()-1; j++, i++)
    {
        if(this->array[i%this->array.size()] < this->array[(i-1)%this->array.size()])
            return false;
    }

    return true;
}

int CircularArray::insert(int key)
{
    int found = this->find(key);

    if(found != -1)
        throw element_already_exists();

    int position = get_better_index(key);

    this->array.emplace(this->array.begin()+position, key);

    this->get_start_index();

    return 0;
}

int CircularArray::get_start_index()
{
    int smaller = INT_MAX;

    for (int i = 0; i < (int)this->array.size(); ++i)
    {
        if(this->array[i] < smaller)
        {
            smaller = this->array[i];
            this->start = i;
        }
    }

    return this->start;
}

int CircularArray::get_better_index(int key)
{
    this->start = get_start_index();

    for (int i = this->start, j = 0; j < (int)this->array.size(); j++, i++)
    {
        if(key < this->array[i%this->array.size()])
            return (i-1)%this->array.size()+1;
    }

    return (this->start-1)%this->array.size()+1;
}