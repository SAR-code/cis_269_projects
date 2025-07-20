/*
* script: OrderedLinkedList.cpp
* action: This program contains a class implementation
*         for an OrderedLinkedList class
* author: D.M
* date: 19JUL25
*/

#include "OrderedLinkedList.h"
using namespace std;

// Constructor
template <typename Type>
OrderedLinkedList<Type>::OrderedLinkedList() {
    first = nullptr;
    last = nullptr;
    count = 0;
}

// Destructor
template <typename Type>
OrderedLinkedList<Type>::~OrderedLinkedList() {
    destroyList();
}

// Destroys all the nodes
template <typename Type>
void OrderedLinkedList<Type>::destroyList() {
    Node<Type>* temp;
    while (first != nullptr) {
        temp = first;
        first = first->link;
        delete temp;
    }
    last = nullptr;
    count = 0;
}

// Insert in sorted order without duplicates
template <typename Type>
void OrderedLinkedList<Type>::insert(const Type& newItem) {
    Node<Type>* newNode = new Node<Type>{ newItem, nullptr };

    if (first == nullptr) {
        // Empty list
        first = last = newNode;
        count++;
        return;
    }

    Node<Type>* current = first;
    Node<Type>* trail = nullptr;

    // Traverse to find position or duplicate
    while (current != nullptr && current->info < newItem) {
        trail = current;
        current = current->link;
    }

    if (current != nullptr && current->info == newItem) {
        // Duplicate found
        cout << "Error: Item '" << newItem << "' already exists in the list.\n";
        delete newNode;
        return;
    }

    if (trail == nullptr) {
        // Insert at beginning
        newNode->link = first;
        first = newNode;
    }
    else {
        // Insert in middle or end
        trail->link = newNode;
        newNode->link = current;
    }

    if (current == nullptr)
        last = newNode;

    count++;
}

// Print the list
template <typename Type>
void OrderedLinkedList<Type>::print() const {
    Node<Type>* current = first;
    while (current != nullptr) {
        cout << current->info << " ";
        current = current->link;
    }
    cout << endl;
}


// Merge two ordered lists into this list
template <typename Type>
void OrderedLinkedList<Type>::mergeLists(OrderedLinkedList<Type>& list1, OrderedLinkedList<Type>& list2) {
    destroyList(); // Start with an empty list

    Node<Type>* first1 = list1.first;
    Node<Type>* first2 = list2.first;

    Node<Type>* lastMerged = nullptr;

    // Traverse both lists and insert smaller node
    while (first1 != nullptr && first2 != nullptr) {
        Node<Type>* newNode = new Node<Type>;
        if (first1->info < first2->info) {
            newNode->info = first1->info;
            first1 = first1->link;
        }
        else {
            newNode->info = first2->info;
            first2 = first2->link;
        }
        newNode->link = nullptr;

        if (first == nullptr) {
            first = last = newNode;
        }
        else {
            last->link = newNode;
            last = newNode;
        }
    }

    // Copy remaining elements
    Node<Type>* remaining = (first1 != nullptr) ? first1 : first2;
    while (remaining != nullptr) {
        Node<Type>* newNode = new Node<Type>{ remaining->info, nullptr };
        if (first == nullptr) {
            first = last = newNode;
        }
        else {
            last->link = newNode;
            last = newNode;
        }
        remaining = remaining->link;
    }

    // Update count
    Node<Type>* temp = first;
    count = 0;
    while (temp != nullptr) {
        count++;
        temp = temp->link;
    }

    // Empty list1 and list2
    list1.destroyList();
    list2.destroyList();
}

// Instantiated template for int
template class OrderedLinkedList<int>;