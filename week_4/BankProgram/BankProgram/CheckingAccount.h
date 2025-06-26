/*
* script: CheckingAccount.h
* action: This program contains a class definition for a checking account.
* author: D.M
* date: 24JUN25
*/

#ifndef CHECKINGACCOUNT_H
#define CHECKINGACCOUNT_H

#include "BankAccount.h"

class CheckingAccount : public BankAccount {
public:

	// Default constructor
	CheckingAccount(const std::string& name, int accountNum, double balance);
	virtual void writeCheck(double amount) = 0;
};

#endif



