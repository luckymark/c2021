#include<stdio.h>
#include<windows.h>
#include<conio.h>
#define path "D://good.txt"
void ex_cargo();
void list();
void store();
void update();
void menu();
FILE* fp;
int type;
struct goods {
	int id;
	int num;
};
struct goods article[100];
int main() {
	int ch;
	menu();
	while (ch = _getch())
	{
		switch (ch)
		{
		case '1':list(); break;
		case '2':store(); break;
		case '3':ex_cargo(); break;
		case '4':exit(0);
		}
	}
	return 0;
}
void menu()
{
	system("color f2");
	system("cls");
	puts("INPUT NUMBERS TO REALIZE THE FUNCTION");
	puts("1.Display inventory list");
	puts("2.BUY IN");
	puts("3.SELL");
	puts("4.exit");
}
void update()
{
	fopen_s(&fp, path, "r");
	fscanf_s(fp, "Total good types:%d\n", &type);
	for (int i = 0; i < type; i++)
		fscanf_s(fp, "%d:%dkg", &article[i].id, &article[i].num);
	fclose(fp);
}
void list()
{
	fopen_s(&fp, path, "r");
	fscanf_s(fp, "Total good types:%d\n", &type);
	for (int i = 0; i < type; i++)
	{
		fscanf_s(fp, "%d:%dkg", &article[i].id, &article[i].num);
		printf("the %d	th	aticle remains %d\n", article[i].id, article[i].num);
	}
	fclose(fp);
	char b;
	printf("\nif you wanna get back,enter 'b':");
	b = _getch();
	if (b == 'b')
		menu();
}
void store()
{
	update();
	fopen_s(&fp, path, "w");
	fscanf_s(fp, "Total good types:%d\n", &type);
	int id, num;
	printf("Enter the id of the goods stored:");
	scanf_s("%d", &id);
	printf("Enter the number of the goods stored:");
	scanf_s("%d", &num);
	int tmp = 1;
	for (int i = 0; i < type; i++)
	{
		if (id == article[i].id)
		{
			article[i].num += num;
			tmp = 0;
			break;
		}
	}
	int a = type;
	if (tmp == 1) type++;
	fprintf(fp, "Total good types:%d\n", type);

	for (int i = 0; i < a; i++)
	{
		fprintf(fp, "%d:%dkg\n", article[i].id, article[i].num);
	}
	if (tmp == 1)
		fprintf(fp, "%d:%dkg\n", id, num);
	fclose(fp);
	printf("\nif you wanna get back,enter 'b':");
	char b;
	b = _getch();
	if (b == 'b')
		menu();
}
void ex_cargo()
{
	update();
	int id, num;
	fopen_s(&fp, path, "w");
	if (type == 0)
	{
		printf("there are no goods.");
		return;
	}
	printf("Enter the id of the ex-goods:");
	scanf_s("%d", &id);
	int tmp;
	for (int i = 0; i < type; i++)
	{
		if (article[i].id == id)
		{
			tmp = i;
			break;
		}
	}
	printf("Enter the number of the ex-goods(no more than %d):", article[tmp].num);
	scanf_s("%d", &num);
	article[tmp].num -= num;
	fprintf(fp, "Total good types:%d\n", type);
	for (int i = 0; i < type; i++)
	{
		fprintf(fp, "%d:%dkg\n", article[i].id, article[i].num);
	}
	fclose(fp);
	update();
	printf("\nif you wanna get back,enter 'b':");
	char b;
	b = _getch();
	if (b == 'b')
		menu();
}
