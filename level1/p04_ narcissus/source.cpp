#include<iostream>
#include<math.h>
#include<stdio.h>
using namespace std;
bool judge(int n) {
	bool ex = true;
	if (n < 2)return false;
	for (int i = 2; i <= sqrt(n); i++) {
		if (n % i == 0) ex = false;
	}
	return ex; 
}
int main() {
  cout <<(5+4)/(1-1.0/6-1.0/12-1.0/7-1.0/2)-4 <<endl;
  system("pause");
	return 0;
}