#include<cstdio>
#include<malloc.h>
using namespace std;

typedef struct Linklist{
    int value;
    int order;
    struct Linklist *next;
}Linklist;

Linklist * Linkinit();// set up a Linklist
Linklist * Linkunit(Linklist *list,int value);// 
Linklist * Linkinv(Linklist *p,Linklist *head);
int Linkfind(Linklist *head,int val);

int size;
int main(){
    Linklist *head,*list;
    head=list=Linkinit();
    head->next=list;
    head->order=0;
    printf("Please input the size of the linklist:");
    scanf("%d",&size);
    for(int i=1;i<=size;i++){
        int value;
        scanf("%d",&value);
        list=Linkunit(list,value);
        list->order=i;
    }
    /*list=head;
    for(int i=0;i<size;i++){
        list=list->next;
        printf("%d %d\n",list->order,list->value);
    }
    
    list=head;
    for(int i=0;i<size;i++){
        list=list->next;
        printf("%d %d\n",list->order,list->value);
    }
    //int find;
    //scanf("%d",&find);*/
    head=Linkinv(head->next,head);
    //printf("%p\n",head);
    printf("%d\n",Linkfind(head,5));
    //printf("%p\n",head);
    printf("%d\n",Linkfind(head,5));
    return 0;
}

Linklist * Linkinit(){
    Linklist *p=(Linklist*)malloc(sizeof(Linklist));
    if(p==NULL){
        printf("WRONG");
        return p;
    }
    p->next=NULL;
    return p;
}

Linklist * Linkunit(Linklist *list,int value){
    Linklist *p=(Linklist*)malloc(sizeof(Linklist));
    if(p==NULL){
        printf("WRONG");
        return p;
    }
    p->next=NULL;
    p->value=value;
    list->next=p;
    return p;
}

Linklist * Linkinv(Linklist *p,Linklist *head){
    p->order=size+1-p->order;
	if(p->next!=NULL){
		head=Linkinv(p->next,head);
		p->next->next=p;
	}
	else{
        head->next=p;
        return head;
    }
    if(p->order==size){
        p->next=NULL;
    }
    return head;
}

int ii=0;
int Linkfind(Linklist *head,int val){
    //printf("%d %d %d\n",head->order,head->value,ii++);
    if(ii>100)
    return 0;
    if(head->next==NULL&&head->value!=val){
        return -1;
    }
    else if(head->order<1||head->value!=val){
        return Linkfind(head->next,val);
    }
    head->value=-5;
    return head->order;
}