
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

int** board;

int AI_regrex, AI_regrey, man_regrex, man_regrey;

int AI_x, AI_y;
int AI_x2, AI_y2;
int man_x, man_y;
int man_x2, man_y2;

void BackGround(unsigned int ForeColor, unsigned int BackGroundColor);
void gotoxy(int x, int y);
void chess_menu();
void chess_board();//��ӡ���� 
void board_array();
void man_move();//�������ƶ����
void machine_move();
void convert(int x, int y, int x2, int y2);
void man_machine();//�˻���ս
int judge_chess(int x, int y);//�ж����λ���Ƿ��¹� 
int judge_winner(int x, int y, int temp);//�ж���Ӯ 
void Regret();//���庯�� 
void welcome();
char Gametips();