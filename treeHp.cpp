#include "treeHp.h"
#include <iostream>
#include <stack>
#include <queue>




// Create a binary search tree
pBinaryTreeNode 
createBinarySearchTree(valueType array[], int nodeNum)
{
	pBinaryTreeNode root = new binaryTreeNode;
	root->m_nValue = array[0];
	root->m_pRight = root->m_pLeft = nullptr;

	for (int i = 1; i < nodeNum; ++i)
		insertIntoBinarySearchTree(array[i], root);

	return root;
}


// Insert a node into binary search tree
pBinaryTreeNode
insertIntoBinarySearchTree(valueType value, pBinaryTreeNode& pNode)
{
	if (pNode == nullptr)
	{
		// Make an empty tree
		pNode = new binaryTreeNode;
		if (pNode == nullptr)
			return nullptr;

		pNode->m_nValue = value;
		pNode->m_pRight = pNode->m_pLeft = nullptr;
	}
	
	else
	{	
		if (pNode->m_nValue < value)
			insertIntoBinarySearchTree(value, pNode->m_pRight);

		else if (pNode->m_nValue > value)
			insertIntoBinarySearchTree(value, pNode->m_pLeft);
	}

	return pNode;
}


// Print in preorder
void
printBinaryTreePreorderRecursive(pBinaryTreeNode pNode)
{
	if (pNode == nullptr)
		return;

	else
	{
		std::cout << pNode->m_nValue << " ";
		printBinaryTreePreorderRecursive(pNode->m_pLeft);
		printBinaryTreePreorderRecursive(pNode->m_pRight);
	}
}

void
printBinaryTreePreorderStack1(pBinaryTreeNode root)
{
	if (root == nullptr)
		return;

	std::stack<pBinaryTreeNode> treeStack;
	pBinaryTreeNode pNode = root;
	treeStack.push(pNode);

	while (!treeStack.empty())
	{
		pNode = treeStack.top();
		treeStack.pop();

		std::cout << pNode->m_nValue << " ";

		if (pNode->m_pRight != nullptr)
			treeStack.push(pNode->m_pRight);

		if (pNode->m_pLeft != nullptr)
			treeStack.push(pNode->m_pLeft);
	}
}

void
printBinaryTreePreorderStack2(pBinaryTreeNode root)
{
	if (root == nullptr)
		return;

	std::stack<pBinaryTreeNode> treeStack;
	pBinaryTreeNode pNode = root;

	while (pNode != nullptr || !treeStack.empty())
	{
		if (pNode != nullptr)
		{
			std::cout << pNode->m_nValue << " ";

			treeStack.push(pNode);

			pNode = pNode->m_pLeft;
		}
		else
		{
			pNode = treeStack.top();
			treeStack.pop();

			pNode = pNode->m_pRight;
		}
	}
}


// Print in inorder
void
printBinaryTreeInorderRecursive(pBinaryTreeNode pNode)
{
	if (pNode == nullptr)
		return;

	else
	{
		printBinaryTreeInorderRecursive(pNode->m_pLeft);
		std::cout << pNode->m_nValue << " ";
		printBinaryTreeInorderRecursive(pNode->m_pRight);
	}
}

void
printBinaryTreeInorderStack(pBinaryTreeNode root)
{
	if (root == nullptr)
		return;

	std::stack<pBinaryTreeNode> treeStack;
	pBinaryTreeNode pNode = root;

	while (pNode != nullptr || !treeStack.empty())
	{
		if (pNode != nullptr)
		{
			treeStack.push(pNode);

			pNode = pNode->m_pLeft;
		}
		else
		{
			pNode = treeStack.top();
			treeStack.pop();

			std::cout << pNode->m_nValue << " ";

			pNode = pNode->m_pRight;
		}
	}
}


// Print in postorder
void
printBinaryTreePostorderRecursive(pBinaryTreeNode pNode)                                      
{
	if (pNode == nullptr)
		return;

	else
	{
		printBinaryTreePostorderRecursive(pNode->m_pLeft);
		printBinaryTreePostorderRecursive(pNode->m_pRight);
		std::cout << pNode->m_nValue << " ";
	}
}

void
printBinaryTreePostorderStack(pBinaryTreeNode root)
{
	if (root == nullptr)
		return;

	std::stack<pBinaryTreeNode> treeStack;
	pBinaryTreeNode pNode = root;

	while (pNode != nullptr || !treeStack.empty())
	{
		if (pNode != nullptr)
		{
			treeStack.push(pNode);
			treeStack.push(pNode->m_pRight);

			pNode = pNode->m_pLeft;
		}
		else
		{
			pNode = treeStack.top();
			treeStack.pop();

			if (pNode == nullptr)
			{
				pNode = treeStack.top();
				treeStack.pop();

 				if (pNode != nullptr)
 					std::cout << pNode->m_nValue << " ";

				if (treeStack.empty())
					return;
				
				pNode = treeStack.top();
				treeStack.pop();
			}

			treeStack.push(nullptr);
		}
	}
}


// Print in breadth-first order
void
printBinaryTreeBreadthFirstOrder(pBinaryTreeNode root)
{
	std::queue<pBinaryTreeNode> treeQueue;
	treeQueue.push(root);
	pBinaryTreeNode pNode;

	while (!treeQueue.empty())
	{
		pNode = treeQueue.front();
		treeQueue.pop();

		std::cout << pNode->m_nValue << " ";

		if (pNode->m_pLeft != nullptr)
			treeQueue.push(pNode->m_pLeft);

		if (pNode->m_pRight != nullptr)
			treeQueue.push(pNode->m_pRight);
	}
}


// Find the node through the value(Condition: no duplicate value in the tree)
pBinaryTreeNode
findByValue(pBinaryTreeNode pNode, valueType value)
{
	if (pNode == nullptr)
		return nullptr;

	if (pNode->m_nValue != value)
	{
		findByValue(pNode->m_pLeft, value);
		findByValue(pNode->m_pRight, value);
	}

	return pNode;
}



// Reconstruct the tree through preorder traversal and inorder traversal
pBinaryTreeNode
reconstructTree(valueType* preOrder, valueType* inOrder, int nodeNum)
{
	if (nodeNum <= 0)
		return nullptr;

	pBinaryTreeNode father = new binaryTreeNode;
	pBinaryTreeNode leftSon = new binaryTreeNode;
	pBinaryTreeNode rightSon = new binaryTreeNode;

	int rootValue = father->m_nValue = *preOrder;
	int i;
	for (i = 0; i < nodeNum; ++i)
	{
		if (inOrder[i] == rootValue)
			break;
	}
	int leftSonNum = i;
	int rightSonNum = nodeNum - i - 1;

	father->m_pLeft = leftSon;
	leftSon->m_nValue = *(preOrder + 1);
	father->m_pRight = rightSon;
	rightSon->m_nValue = *(preOrder + leftSonNum);

	reconstructTree(preOrder + 1, inOrder, leftSonNum);
	reconstructTree(preOrder + leftSonNum, inOrder + leftSonNum + 1, rightSonNum);

	return father;
}