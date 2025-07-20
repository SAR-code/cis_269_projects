/*
* script: OrderedLinkedList.h
* action: This program contains a class definition
*         for an OrderedLinkedList class
* author: D.M
* date: 19JUL25
*/

#ifndef ORDERED_LINKED_LIST_H
#define ORDERED_LINKED_LIST_H

#include <iostream>

// Declare a node struct
template <typename Type>
struct Node {
    Type info;
    Node<Type>* link;
};

template <typename Type>
class OrderedLinkedList
{
public:

    // Constructor
    OrderedLinkedList();

    // Destructor
    ~OrderedLinkedList();

    // Declare required class methods to manipulate the list
    void insert(const Type& newItem);
    void print() const;
    void destroyList();

    // Code from problem page
    void mergeLists(OrderedLinkedList<Type>& list1, OrderedLinkedList<Type>& list2);
    // This function creates a new list by merging the
    // elements of list1 and list2.
    // Postcondition: first points to the merged list.
    //                list1 and list2 are empty.

private:

    // Declare required private data members
    Node<Type>* first;
    Node<Type>* last;
    int count;
};
#endif
