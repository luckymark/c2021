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
	printf("��������Ҫ�����ַ����ĳ��ȣ�");
	int n = 0;
	std::cin >> n;
	char* a = new char[n + 1]();
	char* b = new char[n + 1]();
	scanf("%s", a);
	encrypt(a, b);
	printf("���ܺ���ַ���Ϊ��");
	printf("%s\n", b);
	printf("��������Ҫ���ܵ��ַ����ĳ��ȣ�");
	int s = 0;
	scanf("%d", &s);
	char* c = new char[n + 1]();
	char* d = new char[n + 1]();
	printf("��Ҫ���ܵ��ַ���Ϊ��");
	scanf("%s", c);
	decrypt(c, d);
	printf("���ܺ���ַ���Ϊ��");
	printf("%s", d);
}