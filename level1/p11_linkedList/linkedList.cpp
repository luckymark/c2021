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

const int N=1e7+7;

struct Node{
	int Val;
	int ID;
	Node* Next;
};

int n;
Node* head;

inline void build(){
	puts("Please input the number of elements");
	r(n);
	printf("Please input the %d elements\n",n);
	Node* lst=NULL;
	for(int i=1;i<=n;++i){
		Node* now=new Node;
		int x;r(x);
		now->Val=x;
		now->ID=i;
		if(lst)lst->Next=now;
		else head=now;
		lst=now;
	}
	lst->Next=NULL;
}

inline void visit(){
	for(auto x=head;x;x=x->Next){
		printf("%d ",x->Val);
	}
	puts("");
}

Node* tail;

void reverse(Node* x){
	x->ID=n+1-x->ID;
	if(x->Next){
		reverse(x->Next);
		x->Next->Next=x;
	}
	else tail=x;
}

Node* Now;

inline int search(int x){
	for(;Now;Now=Now->Next){
		if(Now->Val==x)return Now->ID;
	}
	return -1;
}

int main(){
	// freopen(".in","r",stdin);
	// freopen(".out","w",stdout);
	build();
	puts("List built");
	visit();

	reverse(head);
	head->Next=NULL;
	head=tail;
	puts("List reversed");
	visit();

	puts("searching for the first 5");
	Now=head;
	printf("%d\n",search(5));
	puts("searching for the second 5");
	if(Now)Now=Now->Next;
	printf("%d\n",search(5));
	return 0;
}