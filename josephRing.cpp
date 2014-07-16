#include <stdio.h>
#include <stdlib.h>

typedef struct DLIST
{
	int value;
	struct DLIST* next;
	struct DLIST* pre;
}dList, *pDList;




int josephRing(int argc, char* argv[])
{
	int n, k, m;
	scanf("%d %d %d", &n, &k, &m);

	dList* list = (dList*)calloc(n, sizeof(dList));
	list[0].value = 1;
	list[0].next = &list[1];
	list[0].pre = &list[n - 1];
	for (int i = 1; i < n - 1; ++i)
	{
		list[i].value = i + 1;
		list[i].next = &list[i + 1];
		list[i].pre = &list[i - 1];
	}
	list[n - 1].value = n;
	list[n - 1].next = &list[0];
	list[n - 1].pre = &list[n - 2];

	int size = n;
	dList* ptr = &list[k-1];
	while (size != 0)
	{
		for (int i = 1; i < m; ++i)
			ptr = ptr->next;

		dList* pre = ptr->pre;
		dList* next = ptr->next;
		pre->next = next;
		next->pre = pre;
		ptr->next = NULL;
		ptr->pre = NULL;
		printf("%d", ptr->value);
		size--;
		ptr = next;
	}

	free(list);

	return 0;
}