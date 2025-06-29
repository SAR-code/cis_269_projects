/*
* script: BankAccount.cpp
* action: This program contains a class implementation for a bank account.
* author: D.M
* date: 29JUN25
*/

#include "BankAccount.h"
#include <iostream>
#include <iomanip>
using namespace std;

// Constructors
BankAccount::BankAccount() : accountNumber(0), balance(0.0) {}

BankAccount::BankAccount(int accountNum, double balance)
    : accountNumber(accountNum), balance(balance) {
}

// Method to set the account number
void BankAccount::setAccountNumber(int accountNum) {

    // Assign the account number
    accountNumber = accountNum;
}

// Method to get the account number
int BankAccount::getAccountNumber() const {

    // Return the account number
    return accountNumber;
}

// Method to get the balance
double BankAccount::getBalance() const {

    // Return the balance
    return balance;
}

// Method to deposit a specified amount
void BankAccount::deposit(double amount) {

    // Checks to see if the amount is greater than 0
    if (amount > 0) {
        balance += amount;

    }
    else {
        cout << "Deposit amount must be positive." << endl;
    }
}

// Method to withdraw a specified amount
void BankAccount::withdraw(double amount) {

    // Checks to see if the amount is greater than 0 or matches the balance amount
    if (amount > 0 && amount <= balance) {
        balance -= amount;
    }
    else {
        cout << "Withdrawl amount must be positive and less than or equal to the balance." << endl;
    }
}

// Method to display the account information
void BankAccount::outputDetails() const {

    //Display the account number and balance
    cout << fixed << setprecision(2);
    cout << "Account Number: " << accountNumber << endl;
    cout << "Balance: $" << balance << endl;

}
