#include <stdio.h>
#include <stdlib.h>


struct ListNode
{
    int m_nKey;
    struct ListNode* m_pNext;
};


ListNode* FindKthToTail(ListNode* pListHead, unsigned int k)
{
    unsigned int i = 0;
    ListNode* pAhead = pListHead;
    ListNode* pBehind = pListHead;

    for (i = 0; i < k - 1; ++i)
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
}













