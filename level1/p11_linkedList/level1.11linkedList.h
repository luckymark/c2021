#pragma once
typedef struct node{
    int value;
    struct node* next;
    struct node* last;
}Node;

typedef struct list {
    Node* head;
    Node* tail;
}List;

void add(List* plist, int number);
int search(List* plist, int aim);
int searchAgain(List* plist, int isfound, int aim);
void reverse(List* plist);
void deleteNode(List* plist, int number);
void freeList(List* plist);

