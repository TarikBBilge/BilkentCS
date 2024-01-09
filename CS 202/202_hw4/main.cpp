/**
* Title: Balanced Search Trees
* Author: Tarik Berkan Bilge
* ID: 22003392
* Section: 1
* Assignment: 4
*/

#include <iostream>
#include "AVLTree.h"
using namespace std;

int main( int argc, char* argv[] ) {
    if (argc != 2) {
        cerr << "Usage: " << argv[0] << " <input_filename>" << endl;
        return 1;
    }

    string inputFilename = argv[1];
    AVLTree avlTree;
    avlTree.generateTree(inputFilename);

    avlTree.printWordFrequencies("wordfreqs");

    ofstream statsFile("statistics");
    if (!statsFile) {
        cerr << "Error opening statistics file." << endl;
        return 1;
    }

    statsFile << "Total Word Count: " << avlTree.calculateTotalWordCount() << endl;
    statsFile << "Tree Height: " << avlTree.getHeight() << endl;
    statsFile << "Most Frequent: " << avlTree.printMostFrequent() << endl;
    statsFile << "Most Frequent: " << avlTree.printLeastFrequent() << endl;
    statsFile << "Standard Deviation: " << avlTree.printStandardDeviation(avlTree.calculateTotalWordCount()) << endl;

    statsFile.close();

    return 0;
}
