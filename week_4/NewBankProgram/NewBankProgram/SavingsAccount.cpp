/*
* script: SavingsAccount.cpp
* action: This program contains a class implementation for a SavingsAccount class.
* author: D.M
* date: 29JUN25
*/

#include "SavingsAccount.h"
#include <iostream>
#include <iomanip>

using namespace std;

// Constructors

SavingsAccount::SavingsAccount() : BankAccount(), interestRate(0.0) {}

SavingsAccount::SavingsAccount(int accountNum, double balance, double rate)
    : BankAccount(accountNum, balance), interestRate(rate) {
}

// Setters and getters for interest rate
void SavingsAccount::setInterestRate(double rate) {

    // Assign the interest rate
    interestRate = rate;
}

double SavingsAccount::getInterestRate() const {

    // Return the interest rate
    return interestRate;
}

// Method to calculate post-interest balance
void SavingsAccount::postInterest() {

    // Update the balance with the interest
	balance += (balance * interestRate / 100.0);
}

// Methods to withdraw funds and display account information
void SavingsAccount::withdraw(double amount) {

    // Check if the account has sufficient funds
    if (amount > 0 && amount <= balance) {
        balance -= amount;
    }
    else {
		cout << "Insufficient funds for withdrawal." << endl;
    }
}

void SavingsAccount::outputDetails() const {

    // Display account details
    cout << fixed << setprecision(2);
    cout << "Savings Account Information:\n";
	BankAccount::outputDetails();
    cout << "Interest Rate: " << interestRate << "%\n";
	cout << "Balance after interest: $" << balance << endl;
}