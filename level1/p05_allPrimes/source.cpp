#include <iostream>
#include <math.h>
#include <stdio.h>
#include <Windows.h>
#include <time.h>
using namespace std;
int primes[170], pn = 1;
bool judge(int n)
{
  if (n < 2)
    return false;
  for (int i = 0; i < pn; i++)
  {
    if (n % primes[i] == 0)
      return false;
    if (primes[i] > sqrt(n))
      return true;
  }
  return false;
}
int main()
{
  primes[0] = 2;
  DWORD start_time = GetTickCount();
  int start_clock = clock();
  cout << 2 << endl;
  for (int i = 3; i <= 1000; i = i + 2)
  {
    if (judge(i))
    {
      cout << i << endl;
      primes[pn] = i;
      pn = pn + 1;
    }
  }
  DWORD end_time = GetTickCount();
  int end_clock = clock();
  cout << "time:" << end_time - start_time << endl;
  cout << "clock:" << end_clock - start_clock << endl;
  system("pause");
  return 0;
}