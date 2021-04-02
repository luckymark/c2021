#include <stdio.h>
#include <windows.h>
#include <iostream>
using namespace std;

struct Ware
{
    int number = 0;
    char name[50];
    int num;
    float price;
};

Ware ware[100];

void read();
void write();
void show();
void in();
void out();

int main()
{
    while(true)
    {
        read();
        printf("������������ѡ�����Ӧ�Ĺ���\n");
        printf("1.��ʾ����б�\n");
        printf("2.���\n");
        printf("3.����\n");
        printf("4.�˳�����\n");
        int c = 0;
        if(scanf("%d", &c)!=1)
        {
            printf("�������\n");
            break;
        }
        else
        {
            if(c==4)
            {
                return 0; 
            }
            else if(c==1)
            {
                show();
            }
            else if(c==2)
            {
                in();
                write();
            }
            else if(c==3)
            {
                out();
                write();
            }
        }
    }
}

void read()
{
    memset(ware, 0, 100*sizeof(ware[0]));
    FILE *p = fopen("ware_house.txt", "r");
    if(p==NULL)
    {
        printf("�ֿ��ļ���ʧ��\n");
        return;
    }
    int i = 0;
    while(fscanf(p,"%d",&ware[i].number)==1)
    {
        fscanf(p, "%s", ware[i].name);
        fscanf(p, "%d", &ware[i].num);
        fscanf(p, "%f", &ware[i].price);
        i++;
    }
    fclose(p);
}

void write()
{
    FILE *p = fopen("ware_house.txt", "w");
    if(p==NULL)
    {
    	printf("�ֿ��ļ���ʧ��\n");
    	return;
	}
    int i = 0;
    int f = 0;
    while (ware[i].number != 0)
    {
        if(ware[i].num!=0)
        {
            fprintf(p, "%d %s %d %f\n", f + 1, ware[i].name, ware[i].num, ware[i].price);
            f++;
        }
        i++;
    }
    fclose(p);
}

void show()
{
    int i = 0;
    printf("��� ���� ��Ŀ �۸�\n");
    while(ware[i].num!=0)
    {
        printf("%d    %s   %d   %f\n", ware[i].number, ware[i].name, ware[i].num, ware[i].price);
        i++;
    }
}

void in()
{
    printf("���������ơ���Ŀ�ͼ۸��ÿո�ָ�\n");
    char n[50];
    int n1, p;
    scanf("%s", n);
    cin >> n1 >> p;
    int i = 0;
    int is = 0;
    int nis = 0;
    while (ware[i].number != 0)
    {
        nis = 0;
        int g = 0;
        while(n[g]!=NULL)
        {
            if(n[g]!=ware[i].name[g])
            {
                nis = 1;
            }
            g++;
        }
        if (nis==0)
        {
            if (ware[i].price == p)
            {
                ware[i].num += n1;
                is = 1;
            }
        }
        i++;
    }
    if(is==0)
    {
        ware[i].number = i + 1;
        for (int g = 0; g < 50; g++)
        {
            ware[i].name[g] = n[g];
        }
        ware[i].num = n1;
        ware[i].price = p;
    }
}

void out()
{
    printf("�����������Ʒ����Լ��������ÿո�ָ���\n");
    int n1,n2;
    cin >> n1 >> n2;
    if(ware[n1-1].number==0)
    {
        printf("�޴���Ʒ��\n");
        return;
    }
    ware[n1 - 1].num -= n2;
    if(ware[n1-1].num<0)
    {
        ware[n1 - 1].num = 0;
    }
    return;
}
