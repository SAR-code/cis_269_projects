/*
* script: BankAccount.h
* action: This program contains a class definition for a bank account.
* author: D.M
* date: 24JUN25
*/

#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H

#include <string>

class BankAccount {

public :
	// Default constructor
	BankAccount(const std::string& name, int accountNum, double balance);

	// Establish virtual function
	virtual ~BankAccount() {};

	// Class methods for getting account details
	std::string getName() const;
	int getAccountNumber() const;
	double getBalance() const;

	// Virtual methods for deposit and withdraw operations
	virtual void deposit(double amount);
	virtual void withdraw(double amount) = 0;
	virtual void createMonthlyStatement() = 0;

protected:

	// Declare required data members
	std::string name;
	int accountNumber;
	double balance = 0.0;
};

#endif
