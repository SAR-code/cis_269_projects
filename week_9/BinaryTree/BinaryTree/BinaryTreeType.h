/*
* script: BinaryTreeType.h
* action: This program contains the definition
*         of the BinaryTreeType file.
* author: D.M
* date: 03AUG2025
*/


#ifndef BINARY_TREE_TYPE_H
#define BINARY_TREE_TYPE_H

// Define the structure for a tree node
struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;
};


class binaryTreeType {
public:
    // Constructor
    binaryTreeType();

    // Destructor
    ~binaryTreeType();                

    // Declare public methods for node insert and count
    void insert(int value);           
    int nodeCount();  

private:
    // Declare required private members

    TreeNode* root;                   

    void destroy(TreeNode* node);     
    void insertTreeNode(TreeNode*& node, int value);  
    int countNodes(TreeNode* node);   
};

#endif
