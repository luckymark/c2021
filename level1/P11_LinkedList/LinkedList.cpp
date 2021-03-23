#include <stdlib.h>
#include <stdio.h>

typedef struct _NODE {
	int data;
	_NODE *prev, *next;
} NODE;

NODE *head = nullptr, *tail = nullptr;

void push(int dat) {
	NODE *nod = (NODE*)malloc(sizeof(NODE));
	nod->data = dat;
	nod->prev = tail;
	nod->next = nullptr;
	if (tail != nullptr)
		tail->next = nod;
	tail = nod;
	if (head == nullptr)
		head = nod;
}

int pop() {
	if (tail != nullptr) {
		int dat = tail->data;
		NODE *prev = tail->prev;
		free(tail);
		tail = prev;
		if (prev != nullptr) {
			prev->next = nullptr;
		} else {
			head = nullptr;
		}
		return dat;
	} else {
		return -1;
	}
}

void insert(int dat) {
	NODE *nod = (NODE*)malloc(sizeof(NODE));
	nod->data = dat;
	nod->prev = nullptr;
	nod->next = head;
	if (head != nullptr)
		head->prev = nod;
	head = nod;
	if (tail == nullptr)
		tail = nod;
}

int shift() {
	if (head != nullptr) {
		int dat = head->data;
		NODE *nxt = head->next;
		free(head);
		head = nxt;
		if (nxt != nullptr) {
			nxt->prev = nullptr;
		} else {
			tail = nullptr;
		}
		return dat;
	} else {
		return -1;
	}
}

int get(int i) {
	int j = 0;
	for (NODE *nod = head; nod != nullptr; nod = nod->next, j++) {
		if (j == i)
			return nod->data;
	}
	return -1;
}

void trace() {
	puts("T");
	if (head == nullptr) {
		puts("N Empty");
		return;
	}
	int i = 0;
	for (NODE *nod = head; nod != nullptr; nod = nod->next) {
		printf("N%04d %d\n", i, nod->data);
		i++;
	}
}

int main() {
	push(2);
	push(3);
	insert(1);
	insert(0);
	pop();
	shift();
	printf("N %d %d\n", get(0), get(1));
	trace();
	return 0;
}
