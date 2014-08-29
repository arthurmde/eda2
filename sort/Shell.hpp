#ifndef SHELL_HPP_
#define SHELL_HPP_

#include <vector>
#include "Sort.hpp"

using namespace std;

class Shell : public Sort
{
    public:
        Shell();
        ~Shell();

        void sort(vector<int>& array);
};

#endif