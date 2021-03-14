#include<iostream>
#include<stdio.h>
#include<cstdlib>
#include<time.h>
#include<string>
using namespace std;

int a;
const int g=127-32;
//use char from 32(space) to 126`

void encrypt(string &s){
    for(int i=0;s[i]!='\0';i++){
        s[i]=(s[i]-32+a)%g+32;
    }
    return;
}
void decrypt(string &s){
    for(int i=0;s[i]!='\0';i++){
        s[i]=(s[i]-32+g-a)%g+32;
    }
    return;
}
int main(){
    srand(time(0));
    //time(0) return the seconds from 1970 UTC Jan 1 00:00 to now
    while(!a)
    a=rand()%g;
    printf("Input a string:");
    string s;
    cin>>s;
    encrypt(s);
    cout<<"The encrypt string:"<<s<<endl;
    decrypt(s);
    cout<<"The dectypt string:"<<s;
    return 0;
}