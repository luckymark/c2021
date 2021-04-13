#include<bits/stdc++.h>
#include<conio.h>
#include<windows.h>
using namespace std;
int n;
struct stuff
{
	char name[21];
	int num;
}a[10001];
void dispaly()
{
	printf("现在库房内共有%d种货物\n",n);
	for(int i=0;i<n;i++) cout<<a[i].name<<" "<<a[i].num<<endl;
	cout<<endl;
	system("pause");
	system("cls");
}
void _in()
{
	cout<<"请输入入库货物的信息："<<endl;
	stuff newone;
	int flag=0;
	scanf("%s %d",&newone.name,&newone.num);
	for(int i=0;i<n;i++)
	{
		if(strcmp(newone.name,a[i].name)==0)//这里不能直接用==判断两个字符串是否相等，而要用字符串比较函数strcmp，该函数会对a和b的每个字符，按照ascii码值比较，如果二者完全相同返回0；如果a的ascii码值先出现较大者，会返回1；否则返回-1； 
		{
			a[i].num+=newone.num;
			flag=1;
			break;
		}
	}
	if(flag==0) a[n++]=newone;
	cout<<"录入成功！"<<endl; 
	system("pause");
	system("cls");
}
void _out()
{
	cout<<"请输入出库货物的信息："<<endl;
	stuff newone;
	int flag=0;
	scanf("%s %d",&newone.name,&newone.num);
	for(int i=0;i<n;i++)
	{
		if(strcmp(newone.name,a[i].name)==0)
/*这里不能直接用==判断两个字符串是否相等，而要用字符串比较函数strcmp;
该函数会对a和b的每个字符，按照ascii码值比较，
如果二者完全相同返回0；如果a的ascii码值先出现较大者，会返回1；否则返回-1；*/ 
		{
			a[i].num-=newone.num;
			if(a[i].num<0)
			{
				a[i].num+=newone.num;
				cout<<"库存不足，无法出库"<<endl; 
			}
			else cout<<"出库成功"<<endl; 
			flag=1;
			break;
		}
	}
	if(flag==0) cout<<"未找到该货物，无法出库"<<endl;  
	system("pause");
	system("cls");

}
int main()
{
	FILE*List;
	if((List=fopen("List.txt","r+"))==NULL)//这里r+表示打开的文件可读; 
	{
		cout<<"库存文件读取失败！";
		return 0;
	}
	else
	{
		fscanf(List,"%d",&n);
		for(int i=0;i<n;i++) fscanf(List,"%s %d",&a[i].name,&a[i].num);
	}
	while(1)
	{
		cout<<"1.显示存货列表"<<endl<<"2.入库"<<endl<<"3.出库"<<endl<<"4.退出程序"<<endl<<"（按数字选择菜单功能）"<<endl; 
		char t=_getch();
		system("cls");
		int flag=0;
		switch(t)
		{
			case '1':
			{
				dispaly();
				break;//要加break；否则会在执行完case '1'后再去执行后面几个case！！！ 
			}
			case '2':
			{
				_in();
				break;
			}
			case '3':
			{
				_out();
				break;
			}
			case '4':
			{
				fclose(List);
				FILE*fp;
				if((fp=fopen("List.txt","w+"))==NULL)//这里只有写w+才能写； 
				{
					cout<<"库存文件读取失败！";
					return 0;
				}
				else
				{
					fprintf(fp,"%d\n",n);//之前所有的操作都对结构体数组进行，只在最后要结束进程前再重新写文件； 
					for(int i=0;i<n;i++) fprintf(fp,"%s %d\n",a[i].name,a[i].num);
					fclose(List);
				}
				return 0;
			}
			default:
			{
				flag=1;
				break;
			}
		}
		if(flag)
		{
			cout<<"error"<<endl;
			Sleep(100);
			system("cls");
		}
	}
	return 0;
}
