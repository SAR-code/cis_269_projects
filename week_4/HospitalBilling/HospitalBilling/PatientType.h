/*
* script: PatientType.h
* action: This program contains a class definition for the PatientType class.
* author: D.M
* date: 28JUN25
*/

#ifndef PATIENTTYPE_H
#define PATIENTTYPE_H

#include "PersonType.h"
#include "DoctorType.h"
#include "DateType.h"

class PatientType : public PersonType {
public:

	// Default Constructor
	PatientType(const std::string& firstName = "", const std::string& lastName = "", int id = 0, int age = 0);

	// Function to set patient info
	void setPatientInfo(int id, int age, const DateType& dob, const DoctorType& physician, 
		                const DateType& admitDate,const DateType& dischargeDate);

	// Function to display patient info
	void displayPatientInfo() const;

	// Function to get patient ID
	int getPatientID() const;

private:

	// Declare private data members
	int patientID = 0;
	int age = 0;
	DateType dateOfBirth;
	DoctorType assignedPhysician;
	DateType admitDate;
	DateType dischargeDate;
};

#endif
