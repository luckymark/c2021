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

struct List{
	struct Node{
		int val;
		Node* next;
	}*head;
	
	List(){
		head = (Node *)malloc(sizeof(Node));
	}

	inline void append(const int &x){
		Node *ptr = head;
		while(ptr -> next){
			ptr = ptr -> next;
		}
		ptr -> next = (Node *)malloc(sizeof(Node));
		assert(ptr -> next);
		ptr -> next -> val = x;
	}

	inline Node* insert(const int &ID, const int &x){
		Node *ptr = head;
		for(int i = 1; i < ID; ++i){
			if(ptr -> next){
				ptr = ptr -> next;
			}
			else {
				return NULL;
			}
		}
		Node *NewNode = (Node *)malloc(sizeof(Node));
		assert(NewNode);
		NewNode -> val = x;
		NewNode -> next = ptr -> next;
		return ptr -> next = NewNode;
	}

	inline Node* find_next(Node *ptr, const int &x){
		if(!ptr)return NULL;
		while(ptr -> val != x){
			if(ptr -> next){
				ptr = ptr -> next;
			}
			else {
				return NULL;
			}
		}
		return ptr;
	}

	inline Node* find(const int &x){
		return find_next(head, x);
	}

	inline void erase(Node *x,Node *y){
		x -> next = y -> next;
		free(y);
	}

	inline void erase_val(const int &x){
		Node *ptr = head;
		while(ptr -> next){
			while(ptr -> next && ptr -> next -> val == x){
				erase(ptr, ptr -> next);
			}
			if(ptr -> next){
				ptr = ptr -> next;
			}
		}
	}

	inline void erase_ID(const int ID){
		Node *ptr = head;
		for(int i = 1; i < ID; ++i){
			if(ptr -> next){
				ptr = ptr -> next;
			}
			else {
				return ;
			}
		}
		if(ptr -> next){
			erase(ptr, ptr -> next);
		}
	}

	inline void visit(){
		Node *ptr = head;
		while(ptr -> next){
			ptr = ptr -> next;
			printf("%d ",ptr -> val);
		}
		puts("");
	}
}List;

int main(){
	// freopen(".in","r",stdin);
	// freopen(".out","w",stdout);
	List.append(1);
	List.append(2);
	List.append(3);
	List.append(4);
	List.visit();
	List.erase_ID(3);
	List.visit();
	List.append(1);
	List.insert(2, 1);
	List.visit();
	List.erase_val(1);
	List.visit();
	srand(time(NULL));
	const int N = 10;
	for(int i = 0; i < N; ++i){
		List.append(rand() & 0xffff);
	}
	List.visit();
	for(int i = 0; i < N / 2; ++i){
		List.erase_ID(i);
	}
	List.visit();
	for(int i = 0; i < N / 2; ++i){
		List.insert(i, rand() & 0xffff);
	}
	List.visit();
	for(int i = 0; i < N / 4; ++i){
		List.erase_val(rand() & 0xffff);
	}
	List.visit();
	return 0;
}