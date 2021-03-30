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
		Node* prev;
	}*head, *tail;
	
	List(){
		head = (Node *)malloc(sizeof(Node));
		tail = (Node *)malloc(sizeof(Node));
		tail -> prev = head;
		head -> next = tail;
	}

	inline Node* push_back(const int &x){
		Node *NewNode = (Node *)malloc(sizeof(Node));
		assert(NewNode);
		NewNode -> prev = tail -> prev;
		tail -> prev -> next = NewNode;
		NewNode -> next = tail;
		tail -> prev = NewNode;
		NewNode -> val = x;
		return NewNode;
	}

	inline Node* push_front(const int &x){
		Node *NewNode = (Node *)malloc(sizeof(Node));
		assert(NewNode);
		NewNode -> next = head -> next;
		head -> next -> prev = NewNode;
		NewNode -> prev = head;
		head -> next = NewNode;
		NewNode -> val = x;
		return NewNode;
	}

	inline void erase(Node *x){
		x -> prev -> next = x -> next;
		x -> next -> prev = x -> prev;
		free(x);
	}

	inline void pop_back(){
		if(tail -> prev != head)erase(tail -> prev);
	}

	inline void pop_front(){
		if(head -> next != tail)erase(head -> next);
	}

	inline Node* insert(const int &ID, const int &x){
		Node *ptr = head;
		for(int i = 1; i < ID; ++i){
			if(ptr -> next != tail){
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
		if(ptr == tail || !ptr)return NULL;
		while(ptr -> val != x){
			if(ptr -> next != tail){
				ptr = ptr -> next;
			}
			else return NULL;
		}
		return ptr;
	}

	inline Node* find_prev(Node *ptr, const int &x){
		if(ptr == head || !ptr)return NULL;
		while(ptr -> val != x){
			if(ptr -> prev != head){
				ptr = ptr -> prev;
			}
			else return NULL;
		}
		return ptr;
	}

	inline Node* find_front(const int &x){
		return find_next(head, x);
	}

	inline Node* find_back(const int &x){
		return find_prev(tail, x);
	}

	inline void erase_val(const int &x){
		Node *ptr = head;
		while(ptr -> next != tail){
			if(ptr -> next -> val == x){
				erase(ptr -> next);
			}
			ptr = ptr -> next;
		}
	}

	inline void erase_ID(const int ID){
		Node *ptr = head;
		for(int i = 0; i < ID; ++i){
			if(ptr -> next != tail){
				ptr = ptr -> next;
			}
			else {
				return ;
			}
		}
		erase(ptr);
	}

	inline void visit(){
		Node *ptr = head;
		while(ptr -> next != tail){
			ptr = ptr -> next;
			printf("%d ",ptr -> val);
		}
		puts("");
	}
}List;

int main(){
	// freopen(".in","r",stdin);
	// freopen(".out","w",stdout);
	List.push_back(3);
	List.push_back(4);
	List.push_front(2);
	List.push_front(1);
	List.visit();
	List.erase_ID(3);
	List.visit();
	List.push_back(1);
	List.insert(2, 1);
	List.visit();
	List.pop_back();
	List.pop_front();
	List.visit();
	List.erase_val(1);
	List.visit();
	return 0;
}