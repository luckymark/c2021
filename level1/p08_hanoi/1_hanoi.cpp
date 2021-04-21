#include<stdio.h>
#include<iostream>
using namespace std;
int tot;
void hanoi(int n,char a,char b,char c){
	if(n==1){
		printf("%d:%c->%c\n",n,a,c);
		tot++;
		return;
	}
	hanoi(n-1,a,c,b);
	printf("%d:%c->%c\n",n,a,c);
	tot++;
	hanoi(n-1,b,a,c);
}
int main(){
	int n;
	scanf("%d",&n);
	hanoi(n,'A','B','C');
	printf("Times:%d",tot);
	return 0;
}