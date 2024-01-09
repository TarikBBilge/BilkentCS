/**
* Title: Trees
* Author: Tarik Berkan Bilge
* ID: 22003392
* Section: 1
* Assignment: 2
*/

#include <iostream>
using namespace std;

#ifndef INC_202_HW2_NODE_H
#define INC_202_HW2_NODE_H

class Node {
public:
    int count;
    string ngram;
    Node* left;
    Node* right;

    Node(const string &ngram);
    ~Node();

    friend class NgramTree;
};


#endif //INC_202_HW2_NODE_H
