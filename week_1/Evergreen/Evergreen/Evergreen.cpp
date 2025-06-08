/*
* script: Evergreen.cpp
* action: This program receives the user's input for milk produced
*         in the morning and outputs the cartons required, cost,
*         and profit for production.
* author: D.M
* date: 07JUN25
*/

#include <iostream>
#include <iomanip>

using namespace std;

// Function prototypes
void handleTreeCalculation(double length, double radius, double spaceBetween);

int main()
{
    // Declare required variables
    double length, radius, spaceBetween;

    // Prompt the user for input
    cout << "Enter the length of the yard in feet: ";
	cin >> length;
    cout << "Enter the radius of a fully grown tree in feet: ";
	cin >> radius;
	cout << "Enter the space between trees in feet: ";
    cin >> spaceBetween;

    // Validate the input
    if (length <= 0 || radius <= 0 || spaceBetween < 0) {
        cout << "Invalid input. Enter a positive value and non-negative values" << endl;
        return 1;
    }

    // Invoke the function to handle the tree calculation
	handleTreeCalculation(length, radius, spaceBetween);

    return 0;
}

// Define the function to handle the tree calculation
void handleTreeCalculation(double length, double radius, double spaceBetween) {

    // Calculate the diameter of a single tree
    double treeDiameter = radius * 2;

    // Calculate how many trees are able to fit
    int numberOfTrees = 0;
    if (length >= treeDiameter) {
        numberOfTrees = static_cast<int>(
            (length + spaceBetween) / (treeDiameter + spaceBetween)
            );
    }

    // Determine the space occupied by the trees
    double spaceOccupied = numberOfTrees * treeDiameter;

    // Display the results
	cout << "Number of trees that can be planted: " << numberOfTrees << endl;
    cout << "Space occupied by the trees: " << fixed << setprecision(2)
        << spaceOccupied << " feet" << endl;
}


