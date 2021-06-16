#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<conio.h>
//�Ͳ���ݴ����ļ�

struct Ware
{
    int num;//��Ʒ���
    int stock;//��Ʒ��� 
    char name[20];//��Ʒ���֣�����ʱ�����þ�̬���飩 
    char store[20];//��Ʒ���ڲֿ� 
    struct Ware *next;//��һ��ָ��ڵ� 
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
    ware* temp=p;//ͷ�ڵ��Ƿ�������
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

ware* putin(ware* p)//��⣬������Ʒ 
{
    system("cls");
    printf("\tthe ware is under putin mode\n");
    printf("-----------------------------------------------\n");
	ware* temp=p;//��ͷ�ڵ㿪ʼ��ͷ�ڵ�������
	int i=1;
    while(temp->next!=NULL)
    {
        temp=temp->next;
        ++i;
    }
	//��ָ���ƶ�����β
	//�������������
	append(temp);//���ϱ�β
	//��ȡ��������
    printf("\n\n");
    printf("the ware is successfully putin....\n\n\n");
    printf("\t enter anykey to back to menu\n");//һ�μ�һ���������β 
    while(!getch())
    {
    	//press anykey to continue
	}
    return p;//����ͷ�ڵ� 
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

ware* putout(ware* p)//���⣬ɾ����Ʒ 
{

	system("cls");
    ware* temp=p;
    printf("\nthe repository is below:\n");
    printf("------------------------------------------\n");
    printf("\nnum\tstore\tname\tcommodity stock\n");
    printf("------------------------------------------\n");
    while(temp->next!=NULL)//ָ�� 
    {
        printf("%d\t%s\t%s\t%d\n",temp->num,temp->store,temp->name,temp->stock);
        printf("------------------------------------------\n");
        temp=temp->next;
    }
    printf("\nenter the number of the commodity you want to out\n");
    int numm;
    scanf("%d",&numm);
    deleteNode(p,numm);
    //ɾ������ 
    //Sleep(1500);
    return p;
}

void deleteNode(ware* p,int numm)
{
    ware* temp1=p;//�����ƶ�
    ware* temp2;//���ڲ���
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
    ware* temp2;//�ƶ�temp2
    /*temp1->next=(ware*)malloc(sizeof(ware));
    temp1=temp1->next;*/
    for(int i=0;i<5;i++)
    {
        strcpy(temp1->name,"123");
        strcpy(temp1->store,"321");//���ַ���������ֵ 
        temp1->num=i+1;
        temp1->stock=50;
        temp2=(ware*)malloc(sizeof(ware));
        temp1->next=temp2;
        temp1=temp2;
    }
    temp1->next=NULL;
    return p; 
}

void writeFile(ware* temp1)//�ļ����
{
    FILE* fp;
    fp=fopen("data.txt","w");
    if(fp==NULL)
    {
        printf("File fail to open!\n");
        exit(0);
    }
    fseek(fp,1,SEEK_END);//ȫд��һ���� 
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
