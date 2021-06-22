#include<bits/stdc++.h>
using namespace std;
void encrypt(char *s)
{
  while(*s){
    *s=*s+3;
    s++;
  }
}
void decrypt(char *s)
{
  while(*s)
  {
    *s=*s-3;
    s++;
  }
}
int main()
{
  printf("Input 1 to encrypt a string\n");
  printf("Input 2 to decrypt a string\n");
  printf("Input 0 to exist\n");
  int a;
  cin>>a;
  while(a)
  {
    char str[1000];
    scanf("%s",str);
    if(a==1){
      encrypt(str);
      printf("%s",str);
    }
    if(a==2){
      decrypt(str);
      printf("%s",str);
    }
    cin>>a;
  }
  return 0;
}
