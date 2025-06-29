/*
* script: CheckingAccount.h
* action: This program contains a class definition for a CheckingAccount class.
* author: D.M
* date: 29JUN25
*/

#ifndef CHECKINGACCOUNT_H
#define CHECKINGACCOUNT_H

#include "BankAccount.h"

class CheckingAccount : public BankAccount {

public:

	// Constructors
	CheckingAccount();

	CheckingAccount(int accountNum, double balance,
		double rate, double minBalance, double charge);

	// Method setters for interest rate, minimum balance, and service charge
	void setInterestRate(double rate);
	void setMinBalance(double minBalance);
	void setServiceCharge(double charge);

	// Method getters for interest rate, minimum balance, and service charge
	double getInterestRate() const;
	double getMinBalance() const;
	double getServiceCharge() const;

	// Method to calculate balance post interest
	void postInterest();

	// Method to determine if balance is below minimum
	bool isBelowMinBalance() const;

	// Methods to witdraw, write a check, and output account information
	void writeCheck(double amount);
	void withdraw(double amount) override;
	void outputDetails() const override;

private:

	// Declare private data members
	double interestRate = 0.0;
	double minBalance = 0.0;
	double serviceCharge = 0.0;

};

#endif
