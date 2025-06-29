/*
* script: PersonType.cpp
* action: This program contains a class implementation for a person type.
* author: D.M
* date: 28JUN25
*/

#include "PersonType.h"
#include <iostream>

// Default constructor
PersonType::PersonType(std::string first, std::string last)
	: firstName(first), lastName(last){ }

// Member function to set the name
void PersonType::setName(std::string first, std::string last)
{
	// Assigning the first and last name
	firstName = first;
	lastName = last;
}

// Member function to get the first name
std::string PersonType::getFirstName() const
{
	return firstName;
}

// Member function to get the last name
std::string PersonType::getLastName() const
{
	return lastName;
}

// Member function to print the full name
std::string PersonType::printFullName() const
{
	return firstName + " " + lastName;
}






