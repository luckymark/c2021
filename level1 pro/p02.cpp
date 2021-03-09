#include<bits/stdc++.h>
using namespace std;
bool is_prime(int k){
    if(k==1||k==0)return false;
    for(int i=2;i<=sqrt(k);++i){
        if(k%i)continue;
        else return false;
    }
    return true;
}
int main(){
    int n;
    cin>>n;
    if(is_prime(n))cout<<"True";
    else cout<<"False";
    return 0;
}