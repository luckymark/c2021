//本加密器目前仅支持对26个小写英文字母加密 
#include<bits/stdc++.h>
#include<windows.h>
#include<conio.h>
using namespace std;
string w,mp="qazxswedcvfrtgbnhyujmkiolp";
void enc(void)
{
	for(int i=0;i<w.length();i++)
	{
		w[i]=mp[w[i]-'a'];
	}
}
void dec(void)
{
	for(int i=0;i<w.length();i++)
	{
		w[i]=mp.find(w[i])+'a';
	}
}
int main()
{
	while(1)
	{
		int flag=0;
		cout<<"请输入密文：";
		cin>>w;
		for(int i=0;i<w.length();i++)
		{
			if(w[i]<97 || w[i]>122)
			{
				cout<<endl<<"error";
				Sleep(100);
				system("cls");
				flag=1;
				break;
			}
		} 
		if(!flag)
		{
			system("cls");
			break;
		}
	}
	while(1)
	{
		cout<<"选择加密请按1，选择解密请按2。"<<endl;
		char t=_getch();
		if(t=='1')
		{
			enc();
			break;
		}
		else if(t=='2')
		{
			dec();
			break;
		}
		else
		{
			cout<<endl<<"error";
			Sleep(100);
			system("cls");
		}
	}
	system("cls");
	cout<<"结果为："<<w<<endl; 
	return 0;
}
