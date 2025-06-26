/*
* script: CertificateOfDeposit.cpp
* action: This program contains a class implementation for
  CertificateOfDeposit class.
* author: D.M
* date: 24JUN25
*/

#include "CertificateOfDeposit.h"
#include <iostream>

// Default constructor
CertificateOfDeposit::CertificateOfDeposit(const std::string& name, int accountNum,
	double balance, int maturity, double rate)
	: BankAccount(name, accountNum, balance),
	matureMonth(maturity), currentMonth(0),
	interestRate(rate) {
}

// Declare virtual methods
void CertificateOfDeposit::withdraw(double amount) {

	// Adjusts the balance on the COD
	// Alerts the user if early withdraw is detected

	if (currentMonth < matureMonth) {
		std::cout << "Early withdrawal detected, request denied.\n";
	} else if (amount <= balance) {
		balance -= amount;
	}
}

void CertificateOfDeposit::createMonthlyStatement() {

	// Calculates the balance for the monthly statement
	if (currentMonth < matureMonth) {
		currentMonth++;
	}

	balance += balance * interestRate;
}