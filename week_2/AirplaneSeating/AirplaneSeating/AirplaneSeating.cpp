/*
* script: AirplaneSeating.cpp
* action: This program assigns seats for a commercial
*         airplane. The user's input includes the ticket
*         type and desired seat.
* author: D.M
* date: 15JUN25
*/

#include <iostream>
#include <iomanip>
#include <string>
#include <cctype>

using namespace std;

// Constant & Global Variables
const int SEAT_ROWS = 13;
const int SEAT_COLS = 6;

char airplaneSeats[SEAT_ROWS][SEAT_COLS];

// Function Prototypes
void loadSeatingChart();
void displaySeatingChart();
bool getSeatClass(const string& ticketClass, int& startRow, int& endRow);
void assignSeat();
void displayMenu();

int main()
{
    // Invoke function to load the seating chart
	loadSeatingChart();

    // Declare required variables
    int selection = 0;

    // Do while loop to receive user input based on their selection
    do {
        displayMenu();
        cin >> selection;

        switch (selection) {
        case 1:
            assignSeat();
            break;
        case 2:
            displaySeatingChart();
            break;
        case 3:
            cout << "Closing menu";
            break;
        default:
            cout << "Invalid option, try again\n";
        }
    } while (selection != 3);

    return 0;
}

// Declare function to load the seating chart
void loadSeatingChart() {

    // Loop through the constant variables to build the chart
    for (int index = 0; index < SEAT_ROWS; index++) {

        // Loop through columns
        for (int jndex = 0; jndex < SEAT_COLS; jndex++) {
            airplaneSeats[index][jndex] = '*';
        }
    }
}

// Declare function to display the seating chart
void displaySeatingChart() {

    // Display the header
    cout << "       A B C D E F\n";

    // Loops through the rows and columns
    for (int index = 0; index < SEAT_ROWS; index++) {
        cout << "Row " << setw(2) << index + 1 << " ";
        for (int jndex = 0; jndex < SEAT_COLS; jndex++) {
            cout << airplaneSeats[index][jndex] << " ";
        }
        cout << endl;
    }
}

// Declare function to get the seat class based on ticket type
bool getSeatClass(const string& ticketClass, int& startRow, int& endRow) {

	// Initialize start and end row variables
    if (ticketClass == "economy") {
        startRow = 7;
        endRow = 12;
     
    } else if (ticketClass == "business") {
        startRow = 2;
        endRow = 6;
        
    } else if (ticketClass == "first") {
        startRow = 0;
        endRow = 1;
    }
    else {
        return false;
    }
    return true;
}

// Declare function to assign a seat based on user input
void assignSeat() {

	// Declare variables to hold user input
    string ticketClass;
    string seat;
    int row = 0;
    int col = 0;
    char seatLetter;

    // Prompt use for ticket class and seat
    cout << "Enter ticket class (economy, business, first): ";
    cin >> ticketClass;

    // Convert input to lowercase
    for (char& c : ticketClass) {
        c = tolower(c);
    }

    // Get the start and end row based on ticket class
    int startRow, endRow;

    // Check to see if the ticket class is valid
    if (!getSeatClass(ticketClass, startRow, endRow)) {
        cout << "Invalid ticket class. Please try again.\n";
        return;
	}

    // Prompt the user for a seat
	cout << "Enter desired seat (e.g., 1A): ";
    cin >> seat;

    // Check if the seat input is valid
    if (seat.length() < 2 || seat.length() > 3) {
        cout << "Invalid seat format. Please try again.\n";
		return;
    }

	// Extract the seat letter and column index
    row = stoi((seat.substr(0, seat.length() - 1))) - 1;
    seatLetter = toupper(seat.back());
    col = seatLetter - 'A';

	 // Check if the row and column are within valid ranges
     if (row < startRow || row > endRow || col < 0 || col >= SEAT_COLS) {
        cout << "Invalid seat selection. Please try again.\n";
        return;
	 }

     // Check if the seat is already taken
     if (airplaneSeats[row][col] == 'X') {
        cout << "Seat " << seat << " is already taken. Please choose another seat.\n";
        
     } else {
         // Assign the seat
         airplaneSeats[row][col] = 'X'; // Mark the seat as taken
         cout << "Seat " << seat << " assigned successfully.\n";
     }
     
}

// Declare function to display the menu options
void displayMenu() {

    // Output the menu options to the user
    cout << "\nAirplane Seating Menu:\n";
    cout << "1. Assign a seat\n";
    cout << "2. Display seating chart\n";
    cout << "3. Exit\n";
    cout << "Enter your choice: ";
}


