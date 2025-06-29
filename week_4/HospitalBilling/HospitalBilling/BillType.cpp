/*
* script: BillType.cpp
* action: This program contains a class implementation for the BillType class.
* author: D.M
* date: 28JUN25
*/

#include "BillType.h"
#include <iostream>
#include <iomanip>

// Default constructor
BillType::BillType(int id, double pharma, double doctor, double room)
    : patientID(id), pharmacyCharges(pharma), doctorCharges(doctor), roomCharges(room) {
}

// Function to set the charges
void BillType::setCharges(double pharma, double doctor, double room) {

    // Assign the charges to the member variables
	pharmacyCharges = pharma;
	doctorCharges = doctor;
	roomCharges = room;
}

// Function to set the patient ID
void BillType::setPatientID(int id) {

	// Assign the patient ID to the member variable
	patientID = id;
}

// Function to get the total bill amount
double BillType::getTotalBill() const {

	// Calculate the total bill amount
	double totalBill = pharmacyCharges + doctorCharges + roomCharges;
	return totalBill;
}

// Function to print the bill details
void BillType::displayBill() const {

	// Output the bill details
	std::cout << "Patient ID: " << patientID << "\n"
		<< "Pharmacy Charges: $" << std::fixed << std::setprecision(2) << pharmacyCharges << "\n"
		<< "Doctor Fee: $" << doctorCharges << "\n"
		<< "Room Fee: $" << roomCharges << "\n"
		<< "Total Bill: $" << getTotalBill() << std::endl;
}