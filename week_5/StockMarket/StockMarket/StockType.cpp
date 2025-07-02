/*
* script: StockType.cpp
* action: This program contains a class implementation for a StockType class.
* author: D.M
* date: 01JUL25
*/

#include "StockType.h"

using namespace std;

// Constructor
StockType::StockType() {

	// Initialize member variables with default values
	symbol = "";
	openPrice = 0.0;
	closePrice = 0.0;
	dayHighPrice = 0.0;
	dayLowPrice = 0.0;
	previousClosePrice = 0.0;
	volume = 0;
}

// Method to set stock details
void StockType::setStockDetails(std::string ticker, double oPrice, double cPrice, double dHigh, 
	                            double dLow, double prevClose, int vol)
{
	// Set the stock details with the parameters
	symbol = ticker;
	openPrice = oPrice;
	closePrice = cPrice;
	dayHighPrice = dHigh;
	dayLowPrice = dLow;
	previousClosePrice = prevClose;
	volume = vol;
}

// Method to display the stock details
void StockType::displayStockDetails() const
{
	// Display the stock details
	cout << "Stock Symbol: " << symbol << endl;
	cout << "Open Price: $" << openPrice << endl;
	cout << "Close Price: $" << closePrice << endl;
	cout << "Day High Price: $" << dayHighPrice << endl;
	cout << "Day Low Price: $" << dayLowPrice << endl;
	cout << "Previous Close Price: $" << previousClosePrice << endl;
	cout << "Volume: " << volume << endl;
	cout << "Change: " << getPercentChange() << "%" << endl;
}

// Method to get the daily percentage change
double StockType::getPercentChange() const
{
	if (previousClosePrice == 0.0) {
		return 0.0;
	}

	// Return the percentage change from previous close to current close
	return ((closePrice - previousClosePrice) / previousClosePrice) * 100.0;
}

// Method to get the stock ticker symbol
std::string StockType::getTicker() const
{
	return symbol;
}

// Method to get the volume of the stock
int StockType::getVolume() const
{
	return volume;
}

// Methods to get the various price details
double StockType::getOpenPrice() const
{
	return openPrice;
}

double StockType::getClosePrice() const
{
	return closePrice;
}

double StockType::getDayHighPrice() const
{
	return dayHighPrice;
}

double StockType::getDayLowPrice() const
{
	return dayLowPrice;
}

double StockType::getPrevClosePrice() const
{
	return previousClosePrice;
}

// Overloaded operators for comparison
bool StockType::operator<(const StockType& other) const
{
	return symbol < other.symbol;
}

// Overloaded operators for output
std::ostream& operator<<(std::ostream& os, const StockType& stock)
{
	// Output the stock details in a formatted manner
	os << "Stock Symbol: " << stock.symbol << "\n"
		<< "Open Price: $" << stock.openPrice << "\n"
		<< "Close Price: $" << stock.closePrice << "\n"
		<< "Day High Price: $" << stock.dayHighPrice << "\n"
		<< "Day Low Price: $" << stock.dayLowPrice << "\n"
		<< "Previous Close Price: $" << stock.previousClosePrice << "\n"
		<< "Volume: " << stock.volume << "\n";

	return os;
}


// Overloaded operators for input
std::istream& operator>>(std::istream& is, StockType& stock)
{
	// Input the stock details
	is >> stock.symbol
	   >> stock.openPrice
	   >> stock.closePrice
	   >> stock.dayHighPrice
	   >> stock.dayLowPrice
	   >> stock.previousClosePrice
	   >> stock.volume;
	return is;
}
