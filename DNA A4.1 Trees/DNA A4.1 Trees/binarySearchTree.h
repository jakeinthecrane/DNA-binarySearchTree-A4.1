#pragma once

#include <vector>     // For returning traversal data in a vector
#include <stdexcept>  // For throwing runtime errors when necessary

/*
 
  Templated Binary Search Tree class definition....BST template.
 
  This header contains:
   1) A templated BinarySearchTree class
   2) Forward declarations of its private and public member functions
 */

template <typename T>
class BinarySearchTree
{
private:
    /*
      Node structure representing each element (T).
      Contains pointers to left and right child nodes.
     */
    struct Node 
    {
        T value;      // The data value for container ID
        Node* left;   // Pointer to the left child
        Node* right;  // Pointer to the right child

        // Constructor initializes left and right to nullptr
        Node(const T& val) : value(val), left(nullptr), right(nullptr)
        {}
    };

    Node* root;  // Pointer to the root of the BST

    /*
      Helper function to recursively insert a value into the BST.
      Pointer to the current node in the BST.
      The value to insert....
     */
    Node* insertHelper(Node* node, const T& value);


    // Helper function to recursively delete a value from the BST.        
       Node* deleteHelper(Node* node, const T& value);


    // brief Utility function to find the node with the minimum value
       Node* findMin(Node* node) const;

    // Utility function to find the node with the maximum value    
       Node* findMax(Node* node) const;

    //  Helper function for in-order traversal.
       void inOrderTraversalHelper(Node* node, std::vector<T>& result) const;

public:
     // Constructor sets root to nullptr, making an empty BST.     
    BinarySearchTree();

    //  Inserts a new value into the BST, maintaining BST properties.
       void insert(const T& value);

    //  Removes a value from the BST, if it exists.
        void remove(const T& value);

    // Finds the maximum value stored in the BST.
         T maximum() const;

    // Performs an in-order traversal and returns a sorted vector of all values.
       std::vector<T> inOrderTraversal() const;

    // Checks if the BST is empty (root == nullptr).
       bool isEmpty() const;
};
