#include <bits/stdc++.h>
#include <windows.h>

using namespace std;

const int N=70;

int main(){
	system("cls");
	int x=0,d=1;
	while(1){
		for(int i=0;i<x;++i)putchar(' ');
		puts("LJJ AK IOI");
		Sleep(500);
		system("cls");
		x+=d;
		if(x==N)d=-1;
		if(x==0)d=1;
	}
}