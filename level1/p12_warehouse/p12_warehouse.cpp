/*
实现如下的菜单（按数字选择菜单功能）：
显示存货列表
入库
出库
退出程序
实现菜单对应功能（需记录货物的型号、数量等信息）；
程序启动时从文件中读取当前库存数据，退出时保存库存数据；
*/

#include<bits/stdc++.h>
using namespace std;
int tmp,num;
char morex;
bool f;
struct ware
{
	int nums;
	char mtype[35];
}s[10005];
void start()
{
	system("cls");
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	printf("|               菜单              |\n");
	printf("|         1.显示存货列表          |\n");
	printf("|         2.    入库              |\n");
    printf("|         3.    出库              |\n");
    printf("|         4.  退出程序            |\n");
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	return ;
}
void list_display()
{
	system("cls");
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	printf("#当前库中共有%d种货物\n",num);
	for(int i=1;i<=num;++i)
	cout<<"第"<<i<<"种："<<s[i].mtype<<" "<<s[i].nums<<endl;
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	printf("  #请按回车键返回菜单#  \n");
	morex=getchar();morex=getchar();
	return ;
}
void warehousing()
{
	system("cls");
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	printf("#请输入货物种类和数目：\n");
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	ware newware;
	bool flag=1;
	cin>>newware.mtype>>newware.nums;
	
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	printf("#入库中............................\n");
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	for(int i=1;i<=num;++i)
	if(s[i].mtype==newware.mtype)
	{
		s[i].nums+=newware.nums;
		flag=0;
		break;
	}
	
	if(flag)s[++num]=newware;
	printf("#入库完成.\n");
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	
	printf("  #请按回车键返回菜单#  \n");
	morex=getchar();morex=getchar();
	return ;
}
bool meql(char a[],char b[])
{
	for(int i=0;a[i]||b[i];++i)
	if(a[i]!=b[i])return 0;
	return 1;
}
void ex_warehouse()
{
	system("cls");
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	printf("#请输出货物种类和数目：\n");
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	ware newware;
	bool flag=1;
	scanf("%s%d",&newware.mtype,&newware.nums);
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	printf("#出库中............................\n");
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	
	for(int i=1;i<=num;++i)
	if(meql(s[i].mtype,newware.mtype))
	{
		if(s[i].nums<newware.nums)
		{
			printf("#出库错误，库中该类货物数目不足。\n");
			printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n"); 
			printf("  #请按回车键返回菜单#  \n");
			morex=getchar();morex=getchar();
			return ;
		}
		else if(s[i].nums>newware.nums)
		{
			s[i].nums-=newware.nums;
			flag=0;
		}
		else 
		{
			for(int j=i;j<num;++j)
			s[j]=s[j+1];
			num--;
			flag=0;
		}
		break;
	}
	if(flag)
	{
		printf("#出库错误，库中没有该类货物。\n");
		printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n"); 
	}
	else 
	{
		printf("#出库完成.\n");
		printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	}
	printf("  #请按回车键返回菜单#  \n");
	morex=getchar();morex=getchar();
	return ;
}
int main()
{

	FILE *fp=fopen("saved.txt","r");
	fscanf(fp,"%d",&num);
	for(int i=1;i<=num;++i)
	fscanf(fp,"%s%d",&s[i].mtype,&s[i].nums);
	f=1;
	fclose(fp);

	while(f)
	{
		start();
		cin>>tmp;
		while(tmp<1||tmp>4){printf("错误指令\n#请重新输入#\n");cin>>tmp;}
		if(tmp==1)list_display();
		else if(tmp==2)warehousing();
		else if(tmp==3)ex_warehouse();
		else if(tmp==4)f=0;
	}
	
	system("cls");
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	printf("|     正在退出，感谢您的使用。     |\n");
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n"); 
	
	fp=fopen("saved.txt","w");
	fprintf(fp,"%d\n",num);
	for(int i=1;i<=num;++i)
	fprintf(fp,"%s  %d\n",s[i].mtype,s[i].nums);
	fclose(fp);
	
	return 0;
}
