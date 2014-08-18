#ifndef ARRAY_H
#define ARRAY_H

using namespace std;

class Array
{
    public:
        Array(int size, int gap);
        Array(int size, int gap, int initial_array[]);
        virtual ~Array();

        int find(int key);
        int find_and_insert(int key);
        void insert(int key);
        void remove(int key);

        void print_index_table();
		void print_array();


    protected:
    	void sort_array();
    	int get_primary_index(int key);
    	void make_index_table();

    	int * array;
    	int * index;
    	int size;
    	int gap;
};

#endif