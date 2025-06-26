/*
* script: CheckingAccount.cpp
* action: This program contains a class implementation for a checking account.
* author: D.M
* date: 24JUN25
*/

#include "CheckingAccount.h"
#include <iostream>

CheckingAccount::CheckingAccount(const std::string& name, int accountNum, double balance)
	: BankAccount(name, accountNum, balance) {
}


