//规定 需要有头指针才能实现插入或者附上的操作
#include<stdio.h>
#include<stdlib.h>
struct node {
	int data;
	struct node* next;
};

struct node* head = (struct node*)malloc(sizeof(struct node*));

struct node* insert(struct node* head, int position, int a);
struct node* append(struct node* head, int a);
void display(struct node* head);
struct node* reverse(struct node*);
int exist(int a, int times);

int main() {
	head->data = 0;
	head->next = NULL;
	append(head, 1);
	append(head, 2);
	append(head, 3);
	display(head);
	insert(head, 2, 5);
	display(head);
	reverse(head);
	display(head);
	exist(5, 1);
	exist(5, 2);

}
struct node* insert(struct node* head, int position, int a)
{
	//确定节点总数
	struct node* end = head;
	int len = 1;
	while (end->next != NULL)
	{
		len++;
		end = end->next;
	}
	//判断插入的位置是否合法
	if (position > len + 1)
	{
		printf("error!the link is not long enough.");
	}
	if (position < 0) printf("error! The position is not crrect.");
	//建立节点
	struct node* p = NULL;
	p = (struct node*)malloc(sizeof(struct node*));
	p->data = a;
	//先考虑只插入链表的中间的情况，即插入位置前后都有节点
	if (position != 0 && position != len + 1)
	{
		p->next = head->next;
		head->next = p;
	}
	//插入第一个位置
	if (position == 0)
	{
		p->next = head;
		head = p;
	}
	//插入最后一个位置
	if (position == len + 1)
	{
		end->next = p;
		p->next = NULL;
	}
	return head;
}
struct node* append(struct node* head, int a)
{
	struct node* end = head;
	int len = 1;
	while (end->next != NULL)
	{
		len++;
		end = end->next;
	}
	struct node* p = NULL;
	p = (struct node*)malloc(sizeof(struct node*));
	p->data = a;
	end->next = p;
	p->next = NULL;
	return head;
}
void display(struct node* head)
{
	struct node* tmp = head;
	while (tmp != NULL)
	{
		printf("%d	", tmp->data);
		tmp = tmp->next;
	}
	printf("\n");
}
struct node* reverse(struct node*)
{
	struct node* tmp1 = NULL;
	struct node* tmp2;
	//节点只能一个一个连接，而且中间不能突然断开，所以需要抽丝剥茧。
	//详见：https://blog.csdn.net/autumn20080101/article/details/7607148
	while (head != NULL)
	{
		tmp2 = head->next;
		head->next = tmp1;
		tmp1 = head;
		head = tmp2;
	}
	head = tmp1;
	return head;
}
int exist(int a, int times)
{
	int b = 0;
	int len = 0;
	struct node* tmp = head;
	while (tmp != NULL)
	{
		len++;
		if (tmp->data == a)
		{
			b++;
			if (b == times)
			{
				printf("%d\n", len);
				return len;
			}
		}
		tmp = tmp->next;
	}
	printf("-1\n");
	return -1;
}


