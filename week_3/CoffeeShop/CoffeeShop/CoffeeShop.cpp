/*
* script: CoffeeShop.cpp
* action: This is a menu-driven program that makes the coffee
*         shop operational. The user should be able to:
*         - Buy a coffee in any size & number of cups
*         - Show the total number of cups each size sold
*         - Show the total amount of coffee sold
*         - Show the total money made
* author: D.M
* date: 16JUN25
*/

#include <iostream>
#include <iomanip>

using namespace std;

// Declare constants for coffee sizes and prices
const int SHORT = 9;
const int TALL = 12;
const int GRANDE = 15;

const double SHORT_PRICE = 1.75;
const double TALL_PRICE = 1.90;
const double GRANDE_PRICE = 2.00;

// Function prototypes
void displayInstructions();
void sellCoffee(int& shortSold, int& tallSold, int& grandeSold);
void displayCupsSold(int shortSold, int tallSold, int grandeSold);
void displayTotalCoffeeSold(int shortSold, int tallSold, int grandeSold);
void showTotalProfits(int shortSold, int tallSold, int grandeSold);

int main()
{
    // Declare required variables
    int selection;
    int shortCupsSold = 0;
    int tallCupsSold = 0;
    int grandeCupsSold = 0;

    // Implement a do-while loop to handle user input
    do {
        displayInstructions();

        // Prompt the user to make a selection
        cout << "\nPlease make a selection: ";
        cin >> selection;

        switch (selection) {
        case 1:
            sellCoffee(shortCupsSold, tallCupsSold, grandeCupsSold);
            break;
        case 2:
            displayCupsSold(shortCupsSold, tallCupsSold, grandeCupsSold);
            break;
        case 3:
            displayTotalCoffeeSold(shortCupsSold, tallCupsSold, grandeCupsSold);
            break;
        case 4:
            showTotalProfits(shortCupsSold, tallCupsSold, grandeCupsSold);
            break;
        case 5:
            cout << "Closing program!\n";
            break;
        default:
            cout << "Invalid input. Select a number between 1 to 5\n";
        }
    } while (selection != 5);

    return 0;
}

// Function to display instructions
void displayInstructions()
{
    cout << "\nWelcome to Dylan's Coffee Shack!\n";
	cout << "Please select an option from the menu below:\n";
    cout << "1. Purchase Coffee\n";
    cout << "2. Show Total Cups Each Size Sold\n";
	cout << "3. Show Total Amount of Coffee Sold\n";
    cout << "4. Show Total Profits Made\n";
    cout << "5. Exit\n";
}

// Function to handle the sale of coffee
void sellCoffee(int& shortSold, int& tallSold, int& grandeSold)
{
    int choice;
    int quantity = 0;

    // Prompt the user to select coffee cup size
    cout << "\nSelect the cup size for your coffee:\n";
    cout << "1. Short (9 oz) - $" << SHORT_PRICE << endl;
    cout << "2. Tall (12 oz) - $" << TALL_PRICE << endl;
    cout << "3. Grande (15 oz) - $" << GRANDE_PRICE << endl;
    cout << "Select your size: ";
    cin >> choice;

    // Validate the choice is between 1 and 3
    if (choice < 1 || choice > 3) {
        cout << "Invalid choice. Please select a valid size.\n";
        return;
	}

    // Prompt the user to enter the quantity of cups
    cout << "Enter the quantity of cups: ";
    cin >> quantity;

    // Validate the quantity input
    if (quantity < 0) {
        cout << "Invalid quantity. Please enter a number greater than 0.\n";
        return;
    }

    // Update the cups sold based on the user's choice
    switch (choice) {
    case 1:
        shortSold += quantity;
        break;
    case 2:
        tallSold += quantity;
        break;
    case 3:
        grandeSold += quantity;
        break;
    default:
        cout << "Invalid choice. Please select a valid size. \n";
    }
   
}

// Function to display the total cups sold for each size
void displayCupsSold(int shortSold, int tallSold, int grandeSold)
{
    // Display the total cups sold for each size
    cout << fixed << setprecision(2);
    cout << "\nTotal cups sold:\n";
    cout << "Short (small): " << shortSold << endl;
    cout << "Tall (medium): " << tallSold << endl;
    cout << "Grande (large): " << grandeSold << endl;
}

// Function to display the total amount of coffee sold
void displayTotalCoffeeSold(int shortSold, int tallSold, int grandeSold)
{
    // Calculate the total amount of coffee sold in ounces
    int totalOunces = (shortSold * SHORT) + (tallSold * TALL) + (grandeSold * GRANDE);

    // Display the total amount of coffee sold
    cout << "\nTotal coffee sold: " << totalOunces << " ounces\n";
}

// Function to show the total profits made
void showTotalProfits(int shortSold, int tallSold, int grandeSold)
{
    // Calculate the total profits made
    double totalProfits = (shortSold * SHORT_PRICE) + 
                          (tallSold * TALL_PRICE) + 
		(grandeSold * GRANDE_PRICE);

    // Display the total profits made
	cout << fixed << setprecision(2);
    cout << "\nTotal profits made: $" << totalProfits << endl;

}


