#ifndef _ASSIST_H
#define _ASSIST_H

#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <conio.h>
#include <windows.h>

#define M_SIZE 15 //���̴�СΪ 15 * 15

//����״̬��ɫ
#define SPACE 0 //��
#define White 1 //����
#define Black 2 //����
#define AIChessColor 1 
#define humChessColor 2

extern int gBoard[M_SIZE][M_SIZE];

//�����涨
#define WIN5 100000 //5��
#define ALIVE4 10000 //����
#define ALIVE3 1000 //����
#define DIE4 1000 //����
#define ALIVE2 100 //��2
#define DIE3 100 //��3
#define DIE2 10 //��2
#define ALIVE1 10 //��1

//����
typedef struct chess_s {
    int x = 0;
    int y = 0;
}chess_t;

//���ӵ�����
typedef struct chess_queue_s {
    chess_t chess[M_SIZE * M_SIZE]; 
    int len = 0;
}chess_queue;

int is_win(int x, int y, int chessColor);

#endif