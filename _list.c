#include "_list.h"

/* List operations */



typeNode* createList() {
    int i;
    typeNode* p;

    typeNode* head = (typeNode*)malloc(sizeof(typeNode));
    assert(head != NULL);

    head->value = 0;
    head->next = NULL;

    p = head;
    for (i = 1; i < N; ++i) {
        typeNode* node = (typeNode*)malloc(sizeof(typeNode));
        node->value = i;
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

void printList(typeNode* head) {
    while (head) {
        printf("%d", head->value);
        head = head->next;
    }
}

