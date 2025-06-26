/*
* script: HighInterestSavings.cpp
* action: This program contains a class implementation for
  HighInterestSavings class.
* author: D.M
* date: 24JUN25
*/

#include "HighInterestSavings.h"

// Assign values to constants
const double HighInterestSavings::HIGH_INTEREST_RATE = 0.05;
const double HighInterestSavings::MIN_BAL = 500.00;

// Default Constructor
HighInterestSavings::HighInterestSavings(const std::string& name, int accountNum, double balance)
	: SavingsAccount(name, accountNum, balance) {
}

// Declare virtual method
void HighInterestSavings::createMonthlyStatement() {

	// Calculates the balance for monthly statement
	if (balance >= MIN_BAL) {
		balance += balance * HIGH_INTEREST_RATE;
	}
}