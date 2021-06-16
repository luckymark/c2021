//
// Created by chovy on 2021/5/6.
//

#ifndef PUSHTHEBOX_FUNC_H
#define PUSHTHEBOX_FUNC_H

const int route=0;
const int wall=1;
const int player=2;
const int box=3;
const int destination=4;
const int finish=5;
const int pfinish=6;
const int L=8;

void menu(void);
int (*fileReader(int num))[L];
int (*Push(int map[][L]))[L];
int check(int map[][L]);
void print(int map[][L]);
void start(int map[][L],int nmap);

#endif //PUSHTHEBOX_FUNC_H
