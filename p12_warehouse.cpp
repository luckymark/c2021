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
	printf("���ڿⷿ�ڹ���%d�ֻ���\n",n);
	for(int i=0;i<n;i++) cout<<a[i].name<<" "<<a[i].num<<endl;
	cout<<endl;
	system("pause");
	system("cls");
}
void _in()
{
	cout<<"���������������Ϣ��"<<endl;
	stuff newone;
	int flag=0;
	scanf("%s %d",&newone.name,&newone.num);
	for(int i=0;i<n;i++)
	{
		if(strcmp(newone.name,a[i].name)==0)//���ﲻ��ֱ����==�ж������ַ����Ƿ���ȣ���Ҫ���ַ����ȽϺ���strcmp���ú������a��b��ÿ���ַ�������ascii��ֵ�Ƚϣ����������ȫ��ͬ����0�����a��ascii��ֵ�ȳ��ֽϴ��ߣ��᷵��1�����򷵻�-1�� 
		{
			a[i].num+=newone.num;
			flag=1;
			break;
		}
	}
	if(flag==0) a[n++]=newone;
	cout<<"¼��ɹ���"<<endl; 
	system("pause");
	system("cls");
}
void _out()
{
	cout<<"���������������Ϣ��"<<endl;
	stuff newone;
	int flag=0;
	scanf("%s %d",&newone.name,&newone.num);
	for(int i=0;i<n;i++)
	{
		if(strcmp(newone.name,a[i].name)==0)
/*���ﲻ��ֱ����==�ж������ַ����Ƿ���ȣ���Ҫ���ַ����ȽϺ���strcmp;
�ú������a��b��ÿ���ַ�������ascii��ֵ�Ƚϣ�
���������ȫ��ͬ����0�����a��ascii��ֵ�ȳ��ֽϴ��ߣ��᷵��1�����򷵻�-1��*/ 
		{
			a[i].num-=newone.num;
			if(a[i].num<0)
			{
				a[i].num+=newone.num;
				cout<<"��治�㣬�޷�����"<<endl; 
			}
			else cout<<"����ɹ�"<<endl; 
			flag=1;
			break;
		}
	}
	if(flag==0) cout<<"δ�ҵ��û���޷�����"<<endl;  
	system("pause");
	system("cls");

}
int main()
{
	FILE*List;
	if((List=fopen("List.txt","r+"))==NULL)//����r+��ʾ�򿪵��ļ��ɶ�; 
	{
		cout<<"����ļ���ȡʧ�ܣ�";
		return 0;
	}
	else
	{
		fscanf(List,"%d",&n);
		for(int i=0;i<n;i++) fscanf(List,"%s %d",&a[i].name,&a[i].num);
	}
	while(1)
	{
		cout<<"1.��ʾ����б�"<<endl<<"2.���"<<endl<<"3.����"<<endl<<"4.�˳�����"<<endl<<"��������ѡ��˵����ܣ�"<<endl; 
		char t=_getch();
		system("cls");
		int flag=0;
		switch(t)
		{
			case '1':
			{
				dispaly();
				break;//Ҫ��break���������ִ����case '1'����ȥִ�к��漸��case������ 
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
				if((fp=fopen("List.txt","w+"))==NULL)//����ֻ��дw+����д�� 
				{
					cout<<"����ļ���ȡʧ�ܣ�";
					return 0;
				}
				else
				{
					fprintf(fp,"%d\n",n);//֮ǰ���еĲ������Խṹ��������У�ֻ�����Ҫ��������ǰ������д�ļ��� 
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
