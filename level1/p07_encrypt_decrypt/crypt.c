#include <stdio.h>
#include <windows.h>
#include <ctype.h>
#include <time.h>
//类似于哈夫曼树
//适用于26个字母的大小写，十个数字//
//在外部base文件中输入解密基于的文章，origin中输入要加密的密码
typedef struct mode
{
    char member;
    int pl;
} mode;
typedef struct haf
{
    int form;
    haf *left;
    haf *right;
    mode *save;
} haf;

void base(mode *node);
void step1(mode *node); //初始化member
void paixu(mode *node); //频率排序
void hafgo(mode *node, haf *any);
void encrypt(haf *n, haf *u, haf *l, FILE *mid);
void decrypt(haf *n, haf *u, haf *l, FILE *mid, FILE *final);

int main()
{

    mode uln[62];
    mode *node = uln;
    memset(uln, 0, sizeof(uln));
    //结构体数组用于储存 初始化pl uln means "upper and lower and number" 26+26+10
    step1(node);
    base(uln); //任意文章作为解密依据 放在base.txt中
    paixu(node);
    //新建3棵哈夫曼树
    haf num = {2, NULL, NULL, NULL};
    haf upper = {3, NULL, NULL, NULL};
    haf lowwer = {4, NULL, NULL, NULL};

    haf *n = &num;
    haf *l = &lowwer;
    haf *u = &upper;
    hafgo(node, u); //建立大写哈夫曼树
    hafgo(node, l); //建立小写哈夫曼树
    hafgo(node, n); //建立数字哈夫曼树

    int choice;
    puts("what do you want 1--encrypt 2--decrypt");
    scanf("%d", &choice);
    if (choice == 1)
    {
        FILE *mid = fopen("mid.txt", "w");

        encrypt(n, u, l, mid); //加密
        fclose(mid);
    }
    else
    {
        FILE *final = fopen("final.txt", "w");
        FILE *mid = fopen("mid.txt", "r");
        decrypt(n, u, l, mid, final); //解密
        fclose(final);
    }

    system("Pause");
    return 0;
}
void base(mode *node)
{
    FILE *fp = fopen("base.txt", "r");
    while (1)
    {
        char current = fgetc(fp);
        if (current == EOF)
            return;
        else if (isdigit(current))
            (node + current - '0')->pl++;
        else if (isupper(current))
            (node + current - 'A' + 10)->pl++;
        else if (islower(current))
            (node + current - 'a' + 36)->pl++;
    }
    fclose(fp);
}
void step1(mode *node)
{
    for (int i = 0; i < 10; i++)
        (node + i)->member = '0' + i;
    for (int i = 10; i < 36; i++)
        (node + i)->member = 'A' + i - 10;
    for (int i = 36; i < 62; i++)
        (node + i)->member = 'a' + i - 36;
}
void paixu(mode *node)
{
    mode temp;
    for (int i = 0; i < 10; i++)
        for (int j = i; j < 10; j++)
        {
            if ((node + j)->pl > (node + i)->pl)
            {
                temp = *(node + i);
                *(node + i) = *(node + j);
                *(node + j) = temp;
                continue;
            }
        }
    for (int i = 10; i < 36; i++)
        for (int j = i; j < 36; j++)
        {
            if ((node + j)->pl > (node + i)->pl)
            {
                temp = *(node + i);
                *(node + i) = *(node + j);
                *(node + j) = temp;
                continue;
            }
        }
    for (int i = 36; i < 62; i++)
        for (int j = i; j < 62; j++)
        {
            if ((node + j)->pl > (node + i)->pl)
            {
                temp = *(node + i);
                *(node + i) = *(node + j);
                *(node + j) = temp;
                continue;
            }
        }
}
void hafgo(mode *node, haf *head)
{
    int judge;
    haf *current;
    //初始化头节点
    current = head;
    head->save = NULL;
    if (rand() % 2 == 0)
    {
        current->left = (haf *)malloc(sizeof(haf));
        current->right = NULL;
        current = current->left;
    }
    else
    {
        current->right = (haf *)malloc(sizeof(haf));
        current->left = NULL;
        current = current->right;
    }
    //树的类型
    switch (head->form)
    {
    case 2:
    {

        for (int i = 0; i < 10; i++)
        {
            current->save = (node + i);
            if (i == 9)
            {
                current->left = NULL;
                current->right = NULL;
                break;
            }
            if (rand() % 2 == 0)
            {
                current->left = (haf *)malloc(sizeof(haf));
                current->right = NULL;
                current = current->left;
            }
            else
            {
                current->right = (haf *)malloc(sizeof(haf));
                current->left = NULL;
                current = current->right;
            }
        }
        break;
    }
    case 3:
    {

        for (int i = 10; i < 36; i++)
        {
            current->save = (node + i);
            if (i == 35)
            {
                current->left = NULL;
                current->right = NULL;
                break;
            }
            if (rand() % 2 == 0)
            {
                current->left = (haf *)malloc(sizeof(haf));
                current->right = NULL;
                current = current->left;
            }
            else
            {
                current->right = (haf *)malloc(sizeof(haf));
                current->left = NULL;
                current = current->right;
            }
        }
        break;
    }
    case 4:
    {

        for (int i = 36; i < 62; i++)
        {
            current->save = (node + i);
            if (i == 61)
            {
                current->left = NULL;
                current->right = NULL;
                break;
            }
            if (rand() % 2 == 0)
            {
                current->left = (haf *)malloc(sizeof(haf));
                current->right = NULL;
                current = current->left;
            }
            else
            {
                current->right = (haf *)malloc(sizeof(haf));
                current->left = NULL;
                current = current->right;
            }
        }
        break;
    }
    }
}
void encrypt(haf *n, haf *u, haf *l, FILE *mid)
{
    FILE *origin = fopen("origin.txt", "r");

    while (1)
    {
        char current = fgetc(origin);
        if (current == EOF)
            return;
        if (isdigit(current))
        {
            haf *seek = n;
            fprintf(mid, "2");
            for (int i = 0; i < 10; i++)
                if (seek->right == NULL)
                {
                    fprintf(mid, "0");
                    seek = seek->left;
                    if (seek->save->member == current)
                        break;
                }
                else if (seek->left == NULL)
                {
                    fprintf(mid, "1");
                    seek = seek->right;
                    if (seek->save->member == current)
                        break;
                }
        }
        else if (isupper(current))
        {
            haf *seek = u;
            fprintf(mid, "3");
            for (int i = 10; i < 36; i++)
                if (seek->right == NULL)
                {
                    fprintf(mid, "0");
                    seek = seek->left;
                    if (seek->save->member == current)
                        break;
                }
                else if (seek->left == NULL)
                {
                    fprintf(mid, "1");
                    seek = seek->right;
                    if (seek->save->member == current)
                        break;
                }
        }
        else if (islower(current))
        {
            haf *seek = l;
            fprintf(mid, "4");
            for (int i = 36; i < 62; i++)
                if (seek->right == NULL)
                {
                    fprintf(mid, "0");
                    seek = seek->left;
                    if (seek->save->member == current)
                        break;
                }
                else if (seek->left == NULL)
                {
                    fprintf(mid, "1");
                    seek = seek->right;
                    if (seek->save->member == current)
                        break;
                }
        }
        else if (current == ' ')
            fprintf(mid, "5");
    }
}
void decrypt(haf *n, haf *u, haf *l, FILE *mid, FILE *final)
{
    char current = fgetc(mid);

    while (1)
    {
        haf *seekn = n;
        haf *seekl = l;
        haf *seeku = u;
        if (current == EOF)
            return;
        switch (current)
        {
        case '2':
        {

            for (int i = 0;; i++)
            {
                current = fgetc(mid);
                if (current == '0' && seekn->left != NULL)
                    seekn = seekn->left;
                else if (current == '1' & seekn->right != NULL)
                    seekn = seekn->right;
                else
                {
                    fprintf(final, "%c", seekn->save->member);
                    break;
                }
            }
            break;
        }
        case '3':
        {

            for (int i = 0;; i++)
            {
                current = fgetc(mid);
                if (current == '0' && seeku->left != NULL)
                    seeku = seeku->left;
                else if (current == '1' & seeku->right != NULL)
                    seeku = seeku->right;
                else
                {
                    fprintf(final, "%c", seeku->save->member);
                    break;
                }
            }
            break;
        }
        case '4':
        {

            for (int i = 0;; i++)
            {
                current = fgetc(mid);
                if (current == '0' && seekl->left != NULL)
                    seekl = seekl->left;
                else if (current == '1' & seekl->right != NULL)
                    seekl = seekl->right;
                else
                {
                    fprintf(final, "%c", seekl->save->member);
                    break;
                }
            }
            break;
        }
        case '5':
        {
            fprintf(final, " ");
            current = fgetc(mid);
            break;
        }
        }
    }
}