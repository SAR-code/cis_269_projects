/*
* script: HighInterestChecking.cpp
* action: This program contains a class implementation for
  HighInterestChecking class.
* author: D.M
* date: 24JUN25
*/

#include "HighInterestChecking.h"

// Assign values to constants
const double HighInterestChecking::HIGH_INT_RATE = 0.05;
const double HighInterestChecking::HIGH_MIN_BAL = 1000.00;

// Default Constructor
HighInterestChecking::HighInterestChecking(const std::string& name, int accountNum, double balance)
	: NoServiceChargeChecking(name, accountNum, balance){ }

// Implement logic to virtual method
void HighInterestChecking::createMonthlyStatement() {

	if (balance >= HIGH_MIN_BAL) {
		balance += balance * HIGH_INT_RATE;
	}
}