/*
* script: LinkedListUpdated.cpp
* action: This program demonstrates and tests
*         the class OrderedLinkedList with an updated
*         insert function
* author: D.M
* date: 19JUL2025
*/

#include <iostream>
#include "OrderedLinkedList.h"
using namespace std;

int main()
{
    // Declare test lists
    OrderedLinkedList<int> list1;
    
    // Insert the requested numbers into list1
    list1.insert(2);
    list1.insert(6);
    list1.insert(7);

    // Attempt to insert duplicates
    list1.insert(2);  
    list1.insert(6);  

    // Insert more unique items
    list1.insert(5);
    list1.insert(1);

    cout << "Final List: ";
    list1.print();  

    return 0;
}


