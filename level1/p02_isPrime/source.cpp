#define WIDTH 60
#include <iostream>
#include <string>
#include <Windows.h>
#include <math.h>
#include <stdio.h>
using namespace std;
bool judge(int n)
{
  if (n < 2)
  {
    return false;
  }
  for (int i = 2; i <= sqrt(n); i++)
  {
    if (n % i == 0)
      return false;
  }
  return false;
}
int main()
{
  int x;
  cin >> x;
  if (judge(x))
  {
    cout << "yes";
  }
  else
  {
    cout << "no" << endl;
  }
  system("pause");
  return 0;
}