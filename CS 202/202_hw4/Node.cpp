/**
* Title: Balanced Search Trees
* Author: Tarik Berkan Bilge
* ID: 22003392
* Section: 1
* Assignment: 4
*/

#include "Node.h"

Node::Node(const string &word){
    height = 1;
    frequency = 1;
    left = NULL;
    right = NULL;
}

Node::~Node() {
    delete left;
    delete right;
    left = NULL;
    right = NULL;
}