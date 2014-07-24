#include <stdio.h>
#include <stdlib.h>
#include <exception>


using namespace std;


struct ListNode
{
    int m_nKey;
    struct ListNode* m_pNext;
};


ListNode* FindKthToTail(ListNode* pListHead, unsigned int k)
{
	if (pListHead == NULL || k == 0)
		return NULL;

    ListNode* pAhead = pListHead;
	for (unsigned int i = 0; i < k - 1; ++i)
	{
		if (pAhead->m_pNext != NULL)
			pAhead = pAhead->m_pNext;
		else
			return NULL;
	}

	ListNode* pBehind = pListHead;
	while (pAhead ->m_pNext != NULL)
	{
		pAhead = pAhead->m_pNext;
		pBehind = pBehind->m_pNext;
	}

	return pBehind;
}


ListNode* findMidInList(ListNode* pListHead)
{
	if (pListHead == NULL)
		return NULL;

	ListNode* pSingleStep = pListHead;
	ListNode* pDoubleStep = pListHead;

	while (pDoubleStep->m_pNext != NULL)
	{
		pDoubleStep = pDoubleStep->m_pNext;
		pSingleStep = pSingleStep->m_pNext;

		if (pDoubleStep->m_pNext != NULL)
		{	
			pDoubleStep = pDoubleStep->m_pNext;
		}
		else
			return pSingleStep;
	}

	return pSingleStep;
}


bool checkListCircle(ListNode* pListHead)
{
	if (pListHead == NULL)
		throw new exception("Invalid input");

	ListNode* pSingleStep = pListHead;
	ListNode* pDoubleStep = pListHead;

	while (pDoubleStep->m_pNext != NULL)
	{
		pDoubleStep = pDoubleStep->m_pNext;
		pSingleStep = pSingleStep->m_pNext;
		
		if (pDoubleStep->m_pNext != NULL)
		{
			pDoubleStep = pDoubleStep->m_pNext;
		}
		else
			return false;
		
		if (pDoubleStep == pSingleStep || pDoubleStep->m_pNext == pSingleStep)
			return true;
	}

	return false;
}


int findKth2Tail(int argc, char* argv[])
{
    int nodeNum = 0;
    ListNode* list = NULL;
    ListNode* listPtr = NULL;
    int i = 0;
    int k = 0;
    ListNode* pNodeRk = NULL;

    scanf_s("%d", &nodeNum);
    if (nodeNum <= 0)
        return -1;

    if (getchar() != '\n')
        return -1;

    list = (ListNode*)calloc(nodeNum, sizeof(ListNode));
    if (list == NULL)
    {
        return -1;
    }

    listPtr = list;
    for (i = 0; i < nodeNum-1; ++i)
    {
        list[i].m_pNext = &(list[i+1]);
    }
    list[i].m_pNext = NULL;

    for (i = 0; i < nodeNum; ++i)
    {
        if (scanf_s("%d", &(listPtr->m_nKey)) < 1)
            return -1;

        listPtr = listPtr->m_pNext;
    }
    if (getchar() != '\n')
        return -1;

    scanf_s("%d", &k);
    if (k < 0 || k > nodeNum)
        return -1;

    if ((pNodeRk = FindKthToTail(list, k)) == NULL)
        return -1;

    printf("%d", pNodeRk->m_nKey);

	return 0;
}













