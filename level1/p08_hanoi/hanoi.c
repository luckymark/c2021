#include <stdio.h>

void hanoi(int n,char A,char B,char C);
int move(char x,char y);
int i=0;

int main ()
{
	int n;
	scanf("%d",&n);
	hanoi(n,'A','B','C');
	printf("���ƶ�%d��",i);
	return 0;
}

void hanoi(int n,char A,char B,char C)
{
	if(n==1){
		move(A,C);
	} else {
		hanoi(n-1,A,C,B);
		move(A,C);
		hanoi(n-1,B,A,C);
	}	
}

int move(char x,char y)
{
	printf("%c �ƶ��� %c\n",x,y);
	i+=1;
}
