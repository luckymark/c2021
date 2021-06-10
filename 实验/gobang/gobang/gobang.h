//
// Created by 10917 on 2021/4/14.
//

#ifndef GOBANG_GOBANG_H
#define GOBANG_GOBANG_H

#endif //GOBANG_GOBANG_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAP_SIZE 15
#define DEEP 5 // 搜索深度

#define SPACE '+'
#define WHITE 'O'
#define BLACK '@'

typedef enum SCORE
{
    WIN5 = 320000,
    ALIVE4 = 160000,
    ALIVE3 = 8000,
    DIE4 = 8000,
    ALIVE2 = 400,
    DIE3 = 400,
    ALIVE1 = 20,
    DIE2 = 20,
    DIE1 = 1
}score;

struct CHESS
{
    int x;
    int y;
};

struct List
{
    CHESS chess[MAP_SIZE*MAP_SIZE];
    int num;
}chess_list;
