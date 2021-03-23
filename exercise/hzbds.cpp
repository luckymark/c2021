#include<cstdio>
#include<iostream>
#include<stack>
using namespace std;
typedef long long ll;

int main(){
	stack<ll> s;
	char ch=getchar(); 
	while(ch!='@'){
		//printf("111\n");
		ll a=0;
		while(ch>='0'&&ch<='9'){
			a=10*a+ch-'0';
			ch=getchar();
		}
		//printf("%lld\n",a);
		if(a!=0)
		s.push(a);
		//printf("444\n");
		if(ch==','){
			ch=getchar();
			continue;
		}
		//printf("333\n");
		ll c=s.top();
		s.pop();
		ll b=s.top();
		s.pop();
		//printf("%lld %lld\n",b,c);
		switch(ch){
			case '+':{
				s.push(b+c);
				break;
			}
			case '-':{
				s.push(b-c);
				break;
			}
			case '*':{
				s.push(b*c);
				break;
			}
			case '/':{
				s.push(b/c);
				break;
			}
			default:{
                break;
            }
		}
		ch=getchar();
		//printf("222\n");
	}
	ll ans=s.top();
	printf("%lld",ans);
	return 0;
}