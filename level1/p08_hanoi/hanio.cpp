#include<stdio.h>
int main()
{
    int n;
    char A='A',B='B',C='C';
    printf("enter the number of plate you want to move:\n");
    void hanio(int n,char a,char b,char c);
    scanf("%d",&n);
    hanio(n,A,B,C);
    return 0;
}


void hanio(int n,char a,char b,char c)
{
    void move(char a,char b);
    if(n==1)
    {
        move(a,c);
    }
    else
    {
        hanio(n-1,a,c,b);
        move(a,c);
        hanio(n-1,b,c,a);
    }
}

void move(char a,char b)
{
    printf("%c -> %c\n",a,b);
}
