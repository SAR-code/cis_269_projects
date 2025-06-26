/*
* script: SavingsAccount.h
* action: This program contains a class definition for
  SavingsAccount class.
* author: D.M
* date: 24JUN25
*/

#ifndef SAVINGSACCOUNT_H
#define SAVINGSACCOUNT_H


#include "BankAccount.h"

class SavingsAccount : public BankAccount {
public:

	// Default constructor
	SavingsAccount(const std::string& name, int accountNum, double balance);

	// Declare virtual methods
	void withdraw(double amount) override;
	void createMonthlyStatement() override;

protected:

	// Declare protected data members
	static const double INTEREST_RATE;
};

#endif
