#include<bits/stdc++.h>
using namespace std;
int prime[101]={0,2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97};
bool devided[101];
int main(){
    memset(devided,0,sizeof(devided));
    for(int i=1;i<=25;i++)
        for(int j=i;j<=25;j++)
            devided[prime[i]+prime[j]]=true;
    for(int i=4;i<=100;i+=2)
        if(devided[i]==false){
            cout<<i;
            cout<<"false";
            return 0;
        }
    cout<<"true";
    return 0;
}