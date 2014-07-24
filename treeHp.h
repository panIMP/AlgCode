#pragma once

typedef int valueType;

struct bTreeNode
{
	valueType m_nValue;
	bTreeNode* m_pLeft;
	bTreeNode* m_pRight;
};

typedef bTreeNode* pBTreeNode;



// Create a binary search tree
pBTreeNode
createBinarySearchTree(valueType array[], int nodeNum);


// Insert a node into binary search tree
pBTreeNode
insertIntoBinarySearchTree(valueType value, pBTreeNode& pNode);


// Print in preorder
void
printBinaryTreePreorderRecursive(pBTreeNode pNode);

void
printBinaryTreePreorderStack1(pBTreeNode root);

void
printBinaryTreePreorderStack2(pBTreeNode root);


// Print in inorder
void
printBinaryTreeInorderRecursive(pBTreeNode pNode);

void
printBinaryTreeInorderStack(pBTreeNode root);


// Print in postorder
void
printBinaryTreePostorderRecursive(pBTreeNode pNode);

void
printBinaryTreePostorderStack(pBTreeNode root);


// Print in breadth-first order
void
printBinaryTreeBreadthFirstOrder(pBTreeNode root);



// Find the node through the value(Condition: no duplicate value in the tree)
pBTreeNode
findByValue(pBTreeNode pNode, valueType value);


