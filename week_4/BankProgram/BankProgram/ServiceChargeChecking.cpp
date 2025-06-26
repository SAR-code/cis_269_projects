/*
* script: ServiceChargeChecking.cpp
* action: This program contains a class implementation for
  ServiceChargeChecking class.
* author: D.M
* date: 24JUN25
*/

#include "ServiceChargeChecking.h"
#include <iostream>

// Assign constants
const double ServiceChargeChecking::SERVICE_CHARGE = 3.00;

// Default constructor
ServiceChargeChecking::ServiceChargeChecking(const std::string& name, int accountNum, double balance)
	: CheckingAccount(name, accountNum, balance), writtenChecks(0) {
}

void ServiceChargeChecking::writeCheck(double amount) {

	// Compares the checks written with the max checks
	if (writtenChecks < MAXIMUM_CHECKS && amount <= balance) {
		balance -= amount;
		writtenChecks++;
	}
	else {
		std::cout << "Exceeded the check limit or not enough funds\n";
	}
}

void ServiceChargeChecking::withdraw(double amount)
{
	// Checks the balance amount
	if (amount <= balance)
		balance -= amount;
}

void ServiceChargeChecking::createMonthlyStatement() {
	 
	// Subtracts the service charge and sets checks to 0
	balance -= SERVICE_CHARGE;
	writtenChecks = 0;
}
