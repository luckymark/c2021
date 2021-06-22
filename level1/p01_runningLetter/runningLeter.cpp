#include<bits/stdc++.h>
using namespace std;
int main()
{
  char a[100];
  scanf("%s",a);
  for(int i=1;;i++)
  {
    int p=i;
    if(p>20) p=40-i;
    for(int j=1;j<=p;j++)
    {
      if(j != p) printf(" ");
      else printf("%s",a);
    }
    system("cls");
    if(i>=40) i=0;
  }
  return 0;
}
