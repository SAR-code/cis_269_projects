/*
* script: QuickSortAlgo.cpp
* action: This program contains the implementation
*         of the QuickSortAlgo file.
* author: D.M
* date: 27JUL2025
*/


#include "QuickSortAlgo.h"
#include <algorithm> 


// Copy contents of one array into another
void copyArray(int source[], int dest[], int size) {
    for (int i = 0; i < size; i++)
        dest[i] = source[i];
}

// Insertion sort used for small sublists
void insertionSort(int arr[], int low, int high) {
    for (int idx = low + 1; idx <= high; idx++) {
        int key = arr[idx];
        int jdx = idx - 1;
        while (jdx >= low && arr[jdx] > key) {
            arr[jdx + 1] = arr[jdx];
            jdx--;
        }
        arr[jdx + 1] = key;
    }
}

// Return the middle index of a subarray
int getMiddle(int low, int high) {
    return low + (high - low) / 2;
}

// Return the median of three values
int medianOfThree(int first, int mid, int last) {

    if ((first > mid) != (first > last)) {
        return first;
    }
    else if  ((mid > first) != (mid > last)) { 
        return mid;
    }
    else { 
        return last;
    }
}

// QuickSort using the middle pivot
void quickSortMiddlePivot(int arr[], int low, int high) {
    if (low < high) {
        int mid = getMiddle(low, high);
        int pivot = arr[mid];

        int idx = low;
        int jdx = high;

        while (idx <= jdx) {
            while (arr[idx] < pivot) idx++;
            while (arr[jdx] > pivot) jdx--;
            if (idx <= jdx) {
                std::swap(arr[idx], arr[jdx]);
                idx++;
                jdx--;
            }
        }

        quickSortMiddlePivot(arr, low, jdx);
        quickSortMiddlePivot(arr, idx, high);
    }
}

// QuickSort using the median first, middle, and last
void quickSortMedianFirstMiddleLast(int arr[], int low, int high) {
    if (low < high) {
        int mid = getMiddle(low, high);
        int pivot = medianOfThree(arr[low], arr[mid], arr[high]);

        int idx = low;
        int jdx = high;

        while (idx <= jdx) {
            while (arr[idx] < pivot) idx++;
            while (arr[jdx] > pivot) jdx--;
            if (idx <= jdx) {
                std::swap(arr[idx], arr[jdx]);
                idx++;
                jdx--;
            }
        }

        quickSortMedianFirstMiddleLast(arr, low, jdx);
        quickSortMedianFirstMiddleLast(arr, idx, high);
    }
}

// QuickSort using middle pivot and insertion
void quickSortMiddleWithInsertion(int arr[], int low, int high) {
    if (high - low + 1 < INSERTION_SORT_LIMIT) {
        insertionSort(arr, low, high);
    }
    else {
        int mid = getMiddle(low, high);
        int pivot = arr[mid];

        int idx = low;
        int jdx = high;

        while (idx <= jdx) {
            while (arr[idx] < pivot) idx++;
            while (arr[jdx] > pivot) jdx--;
            if (idx <= jdx) {
                std::swap(arr[idx], arr[jdx]);
                idx++;
                jdx--;
            }
        }

        quickSortMiddleWithInsertion(arr, low, jdx);
        quickSortMiddleWithInsertion(arr, idx, high);
    }
}

// QuickSort using first, middle, last, and insertion
void quickSortMedianWithInsertion(int arr[], int low, int high) {
    if (high - low + 1 < INSERTION_SORT_LIMIT) {
        insertionSort(arr, low, high);
    }
    else {
        int mid = getMiddle(low, high);
        int pivot = medianOfThree(arr[low], arr[mid], arr[high]);

        int idx = low;
        int jdx = high;

        while (idx <= jdx) {
            while (arr[idx] < pivot) idx++;
            while (arr[jdx] > pivot) jdx--;
            if (idx <= jdx) {
                std::swap(arr[idx], arr[jdx]);
                idx++;
                jdx--;
            }
        }

        quickSortMedianWithInsertion(arr, low, jdx);
        quickSortMedianWithInsertion(arr, idx, high);
    }
}