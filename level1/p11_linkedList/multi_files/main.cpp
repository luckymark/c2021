#include "List.h"

using namespace std;

int main(){
	// freopen(".in","r",stdin);
	// freopen(".out","w",stdout);
	build();
	push_back(3);
	push_back(4);
	push_front(2);
	push_front(1);
	visit();
	erase_ID(3);
	visit();
	push_back(1);
	insert(2, 1);
	insert(4, 2);
	visit();
	reverse();
	visit();
	pop_back();
	pop_front();
	visit();
	erase_val(2);
	visit();
	return 0;
}