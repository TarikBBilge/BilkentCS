#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <algorithm>
#include <sstream>

using namespace std;

// AVL Node structure
struct AVLNode {
    string word;
    int count;
    AVLNode* left;
    AVLNode* right;
    int height;
};

class AVLTree {
private:
    AVLNode* root;

    int height(AVLNode* node) {
        if (node == nullptr)
            return -1;
        return node->height;
    }

    int balanceFactor(AVLNode* node) {
        return height(node->left) - height(node->right);
    }

    void updateHeight(AVLNode* node) {
        node->height = max(height(node->left), height(node->right)) + 1;
    }

    AVLNode* rotateRight(AVLNode* y) {
        AVLNode* x = y->left;
        y->left = x->right;
        x->right = y;
        updateHeight(y);
        updateHeight(x);
        return x;
    }

    AVLNode* rotateLeft(AVLNode* x) {
        AVLNode* y = x->right;
        x->right = y->left;
        y->left = x;
        updateHeight(x);
        updateHeight(y);
        return y;
    }

    AVLNode* balance(AVLNode* node) {
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

    AVLNode* addWordHelper(AVLNode* node, const string& word) {
        if (node == nullptr) {
            AVLNode* newNode = new AVLNode;
            newNode->word = word;
            newNode->count = 1;
            newNode->left = nullptr;
            newNode->right = nullptr;
            newNode->height = 0;
            return newNode;
        }

        if (word < node->word)
            node->left = addWordHelper(node->left, word);
        else if (word > node->word)
            node->right = addWordHelper(node->right, word);
        else
            node->count++;

        updateHeight(node);
        return balance(node);
    }

    void printWordFrequenciesHelper(AVLNode* node, ofstream& outFile) {
        if (node == nullptr)
            return;

        printWordFrequenciesHelper(node->left, outFile);
        outFile << node->word << " " << node->count << endl;
        printWordFrequenciesHelper(node->right, outFile);
    }

    void findMostFrequentHelper(AVLNode* node, string& mostFrequentWord, int& maxFrequency) {
        if (node == nullptr)
            return;

        findMostFrequentHelper(node->left, mostFrequentWord, maxFrequency);
        if (node->count > maxFrequency) {
            mostFrequentWord = node->word;
            maxFrequency = node->count;
        }
        findMostFrequentHelper(node->right, mostFrequentWord, maxFrequency);
    }

    void findLeastFrequentHelper(AVLNode* node, string& leastFrequentWord, int& minFrequency) {
        if (node == nullptr)
            return;

        findLeastFrequentHelper(node->left, leastFrequentWord, minFrequency);
        if (node->count < minFrequency || minFrequency == -1) {
            leastFrequentWord = node->word;
            minFrequency = node->count;
        }
        findLeastFrequentHelper(node->right, leastFrequentWord, minFrequency);
    }

    void calculateTotalWordCountHelper(AVLNode* node, int& totalWordCount) {
        if (node == nullptr)
            return;

        calculateTotalWordCountHelper(node->left, totalWordCount);
        totalWordCount++;
        calculateTotalWordCountHelper(node->right, totalWordCount);
    }

    void calculateSumOfSquaresHelper(AVLNode* node, double& sumOfSquares, int meanFrequency) {
        if (node == nullptr)
            return;

        calculateSumOfSquaresHelper(node->left, sumOfSquares, meanFrequency);
        sumOfSquares += pow(node->count - meanFrequency, 2);
        calculateSumOfSquaresHelper(node->right, sumOfSquares, meanFrequency);
    }

public:
    AVLTree() {
        root = nullptr;
    }

    void addWord(const string& word) {
        root = addWordHelper(root, word);
    }

    void generateTree(const string& filename) {
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

    void printWordFrequencies(const string& filename) {
        ofstream outFile(filename);
        if (!outFile) {
            cerr << "Error opening output file." << endl;
            return;
        }

        printWordFrequenciesHelper(root, outFile);
        outFile.close();
    }

    string printMostFrequent() {
        string mostFrequentWord;
        int maxFrequency = -1;
        findMostFrequentHelper(root, mostFrequentWord, maxFrequency);
        return mostFrequentWord;
    }

    string printLeastFrequent() {
        string leastFrequentWord;
        int minFrequency = -1;
        findLeastFrequentHelper(root, leastFrequentWord, minFrequency);
        return leastFrequentWord;
    }

    double printStandardDeviation(int totalWordCount) {
        if (totalWordCount <= 0)
            return 0;

        double meanFrequency = static_cast<double>(getSumWordCounts()) / static_cast<double>(totalWordCount);
        double sumOfSquares = 0.0;
        calculateSumOfSquaresHelper(root, sumOfSquares, meanFrequency);
        double standardDeviation = sqrt(sumOfSquares / totalWordCount);
        return standardDeviation;
    }

    int getSumWordCounts() {
        return getSumWordCounts(root);
    }

    int getSumWordCounts(AVLNode* node) {
        if (node == nullptr)
            return 0;
        return node->count + getSumWordCounts(node->left) + getSumWordCounts(node->right);
    }

    int calculateTotalWordCount() {
        int totalWordCount = 0;
        calculateTotalWordCountHelper(root, totalWordCount);
        return totalWordCount;
    }

    int getHeight() {
        return getHeight(root);
    }

    int getHeight(AVLNode* node) {
        if (node == nullptr)
            return -1;
        return max(getHeight(node->left), getHeight(node->right)) + 1;
    }
};

int main(int argc, char* argv[]) {
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

