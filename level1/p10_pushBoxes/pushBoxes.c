#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
enum {MapNum = 10,MaxNum = 100, WinNum = 4};
enum {Space, Wall, Box, Dest, BoxOverDest, P, LineBreak, BoxInDest, PInDest};
int *** maps = NULL;
char ch;
int Steps = 0, quitflag = 0;
int i, j;
int cur_map = 0;
struct map
{
    int row;
    int col;
}mapInfo[MapNum];
struct player
{
    int row;
    int col;
}player;
// void swap(char *a,char *b);
void Move(int n_r,int n_c);
int NotOut(int rr, int cc);
int char2int(char c);
char int2char(int t);
void Update();
void GetPlayerPosition();
void initMaps();
void showMap();
void restart();
void interact();
int victory();
int main(int argc, char const *argv[])
{
    FILE * score_file = fopen("score.txt","w");
    system("cls");
    initMaps();
    GetPlayerPosition();
    Update();
    while(1) {
        interact();
        if (quitflag) break;
        if (victory()) {
            fprintf(score_file,"The level %d takes totally %d steps, the score is %d\n",cur_map,Steps,(1000 + 10000 * cur_map) / Steps);
            Steps = 0;
            cur_map ++;
            if (cur_map == WinNum) {
                printf("You win!");
                break;
            }
            system("cls");
            GetPlayerPosition();
            Update();
        }
    }
    fclose(score_file);
    return 0;
}

void initMaps()
{
    maps = (int ***)malloc(sizeof(int **)*MapNum);
    for (i = 0; i < MapNum; ++ i) {
        maps[i] = (int**)malloc(sizeof(int*)*MaxNum);
        for (j = 0; j < MaxNum; ++ j) {
            maps[i][j] = (int*)malloc(sizeof(int)*MaxNum);
        }
    }

    FILE * maps_file = fopen("maps.txt","r");
    int mapcnt = 0,rowcnt = 0, colcnt = 0;
    while (~(ch = fgetc(maps_file))) {
        if (ch == '&'){
            mapInfo[mapcnt].row = rowcnt;
            mapcnt++;
            rowcnt = 0;
            colcnt = 0;
            fgetc(maps_file);
            continue;
        }
        else if (ch == '\n') {
            mapInfo[mapcnt].col = colcnt;
            maps[mapcnt][rowcnt][colcnt++] = char2int(ch);
            rowcnt ++;
            colcnt = 0;
            continue;
        }
        maps[mapcnt][rowcnt][colcnt++] =char2int(ch);
    };
    fclose(maps_file);
}
void GetPlayerPosition()
{
    for (i = 0; i < mapInfo[cur_map].row; ++ i)
        for (j = 0; j < mapInfo[cur_map].col; ++ j) {
            if (maps[cur_map][i][j] == P) player.row = i, player.col = j;
        }
}
void Update()
{
    char show[1000];
    int cnt = 0;
    for (i = 0; i < mapInfo[cur_map].row; ++ i)
        for (j = 0; j < mapInfo[cur_map].col + 1; ++ j) {
            show[cnt++] = int2char(maps[cur_map][i][j]);
        }
    show[cnt] = '\0';
    printf("%s",show);
    printf("Please move the '#'(box) to the '$'(destination), note that you can move the box in the '$' and you can alse walk on the '$'");
    printf("\nYou can use WASD to move.\nYou can hit R to restart or Q to quit.\n");
    printf("\nNow you have walk %d steps.\n",Steps);
}
void interact() {
    if (_kbhit()) {
        
        ch = _getch();
        int n_r = player.row, n_c = player.col;
        if (ch == 114) {
            restart();
            return;
        }
        else if (ch == 113) {
            Steps ++;
            quitflag = 1;
            return;
        }
        if (ch == 97) {
            Steps ++;
            n_c -= 1;
        }
        else if (ch == 119) {
            Steps ++;
            n_r -= 1;
        }
        else if (ch == 100) {
            Steps ++;
            n_c += 1;
        }
        else if (ch == 115) {
            Steps ++;
            n_r += 1;
        }
        Move(n_r,n_c);
        system("cls");
        Update();
    }
}
int NotOut(int rr, int cc) {
    return rr >= 0 && rr < mapInfo[cur_map].row && cc >= 0 && cc < mapInfo[cur_map].col;
}
// void swap(char * a, char * b) {
//     char t = *a;
//     *a = *b;
//     *b = t;
// }
int char2int(char c) {
    if (c == '*') return P;
    else if (c == ' ') return Space;
    else if (c == 'O') return Wall;
    else if (c == '#') return Box;
    else if (c == '$') return Dest;
    else if (c == '\n') return LineBreak;
} 
char int2char(int t) {
    if (t == P) return '*';
    else if (t == Space) return ' ';
    else if (t == Wall) return 'O';
    else if (t == Box) return '#';
    else if (t == Dest) return '$';
    else if (t == LineBreak) return '\n';
    else if (t == BoxInDest) return '#';
    else if (t == PInDest) return '*';
}
int victory() {
    for (i = 0; i < mapInfo[cur_map].row; ++ i) {
        for (j = 0; j < mapInfo[cur_map].col; ++ j) {
            if (maps[cur_map][i][j] == Box) return 0;
        }
    }
    return 1;
}
void restart() {
    Steps = 0;
    free(maps);
    maps = NULL;
    initMaps();
    GetPlayerPosition();
    system("cls");
    Update();
}
void Move(int n_r,int n_c) {
    //前方空地
        if (NotOut(n_r,n_c) && maps[cur_map][n_r][n_c] == Space) {
            maps[cur_map][n_r][n_c] = P;
            
            maps[cur_map][player.row][player.col] = maps[cur_map][player.row][player.col] == PInDest ? Dest : Space;
            player.row = n_r, player.col = n_c;
        }
        //前方归位点
        if (NotOut(n_r,n_c) && maps[cur_map][n_r][n_c] == Dest) {
            maps[cur_map][n_r][n_c] = PInDest;
            maps[cur_map][player.row][player.col] = maps[cur_map][player.row][player.col] == PInDest ? Dest : Space;
            player.row = n_r, player.col = n_c;
        }
        //前方归位箱
        if (NotOut(n_r,n_c) && maps[cur_map][n_r][n_c] == BoxInDest) {
            int b_n_r = n_r + n_r - player.row;
            int b_n_c = n_c + n_c - player.col;
            //箱子前方空地
            if (NotOut(b_n_r,b_n_c) && maps[cur_map][b_n_r][b_n_c] == Space) {
                maps[cur_map][n_r][n_c] = PInDest;
                maps[cur_map][b_n_r][b_n_c] = Box;
                maps[cur_map][player.row][player.col] = maps[cur_map][player.row][player.col] == PInDest ? Dest : Space;
                player.row = n_r, player.col = n_c;
            }
            //箱子前方归位点
            else if (NotOut(b_n_r,b_n_c) && maps[cur_map][b_n_r][b_n_c] == Dest) {
                maps[cur_map][n_r][n_c] = PInDest;
                maps[cur_map][b_n_r][b_n_c] = BoxInDest;
                maps[cur_map][player.row][player.col] = maps[cur_map][player.row][player.col] == PInDest ? Dest : Space;
                player.row = n_r, player.col = n_c;
            }
        }
        //前方箱子
        if (NotOut(n_r,n_c) && maps[cur_map][n_r][n_c] == Box) {
            int b_n_r = n_r + n_r - player.row;
            int b_n_c = n_c + n_c - player.col;
            //箱子前方空地
            if (NotOut(b_n_r,b_n_c) && maps[cur_map][b_n_r][b_n_c] == Space) {
                maps[cur_map][n_r][n_c] = P;
                maps[cur_map][b_n_r][b_n_c] = Box;
                maps[cur_map][player.row][player.col] = maps[cur_map][player.row][player.col] == PInDest ? Dest : Space;
                player.row = n_r, player.col = n_c;
            }
            //箱子前方归位点
            else if (NotOut(b_n_r,b_n_c) && maps[cur_map][b_n_r][b_n_c] == Dest) {
                maps[cur_map][n_r][n_c] = P;
                maps[cur_map][b_n_r][b_n_c] = BoxInDest;
                maps[cur_map][player.row][player.col] = maps[cur_map][player.row][player.col] == PInDest ? Dest : Space;
                player.row = n_r, player.col = n_c;
            }
        }
}