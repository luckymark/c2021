#pragma once
void heuristic_search(int point_value[][3], int empty_point[][2], int empty_cnt, int me);
int neighbor(int x, int y);
int point_evaluate(int x, int y, int me);
int generator(int* empty[][2]);
int comp(const void* a, const void* b);

typedef struct
{
    int cnt;
    int X[100];
    int Y[100];
    int value[100];
}Point;