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

const int N=1001;

int tot;
int pri[N];
bool mark[N];

int main(){
	// freopen(".in","r",stdin);
	// freopen(".out","w",stdout);
	clock_t start=clock();
	for(int i=2;i<N;++i){
		if(!mark[i])printf("%d ",pri[++tot]=i);
		for(int j=1,tmp;(tmp=i*pri[j])<N&&j<=tot;++j){
			mark[tmp]=1;
			if(i%pri[j]==0)break;
		}
	}
	puts("");
	clock_t end=clock();
	printf("Time used = %lf s\n",(double)(end-start)/CLOCKS_PER_SEC);
	return 0;
}