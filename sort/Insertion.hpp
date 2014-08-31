#ifndef INSERTION_HPP_
#define INSERTION_HPP_

#include <vector>
#include "Sort.hpp"

using namespace std;

class Insertion : public Sort
{
    public:
        Insertion();
        ~Insertion();

        string name();
        void sort(vector<int>& array);
};

#endif