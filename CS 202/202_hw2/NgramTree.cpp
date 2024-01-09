/**
* Title: Trees
* Author: Tarik Berkan Bilge
* ID: 22003392
* Section: 1
* Assignment: 2
*/

#include <fstream>
#include "NgramTree.h"

NgramTree::NgramTree(){
    root = NULL;
}

NgramTree::~NgramTree() {
    destroyTree(root);
    root =  NULL;
}

void NgramTree::addNgram(const string &ngram) {
    insertNode( root, ngram );
}

int NgramTree::getTotalNgramCount() const {
    return countNodes( root );
}

bool NgramTree::isComplete() const {
    return isComplete( root, 0, getTotalNgramCount() );
}

bool NgramTree::isFull() const {
    return isFull( root, getTotalNgramCount() );
}

void NgramTree::generateTree(const string &fileName, const int n) {
    ifstream input( fileName );

    if (!input.is_open()) {
        cerr << "Error opening file: " << fileName << endl;
        return;
    }
    string word;
    while (input >> word) {
        //remove any non-alphabetic characters from the word
        string cleanedWord;
        for (char c : word) {
            if (isalpha(c)) {
                cleanedWord += tolower(c);
            }
        }

        //ignore words with length smaller than n and add nodes to the tree
        if (word.length() >= n) {
            for (int i = 0; i <= word.length() - n; i++) {
                string ngram = word.substr(i, n);
                addNgram(ngram);
            }
        }
    }
    input.close();
}

ostream &operator<<(ostream &out, const NgramTree &tree) {
    tree.printTree( out, tree.root );
    return out;
}

void NgramTree::insertNode(Node *&node, const string &ngram) {
    if (!node) {
        node = new Node(ngram);
    }
    else if (ngram < node->ngram) {
        insertNode(node->left, ngram);
    }
    else if (ngram > node->ngram) {
        insertNode(node->right, ngram);
    }
    else {
        //if the ngram already exists, just increment the count
        node->count++;
    }
}

void NgramTree::destroyTree(Node *&node) {
    if (node) {
        destroyTree(node->left);
        destroyTree(node->right);
        delete node;
        node = NULL;
    }
}

int NgramTree::countNodes(Node *node) const {
    if (!node) {
        return 0;
    }
    return countNodes(node->left) + countNodes(node->right) + 1;
}

bool NgramTree::isComplete(Node *node, int index, int nodeCount) const {
    if(!node){
        return true;
    }
    if(index >= nodeCount){
        return false;
    }
    return isComplete(node->left, 2 * index + 1, nodeCount) &&
           isComplete(node->right, 2 * index + 2, nodeCount);
}

bool NgramTree::isFull(Node *node, int nodeCount) const {
    if( nodeCount == 0 ){
        return true;
    }
    else if( node && isFull(node->left, nodeCount / 2) && isFull(node->right, nodeCount / 2) ){
        return true;
    }
    return false;
}

void NgramTree::printTree(ostream &out, Node *node) const {
    if( node ){
        printTree( out, node->left );
        out << "''" << node->ngram << "'' appears " << node->count << " time(s) " << endl;
        printTree( out, node->right );
    }
}