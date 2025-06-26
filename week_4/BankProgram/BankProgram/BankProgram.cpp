/*
* script: BankProgram.cpp
* action: This program simulates common banking operations.
*         The services offered include:
*         - Checking account
*         - Savings account
*         - Certificate of deposit (CD)
* author: D.M
* date: 24JUN25
*/

#include <iostream>
#include <iomanip>
#include "CertificateOfDeposit.h"
#include "HighInterestChecking.h"
#include "HighInterestSavings.h"
#include "ServiceChargeChecking.h"
#include "NoServiceChargeChecking.h"
#include "SavingsAccount.h"
using namespace std;

int main()
{
    // Test the HighInterestChecking account class
    HighInterestChecking employeeOne("Alex", 100310, 10000.00);
    employeeOne.writeCheck(1000.00);
    employeeOne.createMonthlyStatement();
    cout << fixed << setprecision(2);
    cout << "Account balance high interest checking: " << employeeOne.getBalance() << "\n";

    // Test the HighInterestSavings account class
    HighInterestSavings employeeTwo("John", 100410, 5000.00);
    employeeTwo.withdraw(250.00);
    employeeTwo.createMonthlyStatement();
    cout << "Account balance high interest savings: " << employeeTwo.getBalance() << "\n";

    // Test the certificate of deposit (CD) accoount class
    CertificateOfDeposit employeeThree("Melissa", 200510, 50000, 7, 0.05);

    // To test whether or not a CD has reached maturity change 
    for (int index = 0; index < 7; ++index) {
        employeeThree.createMonthlyStatement();
    }
    employeeThree.withdraw(1000.00);
    cout << "Account balance after maturity: " << employeeThree.getBalance() << "\n";

    // Test savings account class
    SavingsAccount employeeFour("Sam", 100810, 2500);
    employeeFour.deposit(2500);
    employeeFour.createMonthlyStatement();
    cout << "Account balance savings: " << employeeFour.getBalance() << "\n";

    // Test Service Charge Checking
    ServiceChargeChecking employeeFive("Donna", 500810, 15000);
    employeeFive.withdraw(5000);
    cout << "\nService Charge Checking : " << employeeFive.getBalance() << "\n";
    cout << employeeFive.getAccountNumber() << "\n" << employeeFive.getName() << "\n";

    // Test No Service Charge Checking
    NoServiceChargeChecking employeeSix("Max", 276110, 120000);
    cout << "\nMax ";
    employeeSix.deposit(50000);
    cout << "\nNo Service Charge Checking : " << employeeSix.getBalance() << "\n";
    cout << employeeSix.getAccountNumber() << "\n" << employeeSix.getName() << "\n";





    
    return 0;
}


