/*
* script: ListType.h
* action: This program contains a base class to manage
          a list of items.
* author: D.M
* date: 01JUL25
*/

#ifndef LISTTYPE_H
#define LISTTYPE_H

template <class T>
class ListType {
public: 

    // Constructor specific for initializing a list
    ListType(int size = 100);

    // Destructor
    ~ListType();

    // Methods to get the length of the list
    int getLength() const;

    // Method to insert an item into the list
    void insertItem(const T& item);

    // Access the elements of the list by index
    T& operator[](int index);
    const T& operator[](int index) const;

protected:

    // Declare private data members
    T* list;      // Pointer to help manage the list
    int length;
    int maxSize;

};

// Template class implementation
template <class T>
ListType<T>::ListType(int size) {

     // Initialize the list with a specified size
	maxSize = size;
    length = 0;
    list = new T[maxSize];
}

// Destructor to clean up the allocated memory
template <class T>
ListType<T>::~ListType() {
    delete[] list;
}

// Template method to get the length
template <class T>
int ListType<T>::getLength() const {
    return length;
}

// Template method to insert an item into the list
template <class T>
void ListType<T>::insertItem(const T& item) {

    // Checks the max size of the list
    if (length < maxSize) {
        list[length++] = item;
    }
    
}

// Template methods to access elements by index
template <class T>
T& ListType<T>::operator[](int index) {

    // Check for valid index
    if (index < 0 || index >= length) {
        std::cout << "Index out of bounds." << std::endl;
        exit(1); 
	}

    return list[index];
}


template <class T>
const T& ListType<T>::operator[](int index) const {

    // Check for valid index
    if (index < 0 || index >= length) {
        std::cout << "Index out of bounds." << std::endl;
        exit(1); // Exit if index is invalid
    }
	return list[index];
}

#endif