/**
* Title: Balanced Search Trees
* Author: Tarik Berkan Bilge
* ID: 22003392
* Section: 1
* Assignment: 4
*/

#include <iostream>
using namespace std;

#ifndef INC_202_HW4_NODE_H
#define INC_202_HW4_NODE_H


class Node {
public:
    string word;
    int frequency, height;
    Node* left;
    Node* right;

    Node(const string &word);
    ~Node();

    friend class AVLTree;
};


#endif //INC_202_HW4_NODE_H
