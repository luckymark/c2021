#include<bits/stdc++.h>
using namespace std;
struct database
{
	string name;
	unsigned long long hashnum;
	int amount;
}table[1001];
int zero,cur,a,total,tmp2;
string tmp;
unsigned long long dig=19260817,cal;
void Menu();
unsigned long long hash(string a)
{
    unsigned long long ans=0;
    int lena=a.length();
    for(int i=0;i<lena;i++)
    ans=ans*dig+(unsigned long long)a[i];
    return ans;
}
void Search(unsigned long long num,int L,int R)
{
	for(int i=0;i<=R;i++)
	if(table[i].hashnum==num)
	cur=i;
	return;
}
void Enquiry(int num)
{
	cout<<"Product Name: "<<table[num].name<<endl;
	cout<<"Currently Amount: "<<table[num].amount<<endl;
	return;
}
void Add()
{
	system("cls");
	cur=-1;
	cout<<"Please enter the product name (Use _ to replace spaces):"<<endl;
	cin>>tmp;
	cal=hash(tmp);
	Search(cal,0,total-1);
	if(cur==-1)
	cur=total,total++;
	table[cur].name=tmp;
	Enquiry(cur);
	cout<<"Please enter the inbound/outbound amount (negative integer indicates outbound):"<<endl;
	cin>>tmp2;
	if(tmp2+table[cur].amount<0)
	{
		cout<<"Insufficient inventory! Please try again:"<<endl;
		cin>>tmp2;
	}
	table[cur].amount+=tmp2;
	table[cur].hashnum=cal;
	cout<<"Done!"<<endl;
	Enquiry(cur);
	system("pause");
	Menu();
	return;
}
void Print()
{
	system("cls");
	for(int i=0;i<total;i++)
	if(table[i].amount)
	cout<<"Product Name: "<<table[i].name<<endl,
	cout<<"Current Amount: "<<table[i].amount<<endl<<endl;
	system("pause");
	Menu();
	return;
}
void Menu()
{
	system("cls");
	cout<<"Please choose one option below:"<<endl;
	cout<<"1. Inbound/Outbound"<<endl;
	cout<<"2. Print List"<<endl;
	cout<<"3. Exit"<<endl;
	cin>>a;
	if(a==1) Add();
	else if(a==2) Print();
	else if(a==3) return;
	else cout<<"Invalid Input!"<<endl,system("pause"),Menu();
	return;
}

int main()
{
	system("title Microsoft Access 1.0");
	ifstream in("index.mdb");
	in>>total;
	for(int i=0;i<total;i++)
	{
		in>>table[i].name;
		in>>table[i].hashnum;
		in>>table[i].amount;
	}
	Menu();
	for(int i=0;i<total;i++)
	if(!table[i].amount) zero++;
	ofstream out("index.mdb");
	out<<total-zero<<endl;
	for(int i=0;i<total;i++)
	if(table[i].amount)
	out<<table[i].name<<" "<<table[i].hashnum<<" "<<table[i].amount<<endl;
    return 0;
}
