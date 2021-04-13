#include <iostream>
#include <math.h>
#include <stdio.h>
#include <Windows.h>
#include <time.h>
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
    {
      return false;
    }
  }
  return true;
}
int main()
{
  for (int i = 4; i <= 100; i = i + 2)
  {
    for (int j = 2; j < 100; j++)
      if (judge(j) && judge(i - j))
      {
        cout << i << "=" << j << "+" << i - j << endl;
        break;
      }
  }
  system("pause");
  return 0;
}