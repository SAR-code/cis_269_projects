/*
* script: HighInterestChecking.h
* action: This program contains a class definition for
  HighInterestChecking class.
* author: D.M
* date: 24JUN25
*/

#ifndef HIGHINTERESTCHECKING_H
#define HIGHINTERESTCHECKING_H

#include "NoServiceChargeChecking.h"

class HighInterestChecking : public NoServiceChargeChecking {

public:

	// Default Constructor
	HighInterestChecking(const std::string& name, int accountNum, double balance);

	// Virtual Methods
	void createMonthlyStatement() override;

private:

	// Declare private member variables
	static const double HIGH_INT_RATE;
	static const double HIGH_MIN_BAL;
};

#endif