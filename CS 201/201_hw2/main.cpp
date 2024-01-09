#include <iostream>
#include <ctime>
#include <cstdlib>
#include "findMedian.h"

using namespace std;

int main() {
    cout << "Enter array size: " << endl;
    int size;
    cin >> size;

    int *arr1 = new int[size];
    int *arr2 = new int[size];
    int *arr3 = new int[size];

    //declare the arrays
    for (int i = 0; i < size; i++) {
        int rnd = (rand() % 2000) - 1000;
        arr1[i] = rnd;
        arr2[i] = rnd;
        arr3[i] = rnd;
    }

    //Store the starting time 1
    double duration1;
    clock_t startTime1 = clock();

    //algorithm 1
    FIND_MEDIAN_1(arr1, size);

    //Compute the number of seconds that passed since the starting time
    duration1 = 1000.0 * double(clock() - startTime1) / double( CLOCKS_PER_SEC );
    cout << "Algorithm 1 execution took " << duration1 << " milliseconds." << endl;

    //Store the starting time 2
    double duration2;
    clock_t startTime2 = clock();

    //algorithm 2
    FIND_MEDIAN_2(arr2, size);

    //Compute the number of seconds that passed since the starting time
    duration2 = 1000 * double(clock() - startTime2) / CLOCKS_PER_SEC;
    cout << "Algorithm 2 execution took " << duration2 << " milliseconds." << endl;

    //Store the starting time 3
    double duration3;
    clock_t startTime3 = clock();

    //algorithm 3
    FIND_MEDIAN_3(arr3, size);

    //Compute the number of seconds that passed since the starting time
    duration3 = 1000 * double(clock() - startTime3) / CLOCKS_PER_SEC;
    cout << "Algorithm 3 execution took " << duration3 << " milliseconds." << endl;

    delete []arr1;
    delete []arr2;
    delete []arr3;

    return 0;
}