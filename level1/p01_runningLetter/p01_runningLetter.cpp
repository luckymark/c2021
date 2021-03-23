#include <stdlib.h>
#include <cstdio>
#include <iostream>
#include <iomanip>
using namespace std;
string a,s="";
int main()
{
	cin>>a;
/*	for(int i=1;i<100;++i)
	{
		if(i<10)cout<<"00"<<i;
		else cout<<"0"<<i;
	}*/
	bool f=1;
	int l=a.length();
	for(int i=0;;)
	{
		cout<<setw(i+l)<<a;
		system("cls");
		if(f==1)i++;
		if(i+l>120)f=0;
		if(f==0)i--;
		if(i<1)f=1;
	}
}

