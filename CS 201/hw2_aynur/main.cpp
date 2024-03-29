/**
 * Tarik Berkan Bilge
 * CS201 HW2
 * 22003392
 */

#include <iostream>
#include <vector>
#include <chrono>

using namespace std;

/**
* Cubic maximum contiguous subsequence sum algorithm.
*/
int maxSubSum1( const vector<int> & a ){
    int maxSum = 0;
    for(int i = 0; i < a.size(); i++){
        for(int j = i; j < a.size(); j++){
            int thisSum = 0;
            for(int k = i; k <= j; k++) {
                thisSum += a[k];
            }
            if( thisSum > maxSum) {
                maxSum = thisSum;
            }
        }
    }
    return maxSum;
}

/**
* Quadratic maximum contiguous subsequence sum algorithm.
*/
int maxSubSum2( const vector<int> & a){
    int maxSum = 0;
    for(int i = 0; i < a.size(); i++) {
        int thisSum = 0;
        for (int j = i; j < a.size(); j++) {
            thisSum += a[j];
            if (thisSum > maxSum) {
                maxSum = thisSum;
            }
        }
    }
    return maxSum;
}

/**
 * Additional function
 */
int max3( int a, int b, int c ){
    int max;
    if( a > b && a > c ){
        max = a;
    }
    else if( b > a && b > c ){
        max = b;
    }
    else if( c > b && c > a ){
        max = c;
    }
    return max;
}

/**
* Recursive maximum contiguous subsequence sum algorithm.
* Finds maximum sum in subarray spanning a[left..right].
* Does not attempt to maintain actual best sequence.
*/
int maxSumRec( const vector<int> & a, int left, int right ) {
    if (left == right) // Base case
        if (a[left] > 0) {
            return a[left];
        } else {
            return 0;
        }
    int center = (left + right) / 2;
    int maxLeftSum = maxSumRec(a, left, center);
    int maxRightSum = maxSumRec(a, center + 1, right);

    int maxLeftBorderSum = 0, leftBorderSum = 0;
    for (int i = center; i >= left; i--) {
        leftBorderSum += a[i];
        if (leftBorderSum > maxLeftBorderSum) {
            maxLeftBorderSum = leftBorderSum;
        }
    }

    int maxRightBorderSum = 0, rightBorderSum = 0;
    for (int j = center + 1; j <= right; j++) {
        rightBorderSum += a[j];
        if (rightBorderSum > maxRightBorderSum) {
            maxRightBorderSum = rightBorderSum;
        }
    }
    return max3(maxLeftSum, maxRightSum, maxLeftBorderSum + maxRightBorderSum);
}

/**
* Driver for divide-and-conquer maximum contiguous * subsequence sum algorithm.
*/
int maxSubSum3( const vector<int> & a ) {
    return maxSumRec(a, 0, a.size() - 1);
}

/**
* Linear-time maximum contiguous subsequence sum algorithm.
*/
int maxSubSum4( const vector<int> & a){

    int maxSum = 0, thisSum = 0;

    for(int j = 0; j < a.size(); j++){
        thisSum += a[j];
        if( thisSum > maxSum) {
            maxSum = thisSum;
        }
        else if( thisSum < 0) {
            thisSum = 0;
        }
    }

    return maxSum;
}

/**
 * Additional function that creates vector with random integer items
 */
vector<int> createRandomVector(  int size ){
    vector<int> vec(size);
    for (int i = 0; i < size; i++) {
        int rnd = (rand() % 2000) - 1000;
        vec[i] = rnd;
    }
    return vec;
 }

int main() {
    //cout << "Max subSum1 of size 100: " << maxSubSum1( createRandomVector(100 ) ) << endl;

    // Declare necessary variables
    std::chrono::time_point< std::chrono::system_clock > startTime;
    std::chrono::duration< double, milli > elapsedTime{};
    // Store the starting time
    startTime = std::chrono::system_clock::now();
    // Code block
    cout << maxSubSum2( createRandomVector(800000 ) ) << endl;

    // Compute the number of milliseconds that passed since the starting time
    elapsedTime = std::chrono::system_clock::now() - startTime;
    cout << "Execution took " << elapsedTime.count() << " milliseconds." << endl;
    return 0;
}
