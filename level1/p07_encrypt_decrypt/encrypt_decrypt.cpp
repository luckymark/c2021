#include<stdio.h>
#include<string.h>
#include<windows.h>
void crypt(int m)
{
	char text[256] = { '\0' }, text1[256] = { '\0' };
	if (m == 0)
	{
		printf("enter the words you want to encrypt:\n");
		scanf("%s", text);
		for (int i = 0; i <= int(sizeof(text)); i++)
		{
			if ((text[i] >= 'a' && text[i] <= 'z' )||( text[i] >= 'A' && text[i] <= 'Z'))//uvwxyz
			{
				if ((text[i] >= 'a' && text[i] <= 'u' )||( text[i] >= 'A' && text[i] <= 'U'))
				{
					text1[i] = text[i] + 5;
				}
				else
				{
					text1[i] = text[i] + 5 - 26;
				}
			}

		}
		printf("%s-->%s", text, text1);
	}
	else if (m == 1)
	{
		printf("enter the words you want to decrypt:\n");
		scanf("%s", text);
		for (int i = 0; i <= int(sizeof(text)); i++)
		{
			if ((text[i] >= 'a' && text[i] <= 'z' )||( text[i] >= 'A' && text[i] <= 'Z'))//uvwxyz
			{
				if ((text[i] >= 'e' && text[i] <= 'z' )||( text[i] >= 'E' && text[i] <= 'Z'))
				{
					text1[i] = text[i] - 5;
				}
				else
				{
					text1[i] = text[i] -5+26;
				}
			}

		}
		printf("%s<--%s", text, text1);
	}
	else
	{
		printf("error");
	}
}

int main()
{
	int m;
	printf("press 0 to encrypt , press 1 to decrypt, press 2 to end the exe\n");
	scanf("%d", &m);
	while(m!=2)
	{
		crypt(m);
		//system("cls");
		printf("\npress 0 to encrypt , press 1 to decrypt, press 2 to end the exe\n");
		scanf("%d", &m);
	}
	return 0;
}
