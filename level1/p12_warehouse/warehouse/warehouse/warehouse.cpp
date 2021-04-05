// warehouse.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct item
{
	int quantity;//数量
	char name[20];//商品名
	long number;//编号
};

void showlist(item* a);

int main()
{
	int n,num;
	long in, out;
	FILE* p;
	freopen_s(&p, "test.txt", "r", stdin);
	scanf_s("%d\n", &n);
	struct item a[3];
	for (int i = 0; i < n; i++)
	{
		scanf_s("%ld %s %d\n",&a[i].number, &(a[i].name),20,&a[i].quantity);
	}
	restart:system("cls");
	printf("请按以下数字执行操作：\n1.显示存货列表\n2.入库\n3.出库\n4.退出程序\n");
	menu:switch (int x = _getch())
	{
	  case '1':
	  {
		  system("cls");
		  printf("商品列表：\n");
		  showlist(a);
		  printf("按x返回,按其余键结束程序");
		  break;
	  }
	  case '2':
	  {
		  system("cls");
		  showlist(a);
		  printf("请输入需要入库的商品编号和数量\n如：100114514 3\n");
		  freopen_s(&p, "CON", "r", stdin);
		  scanf_s("%ld %d", &in,&num);
		  for (int i = 0; i < n; i++)
		  {
			  if (in == a[i].number)
			  {
				  a[i].quantity = a[i].quantity + num;
				  break;
			  }
		  }
		  freopen_s(&p, "test.txt", "w", stdout);
		  printf("%d\n", n);
		  showlist(a);
		  return 0;
	  }
	  case '3':
	  {
		  system("cls");
		  showlist(a);
		  printf("请输入需要出库的商品编号和数量\n如：100114514 3\n");
		  freopen_s(&p, "CON", "r", stdin);
		  scanf_s("%ld %d", &in, &num);
		  for (int i = 0; i < n; i++)
		  {
			  if (in == a[i].number)
			  {
				  a[i].quantity = a[i].quantity - num;
				  break;
			  }
		  }
		  freopen_s(&p, "test.txt", "w", stdout);
		  printf("%d\n", n);
		  showlist(a);
		  return 0;
	  }
	  case '4':
	  {
		  return 0;
	  }
	  default:goto menu;
	}
	if (_getch() == 'x')
	{
		goto restart;
	}
}

void showlist(item* a)
{
	for (int i = 0; i < 3; i++)
	{
		printf("%ld %s %d\n", a->number,a->name,a->quantity);
		a++;
	}
	return;
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
