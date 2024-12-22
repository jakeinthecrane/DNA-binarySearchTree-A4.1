#include <iostream>             // For input-output operations
#include "binarySearchTree.h"   // Include our BST header

using namespace std;

/*
    We are using a real-world example using shipping containers as our values for this assignment.  
   1. Inserts an unsorted array of container IDs (with intentional duplicates).
   2. Demonstrates edge cases:
      - Inserting duplicates
      - Removal from an empty BST
      - Removing a leaf node
      - Removing a node with one child
      - Removing a node with two children
   3. Prints in-order traversals to verify BST structure after each operation.
   4. Finds the maximum container ID (if the tree is not empty).
 */

int main()
{
    // Create a Binary Search Tree of type int
    BinarySearchTree<int> containerBST;

    // Unsorted array simulating incoming container IDs at the port.
    // Repeated IDs to test duplicate handling.
    vector<int> containerIDs = { 45, 12, 78, 3, 12, 90, 56, 78, 100 };

    cout << "=== SHIPPING CONTAINER MANAGEMENT (BST) ===\n\n";

    // Insert each container ID, catching duplicates
    for (int id : containerIDs) 
    {
        try
        {
            cout << "Inserting container ID: " << id << endl;
            containerBST.insert(id);
        }
        catch (const runtime_error& e) 
        {
            cerr << "  [ERROR] Could not insert " << id
                << ": " << e.what() << endl;
        }
    }
    cout << endl;

    // Display in-order traversal after insertions
    cout << "[In-order after insertions] ";
    auto afterInsertTraversal = containerBST.inOrderTraversal();
    for (int val : afterInsertTraversal)
    {
        cout << val << " ";
    }
    cout << "\n\n";

    // Remove from an empty BST test
    {
        BinarySearchTree<int> emptyTree;
        cout << "Attempting to remove from an empty BST...\n";
        emptyTree.remove(99);  // No error expected, nothing to remove
        cout << "Done - nothing to remove.\n\n";
    }

    // Remove a leaf node (ID 3)
    cout << "Removing leaf node (ID 3)...\n";
    containerBST.remove(3);
    auto afterLeafRemoval = containerBST.inOrderTraversal();
    cout << "[In-order after removing 3] ";
    for (int val : afterLeafRemoval)
    {
        cout << val << " ";
    }
    cout << "\n\n";

    // Remove a node with one child (ID 90)
    cout << "Removing node with one child (ID 90)...\n";
    containerBST.remove(90);
    auto afterOneChildRemoval = containerBST.inOrderTraversal();
    cout << "[In-order after removing 90] ";
    for (int val : afterOneChildRemoval) 
    {
        cout << val << " ";
    }
    cout << "\n\n";

    // Remove a node with two children (ID 45)
    cout << "Removing node with two children (ID 45)...\n";
    containerBST.remove(45);
    auto afterTwoChildRemoval = containerBST.inOrderTraversal();
    cout << "[In-order after removing 45] ";
    for (int val : afterTwoChildRemoval) 
    {
        cout << val << " ";
    }
    cout << "\n\n";

    // Check the maximum value in the BST
    if (!containerBST.isEmpty()) 
    {
        try 
        {
            int maxVal = containerBST.maximum();
            cout << "Maximum container ID in the BST: " << maxVal << "\n";
        }
        catch (const runtime_error& e) 
        {
            cerr << "[ERROR] " << e.what() << endl;
        }
    }
    else {
        cout << "BST is empty. Cannot determine maximum.\n";
    }

    cout << "\n=== END OF DEMO ===\n";
    return 0;
}
