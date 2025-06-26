/*
* script: CertificateOfDeposit.h
* action: This program contains a class definition for
  CertificateOfDeposit class.
* author: D.M
* date: 24JUN25
*/

#ifndef CERTIFICATEOFDEPOSIT_H
#define CERTIFICATEOFDEPOSIT_H

#include "BankAccount.h"

class CertificateOfDeposit : public BankAccount {
public:

	// Default constructor
	CertificateOfDeposit(const std::string& name, int accountNum, 
						double balance, int maturity, double rate);

	// Declare virtual methods
	void withdraw(double amount) override;
	void createMonthlyStatement() override;

private:

	// Declare private data members

	int matureMonth;
	int currentMonth;
	double interestRate;
};

#endif
