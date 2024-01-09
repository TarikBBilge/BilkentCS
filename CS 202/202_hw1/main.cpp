/**
* Title: Sorting and Algorithm Efficiency
* Author: Tarik Berkan Bilge
* ID: 22003392
* Section: 1
* Assignment: 1
*/

#include <iostream>
#include "sorting.h"

int main() {
    // Start the test BubbleSort
    cout << "Bubble Sort Test" << endl;
    int compCount = 0;
    int moveCount = 0;
    int arrayTestBubble[16] = {10, 5, 9, 16, 17, 7, 4, 12, 19, 1,
                               15, 18, 3, 11, 13, 6};
    bubbleSort(arrayTestBubble, 16, compCount, moveCount);
    displayArray(arrayTestBubble, 16);
    cout << "moveCount: " << moveCount << " " << "compCount: " << compCount << endl;

    cout << "Merge Sort Test" << endl;
    compCount = 0;
    int movCount = 0;
    int arrayTestMerge[16] = {10, 5, 9, 16, 17, 7, 4, 12, 19, 1,
                               15, 18, 3, 11, 13, 6};
    mergeSort(arrayTestMerge, 16, compCount, movCount);
    displayArray(arrayTestMerge, 16);
    cout << "moveCount: " << movCount << " " << "compCount: " << compCount << endl;

    cout << "Quick Sort Test" << endl;
    compCount = 0;
    moveCount = 0;
    int arrayTestQuick[16] = {10, 5, 9, 16, 17, 7, 4, 12, 19, 1,
                               15, 18, 3, 11, 13, 6};
    quickSort(arrayTestQuick, 16, compCount, movCount);
    displayArray(arrayTestQuick, 16);
    cout << "moveCount: " << movCount << " " << "compCount: " << compCount << endl;

    performanceAnalysis();
    return 0;
}
