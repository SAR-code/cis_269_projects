/*
* script: NoServiceChargeChecking.cpp
* action: This program contains a class implementation for
  NoServiceChargeChecking class.
* author: D.M
* date: 24JUN25
*/

#include "NoServiceChargeChecking.h"

// Assign the constants a value
const double NoServiceChargeChecking::MINIMUM_BAL = 100.00;
const double NoServiceChargeChecking::INTEREST_RATE = 0.03;

// Default Constructor
NoServiceChargeChecking::NoServiceChargeChecking(const std::string& name, int accountNum, double balance)
	: CheckingAccount(name, accountNum, balance) {
}

// Declare virtual methods previously created
void NoServiceChargeChecking::writeCheck(double amount) {

	if (amount <= balance) {
		balance -= amount;
	}
		
}

void NoServiceChargeChecking::withdraw(double amount) {

	if (amount <= balance) {
		balance -= amount;
	}
}

void NoServiceChargeChecking::createMonthlyStatement() {

	if (balance >= MINIMUM_BAL) {
		balance += balance * INTEREST_RATE;
	}
}