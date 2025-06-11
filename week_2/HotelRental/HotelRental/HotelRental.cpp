/*
* script: HotelRental.cpp
* action: This program prompts the user to enter the cost of renting one room, 
          the number of rooms booked, the number of days the rooms are booked, 
          and the sales tax (as a percent)
* author: D.M
* date: 09JUN25
*/

#include <iostream>
#include <iomanip>

using namespace std;

// Declare constants for discount rates & rooms
const double ROOM_DISCOUNT_10 = 0.10;
const double ROOM_DISCOUNT_20 = 0.20;
const double ROOM_DISCOUNT_30 = 0.30;
const double EXTRA_3_DAY_DISCOUNT = 0.05;
const int ROOMS_BOOKED_10 = 10;
const int ROOMS_BOOKED_20 = 20;
const int ROOMS_BOOKED_30 = 30;
const int BOOKED_ATLEAST_3_DAYS = 3;

// Function prototypes
void calculateTotalCost(double roomCost, int numOfRooms, int numOfDays, double discountRate, double salesTaxPer);
void outputResults(double roomCost, int numOfRooms, int numOfDays,
    double discountRate, double totalRoomCost, double taxedAmount,
    double totalBill);

int main()
{
    // Declare required variables
    double roomPrice, salesTaxPercentage;
	int numOfRooms, numOfDays;

    // Prompt the user for input
    cout << fixed << setprecision(2);
	cout << "Enter the cost of renting one room: $";
    cin >> roomPrice;
    cout << "Enter the number of rooms booked: ";
    cin >> numOfRooms;
    cout << "Enter the number of days the rooms are booked: ";
    cin >> numOfDays;
    cout << "Enter the sales tax percentage: %";
    cin >> salesTaxPercentage;

    // Declare room discount rate
    double discountRate = 0.0;

    // Determine the doscount rate based on the number of rooms booked
    if (numOfRooms >= ROOMS_BOOKED_30) {
        discountRate = ROOM_DISCOUNT_30;
    } else if (numOfRooms >= ROOMS_BOOKED_20) {
        discountRate = ROOM_DISCOUNT_20;
    } else if (numOfRooms >= ROOMS_BOOKED_10) {
        discountRate = ROOM_DISCOUNT_10;
	}

    // Check if the number of days booked is at least 3 for an additional discount
    if (numOfDays >= BOOKED_ATLEAST_3_DAYS) {
        discountRate += EXTRA_3_DAY_DISCOUNT;
    }

    // Invoke the function to calculate the total cost of hotel rentals
	calculateTotalCost(roomPrice, numOfRooms, numOfDays, discountRate, salesTaxPercentage);

    return 0;
}

// Function to calculate the total cost of hotel rental
void calculateTotalCost(double roomCost, int numOfRooms, int numOfDays, double discountRate, double salesTaxPer) {

    // Declare local variables & calculate the total costs
    double discountedRoomCost = roomCost * (1 - discountRate);
    double totalRoomCost = discountedRoomCost * numOfRooms * numOfDays;
    double taxedAmount = totalRoomCost * (salesTaxPer / 100.0);
    double totalBill = totalRoomCost + taxedAmount;

    // Invoke the output function to display results
	outputResults(roomCost, numOfRooms, numOfDays, discountRate, totalRoomCost, taxedAmount, totalBill);

}

// Function to output the results of the hotel rental calculation
void outputResults(double roomCost, int numOfRooms, int numOfDays,
    double discountRate, double totalRoomCost, double taxedAmount,
    double totalBill) {

    // Output the results
    cout << "\nHotel Rental Summary\n";
    cout << "Cost of one room: $" << fixed << setprecision(2) << roomCost << endl;
    cout << "Number of rooms booked: " << numOfRooms << endl;
    cout << "Number of days booked: " << numOfDays << endl;
    cout << "Discount rate applied: " << discountRate * 100 << "%" << endl;
    cout << "Total room cost after discounts: $" << totalRoomCost << endl;
    cout << "Sales tax applied: $" << taxedAmount << endl;
    cout << "Total bill amount: $" << totalBill << endl;
}

