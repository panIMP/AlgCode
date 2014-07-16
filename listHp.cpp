#include <cstdio>
#include <cstdlib>
#include "listHp.h"
#include <iostream>
#include <stack>



// Creat the list, value assigned from 1 to memberNum sequentially
pListNode
creatList(int memberNum)
{
	static pListNode list = nullptr;
	pListNode listNode1;
	pListNode listNode2;

	if (list != nullptr)
	{
		return list;
	}

	list = new listNode;
	list->m_pNext = nullptr;
	list->m_nValue = 1;

	listNode1 = listNode2 = list;

	for (int i = 1; i < memberNum; ++i)
	{
		listNode1 = new listNode;
		listNode1->m_nValue = i + 1;
		listNode1->m_pNext = nullptr;

		listNode2->m_pNext = listNode1;
		listNode2 = listNode1;
	}

	return list;
}


// Print the list
void 
printList(pListNode list)
{
	while (list != nullptr)
	{
		std::cout << list->m_nValue << " ";
		list = list->m_pNext;
	}
}


// Get the length of the list
int 
getListLen(pListNode list)
{
	int len = 0;
	while (list != nullptr)
	{
		list = list->m_pNext;
		len++;
	}

	return len;
}


// Get the tail of the list
pListNode 
getListTail(pListNode list)
{
	while (list->m_pNext != nullptr)
		list = list->m_pNext;
	
	return list;
}


// Remove nodes with the same value
void
RemoveNode(pListNode* pHead, int value)
{
	if (*pHead == nullptr || pHead == nullptr)
		return;

	pListNode pToBeDeleted = nullptr;

	if ((*pHead)->m_nValue == value)
	{
		pToBeDeleted = *pHead;
		*pHead = pToBeDeleted->m_pNext;

		delete pToBeDeleted;
		pToBeDeleted = nullptr;
	}
	else
	{
		pListNode pCurNode = *pHead;
		
		while (pCurNode != nullptr)
		{
			if (pCurNode->m_pNext->m_nValue == value)
			{
				pToBeDeleted = pCurNode->m_pNext;
				pCurNode->m_pNext = pToBeDeleted->m_pNext;
				pToBeDeleted->m_pNext = nullptr;
				
				delete pToBeDeleted;
				pToBeDeleted = nullptr;
			}

			pCurNode = pCurNode->m_pNext;
		}
	}
}


// Find the Kth node to list tail 
pListNode 
findKth2Tail(pListNode list, int k) 
{
	if (k < 0 || k > getListLen(list))
	{
		printf("K value is not right!");
	}

	if (list == nullptr)
	{
		printf("List is null\n");
		getchar();
		return nullptr;
	}

	pListNode pAhead = list;
	pListNode pBehind = list;

	for (int i = 0; i < k - 1; ++i)
	{
		pAhead = pAhead->m_pNext;
	}

	while (pAhead->m_pNext != NULL)
	{
		pBehind = pBehind->m_pNext;
		pAhead = pAhead->m_pNext;
	}

	return pBehind;
}


// Reverse print the list, using recursive functions

// method1: using recursive functions 
void
reversePrintList1(pListNode listHead)
{
	if (listHead->m_pNext == nullptr || listHead == nullptr)
		return;

	if (listHead->m_pNext != nullptr)
		reversePrintList1(listHead->m_pNext);

	std::cout << listHead->m_nValue << " ";
}


// method2: using stack
void
reversePrintList2(pListNode listHead)
{
	if (listHead == nullptr || listHead->m_pNext == nullptr)
		return;

	std::stack<listNode*> reverseList;
	
	pListNode listPtr = listHead;
	while (listPtr != nullptr)
	{
		reverseList.push(listPtr);
		listPtr = listPtr->m_pNext;
	}

	while (!reverseList.empty())
	{
		listPtr = reverseList.top();
		std::cout << listPtr->m_nValue << " ";
		reverseList.pop();
	}
}


// Reverse the list

// method1: using recursive functions
void 
reverseList1(pListNode pre, pListNode cur)
{
	if (pre == nullptr || cur == nullptr)
		return;

	if (cur->m_pNext != nullptr)
		reverseList1(pre->m_pNext, cur->m_pNext);

	cur->m_pNext = pre;
	pre->m_pNext = nullptr;
}


// method2: using loop
void 
reverseList2(pListNode head)
{
	pListNode pre = head;
	pListNode cur = pre->m_pNext;
	pListNode node = nullptr;

	if (head == nullptr || head->m_pNext == nullptr)
		return;

	while (cur != nullptr)
	{
		node = pre;
		pre = cur;
		cur = cur->m_pNext;
		pre->m_pNext = node;
	}

	head->m_pNext = nullptr;
}
