/*
* script: SpecialPay.cpp
* action: This program reads data from the specified file and 
  stores the output in the file Ch3_Ex5Output.dat.
* author: D.M
* date: 07JUN25
*/

#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <string>


using namespace std;

// Function Prototypes
void handleUpdatedFile();

int main()
{
    
	// Invoke the funtion to handle file processing
    handleUpdatedFile();

    return 0;
}

void handleUpdatedFile()
{
    // Declare file streams
    ifstream inputFile("Ch3_Ex5Data.txt");
    ofstream outputFile("Ch3_Ex5Data.dat");

    // Check if the input file is open
    if (!inputFile || !outputFile)
    {
        cout << "Error opening file.\n";
        exit(1);
    }

	// Declare local variables to handle file processing
    string fName, lName;
    double salary, percent;

	while (inputFile >> lName >> fName >> salary >> percent){

		// Calculate the updated salary based on the percentage
		double updatedSalary = salary * (1 + (percent / 100.0));
   

        // Output the formatted data to the output file
		outputFile << fixed << setprecision(2);
		outputFile << fName << " " << lName << " " << updatedSalary << endl;
    }

	// Close the file streams
    inputFile.close();
    outputFile.close();
}




