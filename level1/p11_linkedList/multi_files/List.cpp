#include <bits/stdc++.h>

using namespace std;

struct Node{
	int val;
	Node* next;
	Node* prev;
}*head, *tail;

void build(){
	head = (Node *)malloc(sizeof(Node));
	tail = (Node *)malloc(sizeof(Node));
	tail -> prev = head;
	head -> next = tail;
}

void reverse(){
	Node *ptr = head;
	while(ptr != NULL){
		swap(ptr -> prev, ptr -> next);
		ptr = ptr -> prev;
	}
	swap(head, tail);
}

Node* push_back(const int &x){
	Node *NewNode = (Node *)malloc(sizeof(Node));
	assert(NewNode);
	NewNode -> prev = tail -> prev;
	tail -> prev -> next = NewNode;
	NewNode -> next = tail;
	tail -> prev = NewNode;
	NewNode -> val = x;
	return NewNode;
}

Node* push_front(const int &x){
	Node *NewNode = (Node *)malloc(sizeof(Node));
	assert(NewNode);
	NewNode -> next = head -> next;
	head -> next -> prev = NewNode;
	NewNode -> prev = head;
	head -> next = NewNode;
	NewNode -> val = x;
	return NewNode;
}

void erase(Node *x){
	x -> prev -> next = x -> next;
	x -> next -> prev = x -> prev;
	free(x);
}

void pop_back(){
	if(tail -> prev != head)erase(tail -> prev);
}

void pop_front(){
	if(head -> next != tail)erase(head -> next);
}

Node* insert(const int &ID, const int &x){
	if(ID <= 0)return NULL;
	Node *ptr = head;
	for(int i = 0; i < ID; ++i){
		if(ptr -> next){
			ptr = ptr -> next;
		}
		else {
			return NULL;
		}
	}
	Node *NewNode = (Node *)malloc(sizeof(Node));
	assert(NewNode);
	NewNode -> val = x;
	ptr -> prev -> next = NewNode;
	NewNode -> prev = ptr -> prev;
	NewNode -> next = ptr;
	ptr -> prev = NewNode;
	return NewNode;
}

Node* find_next(Node *ptr, const int &x){
	if(ptr == tail || !ptr)return NULL;
	while(ptr -> val != x){
		if(ptr -> next != tail){
			ptr = ptr -> next;
		}
		else return NULL;
	}
	return ptr;
}

Node* find_prev(Node *ptr, const int &x){
	if(ptr == head || !ptr)return NULL;
	while(ptr -> val != x){
		if(ptr -> prev != head){
			ptr = ptr -> prev;
		}
		else return NULL;
	}
	return ptr;
}

Node* find_front(const int &x){
	return find_next(head, x);
}

Node* find_back(const int &x){
	return find_prev(tail, x);
}

void erase_val(const int &x){
	Node *ptr = head -> next;
	while(ptr != tail){
		Node *next = ptr -> next;
		if(ptr -> val == x){
			erase(ptr);
		}
		ptr = next;
	}
}

void erase_ID(const int &ID){
	if(ID <= 0)return ;
	Node *ptr = head;
	for(int i = 0; i < ID; ++i){
		if(ptr -> next != tail){
			ptr = ptr -> next;
		}
		else {
			return ;
		}
	}
	erase(ptr);
}

void visit(){
	Node *ptr = head -> next;
	while(ptr != tail){
		printf("%d ", ptr -> val);
		ptr = ptr -> next;
	}
	puts("");
}
