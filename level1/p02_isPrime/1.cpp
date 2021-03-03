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

int main(){
	// freopen(".in","r",stdin);
	// freopen(".out","w",stdout);
	int n;r(n);
	if(n<=1)return puts("No"),0;
	for(int i=2;(ll)i*i<=n;++i){
		if(n%i)continue;
		return puts("No"),0;
	}
	return puts("Yes"),0;
}