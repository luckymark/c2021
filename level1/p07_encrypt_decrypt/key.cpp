#include<stdio.h>
#include<algorithm>
#include<time.h>
#include<string.h>
#include<iostream>
using namespace std;
int delta;
inline char encrypt(const char &x){
    return (x+delta-32)%(127-32)+32;
}
//内联函数，不能递归，代码膨胀，但是很快
inline char decrypt(const char &x){
    return (x-32-delta+127-32)%(127-32)+32;
}
int main(){
    srand((unsigned)time(NULL));
    //使用系统时间初始化，防止随机数重复
    while(!(delta=rand()%(127-32)));
    //delta为asc码偏移
    //asc码前32位不代表字符
    string c;
    cin>>c;
    puts("The origin string is:");
    cout<<c;
    puts("");
    puts("The encrypt string is:");
    for(int i=0;c[i];i++){
        putchar(c[i]=encrypt(c[i]));
    }
    puts("");
    puts("The decrypt string is:");
    for(int i=0;c[i];i++){
        putchar(c[i]=decrypt(c[i]));
    }
    return 0;
}