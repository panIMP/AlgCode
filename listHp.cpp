#include <exception>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <stack>

#include "_std.h"

typedef struct _typeNode {
    int value;
    struct _typeNode* next;
}typeNode;

typedef struct _LIST_NODE
{
	int m_nValue;
	_LIST_NODE* m_pNext;
} listNode, *pListNode;


using namespace std;


/* List operations */



typeNode* createList(int array[], int len) {
    int i;
    typeNode* p;

    typeNode* head = (typeNode*)malloc(sizeof(typeNode));
    assert(head != NULL);

    head->value = array[0];
    head->next = NULL;

    p = head;
    for (i = 1; i < len; ++i) {
        typeNode* node = (typeNode*)malloc(sizeof(typeNode));
        node->value = array[i];
        node->next = NULL;
        p->next = node;
        p = p->next;
    }

    return head;
}


void listReverse (typeNode* p) {
    if (p->next != NULL) {
        listReverse (p->next);
    }

    printf("%d", p->value);
}

void listReverse2(typeNode* node, typeNode* pre) {
    if (node->next != NULL) {
        listReverse2(node->next, node);
    }

    node->next = pre;
    pre->next = NULL;
}


void listReverse3(typeNode** head) {
    typeNode* pre = (*head);
    typeNode* cur = (*head)->next;
    typeNode* node;

    assert(*head != NULL);

    while (cur != NULL) {
        node = pre;
        pre = cur;
        cur = cur->next;
        pre->next = node;
    }

    (*head)->next = NULL;
    *head = pre;
}


void listReverseTotal(typeNode** head)
{
	if (*head == NULL)
        throw new exception();

	typeNode* cur = *head;
	typeNode* next = NULL;
	typeNode* pre = NULL;

	while (cur->next != NULL)
	{
		next = cur->next;
		cur->next = pre;
		pre = cur;
		cur = next;
	}

	cur->next = pre;
	*head = cur;
}


typeNode* listMerge(typeNode* list1, typeNode* list2)
{
	if (list1 == NULL)
		return list2;
	if (list2 == NULL)
		return list1;

	typeNode* listMergeHead = NULL;

	if (list1->value < list2->value)
	{
		listMergeHead = list1;
		listMergeHead->next = listMerge(list1->next, list2);
	}
	else
	{
		listMergeHead = list2;
		listMergeHead->next = listMerge(list1, list2->next);
	}

	return listMergeHead;
}


typeNode* listMerge2(typeNode* list1, typeNode* list2)
{
	if (list1 == NULL)
		return list2;
	if (list2 == NULL)
		return list1;

	typeNode* listMergeHead = list1->value <= list2->value ? list1 : list2;

	typeNode* list1Pre = list1;
	typeNode* list2Pre = list2;

	while (list1 != NULL && list2 != NULL)
	{
		while (list1 != NULL && list1->value <= list2->value)
		{
			list1Pre = list1;
			list1 = list1->next;
		}

		list1Pre->next = list2;
		if (list1 == NULL)
			break;

		while (list2 != NULL && list2->value <= list1->value)
		{
			list2Pre = list2;
			list2 = list2->next;
		}

		list2Pre->next = list1;
		if (list2 == NULL)
			break;
	}
	
	return listMergeHead;
}


void printList(typeNode* head) {
    while (head) 
	{
        printf("%d", head->value);
        head = head->next;
    }
}



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
