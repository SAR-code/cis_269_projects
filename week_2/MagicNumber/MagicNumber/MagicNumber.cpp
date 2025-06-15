/*
* script: MagicNumber.cpp
* action: This program uses a 3x3 array and randomly
*         places each integer from 1 to 9 into the 
*         nine squares
* author: D.M
* date: 15JUN25
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <ctime>

using namespace std;

// Declare test constants
const int LOW_TEST = 1000;
const int MED_TEST = 10000;
const int HIGH_TEST = 1000000;

// Function prototypes
void fillArray(int arr[3][3]);
bool isMagicSquareSum(int arr[3][3]);

int main()
{

    // Declare required variables
    int magicNumber = 0;
    int magicGrid[3][3];

	// Test the program with a low number of iterations
    for (int index = 0; index < LOW_TEST; ++index)
    {
        fillArray(magicGrid);
        if (isMagicSquareSum(magicGrid))
        {
            ++magicNumber;
        }
    }

    // Output the results of low test
    cout << "Low Test\n";
    cout << "Tests completed: " << LOW_TEST << endl;
    cout << "Magic squares found: " << magicNumber << endl;


    // Test the program with a medium number of iterations
    for (int index = 0; index < MED_TEST; ++index)
    {
        fillArray(magicGrid);
        if (isMagicSquareSum(magicGrid))
        {
            ++magicNumber;
        }
    }

	// Output the results of medium test
	cout << "\nMedium Test\n";
    cout << "Tests completed: " << MED_TEST << endl;
	cout << "Magic squares found: " << magicNumber << endl;

    // Test the program with a high number of iterations
    for (int index = 0; index < HIGH_TEST; ++index)
    {
        fillArray(magicGrid);
        if (isMagicSquareSum(magicGrid))
        {
            ++magicNumber;
        }
    }

	// Output the results of high test
	cout << "\nHigh Test\n";
    cout << "Tests completed: " << HIGH_TEST << endl;
    cout << "Magic squares found: " << magicNumber << endl;
    return 0;
}

// Declare the function to fill the array
void fillArray(int arr[3][3])
{
    // Create a vector that contains numbers 1 to 9
	vector<int> numbers = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };

    // Randomize the order of the numbers
    static random_device randomDevice;
	static mt19937 generator(randomDevice());

    // Shuffle the numbers vector
	shuffle(numbers.begin(), numbers.end(), generator);

    // Fill the 3x3 array with the shuffled numbers
    int numIndex = 0;
    for (int index = 0; index < 3; ++index) {
        for (int jndex = 0; jndex < 3; ++jndex) {
			arr[index][jndex] = numbers[numIndex++];
        }
    }
}

// Declare the function to check if the array is a magic square
bool isMagicSquareSum(int arr[3][3]) {
	
    // Declare local variables
    int sumTotal = 0;
    int magicNum = 0;

    //  Get the sum total then divide by 3 to get the magic number
    for (int index = 0; index < 3; ++index) {
        for (int jndex = 0; jndex < 3; ++jndex) {
            sumTotal += arr[index][jndex];
        }
	}

	// Assign the magic number
    magicNum = sumTotal / 3;

    // Check the rows
    for (int index = 0; index < 3; ++index) {
        int rowSum = 0;
        for (int jndex = 0; jndex < 3; ++jndex) {
            rowSum += arr[index][jndex];
        }
        if (rowSum != magicNum) {
            return false;
        }
    }
    // Check the columns
    for (int jndex = 0; jndex < 3; ++jndex) {
        int colSum = 0;
        for (int index = 0; index < 3; ++index) {
            colSum += arr[index][jndex];
        }
        if (colSum != magicNum) {
            return false;
        }
    }
    // Check the diagonals 
    int diag1Sum = arr[0][0] + arr[1][1] + arr[2][2];
    int diag2Sum = arr[0][2] + arr[1][1] + arr[2][0];
	
	// If the diagonals do not match the magic number, return false
    if (diag1Sum != magicNum || diag2Sum != magicNum) {
        return false;
	}

    return true;
}


