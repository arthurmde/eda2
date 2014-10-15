#ifndef RADIX_HPP_
#define RADIX_HPP_

#include <vector>
#include "Sort.hpp"

using namespace std;

class Radix : public Sort
{
    public:
        Radix();
        ~Radix();

        string name();
        void sort(vector<int>& array);
};

#endif
