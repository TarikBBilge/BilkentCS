/**
* Title: Trees
* Author: Tarik Berkan Bilge
* ID: 22003392
* Section: 1
* Assignment: 2
*/

#include "Node.h"

Node::Node(const string &ngramm){
    ngram = ngramm;
    count = 1;
    left = NULL;
    right = NULL;
}

Node::~Node() {
    delete left;
    delete right;
    left = NULL;
    right = NULL;
}