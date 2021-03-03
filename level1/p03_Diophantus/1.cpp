#include<bits/stdc++.h>

using namespace std;

int main(){
	// freopen(".in","r",stdin);
	// freopen(".out","w",stdout);
	for(double x=1;;++x){
		if(x/6+x/12+x/7+5+x/2==x-4){
			return printf("%d\n",int(x)),0;
		}
	}
	return 0;
}