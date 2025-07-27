/*
* script: QuickSortAlgo.h
* action: This program contains the definition
*         of the QuickSortAlgo file.
* author: D.M
* date: 27JUL2025
*/

#ifndef QUICKSORTALGO_H
#define QUICKSORTALGO_H


const int INSERTION_SORT_LIMIT = 20;

// Function to copy an array
void copyArray(int source[], int dest[], int size);

// Function methods for each QuickSort Parameter listed
void quickSortMiddlePivot(int arr[], int low, int high);
void quickSortMedianFirstMiddleLast(int arr[], int low, int high);
void quickSortMiddleWithInsertion(int arr[], int low, int high);
void quickSortMedianWithInsertion(int arr[], int low, int high);

#endif
