#include <stdio.h>
#include <windows.h>
#include <string.h>

typedef struct Node {
    char name[200];
    int num;
    struct Node* next;
}nodeList;

void menu();
void showList(nodeList* p);
void fileWrite(nodeList* p);
int find(nodeList* p, char* name);
nodeList* fileRead();
nodeList* getin(nodeList* p);
nodeList* getout(nodeList* p);
nodeList* remove(nodeList* p, char* name, int num, int del);

int main() {
    menu();
}

// 打印菜单
void menu() {
    int t, q = 1;
    nodeList* p = (nodeList*)malloc(sizeof(nodeList)); //初始化仓库
    p->next = NULL;
    while (q) {
        system("cls");
        printf("--------------\n");
        printf("欢迎来到仓库！\n");
        printf("1.显示存货列表\n");
        printf("2.进库\n");
        printf("3.出库\n");
        printf("4.保存\n");
        printf("5.读取\n");
        printf("0.退出\n");
        printf("--------------\n");
        scanf("%d", &t);
        switch (t) {
        case 1:
            showList(p); //打印仓库清单
            break;
        case 2:
            p = getin(p); //入库
            break;
        case 3:
            p = getout(p); //出库
            break;
        case 4:
            fileWrite(p); //保存文件
            break;
        case 5:
            p = fileRead(); //读取文件
            break;
        case 0: //退出
            q = 0;
            printf("正在退出，欢迎下次再来......\n");
            Sleep(1500);
            break;
        default:
            printf("error\n");
            system("pause");
        }
    }
}

//入库
nodeList* getin(nodeList* p) {
    char name[100];
    int num;
    nodeList* temp = p; //临时变量
    nodeList* value = (nodeList*)malloc(sizeof(nodeList));
    system("cls");
    printf("请输入要存入仓库的货物名称:\n");
    scanf("%s", name);
    printf("请输入要存入仓库的货物数量:\n");
    scanf("%d", &num);
    int position = find(p, name); //寻找货物是否已经在仓库中，若在则返回位置,否则返回0
    if (position == 0) { //插入当链尾
        for (int i = 0; temp->next != NULL; i++) {
            temp = temp->next;
        }
        value->next = NULL;
        strcpy(value->name, name);
        value->num = num;
        temp->next = value;
    }
    else {
        for (int i = 0; i < position; i++) {
            temp = temp->next;
        }
        temp->num += num;
    }
    printf("已存入仓库......\n");
    system("pause");
    return p;
}

//出库
nodeList* getout(nodeList* p) {
    char name[100];
    int num, del;
    nodeList* temp = p;
    system("cls");
    printf("请输入要出库的货品名字:\n");
    scanf("%s", name);
    del = find(p, name); //寻找货物在仓库中的位置
    if (del > 0) {
        printf("请输入要取出的货物数量:\n");
        scanf("%d", &num);
        p = remove(p, name, num, del);
        system("pause");
    }
    else {
        printf("未找到货物......\n");
    }
    return p;
}

//打印仓库
void showList(nodeList* p) {
    system("cls");
    nodeList* temp = p->next;
    printf("---------------------------------------------------\n");
    printf("||货品名称\t\t\t\t货品数量  ||\n");
    printf("---------------------------------------------------\n");
    for (int i = 0; temp != NULL; i++) {
        printf("||%-10s\t\t\t\t%-10d||\n", temp->name, temp->num);
        printf("---------------------------------------------------\n");
        temp = temp->next;
    }
    system("pause");
}

// 寻找货物在仓库中的位置
int find(nodeList* p, char* name) {
    nodeList* temp = p->next;
    for (int i = 1; temp != NULL; i++) {
        if (!strcmp(name, temp->name))
            return i;
        temp = temp->next;
    }
    return 0;
}

// 取出货物
nodeList* remove(nodeList* p, char* name, int num, int del) {
    nodeList* temp = p;
    for (int i = 1; i < del; i++) {
        temp = temp->next;
    }
    if (num == temp->next->num) {
        nodeList* c = temp->next;
        temp->next = temp->next->next;
        printf("已取出货物....... \n");
        free(c);
    }
    else if (num < temp->next->num) {
        temp->next->num -= num;
        printf("已取出货物....... \n");
    }
    else {
        printf("error,没有那么多货物......\n");
    }
    return p;
}

// 写入文件
void fileWrite(nodeList* p) {
    FILE* fp = NULL;
    nodeList* temp = p->next;

    system("cls");
    if ((fp = fopen("test.txt", "w")) == NULL) {
        printf("File failed to open......\n");
        system("pause");
        return;
    }
    else {
        printf("打开文件成功......\n");
    }
    while (temp != NULL) {
        fprintf(fp, "%s %d\n", temp->name, temp->num); //逐行写入文件
        temp = temp->next;
    }
    fclose(fp);
    printf("保存成功......\n");
    system("pause");
}

//读取文件
nodeList* fileRead() {
    nodeList* p = (nodeList*)malloc(sizeof(nodeList));
    nodeList* temp = p;
    system("cls");
    FILE* fp;
    if ((fp = fopen("test.txt", "r")) == NULL) {
        printf("File failed to open......\n");
        system("pause");
        return 0;
    }
    else {
        printf("打开文件成功\n");
    }

    nodeList* q[1000];
    int i = 0;
    q[i] = (nodeList*)malloc(sizeof(nodeList));
    while (fscanf(fp, "%s %d", q[i]->name, &q[i]->num) != EOF) { //逐行读取文件
        temp->next = q[i];
        temp = temp->next;
        temp->next = NULL;
        i++;
        q[i] = (nodeList*)malloc(sizeof(nodeList));
    }
    for (int x = 0; x <= i; x++)
        free(q[i]);
    fclose(fp);
    printf("读取成功\n");
    printf("即将打印仓库......\n");
    Sleep(1500);
    showList(p);
    return p;
}
