#include<stdio.h>
#include<Windows.h>
//郭家瑞 2020080901015
int CurrentCursorPositionX()
{
	int a = 0;
	HANDLE hStdout;
	CONSOLE_SCREEN_BUFFER_INFO pBuffer;
	hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	GetConsoleScreenBufferInfo(hStdout, &pBuffer);
	a = pBuffer.dwCursorPosition.X;
	return a;
}
int CurrentCursorPositionY()
{
	int b = 0;
	HANDLE hStdout;
	CONSOLE_SCREEN_BUFFER_INFO pBuffer;
	hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	GetConsoleScreenBufferInfo(hStdout, &pBuffer);
	b = pBuffer.dwCursorPosition.Y;
	return b;
}
int main() 
{
	char a = 'a';
	int i = 1, n = 1;
	int x = 0, endX = 1, endY = 0;
	bool b = true;
	while (1)
	{
		if (b) n++;
		else n--;
		while (i < n)
		{
			i++;
			printf(" ");
		}
		i = 1;
		x = CurrentCursorPositionX();
		printf("%c", a);
		endX = CurrentCursorPositionX();
		endY = CurrentCursorPositionY();
		if (endX == x || endY >= 1) b = false;
		if (endX == 1 && endY == 0) b = true;
		Sleep(300);
		system("cls");
	}
	return 0;
}



