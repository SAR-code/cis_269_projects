/*
* script: NoServiceChargeChecking.h
* action: This program contains a class definition for
  NoServiceChargeChecking class.
* author: D.M
* date: 24JUN25
*/

#ifndef NOSERVICECHARGECHECKING_H
#define NOSERVICECHARGECHECKING_H

#include "CheckingAccount.h"

class NoServiceChargeChecking : public CheckingAccount {
public:

	// Default Constructor
	NoServiceChargeChecking(const std::string& name, int accountNum, double balance);

	// Override virtual methods
	void writeCheck(double amount) override;
	void withdraw(double amount) override;
	void createMonthlyStatement() override;

protected:

	// Declare protected data members
	static const double MINIMUM_BAL;
	static const double INTEREST_RATE;

};

#endif