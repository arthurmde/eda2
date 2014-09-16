#ifndef HEAPTREE_HPP_
#define HEAPTREE_HPP_

// [i/2] é o pai do índice i
// 2i é o filho esquerdo de i
// 2i+1 é o filho direito de i

// O índice 1 não tem pai
// Um índice i só tem filho esquerdo se 2i <= n e i só tem filho direito se 2i+1 <= n

#include <vector>
#include "Sort.hpp"

using namespace std;

class HeapTree
{
    public:
        HeapTree(vector<int>& array);
        ~HeapTree();

        void heapify(int index = 0, int size = -1);
        void up_heapify(int index);
        void swap(int first, int second);

        int parent(int index);
        int left_child(int index);
        int right_child(int index);
        int get_high();
        int remove_last();
        int remove();
        void insert(int value);

        void print();

    private:
    	vector<int> heap;
};

#endif