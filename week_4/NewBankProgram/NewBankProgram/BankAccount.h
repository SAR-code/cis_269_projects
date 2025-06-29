/*
* script: BankAccount.h
* action: This program contains a class definition for a bank account.
* author: D.M
* date: 29JUN25
*/

#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H

class BankAccount {

public:

	//Constructors
	BankAccount();

	BankAccount(int accountNum, double balance);

	// Method to set the account number
	void setAccountNumber(int accountNum);

	// Method to get the account number
	int getAccountNumber() const;

	// Method to get the balance
	double getBalance() const;

	// Method to deposit money into the account
	void deposit(double amt);

	// virtual methods to to withdraw and output account details
	virtual void withdraw(double amt);
	virtual void outputDetails() const;

protected:

	// Declare protected data members
	int accountNumber = 0;
	double balance = 0.0;
};

#endif
