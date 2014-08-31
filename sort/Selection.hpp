#ifndef SELECTION_HPP_
#define SELECTION_HPP_

#include <vector>
#include "Sort.hpp"

using namespace std;

class Selection : public Sort
{
    public:
        Selection();
        ~Selection();

        string name();
        void sort(vector<int>& array);
};

#endif