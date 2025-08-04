/*
* script: BinaryTreeType.cpp
* action: This program contains the implementation
*         of the BinaryTreeType file.
* author: D.M
* date: 03AUG2025
*/

#include "binaryTreeType.h"
#include <iostream>

using namespace std;

// Constructor
binaryTreeType::binaryTreeType() {
    root = nullptr;
}

// Destructor
binaryTreeType::~binaryTreeType() {
    destroy(root);
}

// Method function to destroy the tree nodes
void binaryTreeType::destroy(TreeNode* node) {
    if (node != nullptr) {
        destroy(node->left);
        destroy(node->right);
        delete node;
    }
}

// Method function to insert a value into the tree
void binaryTreeType::insert(int value) {
    insertTreeNode(root, value);
}

// Method function to count the number of nodes in the tree
int binaryTreeType::nodeCount() {
    return countNodes(root);
}

// Member function to insert a new node in the tree
void binaryTreeType::insertTreeNode(TreeNode*& node, int value) {
    if (node == nullptr) {
        // Create new node if current position is empty
        node = new TreeNode{ value, nullptr, nullptr };
    }
    else if (value < node->data) {
        // Recursion on left subtree
        insertTreeNode(node->left, value);
    }
    else {
        // Recursion on right subtree
        insertTreeNode(node->right, value);
    }
}

// Member function to count the number of nodes in the tree
int binaryTreeType::countNodes(TreeNode* node) {
    if (node == nullptr)
        // Return 0 if base case
        return 0;
    else
        // Count current node + nodes in left + nodes in right
        return 1 + countNodes(node->left) + countNodes(node->right);
}


// Part two of the assignment
// 
// Method function to count leaf nodes
int binaryTreeType::leavesCount() {
    return countLeaves(root);
}

// Method function to count only leaf nodes
int binaryTreeType::countLeaves(TreeNode* node) {
    if (node == nullptr)
        return 0; 
    if (node->left == nullptr && node->right == nullptr)
        return 1; 

    // Sum of leaf nodes in left and right subtrees
    return countLeaves(node->left) + countLeaves(node->right);
}