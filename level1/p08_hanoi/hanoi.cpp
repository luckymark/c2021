#include <stdio.h>

void hanoi(int n, char a, char b, char c);
void move(char from, char to);
int main()
{
	int n;
	scanf_s("%d", &n);
	hanoi(n, 'A', 'B', 'C');
	return 0;
}
void hanoi(int n, char a, char b, char c)
{
	if (n == 1)
	{
		move(a, c);
	}
	else
	{
		hanoi(n - 1, a, c, b);
		move(a, c);
		hanoi(n - 1, b, a, c);
		return;
	}
}
void move(char from, char to)
{
	printf("%c->%c\n", from, to);
	return;
}