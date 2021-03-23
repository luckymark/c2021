#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define N 100

struct stack
{
    int dataS[N];
    int top;
};
typedef struct stack S;

struct queue
{
    char dataQ[N];
    int front;
    int rear;
};
typedef struct queue Q;

void initQueue(Q* myqueue);
void Qappend(Q* myqueue, char y);
char Qpop(Q* myqueue);

void initStack(S* mystack);
void Sappend(S* mystack, int z);
int Spop(S* mystack);

void input(Q* myqueue);
int calculate(char p1, int p2, int p3);
