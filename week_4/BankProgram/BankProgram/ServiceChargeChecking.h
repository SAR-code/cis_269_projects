/*
* script: ServiceChargeChecking.h
* action: This program contains a class definition for 
  ServiceChargeChecking class.
* author: D.M
* date: 24JUN25
*/

#ifndef SERVICECHARGECHECKING_H
#define SERVICECHARGECHECKING_H

#include "CheckingAccount.h"

class ServiceChargeChecking : public CheckingAccount {
public:

	// Default Constructor
	ServiceChargeChecking(const std::string& name, int accountNum, double balance);

	// Declare previous virtual methods
	void writeCheck(double amount) override;
	void withdraw(double amount) override;
	void createMonthlyStatement() override;

private:

	// Declare private data members
	static const int MAXIMUM_CHECKS = 10;
	static const double SERVICE_CHARGE;
	int writtenChecks;
};

#endif