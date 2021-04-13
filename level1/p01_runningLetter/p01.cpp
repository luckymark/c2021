#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<windows.h>

int main(){
	int h=80,w=5;
	char chCmd[32];
	sprintf(chCmd,"mode con cols=%d lines=%d",h,w);
	system(chCmd);
	char ch[30]="cls txdy!!!";
	int d=h-strlen(ch),x=0,t=0;
	//printf("%d",c);
	while(true){
		for(int i=0;i<t;i++){
			printf(" ");
		}
		printf("%s",ch);
		Sleep(300);
		system("cls");
		x++;
		if(x>d&&x<2*d){
			t=2*d-x;
		}
		else if(x==2*d){
			x=0;
			t=0;
		}
		else
		t=x;
	}
	return 0;
}
