#ifndef MERGE_HPP_
#define MERGE_HPP_

#include <vector>
#include "Sort.hpp"

using namespace std;

class Merge : public Sort
{
    public:
        Merge();
        ~Merge();

        string name();
        void sort(vector<int>& array);

        vector<int> merge_sort(vector<int> & array);
        vector<int> merge_vectors(vector<int> & left, vector<int> & right);
};

#endif