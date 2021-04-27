#ifndef RISK_H
#define RISK_H
#include "Global.h"
#include "Graphic.h"
#include "ReadKeyBoard.h"
#include "Algorithm.h"

bool Check();
int Risk(const bool &Color,const int &x,const int &y);
int GetScore(int *A);
int NewRisk(const bool &Color,const int &x,const int &y);
bool neighbor(const int &x,const int &y);
void GeneratePoint(vector<pair<int,pair<int,int> > > &Ans,const bool &Color,const int &Limit,const bool &flag);
#endif