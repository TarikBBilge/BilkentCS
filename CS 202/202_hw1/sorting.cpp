/**
* Title: Sorting and Algorithm Efficiency
* Author: Tarik Berkan Bilge
* ID: 22003392
* Section: 1
* Assignment: 1
*/


#include "sorting.h"
#include <ctime>

/**
 * Bubble Sort
 */
void bubbleSort(int *arr, const int size, int &compCount, int &moveCount) {
    compCount = 0;
    moveCount = 0;

    bool sorted = false ; // False when swaps occur
    int pass = 1;
    while (!sorted && (pass < size)){
        // At this point, arr[n+1-pass..n-1] is sorted
        // and all of its entries are > the entries in arr[0..n-pass]
        sorted = true; // Assume sorted
        for ( int index = 0; index < size - pass; index++){
            compCount++;
            // At this point, all entries in arr[0..index-1]
            // are <= arr[index]
            int nextIndex = index + 1;
            if (arr[index] > arr[nextIndex])
            {
                // Exchange entries
                swap(arr[index], arr[nextIndex]);
                sorted = false; // Signal exchange
                moveCount += 3;
            } // end if
        } // end for
        // Assertion: arr[0..n-pass-1] < arr[n-pass]
        pass++;
    } // end while
}

/**
 * Merge Sort
 */
void merge( int *theArray, int first, int mid, int last, int &compCount, int &moveCount)
{
    int tempArray[ 40000 ]; // Temporary array

    // Initialize the local indices to indicate the subarrays
    int first1 = first; // Beginning of first subarray
    int last1 = mid; // End of first subarray
    int first2 = mid + 1; // Beginning of second subarray
    int last2 = last; // End of second subarray
    // While both subarrays are not empty, copy the
    // smaller item into the temporary array
    int index = first1; // Next available location in tempArray
    while ((first1 <= last1) && (first2 <= last2)){
        compCount++;
        // At this point, tempArray[first..index-1] is in order
        if (theArray[first1] <= theArray[first2]){
            tempArray[index] = theArray[first1];
            first1++;
        }
        else{
            tempArray[index] = theArray[first2];
            first2++;
        } // end if
        moveCount++;
        index++;
    } // end while
    // Finish off the first subarray, if necessary
    while (first1 <= last1){
        // At this point, tempArray[first..index-1] is in order
        tempArray[index] = theArray[first1];
        first1++;
        index++;
        moveCount++;
    } // end while
    // Finish off the second subarray, if necessary
    while (first2 <= last2){
        // At this point, tempArray[first..index-1] is in order
        tempArray[index] = theArray[first2];
        first2++;
        index++;
        moveCount++;
    } // end for
    // Copy the result back into the original array
    for (index = first; index <= last; index++) {
        theArray[index] = tempArray[index];
        moveCount++;
    }
} // end merge

void mergeSortHelper(int *arr, int first, int last, int &compCount, int &moveCount) {
    if (first < last) {
        int mid = first + (last - first) / 2;
        mergeSortHelper(arr, first, mid, compCount, moveCount);
        mergeSortHelper(arr,mid + 1, last, compCount, moveCount);
        merge(arr,  first, mid, last, compCount, moveCount);
    }
}

void mergeSort(int *arr, const int size, int &compCount, int &moveCount) {
    compCount = 0;
    moveCount = 0;
    mergeSortHelper(arr, 0, size - 1, compCount, moveCount);
}

/**
 * Quick Sort
 */
int partition(int *arr, int first, int last, int &compCount, int &moveCount) {
    int pivot = arr[first];
    int i = first + 1;
    int j = last;

    while (true) {
        while (i <= j && arr[i] <= pivot) {
            compCount++;
            i++;
        }
        while (i <= j && arr[j] >= pivot) {
            compCount++;
            j--;
        }
        if (i <= j) {
            swap(arr[i], arr[j]);
            moveCount += 6;
        }
        else {
            break;
        }
    }

    swap(arr[first], arr[j]);
    moveCount += 5;
    return j;
}

void quickSortHelper(int *arr, int first, int last, int &compCount, int &moveCount) {
    if ( first < last ) {
        int pivotIndex = partition(arr, first, last, compCount, moveCount);
        quickSortHelper(arr, first, pivotIndex - 1, compCount, moveCount);
        quickSortHelper(arr, pivotIndex + 1, last, compCount, moveCount);
    }
}

void quickSort(int *arr, const int size, int &compCount, int &moveCount) {
    compCount = 0;
    moveCount = 0;
    quickSortHelper( arr, 0, size - 1, compCount, moveCount );
}

/**
 * auxiliary global functions
 */

void displayArray(const int *arr, const int size) {
    cout << "[";
    for( int i = 0; i < size - 1; i++ ){
        cout << arr[ i ] << ", ";
    }
    cout << arr[ size - 1 ] << "]" << endl;
}

void createRandomArrays(int *&arr1, int *&arr2, int *&arr3, const int size) {
    srand((int) time(NULL));
    for (int i = 0; i < size; i++) {
        int randNum = rand() % size + 1 ; // random number taking values in between [1:size]
        arr1[i] = randNum; // reserved for bubble sort
        arr2[i] = randNum; // reserved for merge sort
        arr3[i] = randNum; // reserved for quick sort
    }
}

void createAscendingArrays(int *&arr1, int *&arr2, int *&arr3, const int size){
    for( int i = 0; i < size; i++ ){
        arr1[ i ] = i;  // reserved for bubble sort
        arr2[ i ] = i;  // reserved for merge sort
        arr3[ i ] = i;  // reserved for quick sort
    }
}

void createDescendingArrays(int *&arr1, int *&arr2, int *&arr3, const int size){
    for( int i = size; i > 0; i-- ){
        arr1[ i ] = i;  // reserved for bubble sort
        arr2[ i ] = i;  // reserved for merge sort
        arr3[ i ] = i;  // reserved for quick sort
    }
}


void performanceAnalysis() {
    /**
     * Bubble Sort Performance
     */

    cout << "-----------------------------------------------------" << endl;
    cout << "Analysis of Bubble Sort" << endl;
    cout << "Array Size Elapsed time compCount moveCount" << endl;

    //random arrays
    for( int i = 4000; i < 40001; i += 4000 ){
        int* arr1 = new int[ i ];
        int* arr2 = new int[ i ];
        int* arr3 = new int[ i ];
        createRandomArrays( arr1, arr2, arr3, i );

        int moveCount = 0;
        int compCount = 0;
        clock_t begin = clock();

        bubbleSort( arr1, i, compCount, moveCount );

        clock_t end = clock();
        double elapsed_secs = 1000 * double(end - begin) / CLOCKS_PER_SEC;
        cout << i << " " << elapsed_secs << " " << compCount << " " << moveCount << endl;
        delete []arr1;
        delete []arr2;
        delete []arr3;
    }

    //ascending arrays
    for( int i = 4000; i < 40001; i += 4000 ){
        int* arr1 = new int[ i ];
        int* arr2 = new int[ i ];
        int* arr3 = new int[ i ];
        createAscendingArrays( arr1, arr2, arr3, i );

        int moveCount = 0;
        int compCount = 0;
        clock_t begin = clock();

        bubbleSort( arr2, i, compCount, moveCount );

        clock_t end = clock();
        double elapsed_secs = 1000 * double(end - begin) / CLOCKS_PER_SEC;
        cout << i << " " << elapsed_secs << " " << compCount << " " << moveCount << endl;
        delete []arr1;
        delete []arr2;
        delete []arr3;
    }

    //descending arrays
    for( int i = 4000; i < 40001; i += 4000 ){
        int* arr1 = new int[ i ];
        int* arr2 = new int[ i ];
        int* arr3 = new int[ i ];
        createDescendingArrays( arr1, arr2, arr3, i );

        int moveCount = 0;
        int compCount = 0;
        clock_t begin = clock();

        bubbleSort( arr3, i, compCount, moveCount );

        clock_t end = clock();
        double elapsed_secs = 1000 * double(end - begin) / CLOCKS_PER_SEC;
        cout << i << " " << elapsed_secs << " " << compCount << " " << moveCount << endl;
        delete []arr1;
        delete []arr2;
        delete []arr3;
    }

    /**
     * Merge Sort Performance
     */

    cout << "-----------------------------------------------------" << endl;
    cout << "Analysis of Merge Sort" << endl;
    cout << "Array Size Elapsed time compCount moveCount" << endl;

    //random arrays
    for( int i = 4000; i < 40001; i += 4000 ){
        int* arr1 = new int[ i ];
        int* arr2 = new int[ i ];
        int* arr3 = new int[ i ];
        createRandomArrays( arr1, arr2, arr3, i );
        int moveCount = 0, compCount = 0;
        clock_t begin = clock();

        mergeSort( arr1, i, compCount, moveCount );

        clock_t end = clock();
        double elapsed_secs = 1000 * double(end - begin) / CLOCKS_PER_SEC;
        cout << i << " " << elapsed_secs << " " << compCount << " " << moveCount << endl;
        delete []arr1;
        delete []arr2;
        delete []arr3;
    }

    //ascending arrays
    for( int i = 4000; i < 40001; i += 4000 ){
        int* arr1 = new int[ i ];
        int* arr2 = new int[ i ];
        int* arr3 = new int[ i ];
        createAscendingArrays( arr1, arr2, arr3, i );

        int moveCount = 0, compCount = 0;
        clock_t begin = clock();

        mergeSort( arr2, i, compCount, moveCount );

        clock_t end = clock();
        double elapsed_secs = 1000 * double(end - begin) / CLOCKS_PER_SEC;
        cout << i << " " << elapsed_secs << " " << compCount << " " << moveCount << endl;
        delete []arr1;
        delete []arr2;
        delete []arr3;
    }

    //descending arrays
    for( int i = 4000; i < 40001; i += 4000 ){
        int* arr1 = new int[ i ];
        int* arr2 = new int[ i ];
        int* arr3 = new int[ i ];
        createDescendingArrays( arr1, arr2, arr3, i );

        int moveCount = 0, compCount = 0;
        clock_t begin = clock();

        mergeSort( arr3, i, compCount, moveCount );

        clock_t end = clock();
        double elapsed_secs = 1000 * double(end - begin) / CLOCKS_PER_SEC;
        cout << i << " " << elapsed_secs << " " << compCount << " " << moveCount << endl;
        delete []arr1;
        delete []arr2;
        delete []arr3;
    }

    /**
     * Quick Sort Performance
     */

    cout << "-----------------------------------------------------" << endl;
    cout << "Analysis of Quick Sort" << endl;
    cout << "Array Size Elapsed time compCount moveCount" << endl;

    //random arrays
    for( int i = 4000; i < 40001; i += 4000 ){
        int* arr1 = new int[ i ];
        int* arr2 = new int[ i ];
        int* arr3 = new int[ i ];
        createRandomArrays( arr1, arr2, arr3, i );

        int moveCount = 0, compCount = 0;
        clock_t begin = clock();

        quickSort( arr1, i, compCount, moveCount );

        clock_t end = clock();
        double elapsed_secs = 1000 * double(end - begin) / CLOCKS_PER_SEC;
        cout << i << " " << elapsed_secs << " " << compCount << " " << moveCount << endl;
        delete []arr1;
        delete []arr2;
        delete []arr3;
    }

    //ascending arrays
    for( int i = 4000; i < 40001; i += 4000 ){
        int* arr1 = new int[ i ];
        int* arr2 = new int[ i ];
        int* arr3 = new int[ i ];
        createAscendingArrays( arr1, arr2, arr3, i );

        int moveCount = 0, compCount = 0;
        clock_t begin = clock();

        quickSort( arr2, i, compCount, moveCount );

        clock_t end = clock();
        double elapsed_secs = 1000 * double(end - begin) / CLOCKS_PER_SEC;
        cout << i << " " << elapsed_secs << " " << compCount << " " << moveCount << endl;
        delete []arr1;
        delete []arr2;
        delete []arr3;
    }

    //descending arrays
    for( int i = 4000; i < 40001; i += 4000 ){
        int* arr1 = new int[ i ];
        int* arr2 = new int[ i ];
        int* arr3 = new int[ i ];
        createDescendingArrays( arr1, arr2, arr3, i );

        int moveCount = 0, compCount = 0;
        clock_t begin = clock();

        quickSort( arr3, i, compCount, moveCount );

        clock_t end = clock();
        double elapsed_secs = 1000 * double(end - begin) / CLOCKS_PER_SEC;
        cout << i << " " << elapsed_secs << " " << compCount << " " << moveCount << endl;
        delete []arr1;
        delete []arr2;
        delete []arr3;
    }
}