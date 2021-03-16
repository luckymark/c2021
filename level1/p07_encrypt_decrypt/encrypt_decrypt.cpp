// encrypt_decrypt.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <stdio.h>
#include <string.h>

int main()
{
	char a[10],e[100],d[100];
	gets_s(a,10);
	if (strcmp(a, "encrypt") == 0)
	{
		printf("please input your string:\n");
		gets_s(e, 100);
		for (int i = 0; i <= 99; i++)
		{
			if ((e[i] >= 65 && e[i] <= 86) || (e[i] >= 97 && e[i] <= 118))
				e[i] = e[i] + 4;
			else
				if ((e[i] >= 87 && e[i] <= 90) || e[i] >= 119 && e[i] <= 122)
					e[i] = e[i] - 22;
		}
		puts(e);
	}
	else
	{
		if (strcmp(a, "decrypt") == 0)
		{
			printf("please input your string:\n");
			gets_s(d, 100);
			for (int j = 0; j <= 99; j++)
			{
				if ((d[j] >= 69 && d[j] <= 90) || (d[j] >= 101 && d[j] <= 122))
					d[j] = d[j] - 4;
				else
					if ((d[j] >= 65 && d[j] <= 68) || d[j] >= 97 && d[j] <= 100)
						d[j] = d[j] + 22;
			}
			puts(d);
		}
		else
			printf("error");
	}
	return 0;
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
