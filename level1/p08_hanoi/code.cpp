#include<bits/stdc++.h>
using namespace std;
int b,c[100],cnt,dig=1;
void Trans(int num,int c1,int c2,int c3)
{
	if(num==1)
	{
		cout<<c1<<" => "<<c3<<endl;
		return;
	}
	Trans(num-1,c1,c3,c2);
	cout<<c1<<" => "<<c3<<endl;
	Trans(num-1,c2,c1,c3);
	return;
}
int main()
{
	system("title Hanoi Problem");
	cout<<"Please enter the amount of the plate:";
	cin>>b;
	c[0]=1;
	for(int i=2;i<=b;i++)
	{
		cnt=-1;
		while(++cnt<dig)
		c[cnt]*=2;
		c[0]+=1;
		cnt=-1;
		while(++cnt<dig)
		c[cnt+1]+=c[cnt]/10,c[cnt]%=10;
		if(c[cnt])
		dig++;
	}
	cout<<"It takes ";
	for(int i=dig-1;i>=0;i--) 
	cout<<c[i];
	cout<<" steps in total. For the detailed procedure, ";
	system("pause");
	cout<<"Note: The three columns are numbered 1,2 and 3. The sign => indicates the transferring direction."<<endl;
	cout<<"The transfer sequence:"<<endl;
	Trans(b,1,2,3);
	return 0;
}
