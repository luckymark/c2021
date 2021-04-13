#include<bits/stdc++.h>
using namespace std;
struct Node
{
	int key;
	Node*next;
};
void append(Node*head,Node*newnode)
{
	Node*p;
	p=head;
	while(1)
	{
		if(p->next==NULL)
		{
			p->next=newnode;
			break;
		}
		p=p->next;
	}
}
void _delete(int n,Node*head)
{
	Node*p,*q;
	p=q=head;//不要忘记初始化； 
	for(int i=1;i<n;i++)
	{
		if(p==NULL)
		{
			cout<<"error"<<endl;
			return;
		}
		p=p->next;
		if(i<n-1) q=q->next;
	}
	q->next=p->next;
	free(p);
}
void insert(int n,Node*head,Node*newone)//指插入在第n位的后面 ;
{
	Node*p=head;
	for(int i=1;i<n;i++)
	{
		p=p->next;
	}
	newone->next=p->next;
	p->next=newone;
}
Node*reverse(Node*head)
{
	Node*n,*p,*q;
	n=head;
	p=head->next;
	if(p==NULL) return head;
	q=p->next;
	while(p!=NULL)
	{
		p->next=n;
		n=p;
		p=q;
		if(q!=NULL) q=q->next; //不能让q“越界”； 
	}
	head->next=NULL;
	return n;
} 
int main()
{
	Node*head;
	head=(Node*)malloc(sizeof(Node));
	if(head==NULL)
	{
		cout<<"error"<<endl;
		return 0;
	}
	
	int v;
	cin>>v;
	*head=(Node){v,NULL};
	while(1)
	{
		cin>>v;
		if(v==-1) break;
		Node*p;
		p=(Node*)malloc(sizeof(Node));
		if(p==NULL)
		{
			cout<<"error"<<endl;
			return 0;
		}
		*p=(Node){v,NULL};
		append(head,p);
	}
	
	Node*p=head;
    while(p!=NULL)
	{
		cout<<p->key<<" ";
		p=p->next;
	}
	cout<<endl;
	
	head=reverse(head);
	p=head;
	while(p!=NULL)
	{
		cout<<p->key<<" ";
		p=p->next;
	}
	cout<<endl;
	
	p=head;
	int flag=0;
	for(int i=1;p!=NULL;i++)
	{
		if(p->key==5)
		{
			cout<<i<<endl;
			flag=1;
		}
		p=p->next;
	}
	if(flag==0) cout<<-1<<endl;
	
/*用于测试_delete函数	
	_delete(2,head);
	p=head;
	while(p!=NULL)
	{
		cout<<p->key<<endl;
		p=p->next;
	} */
	
/*用于测试insert函数 
	Node*t;
	int m;
	t=(Node*)malloc(sizeof(Node));//不要忘了用malloc给t分配内存！ 
	cin>>m>>v;
	*t=(Node){v,NULL};
	insert(m,head,t);
	p=head;
	while(p!=NULL)
	{
		cout<<p->key<<endl;
		p=p->next;
	} */
	
//接下来是释放所有用malloc请求的内存 
	p=head;
	while(p!=NULL)
	{
		Node*q=p->next;
		free(p);
		p=q;
	}
	return 0;
}
