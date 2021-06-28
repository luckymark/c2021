#pragma once
#include <stdio.h>
#include <windows.h>
#include <time.h>
#include <conio.h>
#include <stdlib.h>
#include <math.h>
#define N 65
#define L 15
#define red 1
#define white 2
#define wall 3
#define col 4
#define row 2

extern int board[L+2][L+2];
extern int AI_regrex, AI_regrey, man_regrex, man_regrey;

extern int AI_x, AI_y;
extern int man_x, man_y;
extern int man2_x, man2_y;
extern int AI_regretx, AI_regrety;
extern int man_regretx, man_regrety;
extern int dir[][2];
extern int rank;

void BackGround(unsigned int ForeColor, unsigned int BackGroundColor);
void gotoxy(int x, int y);
void chess_menu();
void chess_board();//打印棋盘 
void board_init();
void man_move();//人类玩家棋移动光标
void machine_move();
void clearlocation(int x, int y);
void location(int x, int y, int color);

void man_machine();//人机对战
int judge_winner(int x, int y, int temp);//判断输赢 
void Regret();//悔棋函数 
void welcome();
char Gametips();

