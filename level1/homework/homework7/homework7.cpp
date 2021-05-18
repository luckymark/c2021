#include<stdio.h>
#include <string.h>
/// <summary>
/// 加密函数
/// </summary>
/// <param name="original">原文，字符串指针</param>
/// <param name="ciphertext">密文，整形数组，范围与原文一致</param>
/// <param name="n">原文长度</param>
/// <returns></returns>
int* Encryption(char * original,int ciphertext[],int n)
{
	int i = 0, f = 1;
	while (i < n)
	{
		ciphertext[i] = (n - i) * ((original[i] + (i + 1) * f));
		i++;
		f *= -1;
	}
	return ciphertext;
}
/// <summary>
/// 解密函数
/// </summary>
/// <param name="ciphertext">密文，整形数组</param>
/// <param name="plaintext">明文，字符串指针，范围与密文数组范围一致</param>
/// <param name="n">原文长度</param>
/// <returns></returns>
char* Deciphering(int  ciphertext[],char* plaintext, int n)
{
	int i = 0, f = 1;
	while (i < n)
	{
		plaintext[i] = ciphertext[i] / (n - i) - (i + 1) * f;
		i++;
		f *= -1;
	}
	return plaintext;
}
int main()
{
	char a[1000];
	int b[1000];int* d;
	char c[1000] = { 0 };char* f;
	int n = -1, i = 0;
	scanf("%s", &a);
	printf("原文：%s\n", a);
	n = strlen(a);
	d = Encryption(a, b, n);
	printf("密文：");
	while (i < n)
	{
		printf("%d  ", d[i]);
		i++;
	}
	f = Deciphering(d, c, n);
	printf("\n明文：%s\n", f);
}


