#include "link.h"
void HomeScreen()
{
    int n;
    int i, j = 1;
    gotoxy(43, 18);
    color(11);
    printf("进销存小程序");
    color(14);          			//黄色边框
    for (i = 20; i <= 26; i++)   	//输出上下边框┅
    {
        for (j = 27; j <= 74; j++)  //输出左右边框┇
        {
            gotoxy(j, i);
            if (i == 20 || i == 26)
            {
                printf("-");
            }
            else if (j == 27 || j == 74)
            {
                printf("|");
            }
        }
    }
    color(10);
    gotoxy(35, 22);
    printf("显示存货请按1");
    gotoxy(55, 22);
    printf("出库请按3");
    gotoxy(35, 24);
    printf("列表入库请按2");
    gotoxy(55, 24);
    printf("退出程序请按4\n");
}

void importdata()
{
    char buf[BUFSIZE] = { '\0' };
    char charthead[BUFSIZE] = { '\0' };
    head = NULL;
    fopen_s(&fp, "D:/tmp/warehouse.txt", "r");
    if (fp == NULL)
        printf("Cannot open file!\n");
    fgets(charthead, BUFSIZE, fp);
    do
    {
        Node* p = (Node*)malloc(sizeof(Node));
        p->next = NULL;
        fgets(buf, BUFSIZE, fp);    //一次读取一行
        sscanf(buf, "%s\t%d\t%d", &(p->name), &(p->type), &(p->quantity));
        Node* last = head;
        if (head)
        {
            while (last->next)
                last = last->next;
            last->next = p;
        }
        else
            head = p;
    } while (!feof(fp));
    fclose(fp);
}

void ShowList()
{
    printf("name\ttype\tquantity\n");
    for (Node* q = head;q;q = q->next)
        printf("%s\t%d\t%d\n", q->name, q->type, q->quantity);
}

void Input()
{
    int issame = 1;
    Node* p = (Node*)malloc(sizeof(Node));
    p->next = NULL;
    printf("请要入库的‘货物名称 货物数量’\n");
    scanf("%s %d", &(p->name), &(p->quantity));
    fflush(stdin);
    for (Node* q = head;q->next;q = q->next)
    {
        if (!strcmp(p->name, q->name))
        {
            q->quantity += p->quantity;
            issame = 0;
            update();
            break;
        }
    }
    if (issame)
    {
        Node* last = head;
        if (head)
        {
            while (last->next)
                last = last->next;
            last->next = p;
        }
        else
            head = p;
        update();
    }
    printf("\n恭喜老板，出库成功！\n");
}

void Output()
{
    char outname[100];
    int outcnt, isfound = 1;
    color(11);
    printf("请输入要出库的‘货物名称 货物数量’:\n");
    scanf("%s %d", &outname, &outcnt);
    for (Node* q = head;q->next;q = q->next)
    {
        if (!strcmp(outname, q->name))
        {
            q->quantity -= outcnt;
            printf("\n恭喜老板，出库成功！\n");
            if (q->quantity < 0)
                printf("存货数量不够\n");
            else
            {
                update();
                isfound = 0;
            }
        }
    }
    if (isfound)
        printf("没有该货物的储存记录，无法出库\n");
}

void update()
{
    fp = fopen("D:/tmp/warehouse2.txt", "w+");
    fprintf(fp, "*%s\r\n", __DATE__);
    for (Node* q = head;q;q = q->next)
        fprintf(fp, "\n%s\t%d\t%d", q->name, q->type, q->quantity);
    fclose(fp);
}


void color(int c)
{
    //SetConsoleTextAttribute是API设置控制台窗口字体颜色和背景色的函数
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), c);
    //更改背景颜色 
}

void gotoxy(int x, int y)
{
    COORD c;
    c.X = x;
    c.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}
