/*
* script: Conversion.cpp
* action: This program converts an infix expression into an
*         equivalent postfix expression
* author: D.M
* date: 26JUL2025
*/

#include "ConvertInfixToPostfix.h"
#include <iostream>
using namespace std;

int main()
{
    // Test expressions from the problem
    string testExpressions[] = {
        "A + B - C;",
        "(A + B) * C;",
        "(A + B) * (C - D);",
        "A + ((B + C) * (E - F) - G) / (H - I);",
        "A + B * (C + D) - E / F * G + H;"
    };

    ConvertInfixToPostfix converter;

    for (const string& express : testExpressions) {
        cout << "----------------------------------------\n";
        converter.getInfix(express);
        converter.convertToPostfix();
        converter.showInfix();
        converter.showPostfix();
    }

    return 0;
}


