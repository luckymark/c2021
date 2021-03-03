#include<bits/stdc++.h>

using namespace std;

#define gc c=getchar()
#define r(x) read(x)
#define ll long long

template<typename T>
inline void read(T&x){
	x=0;T k=1;char gc;
	while(!isdigit(c)){if(c=='-')k=-1;gc;}
	while(isdigit(c)){x=x*10+c-'0';gc;}x*=k;
}

int tot;

inline void move(int x,char from,char to){
	printf("No.%d : Move the No.%d disk from %c to %c\n",++tot,x,from,to);
}

void dfs(int x,char a,char b,char c){
	if(!x)return ;
	dfs(x-1,a,c,b);
	move(x,a,c);
	dfs(x-1,b,a,c);
}

int main(){
	// freopen(".in","r",stdin);
	// freopen(".out","w",stdout);
	puts("Please input the number of disk:");
	int n;
	for(r(n);n>20||n<1;r(n)){
		puts(n>20?"There are too many steps":"The input is not valid");
		puts("Please input the number of disk:");
	}
	dfs(n,'A','B','C');
	return 0;
}