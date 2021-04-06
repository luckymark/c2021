#include <iostream>
#include <stdlib.h>
using namespace std;

struct node{
    int data;
    struct node* next = NULL;
};
typedef struct node node;

node* init(){
    node* head = (node*) malloc(sizeof(node));
    head -> next = NULL;
    return head;
}

node* find_tail(node* head){
    while(head -> next != NULL) head = head -> next;
    return head;
}

void add(node* head, int x){ // add a node whose data is x
    node* p = (node*) malloc(sizeof(node));
    p->data = x;
    p->next = NULL;
    node *tail = find_tail(head);
    tail->next = p;
}

int find_value_value(node* head, int x){
    int cnt = 0;
    bool found = 0;
    while(head -> next != NULL && head -> data != x){
        head = head -> next;
        cnt++;
    }
    if(head -> data == x) found = 1;
    return found ? cnt : -1;
}

node* find_value_pointer(node* head, int x){
    while(head != NULL && head -> data != x){
        head = head -> next;
    }
    return head;
}

void walk(node* head){
    while(head -> next != NULL){
        cout << head -> next -> data << ' ' ;
        head = head -> next;
    }
}

node* find_father(node* head,node* x){
    while(head != NULL){
        if(head -> next == x){
            return head;
        } else head = head -> next;
    }
    return NULL;
}

node* reverse(node* head){//´Óhead¿ªÊ¼
        node* prev = NULL;
        node* current = head;
        while (current) {
            node* n = current->next;
            current->next = prev;
            prev = current;
            current = n;
        }
        return prev;
}

int main() {
    node* h = init();
    add(h,1);
    add(h,2);
    add(h,5);
    add(h,1564);
    add(h,156);
    add(h,15);
    add(h,5);
    walk(h);
    cout << endl;
    cout << find_value_value(h,5) << endl;
    node* h1 = find_value_pointer(h,5);
    cout << find_value_value(h,5) + find_value_value(h1->next,5) + 1 << endl;
    cout << endl;

    system("pause");
    return 0;
}

