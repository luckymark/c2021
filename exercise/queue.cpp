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

typedef struct{
    int g;
    qq *n;
}qq;

qq* qinit(int n){
    qq *p;
    p=(qq*)malloc(n*sizeof(qq));
    if(p==NULL){
        printf("Wrong");
        return;
    }
    return p;
}

int main(){
    int n;
    scanf("%d",&n);
    qq *aq=qinit(n);
    qq *h,*e;
    h=e=aq;
    
    return 0;
}