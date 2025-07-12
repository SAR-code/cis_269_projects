/*
* script: RecursiveFunction.cpp
* action: This program uses recursion to return true
*         if the digits of a positive int are in an
*         increasing order; otherwise it returns false
* author: D.M
* date: 12JUL2025
*/

#include <iostream>
using namespace std;

// Function Prototypes
bool isIncreaseOrder(int num);

int main()
{
    // Declare required variables to test
    int testSample[] = { 86, 34, 996, 718, 128, 335, 1234, 128 };
    int testSize = sizeof(testSample) / sizeof(testSample[0]);

    // Iterate through the sample list using the recursive function
    cout << "Testing the recursive function for digits in increasing order:\n";
    for (int index = 0; index < testSize; ++index) {
        int number = testSample[index];
        cout << "Number: " << number << " ";
        if (isIncreaseOrder(number)) {
            cout << "This number is in increasing order.\n";
        }
        else {
            cout << "This number is NOT in the requested order.\n";
        }
    }


    return 0;
}

// Declare recursive function
bool isIncreaseOrder(int num) {

    // Checks to see if the base case has only a single number
    if (num < 10) {
        return true;
    }

    // Retrieves the last number
    int lastNum = num % 10;

    // Retrieves the next last number
    int secondLastNum = (num / 10) % 10;

    // If the numbers are not in increasing order, return false
    if (secondLastNum >= lastNum) {
        return false;
    }

    // Utilize recursion numbers that are not the last
    return isIncreaseOrder(num / 10);
}


