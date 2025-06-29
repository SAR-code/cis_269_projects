/*
* script: DateType.cpp
* action: This program contains a class implementation for the date.
* author: D.M
* date: 28JUN25
*/

#include "DateType.h"
#include <iostream>

// Default constructor
DateType::DateType(int day, int month, int year)
    : day(day), month(month), year(year) { }


// Function to display the date
void DateType::setDate(int day, int month, int year)
{
    // Assigning the values to the class members
    this->day = day;
    this->month = month;
    this->year = year;
}

// Function to display the date
void DateType::printDate() const
{
    // Displays the date in the format MM/DD/YYYY
    std::cout << "Date: " << month << "/" << day << "/" << year << std::endl;
}


