// linkedlist.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
#include <iostream>
#include <stdio.h>

struct link
{
	int data;
	struct link* next;
};

link* createlink(int n)
{
	link* head = (link*)malloc(sizeof(link));
	link* temp = head;
	for (int i = 1; i <= n; i++)
	{
		link* node = (link*)malloc(sizeof(link));
		if (node!=NULL&&temp!=NULL)
		{
			scanf_s("%d", &(node->data));
			temp->next = node;
			node->next = NULL;
			temp = temp->next;
		}
	}
	return head;
}


link* fanxu(link* p);
void xianshi(link* p);
int searchnode(link* p,int a);
int searchnext(link* p, int a,int x);

int main()
{
	int n;
	scanf_s("%d", &n);
	link* p = createlink(n);
	int number;
	scanf_s("%d", &number);
	link* temp = p->next;
	while (temp!= NULL)
	{
		printf("%d ", temp->data);
		temp = temp->next;
	}
	p = fanxu(p);
	temp = p;
	printf("\n");
	while (temp != NULL)
	{
		printf("%d ", temp->data);
		temp = temp->next;
	}
	int position = searchnode(p, number);
	printf("\n%d", position);
	int next = searchnext(p, position,number);
	printf("\n%d", next);
}

void xianshi(link* p)
{
	link* temp=p;
	while (temp->next!= NULL)
	{
		temp = temp->next;
		printf("%d ", temp->data);
	}
}

link* fanxu(link* p)
{
	int i = 0;
	link* temp[3] = { p,p->next,p->next->next };
	while (temp[0]->next != NULL && temp[1]->next != NULL && temp[2]->next != NULL)
	{
		temp[(i + 1) % 3]->next = temp[i % 3];
		temp[i % 3] = temp[(i + 2) % 3]->next;
		i++;
	}
	temp[(i + 1) % 3]->next = temp[i % 3];
	temp[(i + 2) % 3]->next = temp[(i+1) % 3];
	p->next->next = NULL;
	p= NULL;
	return temp[(i + 2) % 3];
 }

int searchnode(link* p,int a)
{
	int n = 1;
	link* temp = p;
	while (temp != NULL)
	{
		if (temp->data == a)
		{
			return n;
		}
		else
		{
			temp = temp->next;
			n++;
		}
	}
	return -1;
}

int searchnext(link* p, int a,int x)
{
	link* temp = p;
	int n = a+1;
	for (int i = 1; i <= a; i++)
	{
		temp = temp->next;
	}
	while (temp != NULL)
	{
		if (temp->data == x)
			return n;
		else
		{
			temp = temp->next;
			n++;
		}
	}
	return -1;
}
// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
