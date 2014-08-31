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

        string name();
        void sort(vector<int>& array);
};

#endif