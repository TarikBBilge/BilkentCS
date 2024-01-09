/**
* Title: Trees
* Author: Tarik Berkan Bilge
* ID: 22003392
* Section: 1
* Assignment: 2
*/

#include <iostream>
#include "Node.h"

using namespace std;

#ifndef INC_202_HW2_NGRAMTREE_H
#define INC_202_HW2_NGRAMTREE_H


class NgramTree {
public:
    NgramTree();
    ~NgramTree();
    void addNgram( const string& ngram );
    int getTotalNgramCount() const;
    bool isComplete() const;
    bool isFull() const;
    void generateTree( const string& fileName, const int n );
private:
    Node *root;

    void insertNode(Node*& node, const string& ngram);
    void destroyTree(Node*& node);
    int countNodes(Node* node) const;
    bool isComplete(Node* node, int index, int nodeCount) const;
    bool isFull(Node* node, int nodeCount) const;
    void printTree(ostream& out, Node* node) const;
    friend ostream& operator<<( ostream& out, const NgramTree& tree );
};


#endif //INC_202_HW2_NGRAMTREE_H
