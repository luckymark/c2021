//ά���������� 
//��ASC�Ĺ���,��ASC���������a��ASC97�Ϳɣ�ע�����ASC�����ʱ��Ҫ��һ����ĸ26 
//���ܺͽ���ʱ�����������������ڴ�д��ĸ��Сд��ĸ�ķ�Χ�ڼ��ɣ����ھ�-+26 
#include <stdio.h>
#include <string.h>

#define _CRT_SECURE_NO_WARNINGS

void encrypt();
void change(char* k, char* c);
void decrypt();

int main()
{
	int n;
	printf("Hello!This program has two functions:encrypt and decrypt.\n");
	printf("If you want to encrypt,please input 0,if you want to decrypt,please input 1\n");
	scanf("%d", &n);//scanf������֮��Ҫ���stdin����Ȼ\t�ͻ������һ�ε������� 
	fflush(stdin);
	if (n)
		decrypt();
	else
		encrypt();

	return 0;
}

void encrypt()
{
	char M[1000] = { '\0' }, C[1000] = { '\0' }, K[1000] = { '\0' };
	printf("please input your secret key.for example:CompleteVictory\n");
	gets(K);
	printf("please input the text that you want to encrypt.for example:Wherethereisawillthereisaway\n");
	gets(C);
	change(K, C);

	for (int i = 0;C[i] != '\0';i++)
	{
		if (C[i] < 91)
		{
			if (C[i] + K[i] < 189)
			{
				M[i] = C[i] + K[i] - 97;
			}
			else
			{
				M[i] = C[i] + K[i] - 97 - 26;
			}
		}
		else
		{
			if (C[i] + K[i] < 220)
			{
				M[i] = C[i] + K[i] - 97;
			}
			else
			{
				M[i] = C[i] + K[i] - 97 - 26;
			}
		}

	}
	puts(M);
}

void decrypt()
{
	char M[1000] = { '\0' }, C[1000] = { '\0' }, K[1000] = { '\0' };
	printf("please input your secret key.for example:CompleteVictory\n");
	gets(K);
	printf("please input the text that you want to decrypt.for example:Yvqgpxaimmklongnzfwpvxmniytm\n");
	gets(M);   
	change(K, M);
	for (int i = 0;M[i] != '\0';i++)
	{
		if (M[i] < 91)
		{
			if (64 < M[i] - K[i] + 97 && M[i] - K[i] + 97 < 91)
			{
				C[i] = M[i] + 97 - K[i];
			}
			else
			{
				C[i] = M[i] - K[i] + 97 + 26;
			}
		}
		else
		{
			if (96 < M[i] - K[i] + 97 && M[i] - K[i] + 97 < 123)
			{
				C[i] = M[i] - K[i] + 97;
			}
			else
			{
				C[i] = M[i] - K[i] + 97 + 26;
			}
		}
	}
	puts(C);
}

//Ϊ�˶��ʹ����Կ ������ ������Կת����Сд 
 void change(char* k, char* c)
{
	strncat(k, k, strlen(c));
	for (int i = 0;k[i] != '\0';i++)
	{
		if (k[i] < 97)
		{
			k[i] = k[i] + 32;
		}
	}
}
