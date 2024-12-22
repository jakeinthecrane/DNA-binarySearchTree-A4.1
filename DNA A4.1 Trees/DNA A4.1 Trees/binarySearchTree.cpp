#include "binarySearchTree.h"
#include <iostream>
using namespace std;



// Constructor: we initialize the root as nullptr for an empty tree here
template <typename T>
BinarySearchTree<T>::BinarySearchTree() : root(nullptr)
{}

// Insert function: starts the recursive insertion at the root.
template <typename T>
void BinarySearchTree<T>::insert(const T& value)
{
    root = insertHelper(root, value);
}

// Recursively finds the correct position for the new value.
// Throws an exception if the value already exists 
template <typename T>
typename BinarySearchTree<T>::Node* BinarySearchTree<T>::insertHelper(Node* node, const T& value)
{
    if (!node)
    {
        return new Node(value);  // Create a new Node with 'value'
    }
    if (value < node->value) // 
    {
        node->left = insertHelper(node->left, value); // recursively traverses the tree to insert the value where instructed, assigns the value then propagates back up to update the parent node

    }
    else if (value > node->value)
    {
        node->right = insertHelper(node->right, value); 
    }
    else
    {
       
        throw runtime_error("Duplicate value insertion attempt.");
    }
    return node; // base case, the function unwinds from here and propagates back up the tree to update the root node
}

// Remove function: starts recursive deletion from the root.
template <typename T>
void BinarySearchTree<T>::remove(const T& value)
{
    root = deleteHelper(root, value);
}

// Recursively locates and removes the specified value, handling:
// no children, one child, or two children.
template <typename T>
typename BinarySearchTree<T>::Node* BinarySearchTree<T>::deleteHelper(Node* node, const T& value)
{
    if (!node)
    {
        return nullptr;
    }
    if (value < node->value)
    {
        node->left = deleteHelper(node->left, value);
    }
    else if (value > node->value)
    {
        node->right = deleteHelper(node->right, value);
    }
    else {
        // Node to delete found
        if (!node->left && !node->right) 
        {
            // Case: no children
            delete node;
            return nullptr;
        }
        else if (!node->left)
        {
            // Case: one child (right)
            Node* temp = node->right;
            delete node;
            return temp;
        }
        else if (!node->right)
        {
            // Case: one child (left)
            Node* temp = node->left;
            delete node;
            return temp;
        }
        else 
        {
            /* Case: two children
               Find the in-order successor (min in right subtree)
               Replace current node's value with the successor's
               Then delete the successor from the right subtree
            */
            Node* successor = findMin(node->right);
            node->value = successor->value;
            node->right = deleteHelper(node->right, successor->value);
        }
    }
    return node;
}

// findMin: go left until no more left children.
template <typename T>
typename BinarySearchTree<T>::Node* BinarySearchTree<T>::findMin(Node* node) const
{
    while (node && node->left) // while loop if there is a node available and there is a node to the left then the function in the block executes..
    {
        node = node->left;
    }
    return node;
}

// findMax: go right until no more right children.
template <typename T>
typename BinarySearchTree<T>::Node* BinarySearchTree<T>::findMax(Node* node) const
{
    while (node && node->right)
    {
        node = node->right; // the function iterates to the right until null so that it car return the node with the maximum value...
        }
    return node;
}

// maximum: returns the maximum value in the BST, throws if empty.
template <typename T>
T BinarySearchTree<T>::maximum() const
{
    if (!root)
    {
        throw runtime_error("Tree is empty. Cannot find maximum.");
    }
    Node* maxNode = findMax(root);
    return maxNode->value;
}

// inOrderTraversal: returns a sorted vector of values in ascending order.
template <typename T>
std::vector<T> BinarySearchTree<T>::inOrderTraversal() const
{
    std::vector<T> result;
    inOrderTraversalHelper(root, result);
    return result;
}

// inOrderTraversalHelper: visit left subtree, node, then right subtree.
template <typename T>
void BinarySearchTree<T>::inOrderTraversalHelper(Node* node, std::vector<T>& result) const
{
    if (node)
    {
        inOrderTraversalHelper(node->left, result); // recursion traversal of the tree to the left searching for the result. 
        result.push_back(node->value); // proceses the current node's value is stored in the result vector 
        inOrderTraversalHelper(node->right, result); // traverses to the right searching for the result value.. the function assists with the unwinding of the function....rather than the compiler doing it by default.  
    }
}

// isEmpty: returns true if root is nullptr.
template <typename T>
bool BinarySearchTree<T>::isEmpty() const
{
    return (root == nullptr);
}

/*
   EXPLICIT INSTANTIATION for 'int'.
   Required because we separated the template class into a .cpp file.
   This tells the compiler to generate the BST code for type int.
*/
template class BinarySearchTree<int>;
