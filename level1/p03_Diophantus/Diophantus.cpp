#include<stdio.h>
int main() {
	int x=0, y;
	for (x; x <= 100; x++) 
	{
		y = x / 2.0;
		if (x/6.0 + x / 12.0 + x / 7.0 + 5 + y + 4 == x && x / 2.0 == y) printf("%d", x);
	}
}
