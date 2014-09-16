#ifndef INSERT_HEAP_HPP_
#define INSERT_HEAP_HPP_

#include <vector>
#include "Sort.hpp"

using namespace std;

class InsertHeap : public Sort
{
    public:
        InsertHeap();
        ~InsertHeap();

        string name();
        void sort(vector<int>& array);
};

#endif