/**
* Title: Heaps and AVL Tree
* Author: Tarik Berkan Bilge
* ID: 22003392
* Section: 1
* Assignment: 3
*/

#include <iostream>
#include <fstream>
#include "heap.h"

using namespace std;

int main( int argc, char *argv[] ) {
    if (argc != 3) {
        cerr << "Usage: " << argv[0] << " input_filename output_filename" << endl;
        return 1;
    }

    // Open the input file
    ifstream inputFile(argv[1]);
    if (!inputFile.is_open()) {
        cerr << "Error opening the input file." << endl;
        return 1;
    }

    int number;
    int capacity = 0;
    while (inputFile >> number) {
        capacity++;
    }

    // Close the input file
    inputFile.close();

    // Open the input file
    ifstream inputFile2(argv[1]);
    if (!inputFile2.is_open()) {
        cerr << "Error opening the input file." << endl;
        return 1;
    }

    // Create a heap object
    heap maxHeap( capacity );

    int value;
    // Read values from the file and insert them into the max heap
    while (inputFile2 >> value) {
        maxHeap.insert(value);
    }

    // Close the input file
    inputFile2.close();

    // Create a new output file for the sorted elements
    ofstream outputFile(argv[2]);
    if (!outputFile.is_open()) {
        cerr << "Error creating the output file." << endl;
        return 1;
    }

    // Write the sorted elements to the output file in ascending order
    while (maxHeap.size > 0) {
        outputFile << maxHeap.popMaximum() << endl;
    }

    // Close the output file
    outputFile.close();

    // Print the number of comparisons made during the sorting process
    cout << "Number of comparisons: " << maxHeap.getComparisons() << endl;

    return 0;
}
