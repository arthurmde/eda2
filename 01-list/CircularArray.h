#ifndef CIRCULARARRAY_H
#define CIRCULARARRAY_H

#include "Array.h"

using namespace std;

class CircularArray
{
    public:
        CircularArray(int size, int initial_array[]);
        virtual ~CircularArray();

        int find(int key); //binary search
        int insert(int key);
        int remove(int key);

		void print_array();


    protected:
        bool sorted();
        int get_start_index();
        int get_better_index(int key);

        vector<int> array;
        int start;
        int end;
};

#endif