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
	node *head=(node*)malloc(sizeof(node)); //������Ҫһ��ָ���ҵ���Ƭ�ڴ� 
	head->data=0; //��Ƭ�ڴ�ĵ�һ���� 
	head->next=NULL; //�ڶ����� 
	return head; //����ָ���ַ��ָ��
}
void create(node *head,int num)
{
	int i=0;
	node *cur=(node*)head;
	for(int i=0;i<num;i++)
	{
		cin>>cur->data;
		if(i<num-1) //�˲�ּ��ȷ�����һ���ڵ������ɺ�i==num-1ʱ�����������һ���ڵ� 
		{
			cur->next=(node*)malloc((sizeof(node))); //�˲�Ϊcur�Զ�������һ�����ڴ�����node���ڴ棬���ѵ�ַ��¼��next�� 
			cur=cur->next; //ǰ���·�����ڴ��ַ���Ա�������루cur�ı�����ָ�룩 
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
	pprev=(node*)malloc(sizeof(node)); //ָ��һ���·�����ڴ� 
	pprev->next=head; //��ͷָ��ָ��ĵ�ַ���� 
	cur=head; //����ǰָ�� 
	while(cur->next) //��û������NULL֮ǰ 
	{
		pnext=cur->next; //�Ȱѵ�ǰ����һ���ĵ�ַ�ݴ浽pnext 
		cur->next=pnext->next; //���ҵ���ǰ��һ������һ���ĵ�ַ�����ڵ�ǰ���棨��Ϊ��һ������Ҫ�����ˣ� 
		pnext->next=pprev->next; //���ƶ�֮ǰ��������һ���̳�ͷ�ĺ�������Ϊ������Ҫ�䵱�µ�ͷ�ĺ����� 
		pprev->next=pnext; //�ƶ� 
	}
	return pprev->next; //ͷ������0������������ĵ�һ�� 
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
