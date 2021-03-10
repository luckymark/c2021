#include<bits/stdc++.h>
using namespace std;
bool fit_(int x){
    if(x%12==0&&x%7==0&&(x-4-(x/12+x/6+x/7+5))*2==x)return true;
    return false;
}
int main(){
    int x;
    for(int i=1;i<=100;i++){
        if(fit_(i)){
            cout<<i-4;
            break;
        }
    }
    return 0;
}