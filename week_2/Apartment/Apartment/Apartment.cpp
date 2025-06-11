/*
* script: Apartment.cpp
* action: This program prompts the user to enter the
*         total number of units. The rent to occupy all the units
*         The increase in rent that results in a vacant unit, and
*         the amount to maintain a rented unit.
* author: D.M
* date: 10JUN25
*/

#include <iostream>
#include <iomanip>

using namespace std;

// Function prototypes
void getNumberOfUnits(int totalUnits, double initialRent, double rentIncrease, double maintCost);
void displayOutput(int unitsRented, double bestRent, double maximumProfit);


int main()
{
    // Declare variables for user input
    int totalUnits;
	double initialRent, rentIncrease, maintCost;

    // Prompt the user for input
    cout << "Enter the total number of units: ";
	cin >> totalUnits;
	cout << "Enter the rent to occupy all the units: $";
	cin >> initialRent;
	cout << "Enter the increase in rent that results in a vacant unit: $";
	cin >> rentIncrease;
	cout << "Enter the amount to maintain a rented unit: $";
	cin >> maintCost;

    // Invoke the function to calculate the number of units and profit
	getNumberOfUnits(totalUnits, initialRent, rentIncrease, maintCost);

    return 0;
}

// Declare function to loop through the number of units
void getNumberOfUnits(int totalUnits, double initialRent, double rentIncrease, double maintCost) {

    // Declare local variables
    double maximumProfit = -1.0;
    double bestRent = 0.0;
    int unitsRented = 0;

    // Loop through the number of vacant units
    for (int vacantUnits = 0; vacantUnits <= totalUnits; ++vacantUnits) {

        int rentedUnits = totalUnits - vacantUnits;
        double currentRent = initialRent + (vacantUnits * rentIncrease);
        double profit = (rentedUnits * currentRent) - (rentedUnits * maintCost);

        // Update the profit if it's higher than the previous maximum
        if (profit > maximumProfit) {
            maximumProfit = profit;
            unitsRented = rentedUnits;
            bestRent = currentRent;
        }
    }

    // Invoke the display function to show the output
	displayOutput(unitsRented, bestRent, maximumProfit);
};

// Declare function to display the output
void displayOutput(int unitsRented, double bestRent, double maximumProfit) {

    // Display the results
    cout << "\nMaximum Profit Calculation\n";
    cout << fixed << setprecision(2);
    cout << "Units Rented: " << unitsRented << " units" << endl;
    cout << "Best rent per unit to charge: $" << bestRent << endl;
    cout << "Maximum profit: $" << maximumProfit << endl;
}


