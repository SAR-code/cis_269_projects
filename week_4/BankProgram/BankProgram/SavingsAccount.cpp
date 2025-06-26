/*
* script: SavingsAccount.cpp
* action: This program contains a class implementation for
  SavingsAccount class.
* author: D.M
* date: 24JUN25
*/


#include "SavingsAccount.h"

// Assign values to constants
const double SavingsAccount::INTEREST_RATE = 0.01;

// Default constructor
SavingsAccount::SavingsAccount(const std::string& name, int accountNum, double balance)
	: BankAccount(name, accountNum, balance) {
}

// Declare virtual methods
void SavingsAccount::withdraw(double amount) {

	// Checks the balance before withdraw
	if (amount <= balance) {
		balance -= amount;
	}
}

void SavingsAccount::createMonthlyStatement() {
	 
	// Calculate the monthly statement
	balance += balance * INTEREST_RATE;
}