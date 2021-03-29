#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#define Wall 1
#define Road 0

#define Start 2
#define End 3

#define Up 1
#define Down 2
#define Left 3
#define Right 4

#define n 25

int Length, Width;

typedef struct node{
    int x;
    int y;
    int c;
} node;
int map[n][n];
node no[n * n];

void move(int x, int y);

void hidden();

void create(int x, int y);

int get_key();

void paint(int x, int y);

void game();

void hidden(){
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO c;
    GetConsoleCursorInfo(hOut, &c);
    c.bVisible = 0;
    SetConsoleCursorInfo(hOut, &c);
}

void move(int x, int y){
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void create(int x, int y){
    int c[4][2]={0,1,1,0,0,-1,-1,0};
    int i, j, t;
    // randomly swap
    for(i=0;i<4;i++){
        j=rand()%4;
        t=c[i][0];c[i][0]=c[j][0];c[j][0]=t;
        t=c[i][1];c[i][1]=c[j][1];c[j][1]=t;
    }
    map[x][y]=Road;
    for(i=0;i<4;i++)
        if(map[x + 2 * c[i][0]][y + 2 * c[i][1]]==Wall){
            map[x + c[i][0]][y + c[i][1]]=Road;
            create(x+2*c[i][0], y+2*c[i][1]);
        }
    map[2][1]=Start;
    map[Width - 1][Length]=End;
}
int get_key()
{
    char c;
    while (c = getch())
    {
        c = getch();
        if (c == 72) return Up; // the up key next to '0'
        if (c == 80) return Down;
        if (c == 75) return Left;
        if (c == 77) return Right;
    }
    return 0;
}

void paint(int x, int y){
    int i;
    move(2 * y + 1, x + 7);
    switch (map[x][y])
    {
        case Start:
            printf("&"); break;
        case End:
            printf("$"); break;
        case Wall:
            printf("#"); break;
        case Road:
            printf("*"); break;
    }
}
void game()
{
    int x = 2, y = 1;
    int c;
    while (1)
    {
        move(2 * y + 1, x + 7);
        printf("@\n");
        if (map[x][y] == End)
        {
            move(50, 15);
            printf("Congratulations!");
            move(2 * y + 1, x + Width - 13);
            break;
        }
        c = get_key();
        switch (c)
        {
            case Up:
                if (map[x - 1][y] != Wall)
                {
                    paint(x, y);
                    x--;
                }
                break;
            case Down:
                if (map[x + 1][y] != Wall)
                {
                    paint(x, y);
                    x++;
                }
                break;
            case Left:
                if (map[x][y - 1] != Wall)
                {
                    paint(x, y);
                    y--;
                }
                break;
            case Right:
                if (map[x][y + 1] != Wall)
                {
                    paint(x, y);
                    y++;
                }
                break;
        }
    }
}

int main()
{
    system("COLOR 00");
    int i, j, s;
    printf("Start:1 End:2 Please confirm your purpose\n");
    printf("Input:");
    scanf("%d", &s);
    switch (s)
    {
        case 1:
            printf("Input the width of maze(Odd): ");
            scanf("%d", &Width);
            printf("Input the length of maze(Odd): ");
            scanf("%d", &Length);
            printf("   ");
            for (i = 65; i <= (Length + 64); i++)
                printf("%c ", i);
            printf("\n");
            for (i = 65; i <= (Length + 64); i++)
                printf(" %c\n", i);
            system("COLOR 56");
            srand((unsigned)time(NULL));
            hidden();
            for (i = 0; i <= Length + 1; i++)
                for (j = 0; j <= Width + 1; j++)
                    if (i == 0 || i == Length + 1 || j == 0 || j == Width + 1)
                        map[i][j] = Road;
                    else map[i][j] = Wall;
            create(2 * (rand() % (Length / 2) + 1), 2 * (rand() % (Width / 2) + 1));
            for (i = 0; i <= Length + 1; i++)
            {
                map[i][0] = Wall;
                map[i][Width + 1] = Wall;
            }
            for (j = 0; j <= Width + 1; j++)
            {
                map[0][j] = Wall;
                map[Length + 1][j] = Wall;
            }
            for (i = 1; i <= Length; i++)
                for (j = 1; j <= Width; j++)
                    paint(i, j);
            game();
            getch();
            return 0;
            break;
        case 2:
            printf("Goodbye~");
            break;
        default: break;
    }
}