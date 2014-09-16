#ifndef HEAP_HPP_
#define HEAP_HPP_

#include <vector>
#include "Sort.hpp"

using namespace std;

class Heap : public Sort
{
    public:
        Heap();
        ~Heap();

        string name();
        void sort(vector<int>& array);
};

#endif