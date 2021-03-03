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

inline int cube(const int &x){
	return x*x*x;
}

inline bool check(int x){
	int t=x;
	while(t){
		x-=cube(t%10);
		t/=10;
	}
	return !x;
}

int main(){
	// freopen(".in","r",stdin);
	// freopen(".out","w",stdout);
	for(int i=100;i<=999;++i){
		if(check(i))printf("%d ",i);
	}
	puts("");
	return 0;
}