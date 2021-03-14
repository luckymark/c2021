#include <iostream>
#include <cstdio>
#include <stack>
using namespace std;
int n;
stack<int> a,b,c;

void output(int n, int x, char a, char b){
    printf("%d : %d from %c to %c\n",n,x,a,b);
}

char get_top(char x){
    int tmp;
    if(x == 'a'){
        tmp = a.top();
    } else if(x == 'b'){
        tmp = b.top();
    } else{
        tmp = c.top();
    }
    return tmp;
}

void reverse(char x, char y){
    int tmp;
    if(x == 'a' && y == 'b'){
        tmp = a.top();
        a.pop();
        b.push(tmp);
    }else if(x == 'a' && y == 'c'){
        tmp = a.top();
        a.pop();
        c.push(tmp);
    }else if(x == 'b' && y == 'a'){
        tmp = b.top();
        b.pop();
        a.push(tmp);
    }else if(x == 'b' && y == 'c'){
        tmp = b.top();
        b.pop();
        c.push(tmp);
    }else if(x == 'c' && y == 'a'){
        tmp = c.top();
        c.pop();
        a.push(tmp);
    }else if(x == 'c' && y == 'b'){
        tmp = c.top();
        c.pop();
        b.push(tmp);
    }
}

void solve(int n, char x, char y, char z){
    if(n == 1){
        output(n,get_top(x),x,z);
        reverse(x,z);
        return;
    }
    solve(n-1, x,z,y);
    output(n,get_top(x),x,z);
    reverse(x,z);
    solve(n-1,y,x,z);
}
int main(){
    char x = 'a',y = 'b',z = 'c';
    cin >> n;
    for(int i = n; i >= 1; i --){
        a.push(i);
    }
    solve(n,x,y,z);//
    system("pause");
    return 0;
}
