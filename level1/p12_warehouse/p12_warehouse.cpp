/*
ʵ�����µĲ˵���������ѡ��˵����ܣ���
��ʾ����б�
���
����
�˳�����
ʵ�ֲ˵���Ӧ���ܣ����¼������ͺš���������Ϣ����
��������ʱ���ļ��ж�ȡ��ǰ������ݣ��˳�ʱ���������ݣ�
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
	printf("|               �˵�              |\n");
	printf("|         1.��ʾ����б�          |\n");
	printf("|         2.    ���              |\n");
    printf("|         3.    ����              |\n");
    printf("|         4.  �˳�����            |\n");
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	return ;
}
void list_display()
{
	system("cls");
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	printf("#��ǰ���й���%d�ֻ���\n",num);
	for(int i=1;i<=num;++i)
	cout<<"��"<<i<<"�֣�"<<s[i].mtype<<" "<<s[i].nums<<endl;
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	printf("  #�밴�س������ز˵�#  \n");
	morex=getchar();morex=getchar();
	return ;
}
void warehousing()
{
	system("cls");
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	printf("#����������������Ŀ��\n");
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	ware newware;
	bool flag=1;
	cin>>newware.mtype>>newware.nums;
	
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	printf("#�����............................\n");
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	for(int i=1;i<=num;++i)
	if(s[i].mtype==newware.mtype)
	{
		s[i].nums+=newware.nums;
		flag=0;
		break;
	}
	
	if(flag)s[++num]=newware;
	printf("#������.\n");
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	
	printf("  #�밴�س������ز˵�#  \n");
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
	printf("#����������������Ŀ��\n");
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	ware newware;
	bool flag=1;
	scanf("%s%d",&newware.mtype,&newware.nums);
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	printf("#������............................\n");
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	
	for(int i=1;i<=num;++i)
	if(meql(s[i].mtype,newware.mtype))
	{
		if(s[i].nums<newware.nums)
		{
			printf("#������󣬿��и��������Ŀ���㡣\n");
			printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n"); 
			printf("  #�밴�س������ز˵�#  \n");
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
		printf("#������󣬿���û�и�����\n");
		printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n"); 
	}
	else 
	{
		printf("#�������.\n");
		printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	}
	printf("  #�밴�س������ز˵�#  \n");
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
		while(tmp<1||tmp>4){printf("����ָ��\n#����������#\n");cin>>tmp;}
		if(tmp==1)list_display();
		else if(tmp==2)warehousing();
		else if(tmp==3)ex_warehouse();
		else if(tmp==4)f=0;
	}
	
	system("cls");
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	printf("|     �����˳�����л����ʹ�á�     |\n");
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n"); 
	
	fp=fopen("saved.txt","w");
	fprintf(fp,"%d\n",num);
	for(int i=1;i<=num;++i)
	fprintf(fp,"%s  %d\n",s[i].mtype,s[i].nums);
	fclose(fp);
	
	return 0;
}
