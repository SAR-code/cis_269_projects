/*
* script: BreakfastBilling.cpp
* action: This program automates the billing process for a
*         breakfast billing system. The program peforms the following tasks:
*         - Show the customer different breakfast items offered
*         - Allow the customer to select more than one item from the menu
*         - Calculate and print the bill
* author: D.M
* date: 17JUN25
*/

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

// Declare constants for menu size and tax rate
const int MENU_SIZE = 8;
const double TAX_RATE = 0.05;

// Declare a structure to hold breakfast item details
struct menuItemType
{
    string menuItem;
    double menuPrice;
    bool isSelected;
};

// Declare function prototypes
void getData(menuItemType menuList[]);
void showMenu(menuItemType menuList[]);
void printCheck(menuItemType menuList[]);

int main()
{
    // Declare an array to hold the breakfast menu items
	menuItemType menuList[MENU_SIZE];

    // Invoke each function in the program
	getData(menuList);
	showMenu(menuList);
    printCheck(menuList);
	
    return 0;
}

// Declare function to get data for the breakfast menu
void getData(menuItemType menuList[])
{
    // Initialize the breakfast menu items
    menuList[0] = { "Plain Egg", 1.45, false };
    menuList[1] = { "Bacon and Egg", 2.45, false };
    menuList[2] = { "Muffin", 0.99, false };
    menuList[3] = { "French Toast", 1.99, false };
    menuList[4] = { "Fruit Basket", 2.49, false };
    menuList[5] = { "Cereal", 0.69, false };
    menuList[6] = { "Coffee", 0.50, false };
    menuList[7] = { "Tea", 0.75, false };
}

// Declare function to show the breakfast menu and user input
void showMenu(menuItemType menuList[])
{
	// Display the  restaurant name and menu items
    cout << "Welcome to Johnny's Restaurant!\n";
    cout << "Here is the breakfast menu:\n\n";

    // Loop through the menu items and display them
    for (int index = 0; index < MENU_SIZE; ++index) {
        cout << setw(1) << index + 1 << ". "
            << left << setw(20) << menuList[index].menuItem
            << "$" << fixed << setprecision(2) << menuList[index].menuPrice << endl;
    }

	// Prompt the user to select items from the menu
    cout << "\nPlease select the number of items you want to order (1-" 
		 << MENU_SIZE << "), or 0 to finish your order: ";

    // Initialize required variables and implement a loop for user input
    int choice;
    while (true) {
        cin >> choice;

        if (choice == 0) {
            break;
        }

        if (choice >= 1 && choice <= MENU_SIZE) {
            if (menuList[choice - 1].isSelected) {
                cout << "Item already selected. Please select another item\n";
            }
            else {
                menuList[choice - 1].isSelected = true;
                cout << menuList[choice - 1].menuItem 
					 << " has been added to your order.\n";
            }
        }
        else {
            cout << "Invalid choice. Try again\n";
        }
    }
    
}

// Declare function to print the final bill
void printCheck(menuItemType menuList[])
{
    // Declare the variables to hold the total and tax
    double total = 0.0;
    double tax = 0.0;
	double finalTotal = 0.0;

    // Display the bill
    cout << "\nThe Bill\n";

    for (int index = 0; index < MENU_SIZE; ++index) {
        if (menuList[index].isSelected) {
            cout << left << setw(20) << menuList[index].menuItem 
                 << "$" << fixed << setprecision(2) 
                 << menuList[index].menuPrice << endl;
			total += menuList[index].menuPrice;
        }
    }

    // Calculate tax and final total
	tax = total * TAX_RATE;
    finalTotal = total + tax;

    // Display the tax and final total
    cout << left << setw(20) << "\nTax"
         << " $" << fixed << setprecision(2) << tax << endl;
    cout << left << setw(20) << "Total"
         << " $" << fixed << setprecision(2) << finalTotal << endl;

}


