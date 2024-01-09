/**
* Title: Heaps and AVL Tree
* Author: Tarik Berkan Bilge
* ID: 22003392
* Section: 1
* Assignment: 3
*/

#include <iostream>

#ifndef INC_202_HW3_HEAP_H
#define INC_202_HW3_HEAP_H

using namespace std;

class heap {
public:
    heap(int capacity);

    ~heap();

    void insert(const int a);

    int maximum();

    int popMaximum();

    int getComparisons();

    int size;

private:
    int comparisons, capacity;
    int *items;

    void heapDelete(int &root);

    void heapRebuild(int root);
};


#endif //INC_202_HW3_HEAP_H
