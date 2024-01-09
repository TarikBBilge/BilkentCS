/**
* Title: Balanced Search Trees
* Author: Tarik Berkan Bilge
* ID: 22003392
* Section: 1
* Assignment: 4
*/

#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <algorithm>
#include <sstream>
#include "Node.h"
using namespace std;

#ifndef INC_202_HW4_AVLTREE_H
#define INC_202_HW4_AVLTREE_H


class AVLTree {
public:
    AVLTree();
    ~AVLTree();
    void addWord(const string& word);
    void generateTree(const string& filename);
    void printWordFrequencies(const string& filename);
    string printMostFrequent();
    string printLeastFrequent();
    double printStandardDeviation(int totalWordCount);
    int getSumWordCounts();
    int getSumWordCounts(Node* node);
    int calculateTotalWordCount();
    int getHeight();
    int getHeight(Node* node);
private:
    Node* root;
    // Helper functions
    int height(Node* node);
    int balanceFactor(Node* node);
    void updateHeight(Node* node);
    Node* rotateRight(Node* y);
    Node* rotateLeft(Node* x);
    Node* balance(Node* node);
    Node* addWordHelper(Node* node, const string& word);
    void printWordFrequenciesHelper(Node* node, ofstream& outFile);
    void findMostFrequentHelper(Node* node, string& mostFrequentWord, int& maxFrequency);
    void findLeastFrequentHelper(Node* node, string& leastFrequentWord, int& minFrequency);
    void calculateTotalWordCountHelper(Node* node, int& totalWordCount);
    void calculateSumOfSquaresHelper(Node* node, double& sumOfSquares, int meanFrequency);
};


#endif //INC_202_HW4_AVLTREE_H
