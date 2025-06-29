/*
* script: PatientType.cpp
* action: This program contains a class implementation for the PatientType class.
* author: D.M
* date: 28JUN25
*/

#include "PatientType.h"
#include <iostream>

// Default constructor
PatientType::PatientType(const std::string& firsName, const std::string& lastName, int id,
	int age) : PersonType(firsName, lastName), patientID(id), age(age) {
}

// Function to set patient info
void PatientType::setPatientInfo(int id, int age, const DateType& birth,
	                             const DoctorType& physician, const DateType& admitDate,
	                             const DateType& dischargeDate){

	// Assigning the values to the variables
	patientID = id;
	this->age = age;
	dateOfBirth = birth;
	assignedPhysician = physician;
	this->admitDate = admitDate;
	this->dischargeDate = dischargeDate;


}

// Function to output patient info
void PatientType::displayPatientInfo() const {

	// Displaying the patient information
	std::cout << "Patient Name: " << printFullName() << "\n"
		<< "Patient ID: " << patientID << "\n"
		<< "Age: " << age << "\n"
		<< "Birth ";
	dateOfBirth.printDate();
	std::cout << "\nAssigned Physician: " << assignedPhysician.printFullName() << " ["
		       << assignedPhysician.getSpecialty() << "]\n"
		       << "Admission ";
	admitDate.printDate();
	std::cout << "Discharge ";
	dischargeDate.printDate();
	std::cout << "\n";

}

// Functiont to get patient ID
int PatientType::getPatientID() const {
	return patientID;
}
