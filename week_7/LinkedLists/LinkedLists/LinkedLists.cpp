/*
* script: LinkedLists.cpp
* action: This program demonstrates and tests
*         the class OrderedLinkedList
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
    OrderedLinkedList<int> list2;
    OrderedLinkedList<int> newList;

    // Insert the requested numbers into list1
    list1.insert(2);
    list1.insert(6);
    list1.insert(7);

    // Insert the requested numbers into list2
    list2.insert(3);
    list2.insert(5);
    list2.insert(8);

    // Display list1
    cout << "List 1: ";
    list1.print();

    // Display list2
    cout << "List 2: ";
    list2.print();

    // Merge into newList
    newList.mergeLists(list1, list2);

    // Display the merged list
    cout << "Merged List: ";
    newList.print();

    return 0;
}


