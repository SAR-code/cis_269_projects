/*
* script: HighInterestSavings.h
* action: This program contains a class definition for
  HighInterestSavings class.
* author: D.M
* date: 24JUN25
*/

#ifndef HIGHINTERESTSAVINGS_H
#define HIGHINTERESTSAVINGS_H

#include "SavingsAccount.h"

class HighInterestSavings : public SavingsAccount {

public:

	// Default constructor
	HighInterestSavings(const std::string& name, int accountNum, double balance);

	// Declare virtual methods
	void createMonthlyStatement() override;

private:

	// Declare private member variables
	static const double HIGH_INTEREST_RATE;
	static const double MIN_BAL;
};

#endif
