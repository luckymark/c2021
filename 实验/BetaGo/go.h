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
extern int dir[][2];

void BackGround(unsigned int ForeColor, unsigned int BackGroundColor);
void gotoxy(int x, int y);
void chess_menu();
void chess_board();//��ӡ���� 
void board_array();
void man_move();//�������ƶ����
void machine_move();

void man_machine();//�˻���ս
int judge_winner(int x, int y, int temp);//�ж���Ӯ 
void Regret();//���庯�� 
void welcome();
char Gametips();
int search(int x, int y, int me, int vis[][L + 2], int copy[][L + 2]);
int minMax_AB(int deep, int me, int Alpha, int Beta, int tmp_board[][L + 2]);
int evaluate(int me, int copy[][L + 2]);