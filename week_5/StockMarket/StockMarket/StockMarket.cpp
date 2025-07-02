/*
* script: StockMarket.cpp
* action: This program simulates a local stock trading system
*         that has automated trading features. On closing, the
*         company will generate and post its listings of stocks
*         and their performance on the day.
* author: D.M
* date: 01JUL25
*/

#include <iostream>
#include <fstream>
#include "StockListType.h"

using namespace std;

int main()
{
    
    // Declare ifstream and ofstream objects to handle file operations
    ifstream inputFile("StockData.txt");
    ofstream outputFile("StockDataResults.txt");

    // Check if the input/output files are handled correctly
    if (!inputFile || !outputFile) {
        cerr << "Error opening either input or output file.\n";
        exit(1);
    }

    // Declare StockListType and StockType objects
	StockListType stockList;
	StockType stock;

	// Read stock data from the input file and populate the stock list
    while (inputFile >> stock) {

		// Insert the stock into the stock list
		stockList.insertItem(stock);
    }

 
    // Sort the stock list by gain loss
    stockList.sortByLossGains();

    // Prints the formatted stock data
    stockList.outputFormattedReport(cout);
    stockList.outputFormattedReport(outputFile);

    // Close the input and output files
    inputFile.close();
    outputFile.close();
    return 0;
}


