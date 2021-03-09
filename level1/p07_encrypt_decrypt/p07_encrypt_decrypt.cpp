//分别编写“加密”、“解密”函数，输入为任意长度的字符串

#include<bits/stdc++.h>
using namespace std;
string a,b,c;
char make(char a)//127
{
	if(a<5)return a+10;
	if(a<10)return a-5;
	if(a<15)return a-5;
	if(a<45)return a;
	if(a<65)return a+20;
	if(a<85)return a-20;
	if(84<a<127)return a+1;
	return 85;
	
}
char remake(char a)
{
	if(a<5)return a+5;
	if(a<10)return a+5;
	if(a<15)return a-10;
	if(a<45)return a;
	if(a<65)return a+20;
	if(a<85)return a-20;
	if(85<a)return a-1;
	return 127;
}
int main()
{
	cin>>a;
	int l=a.length();
	for(int i=0;i<l;++i)
		b[i]=make(a[i]);
	for(int i=0;i<l;++i)cout<<b[i];
	cout<<endl;
	
	for(int i=0;i<l;++i)
		c[i]=remake(b[i]);
	for(int i=0;i<l;++i)cout<<c[i];
	cout<<endl;
	return 0;
}
