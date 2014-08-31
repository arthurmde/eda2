#ifndef COUNT_HPP_
#define COUNT_HPP_

#include <vector>
#include "Sort.hpp"

using namespace std;

class Count : public Sort
{
    public:
        Count();
        ~Count();

        void sort(vector<int>& array);
        string name();

    private:
    	int min_element(vector<int> & array);
    	int max_element(vector<int> & array);
};

#endif