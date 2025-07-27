/*
* script: ConvertInfixToPostfix.h
* action: This program contains a class definition
*         for an ConvertInfixToPostfix class
* author: D.M
* date: 26JUL25
*/


#ifndef CONVERTINFIXTOPOSTFIX_H
#define CONVERTINFIXTOPOSTFIX_H

#include <string>
#include <stack>

class ConvertInfixToPostfix {

public:

	// Constructor
	ConvertInfixToPostfix();

	// Destructor
	~ConvertInfixToPostfix();

	// Methods to get and display the infix expression
	void getInfix(const std::string& expression);

	void showInfix() const;

	// Methods to convert and display the postfix expression
	void convertToPostfix();

	void showPostfix() const;

private:

	// Declare private data members
	std::string infix;
	std::string postfix;

	// Method to determine the operator precedence
	bool precedence(char op1, char op2);

	// Method to check to see if a character is an operator
	bool isOperator(char character);
};

#endif