/*
* script: DateType.h
* action: This program contains a class definition for the date.
* author: D.M
* date: 28JUN25
*/

#ifndef DATETYPE_H
#define DATETYPE_H

class DateType {

public:
	// Default constructor
	DateType() : day(1), month(1), year(1900) {}

	// Parameterized constructor
	DateType(int day, int month, int year);

	// Member function to set the date
	void setDate(int day, int month, int year);

	// Member function to print the date
	void printDate() const;

private:

	// Declare private member variables
	int day = 1;
	int month = 1;
	int year = 1900;
};


#endif
