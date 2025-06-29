/*
* script: CheckingAccount.cpp
* action: This program contains a class implementation for a CheckingAccount class.
* author: D.M
* date: 29JUN25
*/

#include "CheckingAccount.h"
#include <iostream>
#include <iomanip>

using namespace std;

// Constuctors
CheckingAccount::CheckingAccount()
    : BankAccount(), interestRate(0.0), minBalance(0.0), serviceCharge(0.0) {
}

CheckingAccount::CheckingAccount(int accountNumber, double balance, double interestRate, double minBalance, double serviceCharge)
    : BankAccount(accountNumber, balance), interestRate(interestRate), minBalance(minBalance), serviceCharge(serviceCharge) {
}

// Methods for setting and getting the interest rate, minimum balance, and service charge
void CheckingAccount::setInterestRate(double rate) {

    // Assign the interest rate to the member variable
	interestRate = rate;
}

double CheckingAccount::getInterestRate() const {

    // Return the interest rate
    return interestRate;
}

void CheckingAccount::setMinBalance(double minBal) {

    // Assign the minimum balance to the member variable
	minBalance = minBal;
}

double CheckingAccount::getMinBalance() const {

    // Return the minimum balance
    return minBalance;
}

void CheckingAccount::setServiceCharge(double charge) {

    // Assign the service charge to the member variable
	serviceCharge = charge;
}

double CheckingAccount::getServiceCharge() const {

    // Return the service charge
    return serviceCharge;
}

// Method to calculate post-interest balance
void CheckingAccount::postInterest() {

	// Calculate the balance after applying interest
    balance += (balance * interestRate / 100);
}

// Method to determine if the account is below the minimum balance
bool CheckingAccount::isBelowMinBalance() const {

    // Check if the current balance is below the minimum balance
    return balance < minBalance;
}

// Method to write a check
void CheckingAccount::writeCheck(double amount) {

    // Withdraws the specified amount written on the check
    withdraw(amount);
}

// Method to withdraw funds from the checking account
void CheckingAccount::withdraw(double amount) {

    // Check if the withdrawl amount is less than or equal to the current balance
    if (amount <= balance) {
        balance -= amount;

		// Apply service charge if the balance is below the minimum balance
        if (balance < minBalance) {
            balance -= serviceCharge;
        }
    }
}

// Method to display account information
void CheckingAccount::outputDetails() const {

    // Display checking account details
	cout << fixed << setprecision(2);
    cout << "Checking Account Details:\n";
	BankAccount::outputDetails();
    cout << "Interest Rate: " << interestRate << "%\n";
    cout << "Minimum Balance: $" << minBalance << "\n";
    cout << "Service Charge: $" << serviceCharge << "\n";
	cout << "Current Balance: $" << balance << "\n";
}