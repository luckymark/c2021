#include <stdio.h>
#include <windows.h>
#include <time.h>
#include <math.h>
#include <conio.h>

int rank = 6;
//��ͼ�߳� L�������Թ����� 20�����İ�Χ��ǽ�� 2��������Χ·�� 2
#define L 24
#define WALL 0 //ǽ
#define ROUTE 1 //·��
#define PLAYER 2 //���

void menu();
void start();
void degree();
int init(int** maze);
void print(int** maze);
void creatMaze(int** maze, int x, int y);
void move(int** maze, char t, int& x, int& y);


int main() {
    menu();
    return 0;
}

//��ʾ���˵�
void menu() {
    char c;
    while (1) {
        system("cls");
        printf("---------------------\n");
        printf("---��ӭ�����Թ���Ϸ---\n");
        printf("----1. ��ʼ��Ϸ -----\n");
        printf("----2. ��Ϸ�Ѷ� -----\n");
        printf("----0. �˳���Ϸ -----\n");
        printf("--------------------\n");
        c = _getch();
        switch (c) {
            case '1':
                start();
                break;
            case '2':
                degree();
                break;
            case '0':
                printf("��ӭ�´μ�������........\n");
                Sleep(1500);
                exit(0);
            default:
                break;
        }
    }
}

//��ʼ��Ϸ
void start() {
    char t;
    //x��y����ҵ����꣬out�ǳ��ڵ�������(�к�)
    int i, x = 2, y = 1, out = 0;
    //��ʼ����������ӣ�����ϵͳʱ�����������,֮��Ϳ���ʹ��rand�������������
    srand((unsigned)time(NULL));
    //��ʼ���Թ�
    int** maze = (int**)malloc(L * sizeof(int*));
    for (i = 0; i < L; i++) {
        maze[i] = (int*)calloc(L, sizeof(int));
    }
    //�õ�����������
    out = init(maze);
    system("cls");
    print(maze);
    while (t = _getch()) {
        system("cls");
        move(maze, t, x, y);
        print(maze);
        if (x == out && y == L - 2) {
            system("cls");
            printf("��ϲ�㣬�������յ�!\n");
            printf("�����������˵�\n");
            Sleep(1500);
            break;
        }
    }
    for (i = 0; i < L; i++)
        free(maze[i]);
    free(maze);
}

void degree() {
    char t;
    system("cls");
    printf("---------------------\n");
    printf("---��������Ϸ�Ѷ�---\n");
    printf("----- 1. �� -----\n");
    printf("----- 2. �е� -----\n");
    printf("----- 3. ���� -----\n");
    printf("--------------------\n");
    t = _getch();
    switch (t) {
        case '1':
            printf("���޸���Ϸ�Ѷ�Ϊ��\n");
            rank = 6;
            break;
        case '2':
            printf("���޸���Ϸ�Ѷ�Ϊ�е�\n");
            rank = 3;
            break;
        case '3':
            printf("���޸���Ϸ�Ѷ�Ϊ����\n");
            rank = 0;
            break;
        default:
            break;
    }
    printf("����������ز˵�\n");
    system("pause");

}
//��ʼ���Թ�
int init(int** maze) {
    int i;
    //������㶼����Ϊ�յ�·������ֹ�ڴ�
    for (i = 0; i < L; i++) {
        maze[i][0] = ROUTE;
        maze[0][i] = ROUTE;
        maze[i][L - 1] = ROUTE;
        maze[L - 1][i] = ROUTE;
    }
    creatMaze(maze, 2, 2);//�����Թ���ںͳ���
    maze[2][1] = PLAYER; //����ҳ�ʼλ��
    //Ѱ�ҳ��ڣ����ڿ��ܲ���[L-3][L-2]�������Ҫ����
    for (i = L - 3; i >= 0; i--) {
        if (maze[i][L - 3] == ROUTE) {
            maze[i][L - 2] = ROUTE;
            return i; //���ڷ���������
        }
    }
}

//��ӡ�Թ�
void print(int** maze) {
    int i, j;
    for (i = 0; i < L; i++) {
        for (j = 0; j < L; j++) {
            if (maze[i][j] == ROUTE)
                printf("  ");
            else if (maze[i][j] == WALL)
                printf("ǽ");
            else if (maze[i][j] == PLAYER)
                printf("ʮ");
        }
        printf("\n");
    }
}

//�����Թ�
void creatMaze(int** maze, int x, int y) {
    maze[x][y] = ROUTE;
    //ȷ���ĸ�����������������ǹ̶�������������������
    int direction[4][2] = { { 1,0 },{ -1,0 },{ 0,-1 },{ 0,1 } };
    for (int i = 0; i < 4; i++) {
        int r = rand() % 4;
        int temp = direction[0][0];
        direction[0][0] = direction[r][0];
        direction[r][0] = temp;
        temp = direction[0][1];
        direction[0][1] = direction[r][1];
        direction[r][1] = temp;
    }
    //���ĸ�������
    for (int i = 0; i < 4; i++) {
        int dx = x;
        int dy = y;
        //�����ڵľ��룬��Rank��������С
        int range = 1 + (rank == 0 ? 0 : rand() % rank);
        while (range > 0) {
            //�������Ҫ���ʵ�������
            dx += direction[i][0];
            dy += direction[i][1];
            //�ų�����ͷ·
            if (maze[dx][dy] == ROUTE) {
                break;
            }
            //�ж��Ƿ��ڴ�·��
            int count = 0;
            for (int j = dx - 1; j < dx + 2; j++) {
                for (int k = dy - 1; k < dy + 2; k++) {
                    //abs(j - dx) + abs(k - dy) == 1 ȷ��ֻ�жϾŹ�����ĸ��ض�λ��
                    if (abs(j - dx) + abs(k - dy) == 1 && maze[j][k] == ROUTE) {
                        count++;
                    }
                }
            }
            //count����1����ǽ��ᱻ�ڴ���ֹͣ
            if (count > 1)
                break;
            //ȷ�������ڴ�ʱ��ǰ��
            range -= 1;
            maze[dx][dy] = ROUTE;
        }
        //û���ڴ�Σ�գ��Դ�Ϊ�ڵ�ݹ�
        if (range <= 0) {
            creatMaze(maze, dx, dy);
        }
    }
}

//�ƶ�
void move(int** maze, char t, int& x, int& y) {
    int i, j;
    i = x;
    j = y;
    switch (t) {
        case 'w':
            x--;
            break;
        case 's':
            x++;
            break;
        case 'a':
            y--;
            break;
        case 'd':
            y++;
            break;
        default:
            break;
    }
    if (x >= 0 && x < L-1 && y >= 0 && y < L-1 && maze[x][y] != WALL) {
        maze[i][j] = ROUTE;
        maze[x][y] = PLAYER;
    }
    else {
        x = i;
        y = j;
    }
}
