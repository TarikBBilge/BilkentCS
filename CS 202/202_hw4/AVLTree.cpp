/**
* Title: Balanced Search Trees
* Author: Tarik Berkan Bilge
* ID: 22003392
* Section: 1
* Assignment: 4
*/

#include "AVLTree.h"

AVLTree::AVLTree() {
    root = NULL;
}

AVLTree::~AVLTree() {
    delete root;
    root = NULL;
}

void AVLTree::addWord(const string &word) {
    root = addWordHelper(root, word);
}

void AVLTree::generateTree(const string &filename) {
    ifstream inputFile(filename);
    if (!inputFile) {
        cerr << "Error opening input file." << endl;
        return;
    }

    string line;
    while (getline(inputFile, line)) {
        istringstream iss(line);
        string word;
        while (iss >> word) {
            string cleanWord;
            for (char c : word) {
                if (isalpha(c)) {
                    cleanWord += tolower(c);
                } else if (!cleanWord.empty()) {
                    addWord(cleanWord);
                    cleanWord.clear();
                }
            }
            if (!cleanWord.empty()) {
                addWord(cleanWord);
            }
        }
    }

    inputFile.close();
}

void AVLTree::printWordFrequencies(const string &filename) {
    ofstream outFile(filename);
    if (!outFile) {
        cerr << "Error opening output file." << endl;
        return;
    }

    printWordFrequenciesHelper(root, outFile);
    outFile.close();
}

string AVLTree::printMostFrequent() {
    string mostFrequentWord;
    int maxFrequency = -1;
    findMostFrequentHelper(root, mostFrequentWord, maxFrequency);
    return mostFrequentWord;
}

string AVLTree::printLeastFrequent() {
    string leastFrequentWord;
    int minFrequency = -1;
    findLeastFrequentHelper(root, leastFrequentWord, minFrequency);
    return leastFrequentWord;
}

double AVLTree::printStandardDeviation(int totalWordCount) {
    if (totalWordCount <= 0)
        return 0;

    double meanFrequency = static_cast<double>(getSumWordCounts()) / static_cast<double>(totalWordCount);
    double sumOfSquares = 0.0;
    calculateSumOfSquaresHelper(root, sumOfSquares, meanFrequency);
    double standardDeviation = sqrt(sumOfSquares / totalWordCount);
    return standardDeviation;
}

int AVLTree::getSumWordCounts() {
    return getSumWordCounts(root);
}

int AVLTree::getSumWordCounts(Node *node) {
    if (node == NULL)
        return 0;
    return node->frequency + getSumWordCounts(node->left) + getSumWordCounts(node->right);
}

int AVLTree::calculateTotalWordCount() {
    int totalWordCount = 0;
    calculateTotalWordCountHelper(root, totalWordCount);
    return totalWordCount;
}

int AVLTree::getHeight() {
    return getHeight(root);
}

int AVLTree::getHeight(Node *node) {
    if (node == NULL)
        return -1;
    return max(getHeight(node->left), getHeight(node->right)) + 1;
}

int AVLTree::height(Node *node) {
    if (node == NULL)
        return -1;
    return node->height;
}

int AVLTree::balanceFactor(Node *node) {
    return height(node->left) - height(node->right);
}

void AVLTree::updateHeight(Node *node) {
    node->height = max(height(node->left), height(node->right)) + 1;
}

Node *AVLTree::rotateRight(Node *y) {
    Node* x = y->left;
    y->left = x->right;
    x->right = y;
    updateHeight(y);
    updateHeight(x);
    return x;
}

Node *AVLTree::rotateLeft(Node *x) {
    Node* y = x->right;
    x->right = y->left;
    y->left = x;
    updateHeight(x);
    updateHeight(y);
    return y;
}

Node *AVLTree::balance(Node *node) {
    if (balanceFactor(node) > 1) {
        if (balanceFactor(node->left) < 0)
            node->left = rotateLeft(node->left);
        return rotateRight(node);
    }
    if (balanceFactor(node) < -1) {
        if (balanceFactor(node->right) > 0)
            node->right = rotateRight(node->right);
        return rotateLeft(node);
    }
    return node;
}

Node *AVLTree::addWordHelper(Node *node, const string &word) {
    if (node == NULL) {
        Node* newNode = new Node(word);
        newNode->word = word;
        newNode->frequency = 1;
        newNode->left = NULL;
        newNode->right = NULL;
        newNode->height = 0;
        return newNode;
    }

    if (word < node->word)
        node->left = addWordHelper(node->left, word);
    else if (word > node->word)
        node->right = addWordHelper(node->right, word);
    else
        node->frequency++;

    updateHeight(node);
    return balance(node);
}

void AVLTree::printWordFrequenciesHelper(Node *node, ofstream &outFile) {
    if (node == NULL)
        return;

    printWordFrequenciesHelper(node->left, outFile);
    outFile << node->word << " " << node->frequency << endl;
    printWordFrequenciesHelper(node->right, outFile);
}

void AVLTree::findMostFrequentHelper(Node *node, string &mostFrequentWord, int &maxFrequency) {
    if (node == NULL)
        return;

    findMostFrequentHelper(node->left, mostFrequentWord, maxFrequency);
    if (node->frequency > maxFrequency) {
        mostFrequentWord = node->word;
        maxFrequency = node->frequency;
    }
    findMostFrequentHelper(node->right, mostFrequentWord, maxFrequency);
}

void AVLTree::findLeastFrequentHelper(Node *node, string &leastFrequentWord, int &minFrequency) {
    if (node == NULL)
        return;

    findLeastFrequentHelper(node->left, leastFrequentWord, minFrequency);
    if (node->frequency < minFrequency || minFrequency == -1) {
        leastFrequentWord = node->word;
        minFrequency = node->frequency;
    }
    findLeastFrequentHelper(node->right, leastFrequentWord, minFrequency);
}

void AVLTree::calculateTotalWordCountHelper(Node *node, int &totalWordCount) {
    if (node == NULL)
        return;

    calculateTotalWordCountHelper(node->left, totalWordCount);
    totalWordCount++;
    calculateTotalWordCountHelper(node->right, totalWordCount);
}

void AVLTree::calculateSumOfSquaresHelper(Node *node, double &sumOfSquares, int meanFrequency) {
    if (node == NULL)
        return;

    calculateSumOfSquaresHelper(node->left, sumOfSquares, meanFrequency);
    sumOfSquares += pow(node->frequency - meanFrequency, 2);
    calculateSumOfSquaresHelper(node->right, sumOfSquares, meanFrequency);
}
