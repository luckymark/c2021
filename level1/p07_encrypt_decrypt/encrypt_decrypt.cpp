#include <stdio.h>
#include <string.h>
#include <iostream>

void encrypt(char* source, char* encrypted)
{
	while (*source != '\0')
	{
		*encrypted = 158 - *source;
		source++;
		encrypted++;
	}
}

void decrypt(char* encrypted, char* source)
{
	while (*encrypted != '\0')
	{
		*source = 158 - *encrypted;
		source++;
		encrypted++;
	}
}

int main()
{
	printf("请输入需要加密字符串的长度：");
	int n = 0;
	std::cin >> n;
	char* a = new char[n + 1]();
	char* b = new char[n + 1]();
	scanf("%s", a);
	encrypt(a, b);
	printf("加密后的字符串为：");
	printf("%s\n", b);
	printf("请输入需要解密的字符串的长度：");
	int s = 0;
	scanf("%d", &s);
	char* c = new char[n + 1]();
	char* d = new char[n + 1]();
	printf("需要解密的字符串为：");
	scanf("%s", c);
	decrypt(c, d);
	printf("解密后的字符串为：");
	printf("%s", d);
}