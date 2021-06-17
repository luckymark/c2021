#pragma once
#define PTIF 2147483647//正无穷,Beta
#define NGIF -2147483648//负无穷,Alpha

int search(int x, int y, int me, int vis[][L + 2], int copy[][L + 2]);
int minMax_AB(int deep, int me, int Alpha, int Beta, int tmp_board[][L + 2]);
int evaluate(int me, int copy[][L + 2]);
int IDDFS();

typedef struct
{
    int Alpha;
    int Beta;
    int X;
    int Y;
}Tree;
