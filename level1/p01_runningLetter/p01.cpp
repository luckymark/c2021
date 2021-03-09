#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<windows.h>

int main(){
	system("mode con cols=80 lines=5");
	char ch[30]="cls txdy!!!";
	int d=80-strlen(ch),x=0,t=0;
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
