/**
* Title: Trees
* Author: Tarik Berkan Bilge
* ID: 22003392
* Section: 1
* Assignment: 2
*/

// hw2.cpp

#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>

using namespace std;
#include "NgramTree.h"

int main( int argc, char** argv ) {
    NgramTree tree;
    string fileName( argv[1] );
    int n = atoi( argv[2] );
    tree.generateTree( fileName, n );
    cout << "\nTotal " << n << "-gram count: " << tree.getTotalNgramCount() << endl;
    cout << tree << endl;
    cout << n << "-gram tree is complete: " << (tree.isComplete() ? "Yes" : "No" ) << endl;
// Before insertion of new n-grams
    cout << n << "-gram tree is full: " << (tree.isFull() ? "Yes" : "No") << endl;
    tree.addNgram( "samp" );
    tree.addNgram( "samp" );
    tree.addNgram( "zinc" );
    tree.addNgram( "aatt" );
    cout << "\nTotal " << n << "-gram count: " << tree.getTotalNgramCount() << endl;
    cout << tree << endl;
    cout << n << "-gram tree is complete: " << (tree.isComplete() ? "Yes" : "No") << endl;
    cout << n << "-gram tree is full: " << (tree.isFull() ? "Yes" : "No") << endl;

    return 0;
}
