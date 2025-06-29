/*
* script: HospitalBilling.cpp
* action: This program demonstrates various classes and
*         their usage in a hospital billing system.
* author: D.M
* date: 28JUN25
*/

#include <iostream>
#include "patientType.h"
#include "billType.h"
#include "doctorType.h"
#include "dateType.h"

// Function Prototypes
void displayCompleteInfo(const PatientType& patient, const BillType& bill);

int main()
{
    // Instantiate the class objects for testing
    DoctorType dermatologist("Belmeur", "Dove", "Dermatology");
    DateType dateOfBirth(3, 15, 1985);
	DateType admissionDate(6, 1, 2025);
	DateType dischargeDate(6, 2, 2025);

    // Patient type objects
    PatientType patientOne("Sal", "L'Oreal", 125, 40);
	patientOne.setPatientInfo(125, 40, dateOfBirth, dermatologist, admissionDate, dischargeDate);

	// Bill type object
    BillType bill(125, 75.29, 340.71, 500.00);

    
	// Display complete information
    std::cout << "Patient Information:\n";
    patientOne.displayPatientInfo();

    std::cout << "\nBill Information:\n";
    bill.displayBill();
    return 0;
}

// Function to display complete information
void displayCompleteInfo(const PatientType& patient, const BillType& bill)
{
    std::cout << "Patient Information:\n";
    patient.displayPatientInfo();
    
    std::cout << "\nBill Information:\n";
    bill.displayBill();
    
    
}


