/*
* script: SortArray.cpp
* action: This program sorts an array of 10,000
*         elements using quick sort algorithm.
* author: D.M
* date: 27JUL2025
*/

#include <iostream>
#include <ctime>
#include <random>
#include "QuickSortAlgo.h"

using namespace std;

// Delcare constants
const int SIZE = 10000;

// Function prototype
void fillArray(int arr[], int size);



int main()
{
    // Declare arrays to hold original and sorted data
    int originalArray[SIZE];     
    int sortedArray[SIZE];      

    // Fill original array with random data
    fillArray(originalArray, SIZE); 

	// Declare variables to hold time measurements
    clock_t start, end;

    // QuickSort using middle pivot
    copyArray(originalArray, sortedArray, SIZE);
    start = clock();
    quickSortMiddlePivot(sortedArray, 0, SIZE - 1);
    end = clock();
    cout << "QuickSort with middle pivot: "
        << double(end - start) / CLOCKS_PER_SEC << " seconds.\n";

    // QuickSort using first, middle, and last pivot
    copyArray(originalArray, sortedArray, SIZE);
    start = clock();
    quickSortMedianFirstMiddleLast(sortedArray, 0, SIZE - 1);
    end = clock();
    cout << "QuickSort with median first, middle, and last: "
        << double(end - start) / CLOCKS_PER_SEC << " seconds.\n";

    // QuickSort + Insertion, middle pivot
    copyArray(originalArray, sortedArray, SIZE);
    start = clock();
    quickSortMiddleWithInsertion(sortedArray, 0, SIZE - 1);
    end = clock();
    cout << "QuickSort with middle pivot + insertion sort: "
        << double(end - start) / CLOCKS_PER_SEC << " seconds.\n";

    // QuickSort + Insertion, median of first, middle, and last pivot
    copyArray(originalArray, sortedArray, SIZE);
    start = clock();
    quickSortMedianWithInsertion(sortedArray, 0, SIZE - 1);
    end = clock();
    cout << "QuickSort with median first, middle, and last + insertion sort: "
        << double(end - start) / CLOCKS_PER_SEC << " seconds.\n";

    return 0;
}

// Declare function to fill the array with random numbers
void fillArray(int arr[], int size) {
    
    random_device rd;
    mt19937 gen(rd());                   
    uniform_int_distribution<> dist(1, 1000000); 

    for (int idx = 0; idx < size; ++idx) {
        arr[idx] = dist(gen);
    }
}


