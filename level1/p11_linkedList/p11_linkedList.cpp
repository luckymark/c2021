#include<bits/stdc++.h>
using namespace std;
struct link_node
{
	int data;
	struct link_node *next;
};
int n,x,x_num;
link_node *add_link_list(link_node *q,int x);
void Link_traverse(link_node *p);
link_node *Link_reverse(link_node *p);
void find_num_in_list(link_node *p,int num);
void delete_link(link_node *p);
int main()
{
	cin>>n;
	link_node *p = (link_node *)malloc(sizeof(link_node));
	if(p == NULL)
	{
		printf("error\n");
		return 0;
	}
	p = NULL;
	while(n--)
	{
		cin>>x;
		p = add_link_list(p,x);
	}
	Link_traverse(p);
	p = Link_reverse(p);
	Link_traverse(p);
	cin>>n;
	while(n--)
	{
		cin>>x;
		find_num_in_list(p,x);
	}
	delete_link(p); 
	return 0;
 } 
 link_node *add_link_list(link_node *q,int x)
{
	link_node *p = (link_node *)malloc(sizeof(link_node));
	if(p == NULL)
	{
		printf("error\n");
		return NULL;
	}
	link_node *pr ;
	pr = q;
	if(q == NULL) q = p;
	else
	{
	    while(pr->next != NULL) pr = pr->next;
	    pr->next = p;
    }
	p->data = x;
	p->next = NULL;
	
	return q;
}
void Link_traverse(link_node *p)
{
	while(p != NULL)
	{
		cout<<p->data<<" ";	
		p = p->next;
	}
	cout<<endl;
}
link_node *Link_reverse(link_node *p)
{
	link_node *pr,*la,*np;
	np = p ;
	pr = NULL;
	la = np->next;
	while( np != NULL )
	{
		np->next = pr;
		pr = np;
		np = la;
		if( la != NULL )
		{
			la = la->next;
		}
	}
	p = pr;
	return p;
}
void find_num_in_list(link_node *p,int num)
{
	int j=1;
	bool flag = 0;
	while(p != NULL)
	{
		if( p->data == num )
		{
			flag = 1;
			cout<<j<<" ";
		}
		p = p->next;
		j++;
	}
	if( flag == 0)
	{
		cout<<-1;
	}
	cout<<endl;
}
void delete_link(link_node *p)
{
	link_node *pr = p;
	while(p != NULL)
	{
		p = pr->next;
		free(pr);
	}
	return ;
}
