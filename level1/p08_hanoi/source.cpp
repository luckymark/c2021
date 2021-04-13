#include <iostream>
#include <math.h>
#include <stdio.h>
#include <Windows.h>
#include <time.h>
using namespace std;
int hanoi(int n, int from, int goal, int temp)
{
  if (n != 1)
  {
    int a = hanoi(n - 1, from, temp, goal) + hanoi(1, from, goal, temp) + hanoi(n - 1, temp, goal, from) + 1;
    return a;
  }
  else
    cout << (char)(from + 65) << "->" << (char)(goal + 65) << endl;
  return 1;
}
int main()
{
  int n;
  cin >> n;
  cout << hanoi(n, 0, 2, 1) << endl;
  system("pause");
  return 0;
}
