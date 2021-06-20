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

// ��ӡ�˵�
void menu() {
    int t, q = 1;
    nodeList* p = (nodeList*)malloc(sizeof(nodeList)); //��ʼ���ֿ�
    p->next = NULL;
    while (q) {
        system("cls");
        printf("--------------\n");
        printf("��ӭ�����ֿ⣡\n");
        printf("1.��ʾ����б�\n");
        printf("2.����\n");
        printf("3.����\n");
        printf("4.����\n");
        printf("5.��ȡ\n");
        printf("0.�˳�\n");
        printf("--------------\n");
        scanf("%d", &t);
        switch (t) {
        case 1:
            showList(p); //��ӡ�ֿ��嵥
            break;
        case 2:
            p = getin(p); //���
            break;
        case 3:
            p = getout(p); //����
            break;
        case 4:
            fileWrite(p); //�����ļ�
            break;
        case 5:
            p = fileRead(); //��ȡ�ļ�
            break;
        case 0: //�˳�
            q = 0;
            printf("�����˳�����ӭ�´�����......\n");
            Sleep(1500);
            break;
        default:
            printf("error\n");
            system("pause");
        }
    }
}

//���
nodeList* getin(nodeList* p) {
    char name[100];
    int num;
    nodeList* temp = p; //��ʱ����
    nodeList* value = (nodeList*)malloc(sizeof(nodeList));
    system("cls");
    printf("������Ҫ����ֿ�Ļ�������:\n");
    scanf("%s", name);
    printf("������Ҫ����ֿ�Ļ�������:\n");
    scanf("%d", &num);
    int position = find(p, name); //Ѱ�һ����Ƿ��Ѿ��ڲֿ��У������򷵻�λ��,���򷵻�0
    if (position == 0) { //���뵱��β
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
    printf("�Ѵ���ֿ�......\n");
    system("pause");
    return p;
}

//����
nodeList* getout(nodeList* p) {
    char name[100];
    int num, del;
    nodeList* temp = p;
    system("cls");
    printf("������Ҫ����Ļ�Ʒ����:\n");
    scanf("%s", name);
    del = find(p, name); //Ѱ�һ����ڲֿ��е�λ��
    if (del > 0) {
        printf("������Ҫȡ���Ļ�������:\n");
        scanf("%d", &num);
        p = remove(p, name, num, del);
        system("pause");
    }
    else {
        printf("δ�ҵ�����......\n");
    }
    return p;
}

//��ӡ�ֿ�
void showList(nodeList* p) {
    system("cls");
    nodeList* temp = p->next;
    printf("---------------------------------------------------\n");
    printf("||��Ʒ����\t\t\t\t��Ʒ����  ||\n");
    printf("---------------------------------------------------\n");
    for (int i = 0; temp != NULL; i++) {
        printf("||%-10s\t\t\t\t%-10d||\n", temp->name, temp->num);
        printf("---------------------------------------------------\n");
        temp = temp->next;
    }
    system("pause");
}

// Ѱ�һ����ڲֿ��е�λ��
int find(nodeList* p, char* name) {
    nodeList* temp = p->next;
    for (int i = 1; temp != NULL; i++) {
        if (!strcmp(name, temp->name))
            return i;
        temp = temp->next;
    }
    return 0;
}

// ȡ������
nodeList* remove(nodeList* p, char* name, int num, int del) {
    nodeList* temp = p;
    for (int i = 1; i < del; i++) {
        temp = temp->next;
    }
    if (num == temp->next->num) {
        nodeList* c = temp->next;
        temp->next = temp->next->next;
        printf("��ȡ������....... \n");
        free(c);
    }
    else if (num < temp->next->num) {
        temp->next->num -= num;
        printf("��ȡ������....... \n");
    }
    else {
        printf("error,û����ô�����......\n");
    }
    return p;
}

// д���ļ�
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
        printf("���ļ��ɹ�......\n");
    }
    while (temp != NULL) {
        fprintf(fp, "%s %d\n", temp->name, temp->num); //����д���ļ�
        temp = temp->next;
    }
    fclose(fp);
    printf("����ɹ�......\n");
    system("pause");
}

//��ȡ�ļ�
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
        printf("���ļ��ɹ�\n");
    }

    nodeList* q[1000];
    int i = 0;
    q[i] = (nodeList*)malloc(sizeof(nodeList));
    while (fscanf(fp, "%s %d", q[i]->name, &q[i]->num) != EOF) { //���ж�ȡ�ļ�
        temp->next = q[i];
        temp = temp->next;
        temp->next = NULL;
        i++;
        q[i] = (nodeList*)malloc(sizeof(nodeList));
    }
    for (int x = 0; x <= i; x++)
        free(q[i]);
    fclose(fp);
    printf("��ȡ�ɹ�\n");
    printf("������ӡ�ֿ�......\n");
    Sleep(1500);
    showList(p);
    return p;
}
