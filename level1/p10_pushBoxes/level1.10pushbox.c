/*
ǽ�ᱻ�ƶ�->�ո񳤶Ⱥͱ�ǳ��Ȳ�һ��
�ж�ǰ������
��¼����
�����ļ�����¼�ؿ�
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<Windows.h>
#define Length 10//��Ϸ����ĳ��Ϳ�

int x = 0, y = 0;
int walkcnt = 0;
int score = 0;

int map[Length][Length] = { 0 };// �������Ϸ����ģ��

int count1();
int count2();
void CursorGoto(int x, int y);//��궨λ
void up();
void down();
void left();
void right();
void ChooseLevel();
void GetMap(FILE*fp);
void DrawMap();
int find();
void HomeScreen();
void EndScreen();
int grade();
void SaveGrade();

int main()
{
    int n, m;
    system("title ��������Ϸ~");
    system("color F3");
    
    HomeScreen();
    ChooseLevel();

    getchar();

    system("cls");

    n = count1();

    while (1)
    {
        system("cls");
        DrawMap();
        m = count2();
        walkcnt++;

        switch (getchar())
        {
        case 'w':up(); break;
        case 's':down(); break;
        case 'a':left(); break;
        case 'd':right(); break;
        default:printf("����������");break;
        }

        if (n == m)
        {
            EndScreen();
            SaveGrade();
            return 0;
        }
    }
}

// ��w��ʱ���������
void up()
{
    find();
    switch (map[x - 1][y])//�ж���ǰ����ʲô
    {
    case 0://��
    {
        map[x - 1][y] = 3;
        map[x][y] = 0;
        break;
    }
    case 1:break;//ǽ
    case 2://����
    {
        if (map[x - 2][y] == 0)//����ǰ��գ����Ӻ���һ��
        {
            map[x - 2][y] = 2;
            map[x - 1][y] = 3;
            map[x][y] = 0;
        }
        else
        {
            if (map[x - 2][y] == 4)//����ǰ����Ŀ��
            {
                map[x][y] = 0;
                map[x - 1][y] = 3;
                map[x - 2][y] = 5;
            }
        }
        break;
    }
    }
}

//��d��ʱ���������
void down()
{
    find();
    switch (map[x + 1][y])
    {
    case 0:
    {
        map[x + 1][y] = 3;
        map[x][y] = 0;
        break;
    }
    case 1:break;
    case 2:
    {
        if (map[x + 2][y] == 0)
        {
            map[x + 2][y] = 2;
            map[x + 1][y] = 3;
            map[x][y] = 0;
        }
        else
        {
            if (map[x + 2][y] == 4)
            {
                map[x][y] = 0;
                map[x + 1][y] = 3;
                map[x + 2][y] = 5;
            }
        }
        break;
    }
    }
}

//��a��ʱ���������
void left()
{
    find();
    switch (map[x][y - 1])
    {
    case 0:
    {
        map[x][y - 1] = 3;
        map[x][y] = 0;
        break;
    }
    case 1:break;
    case 2:
    {
        if (map[x][y - 2] == 0)
        {
            map[x][y - 2] = 2;
            map[x][y - 1] = 3;
            map[x][y] = 0;
        }
        else
        {
            if (map[x][y - 2] == 4)
            {
                map[x][y] = 0;
                map[x][y - 1] = 3;
                map[x][y - 2] = 5;
            }
        }
        break;
    }
    }
}

//��d��ʱ���������
void right()
{
    find();
    switch (map[x][y + 1])
    {
    case 0://��
    {
        map[x][y + 1] = 3;
        map[x][y] = 0;
        break;
    }
    case 1:break;
    case 2:
    {
        if (map[x][y + 2] == 0)
        {
            map[x][y + 2] = 2;
            map[x][y + 1] = 3;
            map[x][y] = 0;
        }
        else
        {
            if (map[x][y + 2] == 4)
            {
                map[x][y] = 0;
                map[x][y + 1] = 3;
                map[x][y + 2] = 5;
            }
        }
        break;
    }
    }
}

void DrawMap()
{
    for (x = 0; x < Length; x++)
    {
        for (y = 0; y < Length; y++)
        {
            if (map[x][y] == 1)
                printf("��"); //���ש�������
            if (map[x][y] == 3)
                printf("��"); //����Լ���λ��
            if (map[x][y] == 2)
                printf("��"); //�������
            if (map[x][y] == 4)
                printf("��"); //�������Ҫ����λ��
            if (map[x][y] == 0)
                printf("  "); //����հ�
            if (map[x][y] == 5)
                printf("��"); //������ӵ��˸õ���λ��
        }
        printf("\n");
    }
}
//�ҵ��Լ���λ��
int find()//��breakֻ�������ڲ�ѭ����������������
{
    for (x = 0; x < Length; x++)
        for (y = 0; y < Length; y++)
        {
            if (map[x][y] == 3)return 0;
        }
    return 0;
}
//����Ҫ����λ�õĸ���
int count1()
{
    int n = 0;
    for (x = 0; x < Length; x++)
        for (y = 0; y < Length; y++)
        {
            if (map[x][y] == 4)
                n++;
        }
    return n;
}
//���ӵ���λ�õĸ���
int count2()
{
    int m = 0;
    for (x = 0; x < Length; x++)
        for (y = 0; y < Length; y++)
        {
            if (map[x][y] == 5)
                m++;
        }
    return m;
}
//����������
void HomeScreen()
{
    system("cls");
    CursorGoto(39, 8);
    printf("��ӭ����������Ȥ����������Ϸ");
    CursorGoto(34, 10);
    printf("��Ϸ����");
    CursorGoto(34, 12);
    printf("��wsad����С�����������ƶ������س�����������");
    CursorGoto(34, 14);
    printf("����0 �˳���Ϸ");
    CursorGoto(34, 16);
    printf("����1-4 ѡ��ؿ�");
}
//��¼�÷�
int grade()
{
    score = 1000 / walkcnt;
    return score;
}

void ChooseLevel()
{
    int n;
    scanf_s("%d", &n);
    FILE* fp;
    fp = NULL;
    switch (n)
    {
    case 0:
    {
        system("cls");  //�˳���Ϸ�������ʾ��Ϣ
        CursorGoto(34, 12);
        printf("��ӭ�´ι���");
        exit(0);
    }
    case 1:
    {
        fp = fopen("D:/tmp/pushbox/level1.txt", "a+");
        GetMap(fp);
        break;
    }
    case 2:
    {
        fp = fopen("D:/tmp/pushbox/level2.txt", "a+");
        GetMap(fp);
        break;
    }
    case 3:
    {
        fp = fopen("D:/tmp/pushbox/level3.txt", "a+");
        GetMap(fp);
        break;
    }
    case 4:
    {
        fp = fopen("D:/tmp/pushbox/level4.txt", "a+");
        GetMap(fp);
        break;
    }
    }
    fclose(fp);
}

void GetMap(FILE*fp)
{
    for (int i = 0;i < Length;i++)
    {
        for (int j = 0;j < Length;j++)
            fscanf_s(fp, "%d", &map[i][j]);
    }  
}

void SaveGrade()
{
    FILE* fp;
    fp = NULL;
    fp = fopen("D:/tmp/pushbox/level1.txt", "a+");
    fprintf(fp, "\n���ڱ��صĵ÷���%d\n", score);
    fprintf(fp, "%s\r\t", __DATE__);
    fprintf(fp, "%s\r\n", __TIME__);
    fclose(fp);
}

void EndScreen()
{
    system("cls");
    CursorGoto(39, 8);
    printf("$����Ϸʤ����$~\n");
    CursorGoto(39, 10);
    printf("���߹��Ĳ�����%d\n", walkcnt);
    score = grade(score);
    CursorGoto(39, 12);
    printf("�����ؿ��÷�%d\n", score);
    system("pause");
}
void CursorGoto(int x, int y) //��궨λ
{
    COORD pos = { x,y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}