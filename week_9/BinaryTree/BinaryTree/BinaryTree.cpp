/*
* script: BinaryTree.cpp
* action: This program writes the definition of
*         of the function nodeCount() that returns
*         the number of nodes in a binary tree.
* author: D.M
* date: 03AUG2025
*/

#include <iostream>
#include "binaryTreeType.h"

using namespace std;

int main() {
    binaryTreeType tree;

    // Insert values into the tree
    tree.insert(10);
    tree.insert(5);
    tree.insert(15);
    tree.insert(3);
    tree.insert(7);
    tree.insert(12);
    tree.insert(18);

    // Output the number of nodes
    cout << "Total number of nodes in the tree: " << tree.nodeCount() << endl;

    return 0;
}


