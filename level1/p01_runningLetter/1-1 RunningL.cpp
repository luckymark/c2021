#include<iostream>
#include<cstdio>
#include<math.h>
#include<stdlib.h>
#include<string.h> 
using namespace std;

int main(){
	char s[1000];
	int l=20;//?¨ª?¨¨¡ê? 
	int v=5;//?¨´?¨¨¡ê? 
	int a,i;
	bool t=1;
	cin>>s;
	a=strlen(s);
	system("cls");//???¨¢¡ê?
	i=0;
	while(1){
	    for(int j=1;j<=i/v;j++){
	    	printf(" ");
		}
		printf("%s",s);
		if(t){
			i++;
		}	
		else{
			i--;
		}
		if(i>=(l-a)*v){
			t=1-t;
		}
		else if(i<=0){
			t=1-t;
		}
		system("cls");
	}
}
