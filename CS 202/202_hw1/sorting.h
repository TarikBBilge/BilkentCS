/**
* Title: Sorting and Algorithm Efficiency
* Author: Tarik Berkan Bilge
* ID: 22003392
* Section: 1
* Assignment: 1
*/

#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

#ifndef INC_202_HW1_SORTING_H
#define INC_202_HW1_SORTING_H


void bubbleSort(int *arr, const int size, int &compCount, int &moveCount);
void mergeSort(int *arr, const int size, int &compCount, int &moveCount);
void quickSort(int *arr, const int size, int &compCount, int &moveCount);
void displayArray(const int *arr, const int size);
void createRandomArrays(int *&arr1, int *&arr2, int *&arr3, const int size);
void createAscendingArrays(int *&arr1, int *&arr2, int *&arr3, const int size);
void createDescendingArrays(int *&arr1, int *&arr2, int *&arr3, const int size);
void performanceAnalysis();


#endif //INC_202_HW1_SORTING_H
