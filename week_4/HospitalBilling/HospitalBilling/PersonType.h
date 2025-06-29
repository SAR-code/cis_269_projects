/*
* script: PersonType.h
* action: This program contains a class definition for a person type.
* author: D.M
* date: 28JUN25
*/

#ifndef PERSONTYPE_H
#define PERSONTYPE_H

#include <string>


class PersonType {
public:

	// Default constructor
	PersonType(std::string first = "", std::string last = "");

	// Member function to set the full name
	void setName(std::string first, std::string last);

	// Methods to get first and last name
	std::string getFirstName() const;
	std::string getLastName() const;

	// Output the full name
	std::string printFullName() const;

private:

	// Declare private data members
	std::string firstName;
	std::string lastName;
};

#endif