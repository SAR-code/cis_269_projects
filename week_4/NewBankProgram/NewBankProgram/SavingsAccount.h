/*
* script: SavingsAccount.h
* action: This program contains a class definition for a SavingsAccount class.
* author: D.M
* date: 29JUN25
*/

#ifndef SAVINGSACCOUNT_H
#define SAVINGSACCOUNT_H

#include "BankAccount.h"

class SavingsAccount : public BankAccount {

public:

	// Constructors
	SavingsAccount();

	SavingsAccount(int accountNum, double balance, double rate);

	// Methods to set and get interest rate
	void setInterestRate(double rate);
	double getInterestRate() const;

	// Method to calculate post-interest balance
	void postInterest();

	// Method to withdraw and output account details
	void withdraw(double amount) override;
	void outputDetails() const override;

private:

	// Declare private data members
	double interestRate = 0.0;

};

#endif
