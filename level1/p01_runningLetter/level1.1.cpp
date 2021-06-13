#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	system("mode con cols=50 lines=25 ");
	char a[100]={0};
	int i,j,p;
	gets(a);
	for(i=0;i<50-strlen(a);i++)
	{
		for(j=0;j<i;j++)
		{
			printf(" ");	
		};
		puts(a);
		Sleep(200);
		system("cls");						
	}
	for(int p=i;p>0;p--)
	{
		for(int j=0;j<p;j++)
		{
			printf(" ");	
		};
		puts(a);
		Sleep(200);
		system("cls");						
	}

		
	
}
//#include<stdio.h>
//#include<sys/types.h>
//#include<sys/ioctl.h>
//#include<unistd.h>
//#include<termios.h>
//int main()
//{
//struct winsize size;
//ioctl(STDIN_FILENO,TIOCGWINSZ,&size);
//printf("%d\n",size.ws_col);
//printf("%d\n",size.ws_row);
//return 0;
//}
