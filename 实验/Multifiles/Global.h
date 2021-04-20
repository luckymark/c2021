#ifndef GLOBAL_H
#define GLOBAL_H
#include <bits/stdc++.h>
#include <windows.h>
#include <conio.h>

using namespace std;

#define gc c=getchar()
#define r(x) read(x)
#define ll long long
#define ull unsigned long long

extern bool debug;
extern const int N;
extern const int INF;
extern const int CountLimit;
extern const int DeepLimit;
extern const int CountLimit2;
extern const int DeepLimit2;
extern int Board[15][15];
extern ull Hash[2][15][15];
//-1: unused
// 0: black 
// 1: white 

extern int x,y;
extern int Step;

extern int dx[];
extern int dy[];
extern int dxx[];
extern int dyy[];
extern int dxxx[];
extern int dyyy[];

extern unordered_map<ull,pair<int,pair<int,int> > >F;
#endif