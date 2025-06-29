/*
* script: DoctorType.h
* action: This program contains a class definition for the DoctorType class.
* author: D.M
* date: 28JUN25
*/

#ifndef DOCTORTYPE_H
#define DOCTORTYPE_H

#include "personType.h"
#include <string>

class DoctorType : public PersonType {
public:

	// Default constructor
	DoctorType(const std::string& firstName = "", const std::string& lastName = "",
		const std::string& spec = "");

	// Function to set the specialty
	void setSpecialty(const std::string& spec);

	// Function to get the specialty
	std::string getSpecialty() const;

private:

	// Declare privare data members
	std::string specialty;
};

#endif
