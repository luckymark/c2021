#include<bits/stdc++.h>
#include<windows.h>
using namespace std;
int main()
{
	system("title RunningLetter");
	char a;
	int j;
	cout<<"Enter the desired character:";
	cin>>a;
	system("cls");
	HANDLE hOut;
    CONSOLE_SCREEN_BUFFER_INFO scr;
    hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    GetConsoleScreenBufferInfo(hOut, &scr);
	int I=scr.dwSize.X; 
	while(1)
	{
		for(int i=0;i<I;i++)
		{
			j=i;
			while(j--)
			cout<<" ";
			cout<<a;
			Sleep(10);
			system("cls");
		}
		for(int i=I-2;i;i--)
		{
			j=i;
			while(j--)
			cout<<" ";
			cout<<a;
			Sleep(10);
			system("cls");
		}
	}
	return 0;
}
