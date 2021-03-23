/*#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
int q[102];
//head:q[0]
//end:q[101]
void push(int a){
    int ll=q[101]-q[0];
    if(ll<0)
    ll+=100;
    if(ll==99){
        printf("the queue is full");
        return;
    }
    q[101]++;
    if(q[101]==101){
        q[101]=1;
    }
    q[q[101]]=a;
    return;
}

void pop(){
    if(q[q[0]]==0){
        printf("the queue is empty");
        return;
    }
    q[q[0]]=0;
    q[0]++;
    if(q[0]==101){
        q[0]=1;
    }
    return;
}
int main(){
    q[0]=0;
    q[101]=0;
    int t;
    do{
        printf("input 1 to puah a num\n");
        printf("input 2 to pop a num\n");
        printf("input 3 to end\n");
        scanf("%d",&t);
        switch(t){
            case 1:{
                int n;
                scanf("%d",&n);
                push(n);
                break;
            }
            case 2:{
                pop();
                break;
            }
        }
        if(t==3)
        break;    
    }while(true);
    return 0;
}*/

#include<cstdio>
#include<stdlib.h>
using namespace std;

typedef struct Qnode{
    int data;
    struct Qnode *n;
}Qnode;

Qnode * qinit(){
    Qnode *p=(Qnode*)malloc(sizeof(Qnode));
    p->n=NULL;
    return p;
}

Qnode* qpush(Qnode *e,int b){
    Qnode *p=(Qnode*)malloc(sizeof(Qnode));
    p->n=NULL;
    p->data=b;
    e->n=p;
    e=p;
    return e;
}

Qnode* qpop(Qnode * h,Qnode * e){
    if(h->n==NULL){
        printf("The queue is empty");
        return e;
    }  
    Qnode *p=h->n;
    printf("%d\n",p->data);
    h->n=p->n;
    if(p->n==e->n){
        h=e;
    }
    free(p);
    return e;
}
int main(){
    Qnode *h,*e,*q;
    q=h=e=qinit();
    int t;
    do{
        printf("input 1 to puah a num\n");
        printf("input 2 to pop a num\n");
        printf("input 3 to end\n");
        scanf("%d",&t);
        switch(t){
            case 1:{
                int indata;
                scanf("%d",&indata);
                e=qpush(e,indata);
                break;
            }
            case 2:{
                e=qpop(h,e);
                break;
            }
        }
        if(t==3)
        break;    
    }while(true);
    return 0;
}