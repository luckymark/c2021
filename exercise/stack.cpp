#include<stdio.h>
#include<stdlib.h>
int q[102];
//head:q[0]
//end:q[101]
void push(int a){
    if(q[101]==100){
        printf("the stack is full\n");
        return;
    }
    q[101]++;
    q[q[101]]=a;
    return;
}

void pop(){
    if(q[101]==0){
        printf("the stack is empty\n");
        return;
    }
    q[q[101]]=0;
    q[101]--;
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
}