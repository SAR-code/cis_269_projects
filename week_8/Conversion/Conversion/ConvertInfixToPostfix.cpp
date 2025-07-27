/*
* script: ConvertInfixToPostfix.cpp
* action: This program contains a class implementation
*         for an ConvertInfixToPostfix class
* author: D.M
* date: 26JUL25
*/

#include "ConvertInfixToPostfix.h"
#include <iostream>
#include <cctype>
using namespace std;

// Constructor
ConvertInfixToPostfix::ConvertInfixToPostfix() : infix(""), postfix(""){}

// Destructor
ConvertInfixToPostfix::~ConvertInfixToPostfix() {}

// Gets the infix expression to set
void ConvertInfixToPostfix::getInfix(const string& expression) {
	infix = expression;
	postfix = "";
}

// Displays the infix
void ConvertInfixToPostfix::showInfix() const {
	cout << "Infix expression is: " << infix << endl;
}

// Displays the postfix expression
void ConvertInfixToPostfix::showPostfix() const {
    cout << "Postfix expression: " << postfix << endl;
}

// Checks if a character is an operator
bool ConvertInfixToPostfix::isOperator(char character) {
    return character == '+' || character == '-' || character == '*' || character == '/';
}

// Returns true if op1 has higher or equal precedence than op2
bool ConvertInfixToPostfix::precedence(char op1, char op2) {
    if ((op1 == '*' || op1 == '/') && (op2 == '+' || op2 == '-')) return true;
    if ((op1 == '+' || op1 == '-') && (op2 == '+' || op2 == '-')) return true;
    if ((op1 == '*' || op1 == '/') && (op2 == '*' || op2 == '/')) return true;
    return false;
}

// Converts infix expression to postfix
void ConvertInfixToPostfix::convertToPostfix() {
    std::stack<char> opStack;

    for (char sym : infix) {
        if (isspace(sym)) continue; 

        // Operand: Append to postfix
        if (isalnum(sym)) {
            postfix += sym;
            postfix += ' ';
        }
        // Left parenthesis: Push to stack
        else if (sym == '(') {
            opStack.push(sym);
        }
        // Right parenthesis: Pop until '('
        else if (sym == ')') {
            while (!opStack.empty() && opStack.top() != '(') {
                postfix += opStack.top();
                postfix += ' ';
                opStack.pop();
            }
            if (!opStack.empty() && opStack.top() == '(')
                opStack.pop(); 
        }
        // Operator: Manage precedence and push
        else if (isOperator(sym)) {
            while (!opStack.empty() && opStack.top() != '(' &&
                precedence(opStack.top(), sym)) {
                postfix += opStack.top();
                postfix += ' ';
                opStack.pop();
            }
            opStack.push(sym);
        }
    }

    // Pop remaining operators
    while (!opStack.empty()) {
        postfix += opStack.top();
        postfix += ' ';
        opStack.pop();
    }

    // Remove trailing space
    if (!postfix.empty() && postfix.back() == ' ')
        postfix.pop_back();
}
