#include<iostream>
#include<cstdio>
#include<math.h>
#include<stdlib.h>
#include<string.h> 
using namespace std;

void encrypt(char *s){
	int len;
	char chu;
	chu=s[0];
	len=strlen(s);
	for(int i=0;i<len-1;i++){
		s[i]=s[i+1];
	} 
	s[len-1]=chu;
}

void decrypt(char *s){
	int len;
	char mo;
	len=strlen(s);
	mo=s[len-1];
	for(int i=len-1;i>=1;i--){
		s[i]=s[i-1];
	}
	s[0]=mo;
}

int main(){
	char st[1000];
	cin>>st;
	encrypt(st);
	cout<<st<<endl;
	decrypt(st);
	cout<<st;
	return 0;
}
