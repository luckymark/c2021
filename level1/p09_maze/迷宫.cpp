#include<iostream>
#include<conio.h>
#include<windows.h>
using namespace std;
HANDLE hOut;

char cursorCharRead()
{
	char buf[BUFSIZ];
	CONSOLE_SCREEN_BUFFER_INFO csbiInfo;
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	GetConsoleScreenBufferInfo(hConsole, &csbiInfo);
	COORD pos = csbiInfo.dwCursorPosition;
	TCHAR strFromConsole[1];
	DWORD dwChars;
	ReadConsoleOutputCharacter(hConsole,strFromConsole,1,pos,&dwChars); 
	char c = strFromConsole[0];
	return c;
}

int main()
{
	printf("*******************o*********************\n");
	printf("*           *   *   *       *     *   * *\n");
	printf("* * ******* * * * * ***** * * ***** * * *\n");
	printf("* *     *   * * * *     * *       * * * *\n");
	printf("******* ***** * * ***** *** ***** * * * *\n");
	printf("*   *     *   * *   *     *     *   * * *\n");
	printf("* * * *** * *** *** * *** ***** ***** * *\n");
	printf("* * *   *   *       * *       *     *   *\n");
	printf("* * *** ************* * ***** ***** *** *\n");
	printf("* * *   *     *   *   *   * * * *   * * *\n");
	printf("* *** ******* * * * ***** * * * * *** * *\n");
	printf("*   *           * * * *   * * *     * * *\n");
	printf("* * ********* ***** * * *** * * ***** * *\n");
	printf("* * *   *   * *   *   * *   *   * * *   *\n");
	printf("* * * * * *** * * *** * * ***** * * *****\n");
	printf("* *   * * *   * *   * * *     * *   *   *\n");
	printf("* ***** * * *** *** *** ***** * * ***** *\n");
	printf("* *     * *   *   *   * *     *       * *\n");
	printf("* ******* *** *** *** * *** *** ***** * *\n");
	printf("* *     * *   * *   *   *   * * *   *   *\n");
	printf("* * *** * * *** *** ***** *** * *** *** *\n");
	printf("* * * *     *     *   *     *     * *   *\n");
	printf("* * * * ***** * ***** * ********* * *****\n");
	printf("* * *         *   *   *       *   *     *\n");
	printf("* * ******* ***** * *** * *** *** *** * *\n");
	printf("*   *   *   *     *   * *   *   * *   * *\n");
	printf("* ***** *** * ******* ***** *** * * *****\n");
	printf("*       *   *   *   *     * * *   *     *\n");
	printf("********* ******* * ***** * * * *** *** *\n");
	printf("*     *   *   *   *   *   *   * *   * * *\n");
	printf("***** * *** *** *** * * ******* * *** * *\n");
	printf("*   *   *   *   *   *   *   *   * * *   *\n");
	printf("* * *** * *** ***** ***** * * * * * * ***\n");
	printf("* *     *   * *   *   *   * * *   *     *\n");
	printf("* *** ***** * * * * * * *** *********** *\n");
	printf("*   *   * * *   * * *   * *   *         *\n");
	printf("******* * * ***** ******* *** ******* * *\n");
	printf("*     *   *   *       *   *     *   * * *\n");
	printf("* ***** *** * * ***** * *** *** * *** * *\n");
	printf("*           * *     * *     *   *     * *\n");
	printf("********************* *******************\n");
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD w = { 21, 40 };
	SetConsoleCursorPosition(hOut, w);
	while (w.X != 19 || w.Y != 0)
	{
		int ch1 = 0, ch2 = 0;
		int t = 0;
		if (ch1 = getch())
		{
			ch2 = getch();
			switch (ch2)
			{
			case 72:w.Y--; t = 1; break;
			case 80:w.Y++; t = 2; break;
			case 75:w.X--; t = 3; break;
			case 77:w.X++; t = 4; break;
			}
		}
		SetConsoleCursorPosition(hOut, w);
		if (cursorCharRead() == '*')
		{
			switch (t)
			{
			case 1:w.Y++; break;
			case 2:w.Y--; break;
			case 3:w.X++; break;
			case 4:w.X--; break;
			}
		}
		SetConsoleCursorPosition(hOut, w);
	}
	w.X = 0;
	w.Y = 41;
	SetConsoleCursorPosition(hOut, w);
	printf("成功通关！");
}
