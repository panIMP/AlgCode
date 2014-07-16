#pragma once

typedef int valueType;

struct binaryTreeNode
{
	valueType m_nValue;
	binaryTreeNode* m_pLeft;
	binaryTreeNode* m_pRight;
};

typedef binaryTreeNode* pBinaryTreeNode;



// Create a binary search tree
pBinaryTreeNode
createBinarySearchTree(valueType array[], int nodeNum);


// Insert a node into binary search tree
pBinaryTreeNode
insertIntoBinarySearchTree(valueType value, pBinaryTreeNode& pNode);


// Print in preorder
void
printBinaryTreePreorderRecursive(pBinaryTreeNode pNode);

void
printBinaryTreePreorderStack1(pBinaryTreeNode root);

void
printBinaryTreePreorderStack2(pBinaryTreeNode root);


// Print in inorder
void
printBinaryTreeInorderRecursive(pBinaryTreeNode pNode);

void
printBinaryTreeInorderStack(pBinaryTreeNode root);


// Print in postorder
void
printBinaryTreePostorderRecursive(pBinaryTreeNode pNode);

void
printBinaryTreePostorderStack(pBinaryTreeNode root);


// Print in breadth-first order
void
printBinaryTreeBreadthFirstOrder(pBinaryTreeNode root);



// Find the node through the value(Condition: no duplicate value in the tree)
pBinaryTreeNode
findByValue(pBinaryTreeNode pNode, valueType value);


// Reconstruct the tree through preorder traversal and inorder traversal
pBinaryTreeNode
reconstructTree(valueType* preOrder, valueType* inOrder, int nodeNum);

