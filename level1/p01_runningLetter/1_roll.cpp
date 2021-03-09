#include<stdio.h>
#include<string.h>
#include<windows.h>
using namespace std;
char c[]="zly yyds!!!";
int main(){
	system("mode con cols=80 lines=3");
	//change width and high
	int N=80;
	int x=0,d1=1,d2=1;
	int L=strlen(c);
	int color = 0;
	HANDLE  hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	system("title zly yyds!!!");
	while(1){
		for(int i=0;i<x;i++){
			printf(" ");
		}
		puts(c);
		x+=d1;
		if(x+L>=N)
			d1=-1;
		if(!x)
			d1=1;
		color+=d2;
		SetConsoleTextAttribute(hConsole,color);
		if(color==255)
			d2=-1;
		if(!color)
			d2=1;
		Sleep(200);
		system("cls");
	}
	return 0;
}