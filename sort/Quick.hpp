#ifndef QUICK_HPP_
#define QUICK_HPP_

#include "List.hpp"
#include "Node.hpp"
#include "Sort.hpp"

using namespace std;

class Quick
{
    public:
        Quick();
        ~Quick();

        string name();
        void sort(List* list, Node* left, Node* right, int begin, int end);

};

#endif