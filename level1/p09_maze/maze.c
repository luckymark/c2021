#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
int c_r, c_c, ch, i, j,quitflag;
enum {Width = 50, Height = 25};
char out[(Width+1) * (Height+1)];
int dir[4][2] = {
    {0,1},
    {0,-1},
    {1,0},
    {-1,0}
};
int ** map = NULL;
int * set = NULL;
void init();
void victory();
void showMap(int ** map);
void dig();
int find(int x);
void interact();
int main() {
    while (1) {
        init();
        dig();
        system("cls");
        showMap(map);
        printf("Use WASD or arrows to move to '$'.\n");
        while (c_r != Height - 1 || c_c != Width - 1) {
            interact();
        }
        victory();
        if (quitflag) break;
    }
    printf("\nThanks for playing.");
    return 0;
}
void init() {
    srand((unsigned)time(0));
    c_r = c_c = 0;
    if (!set) set = (int *)malloc(Height * Width * sizeof(int));
    for (i = 0; i < Height * Width; ++ i) set[i] = i;
    if (!map) map = (int **)malloc(Height * sizeof(int *));
    for (i = 0; i < Height; ++ i) {
        map[i] = (int *)malloc(Width * sizeof(int));
    }
    for (i = 0; i < Height; ++ i) 
        for (j = 0; j < Width; ++ j)
            map[i][j] = 1;
}
void dig() {
    while (1) {
        int p1 = find(0), p2 = find(Height * Width - 1);
        if (p1 == p2) {
            break;
        }
        int r = rand() % Height, c = rand() % Width;
        int cnt = 0;
        for (i = 0; i < 4; ++ i) {
            int nr = r + dir[i][0], nc = c + dir[i][1];
            if (nr >= 0 && nr < Height && nc >= 0 && nc < Width && !map[nr][nc]) {
                cnt ++;
            }
        }
        if (cnt <= 3 && map[r][c]) {
            map[r][c] = 0;
            int i;
            for (i = 0; i < 4; ++ i) {
                int nr = r + dir[i][0], nc = c + dir[i][1];
                if (nr >= 0 && nr < Height && nc >= 0 && nc < Width && !map[nr][nc]) {
                    int p_1 = find(r * Width + c);
                    int p_2 = find(nr * Width + nc);
                    set[p_2] = p_1;
                }
            }
        }
    }
}
void showMap(int ** map) {
    int cnt = 0;
    int i,j;
    for (i = 0; i < Height; ++ i) {

        for (j = 0; j < Width; ++ j)
        {
            if (i == c_r && j == c_c) out[cnt++] = '*';
            else if (i == Height - 1 && j == Width - 1) out[cnt++] = '$';
            else if (map[i][j]) out[cnt++] = 'O';
            else out[cnt++] = ' ';
        }
        out[cnt++] = '\n';
    }
    out[cnt] = '\0';
    printf("%s",out);
}
int find(int x) {
    if (set[x] != x) set[x] = find(set[x]);
    return set[x];
}
void interact() {
    if (_kbhit()) {

    ch = _getch();
    int n_r = c_r, n_c = c_c;
    if (ch == 75 || ch == 97) {
        n_c -= 1;
    }
    if (ch == 72 || ch == 119) {
        n_r -= 1;
    }
    if (ch == 77 || ch == 100) {
        n_c += 1;
    }
    if (ch == 80 || ch == 115) {
        n_r += 1;
    }
    if (n_r >= 0 && n_r < Height && n_c >= 0 && n_c < Width && !map[n_r][n_c]) {
        c_r = n_r, c_c = n_c;
    }
    system("cls");
    showMap(map);
}
}
void victory() {
    quitflag = 0;
    system("cls");
    printf("You win!\nEnter q to quit and r to restart.");
    while (1) {
        if (_kbhit()) {
            ch = _getch();
            if (ch == 113) {
                quitflag = 1;
                break;
            }
            else if (ch == 114) break;
            system("cls");
            printf("You win!\nEnter q to quit and r to restart.");
        }
    }
}