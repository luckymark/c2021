#include<iostream>
#include<cstdio>
#include<stdlib.h>
using namespace std;

typedef struct node{
    int data;
    struct node *next;
}node;

void node_append(struct node *newnode,struct node **head);
void node_insert(struct node *newnode,struct node **head,int num);
struct node* node_alter(struct node *aimnode);
int node_search(struct node *aimnode,int n,int num);

int main(){
    struct node *headmain=(struct node*)malloc(sizeof(struct node));
    struct node *c=(struct node*)malloc(sizeof(struct node));
    int a,numb;
    headmain=NULL;
    while(scanf("%d",&a)){
        struct node *c=(struct node*)malloc(sizeof(struct node));
        c->data =a;
        c->next=NULL;
        node_append(c,&headmain);
    }
    struct node *p=(struct node*)malloc(sizeof(struct node));
    struct node *con=(struct node*)malloc(sizeof(struct node));
    con=node_alter(headmain);//反序
    numb=0;
    while(numb!=-1){
        numb=node_search(con,5,numb);//查找
    }
}

void node_append(struct node *newnode,struct node **head){
    struct node *p;
    p=(*head);
    if(p==NULL){
        *head=newnode;
    }
    else if(p->next ==NULL){
        (*head)->next=newnode;
    }
    else{
        p=(*head)->next ;
        node_append(newnode,&p);
    }
}

void node_insert(struct node *newnode,struct node **head,int num){
    struct node *p;
    if(num==0){
        p=(*head)->next;
        (*head)->next=newnode;
        newnode->next=p;
    }
    else{
        node_insert(newnode, &((*head)->next),num-1);
    }
}

struct node* node_alter(struct node *aimnode){
    struct node *p,*after,*temp;
    p=aimnode;
    after=p->next;
    temp=p;
    while(after){
        p=after;
        after=p->next;
        p->next=(aimnode);
        (aimnode)=p;
    }
    temp->next =NULL;
    return p;
}

int node_search(struct node *aimnode,int n,int num){
    int now=1;
    bool find_node=1;
    while(aimnode){
        if(aimnode->data==n&&now>num){
            find_node=0;
            break;
        }
        now=now+1;
        aimnode=aimnode->next;
    }
    if(find_node){
        return -1;
    }
    else{
        return now;
    }
}