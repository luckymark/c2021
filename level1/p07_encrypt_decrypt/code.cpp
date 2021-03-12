#include<bits/stdc++.h>
using namespace std;
string a;
long long n,o;
int p,q,e,d,store[1000],b[1000],prime[21]={101,103,107,109,113,127,131,137,139,149,151,157,163,167,173,179,181,191,193,197,199},prime2[16]={211,223,227,229,233,239,241,251,257,263,269,271,277,281,283,293};
int Pow(int a1,int a2)
{
	int i=a1,j=a2,k=1;
	while(j)
	{
		if(j&1)
		k*=i,k%=n;
		i*=i,i%=n;
		j>>=1;
	}
	return k;
}
int Pow2(int a1,int a2)
{
	int i=a1,j=a2,k=1;
	while(j--)
	k*=i,k%=n;
	return k;
}
void Encrypt(string a)
{
	cout<<"Encrypting...";
	srand(time(0));
	p=prime[rand()%21];
	q=prime[rand()%21];
	e=prime2[rand()%16];
	n=p*q;
	o=(p-1)*(q-1);
	for(d=1;1;d++)
	if((d*e)%o==1)
	break;
	for(int i=0;i<a.length();i++)
	b[i]=Pow(int(a[i]),e);
	cout<<endl<<"The encrypted text:"<<endl;
	cout<<d<<" "<<n<<" ";
	for(int i=0;i<a.length()-1;i++)
	cout<<b[i]<<" ";
	cout<<b[a.length()-1]<<endl;
	system("pause");
	return;
}
void Decrypt()
{
	cout<<"Decrypting...";
	int i=-1;
	cout<<endl<<"The decrypted text:"<<endl;
	while(store[++i])
	cout<<char(Pow(store[i],d));
	cout<<endl;
	system("pause");
	return;
}
int main()
{
	system("title Encrypt Decrypt");
	string b;
	cout<<"What do you want to do next?"<<endl;
	cout<<"1.Text Encryption"<<endl;
	cout<<"2.Text Decryption"<<endl;
	cout<<"Please enter the corresponding number and press Enter:";
	getline(cin,b);
	while(b!="1"&&b!="2")
	{
		cout<<"Invalid input!"<<endl<<"Please enter the corresponding number and press Enter:";	
		getline(cin,b);
	}
	if(b=="1")
	{
		cout<<"Please enter the text you want to encrypt and press Enter:";
		getline(cin,a);
		Encrypt(a);
	}
	else if(b=="2")
	{
		char c;
		int i=0;
		cout<<"Please enter the text you want to decrypt and press Enter:";
		cin>>d;
		getchar();
		cin>>n;
		getchar();
		cin>>store[0];
		while(c=getchar()!='\n')
		cin>>store[++i];
		Decrypt();
	}
	return 0;
}
