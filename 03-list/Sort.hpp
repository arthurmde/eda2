#ifndef SORT_HPP_
#define SORT_HPP_

#include <vector>
#include <string>

using namespace std;

class Sort
{
    public:
        Sort();
        virtual ~Sort();

    	virtual void sort(vector<int> & array) = 0;
    	virtual string name() = 0;
        virtual bool sorted(vector<int>& array);
        virtual void print_array(vector<int>& array);
    protected:
        virtual void swap(vector<int>& array, int first, int second);
};

#endif