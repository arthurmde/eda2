#ifndef ARRAY_H
#define ARRAY_H

using namespace std;

class Array
{
    public:
        Array(int size;
        Array(int size, int initial_array[]);
        virtual ~Array();

        extern int find(int key);
        extern int find_and_insert(int key);
        extern void insert(int key);
        extern void remove(int key);

    protected:
    	int * array;
    	int size;
};

#endif