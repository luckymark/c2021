#ifndef ALGORITHM_H
#define ALGORITHM_H
#include "Global.h"
#include "Risk.h"
#include "Graphic.h"
#include "ReadKeyBoard.h"

pair<int,pair<int,int> > olddfs(int dep,bool Color,int MaxLimit,ull state);
pair<int,pair<int,int> > newdfs(int dep,bool Color,int MaxLimit,ull state);
#endif