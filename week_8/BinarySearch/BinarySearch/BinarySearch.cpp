/*
* script: BinarySearch.cpp
* action: This program uses a binary search
*         that finds the number of comparisons
*         it takes to find if an item is in a list.
* author: D.M
* date: 27JUL2025
*/

#include <iostream>
#include <vector>
using namespace std;

// Function prototype
bool binarySearch(const vector<int>& list, int target, int& comparisons);

int main()
{
    // Declare a the sorted list of integers from the problem
    vector<int> list = { 5, 12, 25, 32, 38, 46, 58, 62, 85, 90, 97, 105, 110 };

    // Declare target numbers to search for
    vector<int> targets = { 32, 20, 105, 60 };

    // Use a binary search function within a loop
    for (int target : targets) {
        int comparisons = 0;
        bool found = binarySearch(list, target, comparisons);

        // Output the search results
        if (found) {
            cout << "Result: " << target << " was located in " << comparisons << " comparisons.\n";
        }
        else {
            cout << "Result: " << target << " was not located after " << comparisons << " comparisons.\n";
        }
    }
    return 0;
}

// Declare a function to perform a binary search
bool binarySearch(const vector<int>& list, int target, int& comparisons) {
    int first = 0;
    int last = list.size() - 1;

    // Passed by reference to count comparisons
    comparisons = 0;

    cout << "\nTarget number: " << target << endl;
    while (first <= last) {
        int middle = (first + last) / 2;
        comparisons++;

        // Show current state
        cout << "Comparison: " << comparisons
            << " first: " << first
            << ", last: " << last
            << ", middle: " << middle << endl;
            
        // Check if the middle element is the target
        if (list[middle] == target) {
            // Target found
            return true;
        }
        else if (list[middle] > target) {
            // Search in the left half
            last = middle - 1;
        }
        else {
            // Search in the right half
            first = middle + 1;
        }
    }

    // Target not found
    return false;
}


