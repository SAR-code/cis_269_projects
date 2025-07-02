/*
* script: StockListType.h
* action: This program contains a class implementation for a StockListType class.
* author: D.M
* date: 01JUL25
*/

#include "StockListType.h"
#include <iomanip>
#include <algorithm>

using namespace std;

// Constructor
StockListType::StockListType(int size) : ListType<StockType>(size) {}

// Method to sort by gain loss
void StockListType::sortByLossGains() {

	// Resize the sort indices vector to match the current list size
	sortIndicesGainLoss.resize(length);

	// For loop to initialize the indices
	for (int i = 0; i < length; ++i) {
		sortIndicesGainLoss[i] = i; 
	}

	// Sort the indices based on the gain/loss of the stocks
	sort(sortIndicesGainLoss.begin(), sortIndicesGainLoss.end(),
		[this](int a, int b) {
			return (list[a].getPercentChange() < list[b].getPercentChange());
		});
}

// Method to output stocks sorted by symbol
void StockListType::outputBySymbol() const {

	// Display header
	cout << "\n--- Listing Stocks By Symbol ---\n";

	// Loop through the list and output each stock
	for (int i = 0; i < length; ++i) {
		list[i].displayStockDetails();
	}
}

// Method to output stocks sorted by gain/loss
void StockListType::outputByGainLoss() const {

	// Display header
		cout << "\n--- Listing Stocks By Gain/Loss ---\n";
	// Loop through the sorted indices and output each stock
	for (int i = 0; i < length; ++i) {
		int index = sortIndicesGainLoss[i];
		list[index].displayStockDetails();
	}
}

// Method to get the sorted indices for gain/loss
std::vector<int> StockListType::getSortIndices() const {
	return sortIndicesGainLoss;
}

// Method to output the formatted report
void StockListType::outputFormattedReport(ostream& os) const {
	// Display Header

	os << "**********   First Investor's Heaven   **********\n";
	os << "**********     Financial Report         **********\n\n";

	os << std::left << setw(13) << "Stock"
		<< setw(10) << "Open"
		<< setw(12) << "Close"
		<< setw(12) << "High"
		<< setw(10) << "Low"
		<< setw(9) << "Prev"
		<< setw(12) << "Percent"
		<< setw(10) << "Volume" << "\n";

	os << setw(8) << "Symbol"
		<< setw(10) << ""
		<< setw(10) << ""
		<< setw(10) << ""
		<< setw(8) << ""
		<< setw(11) << "Close"
		<< setw(10) << "Gain"
		<< setw(10) << "" << "\n";

	os << "--------  ---------- ---------- ---------- ---------- ---------- ---------- ----------\n";

	os << fixed << setprecision(2);

	for (int i = 0; i < length; ++i) {
		const StockType& stock = list[i];
		os << setw(12) << stock.getTicker()
			<< setw(11) << stock.getOpenPrice()
			<< setw(11) << stock.getClosePrice()
			<< setw(12) << stock.getDayHighPrice()
			<< setw(11) << stock.getDayLowPrice()
			<< setw(10) << stock.getPrevClosePrice()
			<< setw(10) << showpos << stock.getPercentChange() << "%" << noshowpos
			<< setw(10) << stock.getVolume() << "\n";
	}

	os << "\nClosing Assets: $" << setprecision(2) << fixed << calculateAllAssets() << "\n";
	os << "***************************************************\n";

}

// Method to calculate the total assets
double StockListType::calculateAllAssets() const {

	// Initialize total assets
	double totalAssets = 0.0;

	// Loop through the list to calculate total assets
	for (int i = 0; i < length; ++i) {
		totalAssets += list[i].getClosePrice() * list[i].getVolume();

	}

	return totalAssets;
}