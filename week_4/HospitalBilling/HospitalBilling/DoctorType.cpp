/*
* script: DoctorType.cpp
* action: This program contains a class implementation for the DoctorType class.
* author: D.M
* date: 28JUN25
*/

#include "DoctorType.h"

// Default constructor
DoctorType::DoctorType(const std::string& firstName, const std::string& lastName,
	const std::string& spec) : PersonType(firstName, lastName), specialty(spec) {
}

// Function to set the specialty of the doctor
void DoctorType::setSpecialty(const std::string& spec) {

	// Assing the specialty to the member
	specialty = spec;
}

// Function to get the specialty of the doctor
std::string DoctorType::getSpecialty() const {
	// Return the specialty
	return specialty;
}