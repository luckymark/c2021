#include "Global.h"

bool debug=0;
bool human;
const int N=15;
const int INF=1e9;
const int CountLimit=40;
const int DeepLimit=5;
const int CountLimit2=1;
const int DeepLimit2=3;
int Board[N][N];
pair<int,int> History[N*N];
ull Hash[2][N][N];
//-1: unused
// 0: black 
// 1: white 

int x,y;
int Step;

int dx[]={-1,0,0,1};
int dy[]={0,-1,1,0};
int dxx[]={1,1,1,0};
int dyy[]={1,-1,0,1};
int dxxx[]={1,1,1,0,-1,-1,-1,0};
int dyyy[]={1,-1,0,1,-1,1,0,-1};

int Base[10];
int Data[20005];

unordered_map<ull,pair<int,pair<int,int> > >F;