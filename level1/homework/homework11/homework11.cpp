#include<stdio.h>
#include<stdlib.h>

struct  LinkedList {
	int num;
	struct LinkedList* nextP;
	int value;
};
LinkedList* first = NULL;
LinkedList* end = NULL;

int Find(LinkedList* first, int a, int num) {//查找指定第几个5
	LinkedList* temp = first;
	while (temp != NULL) {
		temp = temp->nextP;
		if (temp->value == a) {
			num--;
			if (num == 0)
				return temp->num;
		}
	}
	return -1;
}

int main() {
	for (int i = 0;i < 10;i++) {//创建链表
		LinkedList* temp =(LinkedList *)malloc(sizeof(LinkedList));
		temp->num = i + 1;
		temp->nextP = NULL;
		temp->value = rand() % 10;
		if (first == NULL) first = temp;
		else end->nextP = temp;
		end = temp;
	}

	LinkedList* temp = first;//遍历链表，显示value
	while (temp != NULL) {
		printf("%d  %d\n",temp->num, temp->value);
		temp = temp->nextP;
	}

	LinkedList* nomarl = first, * x = first, *change = first;//反序
	while (1) {
		x = change;
		if (nomarl == first) {
			end = nomarl;
			nomarl = nomarl->nextP;
			change->nextP = NULL;
		}
		change = nomarl;
		if (nomarl->nextP != NULL){
			nomarl = nomarl->nextP;
			change->nextP = x;
		}
		else {
			change->nextP = x;
			first = change;
			break;
		}
	}

}

