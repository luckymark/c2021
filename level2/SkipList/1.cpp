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

const int Limit=20;
const int N=1e5+7;
const int INF=(1ll<<31)-1;

struct Node{
	int Level;
	int Key;
	int Val;

	int Next[Limit];
	
}A[N];

int tot,S,T;

inline int NewNode(const int &k,const int &v){
	++tot;
	for(int i=1;i<Limit;++i){
		if(rand()&1)A[tot].Level++;
		else break;
	}
	A[tot].Key=k;
	A[tot].Val=v;
	return tot;
}

inline void build(){
	S=NewNode(-1,0);
	T=NewNode(INF,0);
	A[S].Level=Limit-1;
	A[T].Level=Limit-1;
	for(int i=0;i<Limit;++i)A[S].Next[i]=T;
}

int find(const int &k){
	int x=S;
	int Level=Limit-1;
	while(~Level){
		while(A[A[x].Next[Level]].Key<=k){
			x=A[x].Next[Level];
		}
		--Level;
	}
	if(A[x].Key==k)return A[x].Val;
	return -1;
}

void insert(const int &k,const int &v){
	int x=S;
	int Level=Limit-1;
	while(~Level){
		while(A[A[x].Next[Level]].Key<=k){
			x=A[x].Next[Level];
		}
		--Level;
	}
	if(A[x].Key==k)A[x].Val=v;
	else {
		int y=NewNode(k,v);
		x=S;
		Level=Limit-1;
		while(~Level){
			while(A[A[x].Next[Level]].Key<=k){
				x=A[x].Next[Level];
			}
			if(Level<=A[y].Level){
				A[y].Next[Level]=A[x].Next[Level];
				A[x].Next[Level]=y;	
			}
			--Level;
		}
	}
}

pair<bool,pair<int,int> >Data[N<<1];
const int M=1e5;
int vis[N];

inline void gen(){
	srand(time(0));
	memset(vis,-1,sizeof(vis));
	for(int i=0;i<M;++i)Data[i]={0,{i,rand()}};
	for(int i=0;i<M;++i)Data[M+i]={1,Data[rand()%M].second};
	random_shuffle(Data,Data+(M<<1));
}

int main(){
	// freopen(".in","r",stdin);
	// freopen(".out","w",stdout);
	build();
	gen();
	for(int i=0;i<(M<<1);++i){
		bool opt=Data[i].first;
		int k=Data[i].second.first;
		int v=Data[i].second.second;
		opt?assert(find(k)==(vis[k]|v)):(vis[k]=0,insert(k,v));
	}
	return 0;
}
