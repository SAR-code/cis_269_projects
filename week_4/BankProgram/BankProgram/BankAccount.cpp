/*
* script: BankAccount.cpp
* action: This program contains a class implementation for a bank account.
* author: D.M
* date: 24JUN25
*/

#include "BankAccount.h"
#include <iostream>

// Default constructor
BankAccount::BankAccount(const std::string& name, int accountNum, double balance)
	: name(name), accountNumber(accountNum), balance(balance) {
}

// Method to get the account holder's name
std::string BankAccount::getName() const {
	return name;
}

// Method to get the account number
int BankAccount::getAccountNumber() const {
	return accountNumber;
}

// Method to get the current balance
double BankAccount::getBalance() const {
	return balance;
}

// Method to deposit an amount into the account
void BankAccount::deposit(double amount) {

	// Check if the deposit amount is positive then update the balance
	if (amount > 0) {
		balance += amount;
		std::cout << "Deposited: $" << amount << std::endl;
	} else {
		std::cout << "Deposit amount must be positive." << std::endl;
	}
}
