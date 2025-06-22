/*
* script: FederalTax.cpp
* action: This program calculates the federal tax based on income
*         and filing status
* author: D.M
* date: 21JUN25
*/

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

// Declare constants for standard exemptions
double const SINGLE_STANDARD_EXEMPTION = 4000.00;
double const MARRIED_STANDARD_EXEMPTION = 7000.00;
double const PERSONAL_EXEMPTION = 1500.00;

// Declare a structure to store tax data
struct IndividualTaxData {
    string maritalStatus;
    int numOfDependents;
    double grossIncome;
    double pensionPercentage;
};

// Function prototypes
void getData(IndividualTaxData& taxPayer);
double taxAmount(const IndividualTaxData& taxPayer);
void displayResults(const IndividualTaxData& taxPayer, double taxDue);
string toLower(const string& str);


int main()
{
	// Declare an instance of IndividualTaxData & required variables
	IndividualTaxData taxPayer;
    double taxDue = 0.0;

    // Invoke the function to get data from the user
	getData(taxPayer);

    // Calculate the tax amount due
	taxDue = taxAmount(taxPayer);

    // Display the output
	displayResults(taxPayer, taxDue);
    return 0;
}

// Function to get data from the user
void getData(IndividualTaxData& taxPayer)
{
    // Prompt the user for marital status
    while (true) {
        cout << "Enter marital status (single or married): ";
        cin >> taxPayer.maritalStatus;

		string maritalStatusLower = toLower(taxPayer.maritalStatus);

        // Validate the marital status input
        if (maritalStatusLower == "single" || maritalStatusLower == "married") {
            taxPayer.maritalStatus = maritalStatusLower; 
            break; 
        }
        else {
            cout << "Invalid marital status. Please enter 'single' or 'married'." << endl;
		}
    }

    // If married, prompt for number of dependents under 14
    if (taxPayer.maritalStatus == "married") {
        cout << "Enter number of dependents under 14: ";
        cin >> taxPayer.numOfDependents;
    }
    else {
        taxPayer.numOfDependents = 0;
    }

    // Prompt for gross income
    cout << "Enter gross income: $";
    cin >> taxPayer.grossIncome;

    // Prompt for pension percentage
    cout << "Enter pension percentage(0-6%): ";
    cin >> taxPayer.pensionPercentage;

    // Validate the pension percentage entered
    if (taxPayer.pensionPercentage < 0 || taxPayer.pensionPercentage > 6) {
        cout << "Invalid pension percentage. Please enter a value between 0 and 6." << endl;
        exit(1); // Exit the program if invalid input
	}
}

// Function to calculate the tax amount due
double taxAmount(const IndividualTaxData& taxPayer)
{
    // Declare variables for tax calculations
    // Determine the standard exemption based on marital status
	double standardExemption = (taxPayer.maritalStatus == "married") ? MARRIED_STANDARD_EXEMPTION : SINGLE_STANDARD_EXEMPTION;
	int familySize = (taxPayer.maritalStatus == "married") ? 2 : 1; // Assume 2 for married, 1 for single
    familySize += taxPayer.numOfDependents;

    double personalExemption = familySize * PERSONAL_EXEMPTION;

    // Calculate pension contribution
	double pensionContribution = (taxPayer.pensionPercentage / 100.0) * taxPayer.grossIncome;

    // Calculate taxable income
	double taxableIncome = taxPayer.grossIncome - (standardExemption + personalExemption + pensionContribution);

    if (taxableIncome < 0) {
        taxableIncome = 0; 
    }

	// Calculate tax due based on the tax brackets
    double tax = 0.0;
    if (taxableIncome <= 15000) {
        tax = 0.15 * taxableIncome;
    }
    else if (taxableIncome <= 40000) {
        tax = 2250 + 0.25 * (taxableIncome - 15000);
    }
    else {
		tax = 8460 + 0.35 * (taxableIncome - 40000);
    }

    return tax;
}

// Function to display the results
void displayResults(const IndividualTaxData& taxPayer, double taxDue)
{
    // Display the results in a formatted manner
    cout << fixed << setprecision(2);
    cout << "\nMarital Status: " << taxPayer.maritalStatus << endl;
    cout << "Number of Dependents: " << taxPayer.numOfDependents << endl;
    cout << "Taxable Income: $" << taxPayer.grossIncome << endl;
    cout << "Pension Contribution: $" << (taxPayer.pensionPercentage / 100.0) * taxPayer.grossIncome << endl;
    cout << "Tax Due: $" << taxDue << endl;
}

// Helper function to convert string to lowercase
string toLower(const string& str)
{
	// Convert the input string to lowercase
    string lowerStr = str;
    for (char& c : lowerStr) {
        c = tolower(c);
    }
    return lowerStr;
}


