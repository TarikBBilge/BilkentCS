/**
* Title: Heaps and AVL Tree
* Author: Tarik Berkan Bilge
* ID: 22003392
* Section: 1
* Assignment: 3
*/

#include "heap.h"

heap::heap(int cap) {
    capacity = cap;
    size = 0;
    comparisons = 0;
    items = new int[capacity];
}

heap::~heap() {
    delete[] items;
}

void heap::insert(const int a) {
    //Place the new item at the end of the heap
    items[size] = a;

    //Trickle new item up to its proper position
    int place = size;
    int parent = ( place - 1 ) / 2;
    while( ( place > 0 ) && items[place] > items [parent] ){
    int temp = items[parent];
    items[parent] = items[place];
    items[place] = temp;
    place = parent;
    parent = (place - 1) / 2;
    }
    ++size;
}

int heap::maximum() {
    if (size == 0) {
        throw runtime_error("Heap is empty");
    }

    return items[0];
}

int heap::popMaximum() {
    if (size == 0) {
        throw runtime_error("Heap is empty");
    }

    int max = items[0];
    items[0] = items[--size];
    heapRebuild(0);
    return max;
}

int heap::getComparisons() {
    return comparisons;
}

void heap::heapRebuild(int root) {
    int child = 2 * root + 1;      // index of root's left child, if any
    if (child < size) {
        //root is not a leaf so that it has a left child
        int rightChild = child + 1;     //index of a right child, if any
        //If root has right child, find larger child
        if (rightChild < size && items[rightChild] > items[child]) {
            child = rightChild;     // index of larger child
            comparisons++;
        }
        //If root’s item is smaller than larger child, swap values
        if (items[root] < items[child]) {
            comparisons++;
            swap(items[root], items[child]);

            //transform the new subtree into a heap
            heapRebuild(child);
        }
    }
}