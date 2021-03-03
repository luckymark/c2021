#include <bits/stdc++.h>
#include <windows.h>

using namespace std;

const int N=80;

char s[]="LJJ AK IOI";

int main(){
	system("mode con cols=80");
	int n=strlen(s);
	system("cls");
	int x=0,d=1;
	while(1){
		for(int i=0;i<x;++i)putchar(' ');
		puts(s);
		Sleep(500);
		system("cls");
		x+=d;
		if(x==N-n)d=-1;
		if(x==0)d=1;
	}
}