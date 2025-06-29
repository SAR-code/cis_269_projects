/*
* script: NewBankProgram.cpp
* action: This program tests the design classes of:
*         - BankAccount
*         - CheckingAccount
*         - SavingsAccount 
* author: D.M
* date: 29JUN25
*/

#include <iostream>
#include "CheckingAccount.h"
#include "SavingsAccount.h"

using namespace std;

// Function prototypes
void testCheckingAccount(CheckingAccount& checking);
void testSavingsAccount(SavingsAccount& savings);

int main()
{
    // Create a test checking and savings account

    CheckingAccount checking(275610, 500.00, 1.5, 20.00, 5.00);
    SavingsAccount saving(275611, 1000.00, 2.0);

    // Invoke the test functions
	testCheckingAccount(checking);
	testSavingsAccount(saving);

    return 0;
}

// Function to test CheckingAccount functionality
void testCheckingAccount(CheckingAccount& checking) {

    // Display initial account details
    checking.outputDetails();
    cout << "\n";
	// Test deposit functionality
    checking.deposit(200.00);

    // Test wrting a check
    checking.writeCheck(450.00);

    // Test post interest
    checking.postInterest();
    cout << "\n";

	// Display updated account details
	cout << "Updated Checking Account Details:\n";
    checking.outputDetails();
    cout << "\n";
}

// Function to test SavingsAccount functionality
void testSavingsAccount(SavingsAccount& savings) {

    // Display initial account details
	savings.outputDetails();
    cout << "\n";
    // Test withdraw
    savings.withdraw(100.00);

    // Test post interest
	savings.postInterest();
    cout << "\n";

    // Display updated account details
	cout << "Updated Savings Account Details:\n";
	savings.outputDetails();
}


