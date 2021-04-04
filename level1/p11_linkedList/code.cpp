#include<bits/stdc++.h>
using namespace std;
bool total,judge;
int cnt,cnt2=1;
queue <int> Q;
typedef struct node 
{
	int data;
	node *next;
}node;
node *Init()
{
	node *head=(node*)malloc(sizeof(node)); //我们需要一个指针找到这片内存 
	head->data=0; //这片内存的第一部分 
	head->next=NULL; //第二部分 
	return head; //返回指向地址的指针
}
void create(node *head,int num)
{
	int i=0;
	node *cur=(node*)head;
	for(int i=0;i<num;i++)
	{
		cin>>cur->data;
		if(i<num-1) //此步旨在确保最后一个节点添加完成后（i==num-1时）不会多生成一个节点 
		{
			cur->next=(node*)malloc((sizeof(node))); //此步为cur自动适配了一块用于储存新node的内存，并把地址记录在next中 
			cur=cur->next; //前往新分配的内存地址，以便继续输入（cur的本质是指针） 
		}
	}
	cur->next=NULL;
	return;
}
void traverse(node *head)
{
	node *cur=(node*)head;
	while(cur)
	{
		cout<<cur->data<<" ";
		cnt++;
		if(cur->data==5&&!judge)
		Q.push(cnt);
		cur=cur->next;
	}
	return;
}
node *reverse(node *head)
{
	node *cur,*pnext,*pprev;
	pprev=(node*)malloc(sizeof(node)); //指向一块新分配的内存 
	pprev->next=head; //把头指针指向的地址给它 
	cur=head; //给当前指针 
	while(cur->next) //还没遍历到NULL之前 
	{
		pnext=cur->next; //先把当前的下一个的地址暂存到pnext 
		cur->next=pnext->next; //再找到当前下一个的下一个的地址，连在当前后面（因为下一个马上要移走了） 
		pnext->next=pprev->next; //在移动之前，先让下一个继承头的后续（因为它本身要充当新的头的后续） 
		pprev->next=pnext; //移动 
	}
	return pprev->next; //头本身是0，返回它后面的第一个 
}
void del(node *head)
{
	node *next;
	node *cur=(node*)head;
	while(cur)
	{
		next=cur->next;
		free(cur);
		cur=next;
	}
	head->next=NULL;
	return;
}
int main()
{
	Init();
	int a;
	cin>>a;
	node *first=Init();
	create(first,a); 
	traverse(first);
	cout<<endl;
	judge=1;
	first=reverse(first);
	traverse(first);
	cout<<endl<<"Serial number: ";
	if(Q.empty())
	cout<<"-1";
	else while(!Q.empty()&&cnt2<=2)
	cout<<Q.front()<<" ",Q.pop(),cnt2++;
	del(first); 
	return 0;
}
