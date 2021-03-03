#include <bits/stdc++.h>
#include <windows.h>

using namespace std;

const int N=80;
const int M=40;

char s[]="LJJ AK IOI";

int main(){
	system("mode con cols=80 lines=40");
	int n=strlen(s);
	system("cls");
	int x=0,dx=1,y=0,dy=1;
	while(1){
		for(int i=0;i<y;++i)putchar('\n');
		for(int i=0;i<x;++i)putchar(' ');
		puts(s);
		Sleep(200);
		system("cls");
		x+=dx;
		y+=dy;
		if(x==N-n)dx=-1;
		if(x==0)dx=1;
		if(y==M-2)dy=-1;
		if(y==0)dy=1;
	}
}