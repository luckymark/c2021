#define WIDTH 60
#include <iostream>
#include <string>
#include <Windows.h>
#include <stdio.h>
using namespace std;
int main()
{
  system("mode con cols=60 lines=1");
  char c;
  string s;
  int n = 0, x = 0;
  cin >> s;
  int len = s.length();
  while (true)
  {
    system("mode con cols=60 lines=1");
    for (int i = 0; i < n; i++)
    {
      cout << ' ';
    }
    cout << s;
    Sleep(50);
    system("cls");
    x = (x + 1) % (2 * (WIDTH - len));
    n = (WIDTH - len - abs(x - WIDTH + len));
  }
  return 0;
}
