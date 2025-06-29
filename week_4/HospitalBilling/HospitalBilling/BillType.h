/*
* script: BillType.h
* action: This program contains a class definition for the BillType class.
* author: D.M
* date: 28JUN25
*/

#ifndef BILLTYPE_H
#define BILLTYPE_H

class BillType {
public:
	// Default Constructor
	BillType(int id, double pharma, double doctor, double room);

	// Function to set charges and patient ID
	void setCharges(double pharma, double doctor, double room);
	void setPatientID(int id);

	// Function to get the total bill amount
	double getTotalBill() const;

	// Function to display the bill details
	void displayBill() const;

private:

	// Declare private member variables
	int patientID = 0;
	double pharmacyCharges = 0.0;
	double doctorCharges = 0.0;
	double roomCharges = 0.0;

};

#endif
