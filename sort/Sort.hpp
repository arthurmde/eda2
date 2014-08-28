#ifndef SORT_HPP_
#define SORT_HPP_

#include <vector>

using namespace std;

class Sort
{
    public:
        Sort();
        ~Sort();

    	virtual void sort(vector<int> & array) = 0;
        virtual bool sorted(vector<int>& array);
        virtual void print_array(vector<int>& array);
    protected:
        virtual void swap(vector<int>& array, int first, int second);
};

#endif