#ifndef _LISTHP_H
#define _LISTHP_H

typedef struct _LIST_NODE
{
	int m_nValue;
	_LIST_NODE* m_pNext;
} listNode, *pListNode;


// Creat the list, value assigned from 1 to memberNum sequentially
pListNode
creatList(int memberNum);

// Print the list
void
printList(pListNode list);

// Get the tail of the list
pListNode
getListTail(pListNode list);

// Get the length of the list
int
getListLen(pListNode list);

// Remove nodes with the same value
void 
RemoveNode(pListNode* pHead, int value);

// Find the Kth node to list tail
pListNode
findKth2Tail(pListNode list, int k);

// Reverse print the list, using recursive functions
// method1: using recursive functions 
void
reversePrintList1(pListNode list);

// Reverse print the list, using recursive functions
// method2: using stack
void
reversePrintList2(pListNode listHead);

// Reverse the list
// method1: using recursive functions
void
reverseList1(pListNode pre, pListNode cur);

// method2: using loop
void
reverseList2(pListNode head);

#endif
