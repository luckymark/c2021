#include<bits/stdc++.h>
using namespace std;
bool judge(int x){
    int ans=0,p=x;
    while(p>0){
        int k=p%10,pp=1;
        for(int i=1;i<=3;i++)pp*=k;
        ans+=pp;
        p/=10;
    }
    if(ans==x)return true;
    else return false;
}
int main(){
    for(int i=100;i<=999;i++)
        if(judge(i))cout<<i<<' ';
    return 0;
}
