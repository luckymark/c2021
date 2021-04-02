#include<iostream>

void hanoi(int n, char a, char b, char c)
{
	if (n == 1)
	{
		printf("将圆盘%d从%c移到%c", n, a, c);
	}
	else
	{
		hanoi(n - 1, a, c, b);
		printf("将圆盘%d从%c移到%c", n, a, c);
		hanoi(n - 1, b, a, c);
	}
}
int main()
{
	char A = 'A';
	char B = 'B';
	char C = 'C';
	hanoi(64, A, B, C);
}