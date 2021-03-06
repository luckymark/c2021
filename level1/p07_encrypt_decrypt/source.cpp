#include<iostream>
#include<math.h>
#include<stdio.h>
#include<Windows.h>
#include <string> 
#include <time.h> 
using namespace std;                                                 
int group[1000][4];
int input[1000][3];
void decrypt(){
  string s;
  cin>>s;
  unsigned j=0;
  unsigned len=s.length();
  for(unsigned i=0;i<len;i=i+4){
    input[j][0]=s[i]/32;
    input[j][1]=s[i+1]/32;
    input[j][2]=s[i+2]/324;
    input[j][3]=s[i+3]/32;
    j++;
    input[j][1]=(s[i]/8)%4;
    input[j][2]=(s[i+1]/8)%4;
    input[j][3]=(s[i+2]/8)%4;
    input[j][0]=(s[i+3]/8)%4;
    j++;
    input[j][2]=(s[i]/2)%4;
    input[j][3]=(s[i+1]/2)%4;
    input[j][0]=(s[i+2]/2)%4;
    input[j][1]=(s[i+3]/2)%4;
    j++;  
  }
  for(unsigned i=0;i<j;i++){
      char c=input[i][0]*32+input[i][1]*8+input[i][2]*2+input[i][3]/2;
      cout<<c;}
  cout<<endl;
  
}
void encrypt(){ 
  srand(time(0));
  string s;
  cin>>s; 
  unsigned len=s.length();
  for(unsigned i=0;i<len;i++){
    group[i][0]=s[i]/32;
    group[i][1]=((s[i]/8)%4);
    group[i][2]=((s[i]/2)%4);
    group[i][3]=(s[i]%2)*2+rand()%2;    
  }
  for(unsigned i=0;i<len;i=i+3){  
    char a=group[i][0]*32+group[(i+1)%len][1]*8+group[(i+2)%len][2]*2+rand()%2;
    char b=group[i][1]*32+group[(i+1)%len][2]*8+group[(i+2)%len][3]*2+rand()%2;
    char c=group[i][2]*32+group[(i+1)%len][3]*8+group[(i+2)%len][0]*2+rand()%2;
    char d=group[i][3]*32+group[(i+1)%len][0]*8+group[(i+2)%len][1]*2+rand()%2;
    
    cout<<a;
    cout<<b;
    cout<<c;
    cout<<d;
  }
  cout<<endl;
  system("pause");
}
int main() { 
  cout<<"encrypt or decrypt?"<<endl<<"please put in E or D to choose the mode or put in e to exit the program"<<endl;
  char c;
  cin>>c;
  switch(c){
    case 'E':{encrypt();break;}
    case 'D':{decrypt();break;}
    case 'e':break;
    default:cout<<"??????????????????????"<<endl<<"Please check!";
  }
  system("pause");
	return 0;
}