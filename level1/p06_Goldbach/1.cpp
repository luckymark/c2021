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

const int N=101;

int tot;
int pri[N];
bool mark[N];

int main(){
	// freopen(".in","r",stdin);
	// freopen(".out","w",stdout);
	for(int i=2;i<N;++i){
		if(!mark[i])pri[++tot]=i;
		if(i>2 && !(i&1)){
			bool flag=0;
			for(int j=1;j<=tot;++j){
				if(!mark[i-pri[j]]){
					printf("%d = %d + %d\n",i,pri[j],i-pri[j]);
					flag=1;
					break;
				}
			}
			if(!flag){
				return printf("check failed at %d\n",i),0;
			}
		}
		for(int j=1,tmp;(tmp=i*pri[j])<N&&j<=tot;++j){
			mark[tmp]=1;
			if(i%pri[j]==0)break;
		}
	}
	puts("check finished");
	return 0;
}