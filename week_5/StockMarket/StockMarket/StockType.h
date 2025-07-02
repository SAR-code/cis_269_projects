/*
* script: StockType.h
* action: This program contains a class definition for a StockType class.
* author: D.M
* date: 01JUL25
*/

#ifndef STOCKTYPE_H
#define STOCKTYPE_H

#include <string>
#include <iostream>


class StockType {

public:

	// Constructor
	StockType();

	// Method to set the stock details
	void setStockDetails(std::string ticker, double oPrice, double cPrice, double dHigh,
		double dLow, double prevClose, int vol);

	// Method to display the stock details
	void displayStockDetails() const;

	// Method to get the percentage change (gain/loss)
	double getPercentChange() const;

	// Method to get the stock ticker (symbol)
	std::string getTicker() const;

	// Method to get the stock volume
	int getVolume() const;

	// Methods to get the various stock prices
	double getOpenPrice() const;
	double getClosePrice() const;
	double getDayHighPrice() const;
	double getDayLowPrice() const;
	double getPrevClosePrice() const;

	// Overloaded operator for comparing stock tickers
	bool operator<(const StockType& other) const;

	// Overloaded operator for outputting stock details
	friend std::ostream& operator<<(std::ostream& os, const StockType& stock);

	// Overloaded operator for inputting stock details
	friend std::istream& operator>>(std::istream& is, StockType& stock);

private:

	// Declare private member variables
	std::string symbol;
	double openPrice = 0.0;
	double closePrice = 0.0;
	double dayHighPrice = 0.0;
	double dayLowPrice = 0.0;
	double previousClosePrice = 0.0;
	int volume = 0;

};



#endif

