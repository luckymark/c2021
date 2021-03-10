#include<bits/stdc++.h>
#include<windows.h>
using namespace std;
int main()
{
	char a;
	int j;
	cout<<"Enter the desired character:";
	cin>>a;
	system("cls");
	while(1)
	{
		for(int i=0;i<=20;i++)
		{
			j=i;
			while(j--)
			cout<<" ";
			cout<<a;
			Sleep(100);
			system("cls");
		}
		for(int i=19;i;i--)
		{
			j=i;
			while(j--)
			cout<<" ";
			cout<<a;
			Sleep(100);
			system("cls");
		}
	}
	return 0;
}
