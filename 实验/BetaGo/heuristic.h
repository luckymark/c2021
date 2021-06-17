#pragma once
typedef struct
{
    int X;
    int Y;
    int value;
    int is_killer;
}Point;

int heuristic_search(Point empty_point[200], int empty_cnt, int me, int now_board[L + 2][L + 2]);
int generator(Point empty_point[200], int now_board[L + 2][L + 2]);
int point_evaluate(int x, int y, int me, int now_board[L + 2][L + 2]);
int neighbor(int x, int y, int now_board[L + 2][L + 2]);
void is_killer(Point* p, int me_value, int others_value);
int comp1(const void* a, const void* b);
int comp2(const void* a, const void* b);

