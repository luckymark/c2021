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

int size() {
	int s = 0;
	for (NODE *nod = head; nod != nullptr; nod = nod->next) {
		s++;
	}
	return s;
}

int indexOf(int dat, int st) {
	int j = 0;
	for (NODE *nod = head; nod != nullptr; nod = nod->next, j++) {
		if (j >= st && nod->data == dat)
			return j;
	}
	return -1;
}
int indexOf(int dat) {
	return indexOf(dat, 0);
}

void reverse() {
	int s = size();
	NODE **lst = (NODE**)malloc(sizeof(NODE*) * s);
	int i = 0;
	for (NODE *nod = head; nod != nullptr; nod = nod->next, i++) {
		lst[s - i - 1] = nod;
	}
	for (i = 0; i < s; i++) {
		NODE *nod = lst[i], *nxt = nod->next;
		nod->next = nod->prev;
		nod->prev = nxt;
	}
	NODE *nod = head;
	head = tail;
	tail = nod;
}

void trace() {
	if (head == nullptr) {
		puts(" N Empty");
		return;
	}
	int i = 0;
	for (NODE *nod = head; nod != nullptr; nod = nod->next) {
		printf(" N%04d %d\n", i, nod->data);
		i++;
	}
}

int main() {
	puts("INIT");
	push(3);
	push(4);
	pop();
	push(5);
	insert(1);
	insert(2);
	shift();
	puts("GET");
	printf(" N* %d %d %d\n", get(0), get(1), get(2));
	puts("REVERSE");
	reverse();
	puts("TRACE");
	trace();
	puts("FIND");
	int i = indexOf(5);
	printf(" L5 %d %d\n", i, indexOf(5, i + 1));
	return 0;
}
