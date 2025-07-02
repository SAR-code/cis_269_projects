/*
* script: StockListType.h
* action: This program contains a class definition for a StockListType class.
* author: D.M
* date: 01JUL25
*/

#ifndef STOCKLISTTYPE_H
#define STOCKLISTTYPE_H

#include <iostream>
#include <vector>
#include "ListType.h"
#include "StockType.h"

class StockListType : public ListType<StockType> {
public:

	// Constructor
	StockListType(int size = 100);

	// Method to sort by loss gains
	void sortByLossGains();

	// Method to display stock by symbol
	void outputBySymbol() const;

	// Method to display stock by gain loss
	void outputByGainLoss() const;

	// Method to display shares in an ordered format
	void outputFormattedReport(std::ostream& os) const;

	// Method to calculate the total assets
	double calculateAllAssets() const;

	// Method that implements a vector of indices for sorting
	std::vector<int> getSortIndices() const;

private:

	// Private variable to to sort the indices by gains loss
	std::vector<int> sortIndicesGainLoss;

};

#endif
