#include<bits/stdc++.h>
using namespace std;
int main()
{
	system("title Diophantus");
	int a=12*7,s1=0,s2=0;
	s2+=a/6;
	s2+=a/12;
	s2+=a/7;
	s2+=a/2;
	s1=a-s1;
	s2+=5;
	s2+=4;
	s2*=a;
	cout<<s2/s1;
	return 0;
} 
