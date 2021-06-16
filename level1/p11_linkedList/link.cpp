#include<stdio.h>
#include<stdlib.h>

struct Link* init(void);
struct Link* inverse3(struct Link*head);
void print(struct Link * head);
void search(struct Link*head);
struct Link* append(struct Link*head,int location,int data);
void menu(struct Link* head);

struct Link
{
	int data;
	struct Link*next;
};

struct Link* init(void)
{
	struct Link* head=NULL,*p1,*p2;
	p1=p2=(Link*)malloc(sizeof(struct Link));
	int n=0,temp=1;
	while(1)
	{
		n=n+1;
		scanf("%d",&temp);
		if(temp!=0)
		{
			p1->data=temp;
		}
		else
		break;
		if(n==1)
		{
			head=p1;
		}
		else
		{
			p2->next=p1;
		}
		p2=p1;
		p1=(Link*)malloc(sizeof(struct Link));
	}
	p2->next=NULL;
	return(head);
}

void print(struct Link * head)
{
	struct Link* p=head;
	int i=1;
	while(p!=NULL)
	{
		
		printf("the %d num is %d\n",i,p->data);
		p=p->next;
		i++;
	}
	return;
}

struct Link* append(struct Link*head,int location,int data)
{
	if(location>1)
	{
		struct Link* p1=head;
		for(int i=1;i<location-1;++i)
		{
			p1=p1->next;
		}
		struct Link* new_node=(struct Link*)malloc(sizeof(struct Link));
		struct Link* temp=p1->next;
		new_node->data=data;
		new_node->next=temp;
		p1->next=new_node;
		return head;
	}
	else if(location==1)
	{
		struct Link* temp=head;
		struct Link* p1=head;
		temp->data=data;
		temp->next=p1->next;
		return temp;
	}
	else
	{
		printf("the wrong location\n");
		return NULL;
	}
}

struct Link* inverse1(struct Link*head)
{
	struct Link* former=NULL,*mid=head,*latter=head->next;
	while(latter!=NULL)
	{
		mid->next=former;
		former=mid;
		mid=latter;
		latter=latter->next;
	}
	mid->next=former;
	head=mid;
	return head;
}

struct Link* inverse2(struct Link*head)
{
	struct Link* new_head=NULL,*temp=NULL;
	if(head==NULL||head->next==NULL)
	return head;
	while(head!=NULL)
	{
		temp=head;
		head=head->next;
		temp->next=new_head;
		new_head=temp;
	}
	return new_head;
}

struct Link* inverse3(struct Link*head)
{
	struct Link*beg=NULL,*end=NULL;
	if(head==NULL||head->next==NULL)
	return head;
	beg=head;
	end=beg->next;
	while(end!=NULL)
	{
		beg->next=end->next;
		end->next=head;
		head=end;
		end=beg->next;
	}
	return head;
}

void search(struct Link*head)
{
	struct Link* p=head;
	int flag=1,i=1;
	while(p!=NULL)
	{
		if(p->data==5)
		{
			printf("the %d th num of 5 is on %d\n",flag,i);
			flag++;
		}
		i++;
		
		p=p->next;
	}
	if(flag==1)
	printf("there is no 5 in this list");
	return;
}

void menu(struct Link* head)
{
	printf("\n");
	printf("choose the function you want to do:\n");
	printf("press 1 to append a number in a certain place\n");
	printf("press 2 to inverse the list\n");
	printf("press 3 to search all '5' in the list\n");
	printf("\n");
	int m;
	scanf("%d",&m);
	switch(m)
	{
		case 1:
			{
				printf("enter the appending number\n");
				int apdata,location;
				scanf("%d",&apdata);
				printf("enter the its location:\n");
				scanf("%d",&location);
				head=append(head,location,apdata);
				print(head);
				printf("\n");
				system("pause");
				break;
			}
		case 2:
			{
				head=inverse1(head);
				printf("the inversed list is:\n");
				print(head);
				break;
			}
		case 3:
			{
				search(head);
				break;
			}
		default:
			printf("error!\t enter the right number\n");
			break;
	}
}
int main()
{
	printf("enter the number you want to init in the list(enter 0 as the last number to quit)\n");
	struct Link* head=init();
	print(head);
	menu(head);
	return 0;
}
