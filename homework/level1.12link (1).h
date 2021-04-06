#pragma once
#include<stdio.h>
#include <stdlib.h>
#include <windows.h>
#define BUFSIZE 1000

typedef struct node
{
    char name[20];
    int type;
    int quantity;
    struct node* next;
}Node;

Node* head;
FILE* fp;

void HomeScreen();
void importdata();
void ShowList();
void Input();
void Output();
void update();
void color(int c);
void gotoxy(int x, int y);
