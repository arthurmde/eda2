#ifndef ARRAY_H
#define ARRAY_H

#include <vector>
#include <utility>

using namespace std;

class Array
{
    public:
        Array(int size, int gap, int initial_array[]);
        virtual ~Array();

        int find(int key);
        int find_and_insert(int key);
        int insert(int key);
        int remove(int key);

        void print_index_table();
		void print_array();


    protected:
    	void sort_array();
    	int get_primary_index(int key);
    	void make_index_table();
        int index_size();
        int get_better_index(int key);
        bool sorted();

        vector<int> array;
        vector< pair <int, int> > index;
    	int gap;
};

#endif