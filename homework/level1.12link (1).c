#include "link.h"
void HomeScreen()
{
    int n;
    int i, j = 1;
    gotoxy(43, 18);
    color(11);
    printf("������С����");
    color(14);          			//��ɫ�߿�
    for (i = 20; i <= 26; i++)   	//������±߿�
    {
        for (j = 27; j <= 74; j++)  //������ұ߿�
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
    printf("��ʾ����밴1");
    gotoxy(55, 22);
    printf("�����밴3");
    gotoxy(35, 24);
    printf("�б�����밴2");
    gotoxy(55, 24);
    printf("�˳������밴4\n");
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
        fgets(buf, BUFSIZE, fp);    //һ�ζ�ȡһ��
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
    printf("��Ҫ���ġ��������� ����������\n");
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
    printf("\n��ϲ�ϰ壬����ɹ���\n");
}

void Output()
{
    char outname[100];
    int outcnt, isfound = 1;
    color(11);
    printf("������Ҫ����ġ��������� ����������:\n");
    scanf("%s %d", &outname, &outcnt);
    for (Node* q = head;q->next;q = q->next)
    {
        if (!strcmp(outname, q->name))
        {
            q->quantity -= outcnt;
            printf("\n��ϲ�ϰ壬����ɹ���\n");
            if (q->quantity < 0)
                printf("�����������\n");
            else
            {
                update();
                isfound = 0;
            }
        }
    }
    if (isfound)
        printf("û�иû���Ĵ����¼���޷�����\n");
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
    //SetConsoleTextAttribute��API���ÿ���̨����������ɫ�ͱ���ɫ�ĺ���
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), c);
    //���ı�����ɫ 
}

void gotoxy(int x, int y)
{
    COORD c;
    c.X = x;
    c.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}
