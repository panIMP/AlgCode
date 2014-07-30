#include "treeHp.h"
#include <iostream>
#include <stack>
#include <queue>
#include <exception>


using namespace std;



// Create a binary search tree
pBTreeNode 
createBinarySearchTree(valueType array[], int nodeNum)
{
	pBTreeNode root = new bTreeNode;
	root->m_nValue = array[0];
	root->m_pRight = root->m_pLeft = nullptr;

	for (int i = 1; i < nodeNum; ++i)
		insertIntoBinarySearchTree(array[i], root);

	return root;
}


// Insert a node into binary search tree
pBTreeNode
insertIntoBinarySearchTree(valueType value, pBTreeNode& pNode)
{
	if (pNode == nullptr)
	{
		// Make an empty tree
		pNode = new bTreeNode;
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
printBinaryTreePreorderRecursive(pBTreeNode pNode)
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
printBinaryTreePreorderStack1(pBTreeNode root)
{
	if (root == nullptr)
		return;

	std::stack<pBTreeNode> treeStack;
	pBTreeNode pNode = root;
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
printBinaryTreePreorderStack2(pBTreeNode root)
{
	if (root == nullptr)
		return;

	std::stack<pBTreeNode> treeStack;
	pBTreeNode pNode = root;

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
printBinaryTreeInorderRecursive(pBTreeNode pNode)
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
printBinaryTreeInorderStack(pBTreeNode root)
{
	if (root == nullptr)
		return;

	std::stack<pBTreeNode> treeStack;
	pBTreeNode pNode = root;

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
printBinaryTreePostorderRecursive(pBTreeNode pNode)                                      
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
printBinaryTreePostorderStack(pBTreeNode root)
{
	if (root == nullptr)
		return;

	std::stack<pBTreeNode> treeStack;
	pBTreeNode pNode = root;

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
printBinaryTreeBreadthFirstOrder(pBTreeNode root)
{
	if (root == NULL)
		return;

	std::queue<pBTreeNode> treeQueue;
	treeQueue.push(root);
	pBTreeNode pNode;

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
pBTreeNode
findByValue(pBTreeNode pNode, valueType value)
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
pBTreeNode reconsTroughPreAndIn(int* preHead, int* preEnd, int* inHead, int* inEnd)
{
	int rootVal = *preHead;
	pBTreeNode rootNode = (pBTreeNode)malloc(sizeof(bTreeNode));
	rootNode->m_nValue = rootVal;
	rootNode->m_pLeft = rootNode->m_pRight = NULL;

	// End recursive condition
	if (preHead == preEnd)
	{
		if (inHead == inEnd && *preHead == *inHead)
		{
			return rootNode;
		}
		else
            throw std::exception();
	}

	int* rootIn = inHead;
	while (rootIn <= inEnd && *rootIn != rootVal)
		rootIn++;
	if (rootIn == inEnd && *rootIn != rootVal)
        throw std::exception();
	
	int leftLen = rootIn - inHead;
	int rightLen = inEnd - rootIn;

	// recursive construct the left tree
	if (leftLen > 0)
		rootNode->m_pLeft = reconsTroughPreAndIn(preHead + 1, preHead + leftLen, inHead, rootIn - 1);
	// recursive construct the right tree
	if (rightLen > 0)
		rootNode->m_pRight = reconsTroughPreAndIn(preHead + 1 + leftLen, preEnd, rootIn + 1, inEnd);

	return rootNode;
}


int reconsTroughPreAndInPack(int argc, char* argv[])
{
	int preOrder[8] = {1, 2, 4, 7, 3, 5, 6, 8};
	int inOrder[8] = {4, 7, 2, 1, 5, 3, 8, 6};
	int len = 8;

	pBTreeNode postOrderHead = reconsTroughPreAndIn(preOrder, preOrder + len - 1, inOrder, inOrder + len - 1);

	printBinaryTreePostorderRecursive(postOrderHead);

	system("pause");

	return 0;
}



bool hasSameBranch(pBTreeNode pRoot1, pBTreeNode pRoot2)
{
	if (pRoot2 == NULL)
		return true;

	if (pRoot1 == NULL)
		return false;

	if (pRoot1->m_nValue != pRoot2->m_nValue)
		return false;

	bool resultL = hasSameBranch(pRoot1->m_pLeft, pRoot2->m_pLeft);
	bool resultR = hasSameBranch(pRoot1->m_pRight, pRoot2->m_pRight);

	return resultL && resultR;
}



bool hasSubTree(pBTreeNode pRootA, pBTreeNode pRootB)
{
	bool result = false;

	if (pRootA != NULL && pRootB != NULL)
	{
		if (pRootA->m_nValue == pRootB->m_nValue)
		{
			result = hasSameBranch(pRootA, pRootB);
		}
		
		if (!result)
			result = hasSubTree(pRootA->m_pLeft, pRootB);

		if (!result)
			result = hasSubTree(pRootA->m_pRight, pRootB);
	}

	return result;
}


void mirrorBTree(pBTreeNode root)
{
	if (root == NULL || (root->m_pLeft == NULL && root->m_pRight == NULL))
		return;

	pBTreeNode pNode = root->m_pLeft;
	root->m_pLeft = root->m_pRight;
	root->m_pRight = pNode;

	mirrorBTree(root->m_pLeft);
	mirrorBTree(root->m_pRight);
}










