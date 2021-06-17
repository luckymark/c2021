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
void chess_board();//��ӡ���� 
void board_init();
void man_move();//����������ƶ����
void machine_move();
void clearlocation(int x, int y);
void location(int x, int y, int color);

void man_machine();//�˻���ս
int judge_winner(int x, int y, int temp);//�ж���Ӯ 
void Regret();//���庯�� 
void welcome();
char Gametips();

