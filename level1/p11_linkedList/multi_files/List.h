#ifndef LISH_H
#define LISH_H

struct Node{
	int val;
	Node* next;
	Node* prev;
};

void build();
void reverse();
Node* push_back(const int &x);
Node* push_front(const int &x);
void erase(Node *x);
void pop_back();
void pop_front();
void pop_back();
Node* insert(const int &ID, const int &x);
Node* find_next(Node *ptr, const int &x);
Node* find_prev(Node *ptr, const int &x);
Node* find_front(const int &x);
Node* find_back(const int &x);
void erase_val(const int &x);
void erase_ID(const int &ID);
void visit();

#endif