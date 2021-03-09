#include <stdio.h>
#include <windows.h>

int GetWidth()
{
	CONSOLE_SCREEN_BUFFER_INFO scr;
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	GetConsoleScreenBufferInfo(hOut, &scr);
	return scr.dwMaximumWindowSize.X;
}

int main()
{
	int i = 0, width = GetWidth();
	while (1)
	{
		while (i <= width-2)
		{
			for (int j = 0; j < i; ++j)
			{
				printf(" ");
			}
			printf("p");
			Sleep(20);
			system("cls");
			++i;
		}
		while (i >= 0)
		{
			for (int j = 0; j < i; ++j)
			{
				printf(" ");
			}
			printf("p");
			Sleep(20);
			system("cls");
			--i;
		}
	}
}