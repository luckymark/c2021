#include<bits/stdc++.h>

using namespace std;

#define gc c=getchar()
#define r(x) read(x)
#define ll long long

template<typename T>
inline void read(T &x){
	x=0;T k=1;char gc;
	while(!isdigit(c)){if(c=='-')k=-1;gc;}
	while(isdigit(c)){x=x*10+c-'0';gc;}x*=k;
}

const int N=1e7+5;

int delta;

inline char encrypt(const char &c){
	return (c+delta-32)%(127-32)+32;
}

inline char decrypt(const char &c){
	return (c-delta-32+(127-32))%(127-32)+32;
}

int main(){
	// freopen(".in","r",stdin);
	// freopen(".out","w",stdout);
	srand(time(NULL));
	while(!(delta=rand()%(127-32)));
	string s;
	cin>>s;
	puts("The original string is:");
	for(int i=0;s[i];++i){
		putchar(s[i]);
	}
	puts("");
	puts("The encrypted string is:");
	for(int i=0;s[i];++i){
		putchar(s[i]=encrypt(s[i]));
	}
	puts("");
	puts("The decrypted string is:");
	for(int i=0;s[i];++i){
		putchar(s[i]=decrypt(s[i]));
	}
	puts("");
	return 0;
}