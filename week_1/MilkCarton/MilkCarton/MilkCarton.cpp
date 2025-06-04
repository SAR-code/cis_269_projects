/*
* script: MilkCarton.cpp
* action: This program receives the user's input for milk produced
*         in the morning and outputs the cartons required, cost,
*         and profit for production.
* author: D.M
* date: 03JUN25
*/

#include <iostream>
#include <iomanip>
#include <ios>


#define CARTON_CAPACITY 3.78 // in Liters

using namespace std;

int main()
{

    // Declare required variables
    double milkProduced;
    int cartonsRequired;
    double costPerLiter = 0.38;
    double profitPerCarton = 0.27;

    // Prompt the user to enter the total amount of milk produced in liters
    cout << "Enter the total amount of milk produced in liters: ";
    cin >> milkProduced;

    // Calculate the number of cartons required
    cartonsRequired = milkProduced / CARTON_CAPACITY;

    // Calculate the total cost of milk production
    double totalCost = milkProduced * costPerLiter;

    // Calculate the total profit from producing the milk
    double totalProfit = cartonsRequired * profitPerCarton;

    // Output the final results
    cout << "Cartons required: " << cartonsRequired << endl;
	cout << "Milk leftover: " << fixed << setprecision(2) << milkProduced - (cartonsRequired * CARTON_CAPACITY) << " liters" << endl;
    cout << "Total cost of milk production: $" <<  totalCost << endl;
    cout << "Total profit from producing milk: $" << totalProfit << endl;
	
    return 0;



    
}


