/*
* script: SalespersonPay.cpp
* action: This program prompts the user to enter the salesperson’s fixed commission, the percentage of the commission, 
          the purchasing cost of the car, the minimum and maximum amount to be added to the purchasing cost to determine 
          the minimum and maximum selling price, and outputs minimum and maximum selling price of the car and the salesperson’s 
          commission range.
* author: D.M
* date: 03JUN25
*/

#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    // Declare required variables
    double fixedCommission;
    double commissionPercentage;
    double purchasingCost;
    double minAmountToAdd;
    double maxAmountToAdd;

    // Prompt the user to enter the fixed commision
    cout << "Enter the fixed commission ($20): $";
    cin >> fixedCommission;

    // Prompt the user to enter the commission percentage
    cout << "Enter the commission percentage (30%): ";
    cin >> commissionPercentage;

    // Prompt the user to enter the purchasing cost of the car
    cout << "Enter the purchasing cost of the car: $";
    cin >> purchasingCost;

    // Prompt the user to enter the minimum amount to add to the purchasing cost
    cout << "Enter the minimum amount to add to the purchasing cost ($200): $";
    cin >> minAmountToAdd;

    // Prompt the user to enter the maximum amount to add to the purchasing cost
    cout << "Enter the maximum amount to add to the purchasing cost ($2000): $";
    cin >> maxAmountToAdd;


    // Calculate the selling prices
    double minSellingPrice = purchasingCost + minAmountToAdd;
    double maxSellingPrice = purchasingCost + maxAmountToAdd;

    // Convert commission percentage to decimal
    commissionPercentage /= 100;

    // Calculate the commission range
	double minCommission = fixedCommission + commissionPercentage * (minSellingPrice - purchasingCost);
    double maxCommission = fixedCommission + commissionPercentage * (maxSellingPrice - purchasingCost);

    // Output the results
    cout << fixed << setprecision(2);
    cout << "Minimum selling price of the car: $" << minSellingPrice << endl;
    cout << "Maximum selling price of the car: $" << maxSellingPrice << endl;
	cout << "Commission range: $" << minCommission << " - $" << maxCommission << endl;
    
	return 0;
    





}


