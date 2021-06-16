#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<conio.h>
//就差将数据存入文件

struct Ware
{
    int num;//产品序号
    int stock;//产品库存 
    char name[20];//产品名字（创建时可以用静态数组） 
    char store[20];//产品所在仓库 
    struct Ware *next;//下一个指针节点 
};
typedef struct Ware ware ;

void print(ware* p);
void menu(void);
ware* putin(ware* p);
ware* putout(ware* p);
ware* init(ware*p);
void append(ware* temp);
void deleteNode(ware* p,int numm);
ware* readFile();
void writeFile(ware* temp1);


int main()
{
    menu();
    return 0;
}

void menu(void)
{
    int k=1;
    ware* p=(ware*)malloc(sizeof(ware));
    p=init(p);
    while(k)
    {
        system("cls");
        int t;
        printf("\n\t1.\tshow the list\t\n");
        printf("\n\t2.\tenter warehouse\t\n");
        printf("\n\t3.\tputout warehouse\t\n");
        printf("\n\t4.\tsave the file\t\n");
        printf("\n\t5.\tread the file\t\n");
        printf("\n\t6.\texit\t\n");
        scanf("%d",&t);
        switch(t)
        {
            case 1:
                print(p);
                break;
            case 2:
                p=putin(p);
                break;
            case 3:
                p=putout(p);
                break;
            case 4:
            	writeFile(p);
            	Sleep(500);
            	break;
            case 5:
            	p=readFile();
            	break;
            case 6:
                printf("\n\tthanks for using!\n");
                k=0;
                break;
            default:
                printf("\n\terror!\n");
                break;
        }
    }

}

void print(ware* p)
{
    system("cls");
    ware* temp=p;//头节点是否有数据
    printf("\nnum\tstore\tname\tcommodity stock\n");
    printf("------------------------------------------\n");
    while(temp->next!=NULL){
        printf("%d\t%s\t%s\t%d\n",temp->num,temp->store,temp->name,temp->stock);
        printf("------------------------------------------\n");
        temp=temp->next;
    }
    printf("\t enter anykey to back to menu\n");
	while(!getch())
	{
		//press anykey
	}
}

ware* putin(ware* p)//入库，加入物品 
{
    system("cls");
    printf("\tthe ware is under putin mode\n");
    printf("-----------------------------------------------\n");
	ware* temp=p;//从头节点开始，头节点有数据
	int i=1;
    while(temp->next!=NULL)
    {
        temp=temp->next;
        ++i;
    }
	//将指针移动到表尾
	//创建新链表接上
	append(temp);//接上表尾
	//获取参数函数
    printf("\n\n");
    printf("the ware is successfully putin....\n\n\n");
    printf("\t enter anykey to back to menu\n");//一次加一个，插入表尾 
    while(!getch())
    {
    	//press anykey to continue
	}
    return p;//返回头节点 
}

void append(ware* temp)
{
    ware* newnode;
    newnode=(ware*)malloc(sizeof(ware));
    temp->next=newnode;
    temp=newnode;
    printf("\ninput the name of the store:\n");
    char tempChar[20];
    scanf("%s",tempChar);
    strcpy(temp->store,tempChar);
    printf("\ninput the name of the commodity:\n");
    scanf("%s",tempChar);
    strcpy(temp->name,tempChar);
    printf("\ninput the stock of the ware:\n");
    scanf("%d",&temp->stock);
    temp->num=5;
    temp->next=NULL;
}

ware* putout(ware* p)//出库，删除物品 
{

	system("cls");
    ware* temp=p;
    printf("\nthe repository is below:\n");
    printf("------------------------------------------\n");
    printf("\nnum\tstore\tname\tcommodity stock\n");
    printf("------------------------------------------\n");
    while(temp->next!=NULL)//指针 
    {
        printf("%d\t%s\t%s\t%d\n",temp->num,temp->store,temp->name,temp->stock);
        printf("------------------------------------------\n");
        temp=temp->next;
    }
    printf("\nenter the number of the commodity you want to out\n");
    int numm;
    scanf("%d",&numm);
    deleteNode(p,numm);
    //删除链表 
    //Sleep(1500);
    return p;
}

void deleteNode(ware* p,int numm)
{
    ware* temp1=p;//用于移动
    ware* temp2;//用于插入
    while(temp1->num!=numm&&temp1->next!=NULL)
    {
        temp2=temp1;
        temp1=temp1->next;
    }
    if(temp1->num==numm)
    {
        temp2->next=temp1->next;
    } else
    {
        printf("\nthere is no such a node to delete...\n");
    }
}

ware* init(ware*p)
{
    ware* temp1=p;
    ware* temp2;//移动temp2
    /*temp1->next=(ware*)malloc(sizeof(ware));
    temp1=temp1->next;*/
    for(int i=0;i<5;i++)
    {
        strcpy(temp1->name,"123");
        strcpy(temp1->store,"321");//用字符串函数赋值 
        temp1->num=i+1;
        temp1->stock=50;
        temp2=(ware*)malloc(sizeof(ware));
        temp1->next=temp2;
        temp1=temp2;
    }
    temp1->next=NULL;
    return p; 
}

void writeFile(ware* temp1)//文件光标
{
    FILE* fp;
    fp=fopen("data.txt","w");
    if(fp==NULL)
    {
        printf("File fail to open!\n");
        exit(0);
    }
    fseek(fp,1,SEEK_END);//全写在一行了 
	while(temp1->next!=NULL)
	{
		fprintf(fp,"\n%d\t%s\t%s\t%d\n",temp1->num,temp1->name,temp1->store,temp1->stock);
		temp1=temp1->next;
	}
    fclose(fp);
    printf("the file is successfully saved!\n");
}

ware* readFile()
{
    FILE* fp;
    fp=fopen("data.txt","r");
    if(fp==NULL)
    {
        printf("File fail to open!\n");
        exit(0);
    }
    ware data[100];
    ware* temp=(ware*)malloc(sizeof(ware));
    int i=0;
    while(fscanf(fp,"%d\t%s\t%s\t%d\n",&data[i].num,data[i].name,data[i].store,&data[i].stock)!=EOF)
    {
    	temp->next=&data[i];
    	temp=temp->next;
    	temp->next=NULL;
    	i++;
	}
	ware* p=data;
	printf("the file is successfully read!\n");
    return p;

}
