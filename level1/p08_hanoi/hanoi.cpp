#include<iostream>

void hanoi(int n, char a, char b, char c)
{
	if (n == 1)
	{
		printf("��Բ��%d��%c�Ƶ�%c", n, a, c);
	}
	else
	{
		hanoi(n - 1, a, c, b);
		printf("��Բ��%d��%c�Ƶ�%c", n, a, c);
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