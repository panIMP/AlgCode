#ifndef _LIST_H
#define _LIST_H

#include "_std.h"

typedef struct _typeNode {
    int value;
    struct _typeNode* next;
}typeNode;

typeNode* createList();

void listReverse (typeNode* p);

void listReverse2(typeNode* node, typeNode* pre);

void listReverse3(typeNode** head);

void printList(typeNode* head);


#endif // _LIST_H
