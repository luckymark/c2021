#include<stdio.h>

int s;

void move(int x,char a,char b){
    printf("Step %d:move plate %d from %c to %c.\n",++s,x,a,b);
    return;
}

void hanoi(int p,char a,char b,char c){
    //move p plates from a to c through b
    if(p==1){
        move(1,a,c);
        return;
    }
    hanoi(p-1,a,c,b);
    move(p,a,c);
    hanoi(p-1,b,a,c);
    return;
}

int main(){
    int p=1;// the number of plates
    do{
        printf("Please input the number of plates:");
        scanf("%d",&p);
        if(p<=1)
        printf("the input is invalid");
    }while(p<=1);
    //Use pillar C as the target pillar
    hanoi(p,'A','B','C');
    printf("End");
    return 0;
}