#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>

void appendst(void);
void watch(void);
void inserted(int a);
void deleted(int a);
int build(void);
void reverse(void);
void find(int a);

struct node{
	int data;
	struct node* next;
};
struct node* head,*intput,* p,* p1,* p2;

int main(){
	int n;
	build();
	reverse();
	printf("Reverse the Table \n");
	watch();
	printf("Number you want to find:");
	scanf("%d",&n);
	find(n);
}

int build(void){
	 head = (struct node*)malloc(sizeof(struct node));
	 head->next = NULL;
	 char a;
	 int b;

	 while(1){
	 	printf("1:append\n2:watch\n3:insert\n4:delete\n5:finshing the table\n");
	 	a = getche();
	 	system("cls");
	 	switch(a){
	 		case '1':
	 			appendst();
	 			break;
	 		case '2':
	 			watch();
	 			break;
	 		case '3':
	 			printf("Palce:");
	 			scanf("%d",&b);
	 			inserted(b);
	 			break;
	 		case'4':
	 			printf("Palce:");
	 			scanf("%d",&b);
	 			deleted(b);
	 			break;
	 		case '5':
	 			watch();
	 			return 0;
		 }	 
	}	
}

void reverse(void){
	p=head;
	p1=p->next;
	p2=p1;
	p1=p1->next;
	if(p1->next==NULL){
		p1->next=p2;
		p2->next=NULL;
		head->next=p1;
	}else{
	p=p2;
	p2=p1;
	p1=p1->next;
	p->next=NULL;
	while(p1->next!=NULL){
	p2->next=p;
	p=p2;
	p2=p1;
	p1=p1->next;
	}
	p2->next=p;
	p1->next=p2;
	head->next=p1;
	}
}

void appendst(void){
	
	intput=(struct node*)malloc(sizeof(struct node));
	
	if(intput==NULL){
		printf("Fail\n");
	}
	
	printf("DATA:");
	scanf("%I64d",&intput->data);
	
	p = head;
	
	while(p->next!=NULL){
		p=p->next;	
	}
	p->next = intput;
	intput->next= NULL;
	printf("Succeed\n");
		
}

void watch(void){
	int n=0;
	p = head->next;
	if(p!=NULL){
		while(p!=NULL){
			n++;
			printf("data:%d number:%d\n",p->data,n);
			p=p->next;
			
		}
	}else{
		printf("No Imformation\n");
	}
	
}

void inserted(int a){
	int count = 0;
	intput=(struct node*)malloc(sizeof(struct node));
	
	printf("DATA:");
	scanf("%d",&intput->data);
	p=head;
	while(count!=a){
		p=p->next;
		count++;
	}
	
	intput->next=p->next;
	p->next=intput;
	printf("Succeed\n");
	
}

void deleted(int a){
	int count = 0;
	
	
	p=head;
	while(count!=a-1){
		p=p->next;
		count++;
	}
	
	p->next = p->next->next;
}

void find(int a){
	int count=0;
	int truth=0;
	p = head;
	
	while(p->next!=NULL){
		count++;
		p=p->next;
		if(p->data==a){
			printf("%d\n",count);
			truth=1;
		}	
	}
	if(truth == 0){
		printf("-1\n");
	}
}

