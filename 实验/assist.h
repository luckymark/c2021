#ifndef _ASSIST_H
#define _ASSIST_H

#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <conio.h>
#include <windows.h>

#define M_SIZE 15 //棋盘大小为 15 * 15

//棋子状态颜色
#define SPACE 0 //空
#define White 1 //白子
#define Black 2 //黑子
#define AIChessColor 1 
#define humChessColor 2

extern int gBoard[M_SIZE][M_SIZE];

//分数规定
#define WIN5 100000 //5连
#define ALIVE4 10000 //活四
#define ALIVE3 1000 //活三
#define DIE4 1000 //死四
#define ALIVE2 100 //活2
#define DIE3 100 //死3
#define DIE2 10 //死2
#define ALIVE1 10 //活1

//棋子
typedef struct chess_s {
    int x = 0;
    int y = 0;
}chess_t;

//空子的序列
typedef struct chess_queue_s {
    chess_t chess[M_SIZE * M_SIZE]; 
    int len = 0;
}chess_queue;

int is_win(int x, int y, int chessColor);

#endif