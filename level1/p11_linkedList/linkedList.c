#include<stdio.h>
#include<stdlib.h>
#include<string.h>

 struct Node* head= NULL;
 struct Node* end= NULL;
 int k=0;
 struct Node
 {
 	int a;
 	struct Node* next;
 };
 
 void addend(int a);
 struct Node*findnode(int a);
 void Scanlist();
 void addmiddle(int a,int b);
 struct node*reverse();
 
  int main()
 {
 	struct Node*pfind;
 	for(int i=0;i<6;i++)
 	addend(i);
 	Scanlist();
 	reverse();
 	Scanlist();
 	pfind=findnode(5);
 	if(pfind!=NULL){
 		printf("%d",k);
	 }
	else{
	 	printf("-1");
	 }
 	return 0;
 }
 
 void addend(int a)
 {
 	struct Node*temp=(struct Node*)malloc(sizeof(struct Node));
 	temp->a=a;
 	temp->next=NULL;
 	if(head==NULL){
 		head=temp;
	 }
	else end->next=temp;
	end=temp;
 }
 
struct Node* findnode(int a)
{
	struct Node* temp=head;
	while (temp!=NULL){
		if(temp->a==a){
			return temp;
		}
		k+=1;
		temp=temp->next;
	}
		return NULL;
}

void Scanlist()
{
	struct Node* temp=head;
	while (temp!=NULL){
		printf("%d\n",temp->a);
		temp=temp->next;
	}
}
 
void addmiddle(int a,int b)
{
	if(head==NULL){
		printf("-1");
		return ;
	}
	struct Node* findout=findnode(b);
	if(findout==NULL){
		printf("-1");
		return ; 
	}
	struct Node* temp=(struct Node*)malloc(sizeof(struct Node));
	temp->a=a;
	temp->next=NULL;
	if(findout==end){
		end->next=temp;
		end=temp;
	}
	else{
		temp->next=findout->next;
		findout->next=temp;
	}
	
}
 
 struct node*reverse()
 {
 	struct Node*tmp1=NULL;
 	struct Node*tmp2;
 	while(head!=NULL){
	 tmp2=head->next;
	 head->next=tmp1;
	 tmp1=head;
	 head=tmp2;
	 }
	 head=tmp1;
 }
 

 
 
 
