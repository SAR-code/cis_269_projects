/*
* script: FractionCalculator.cpp
* action: This program lets the user perform basic
*         arithmetic operations on fractions. This 
*         is a menu-driven program that allows
*         adding, subtracting, multiplying, and
*         dividing fractions.
* author: D.M
* date: 21JUN25
*/

#include <iostream>

using namespace std;

// Function prototypes
void menu();
void addFractions(int num1, int den1, int num2, int den2, int& resultNum, int& resultDen);
void subtractFractions(int num1, int den1, int num2, int den2, int& resultNum, int& resultDen);
void multiplyFractions(int num1, int den1, int num2, int den2, int& resultNum, int& resultDen);
void divideFractions(int num1, int den1, int num2, int den2, int& resultNum, int& resultDen);

int main()
{
	// Declare required variables to store fractions and results
	int num1 = 0;
	int den1 = 0;
	int num2 = 0;
	int den2 = 0;
	int resultNum = 0;
	int resultDen = 0;
	char operationChoice;

	// Display the menu to the user
	menu();

	// Prompt the user to enter the operation they want to perform
	cout << "\nSelect an operation (+, -, *, /): ";
	cin >> operationChoice;

	// Prompt the user to enter the first fraction
	cout << "Input the first fraction (format: a b for a/b): ";
	cin >> num1 >> den1;

	// Checks if the denominator is zero
	while (den1 == 0) {
		cout << "Denominator cannot be zero. Please enter again: ";
		cin >> den1;
	}

	// Prompt the user to enter the second fraction
	cout << "Input the first fraction (format: a b for a/b): ";
	cin >> num2 >> den2;

	// Checks if the denominator is zero
	while (den2 == 0) {
		cout << "Denominator cannot be zero. Please enter again: ";
		cin >> den2;
	}

	// Perform the operation based on user choice
	switch (operationChoice) {
		case '+':
			addFractions(num1, den1, num2, den2, resultNum, resultDen);
			cout << "Result: " << resultNum << "/" << resultDen << endl;
			break;
		case '-':
			subtractFractions(num1, den1, num2, den2, resultNum, resultDen);
			cout << "Result: " << resultNum << "/" << resultDen << endl;
			break;
		case '*':
			multiplyFractions(num1, den1, num2, den2, resultNum, resultDen);
			cout << "Result: " << resultNum << "/" << resultDen << endl;
			break;
		case '/':
			divideFractions(num1, den1, num2, den2, resultNum, resultDen);
			cout << "Result: " << resultNum << "/" << resultDen << endl;
			break;
		default:
			cout << "Invalid operation selected." << endl;
			break;
	}

	// Display the results of the selected operation
	cout << "Full Equation: " << num1 << "/" << den1 << " " 
		 << operationChoice << " " << num2 << "/" << den2 
		 << " = " << resultNum << "/" << resultDen << endl;

    return 0;
}

// Function to display the menu
void menu() {
	// Display the menu options to the user

	cout << "Fraction Calculator Menu" << endl;
	cout << "-------------------------" << endl;
	cout << " Enter (+) for Addition" << endl;
	cout << " Enter (-) for Subtraction" << endl;
	cout << " Enter (*) for Multiplication" << endl;
	cout << " Enter (/) for Division" << endl;
}

// Function to perform addition
void addFractions(int num1, int den1, int num2, int den2, int& resultNum, int& resultDen) {

	// Calculate the result of adding two fractions
	resultNum = (num1 * den2) + (num2 * den1);
	resultDen = den1 * den2;
}

// Function to perform subtraction
void subtractFractions(int num1, int den1, int num2, int den2, int& resultNum, int& resultDen) {

	// Calculate the result of subtracting two fractions
	resultNum = (num1 * den2) - (num2 * den1);
	resultDen = den1 * den2;
}

// Function to perform multiplication
void multiplyFractions(int num1, int den1, int num2, int den2, int& resultNum, int& resultDen) {

	// Calculate the result of multiplying two fractions
	resultNum = num1 * num2;
	resultDen = den1 * den2;
}

// Function to perform division
void divideFractions(int num1, int den1, int num2, int den2, int& resultNum, int& resultDen) {

	// Calculate the result of dividing two fractions
	resultNum = num1 * den2;
	resultDen = den1 * num2;
}




