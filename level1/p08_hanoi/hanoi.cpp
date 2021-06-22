#include<bits/stdc++.h>
using namespace std;
void move(char from,char to)
{
  printf("%c->%c\n",from,to);
}
void hanoi(int num,char from,char by,char to)
{
  if(1==num){
    move(from,to);
    return;
  }
  hanoi(num-1,from,to,by);
  move(from,to);
  hanoi(num-1,by,from,to);
  return;
}

int main()
{
  int n;
  cin>>n;
  hanoi(n,'a','b','c');
  return 0;
}
