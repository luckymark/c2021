#include <iostream>
#include <math.h>
#include <stdio.h>
#include <Windows.h>
#include <string>
#include <time.h>
using namespace std;
int group[1000][4];
int input[1000][3];
void decrypt()
{
  string s;
  cout << "please put in the contents you want to decrypt" << endl;
  cin >> s;
  unsigned j = 0;
  unsigned len = s.length();
  for (unsigned i = 0; i < len; i = i + 3)
  {
    char a = ((s[i] - 97) / 8) * 8 + ((s[i + 1] - 97) / 8) * 2 + ((s[i + 2] - 97) / 8) / 2 + 97;
    cout << a;
  }

  cout << endl;
}
void encrypt()
{
  srand(time(0));
  string s;
  cout << "please put in the contents you want to encrypt" << endl;
  cin >> s;
  unsigned len = s.length();
  for (unsigned i = 0; i < len; i++)
  {
    srand((unsigned)time(NULL));
    input[i][0] = (s[i] - 97) / 8;
    input[i][1] = ((s[i] - 97) / 2) % 4;
    input[i][2] = ((s[i] - 97) % 2) * 2 + rand() % 2;
  }
  for (unsigned i = 0; i < len; i = i + 1)
  {
    srand((unsigned)time(NULL));
    char a = input[i][0] * 8 + input[(i + 1) % len][0] * 2 + rand() % 2 + 97;
    char b = input[i][1] * 8 + input[(i + 1) % len][1] * 2 + rand() % 2 + 97;
    char c = input[i][2] * 8 + input[(i + 1) % len][2] * 2 + rand() % 2 + 97;

    cout << a;
    cout << b;
    cout << c;
  }
  cout << endl;
  system("pause");
}
int main()
{
  cout << "encrypt or decrypt?" << endl
       << "please put in E or D to choose the mode or put in e to exit the program" << endl;
  char c;
  cin >> c;
  switch (c)
  {
  case 'E':
  {
    encrypt();
    break;
  }
  case 'D':
  {
    decrypt();
    break;
  }
  case 'e':
    break;
  default:
    cout << "??????????????????????" << endl
         << "Please check!";
  }
  system("pause");
  return 0;
}