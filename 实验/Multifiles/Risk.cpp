#include "Risk.h"

bool Check(){
    for(int i=0;i<N;++i){
        for(int j=0;j+4<N;++j){
            if(~Board[i][j]&&Board[i][j]==Board[i][j+1]&&Board[i][j+1]==Board[i][j+2]&&Board[i][j+2]==Board[i][j+3]&&Board[i][j+3]==Board[i][j+4])return 1;
            if(~Board[j][i]&&Board[j][i]==Board[j+1][i]&&Board[j+1][i]==Board[j+2][i]&&Board[j+2][i]==Board[j+3][i]&&Board[j+3][i]==Board[j+4][i])return 1;
        }
    }
    for(int i=0;i+4<N;++i){
        for(int j=0;j+4<N;++j){
            if(~Board[i][j]&&Board[i][j]==Board[i+1][j+1]&&Board[i+1][j+1]==Board[i+2][j+2]&&Board[i+2][j+2]==Board[i+3][j+3]&&Board[i+3][j+3]==Board[i+4][j+4])return 1;
        }
    }
    for(int i=0;i+4<N;++i){
        for(int j=4;j<N;++j){
            if(~Board[i][j]&&Board[i][j]==Board[i+1][j-1]&&Board[i+1][j-1]==Board[i+2][j-2]&&Board[i+2][j-2]==Board[i+3][j-3]&&Board[i+3][j-3]==Board[i+4][j-4])return 1;
        }
    }
    return 0;
}

int Risk(const bool &Color,const int &x,const int &y){
    int Sum=0;
    for(int d=0;d<4;++d){
        int len=1,cnt=0,nx=x,ny=y;
        for(int i=1;;++i){
            nx+=dxx[d];
            ny+=dyy[d];
            if(nx>=N||nx<0||ny>=N||ny<0||Board[nx][ny]==(Color^1)){
                ++cnt;
                break;
            }
            if(Board[nx][ny]==-1||i==5)break;
            ++len;
        }
        nx=x,ny=y;
        for(int i=1;;++i){
            nx-=dxx[d];
            ny-=dyy[d];
            if(nx>=N||nx<0||ny>=N||ny<0||Board[nx][ny]==(Color^1)){
                ++cnt;
                break;
            }
            if(Board[nx][ny]==-1||i==5)break;
            ++len;
        }
        if(len>=5)return INF;
        if(len==4&&!cnt)return INF/10;
        else if(cnt==2)Sum+=(len!=1);
        else Sum+=pow(10,len-cnt);
    }
    return Sum;
}

const int SFive=1e8;
const int SFour=1e7;
const int SBlockedFour=1e6;
const int SThree=1e5;
const int SBolckedThree=1e4;
const int STwo=1e3;
const int SBlockedTwo=1e2;

#define Assert(x) if(!(x)){for(int i=0;i<9;++i)printf("%d\t",A[i]);puts("");assert(x);system("pause");}

inline int HASH(int *A){
    int ret=0;
    for(int i=0;i<9;++i){
        ret+=Base[i]*((~A[i])?A[i]:2);
    }
    return ret;
}

int GetScore(int *A){
    int &ans=Data[HASH(A)];
    if(~ans)return ans;
    int cnt[2]={0},len[2][4]={0};
    for(int i=3;~i;--i){
        if(A[i]==-1)break;
        if(A[i]^A[i+1])++cnt[0];
        ++len[0][cnt[0]];
    }
    for(int i=5;i<9;++i){
        if(A[i]==-1)break;
        if(A[i]^A[i-1])++cnt[1];
        ++len[1][cnt[1]];
    }

    int lenm=len[0][0]+1+len[1][0];

    if(lenm>=5)return ans=SFive;

    if(lenm+len[0][1]+len[0][2]+len[0][3]+len[1][1]+len[1][2]+len[1][3]<5)return ans=0;
    
    if(lenm==4 && len[0][1]>=1 && len[1][1]>=1 )return ans=SFour;
    if(lenm==3 && len[0][1]==1 && len[0][2]>=1 && len[1][1]==1 && len[1][2]>=1)return ans=SFour;
    if(lenm==2 && len[0][1]==1 && len[0][2]>=2 && len[1][1]==1 && len[1][2]>=2)return ans=SFour;
    if(lenm==1 && len[0][1]==1 && len[0][2]>=3 && len[1][1]==1 && len[1][2]>=3)return ans=SFour;

    if(lenm==4 &&  (len[0][1]>=1 || len[1][1]>=1))return ans=SBlockedFour;
    if(lenm==3 && ((len[0][1]==1 && len[0][2]>=1) || (len[1][1]==1 && len[1][2]>=1)))return ans=SBlockedFour;
    if(lenm==2 && ((len[0][1]==1 && len[0][2]>=2) || (len[1][1]==1 && len[1][2]>=2)))return ans=SBlockedFour;
    if(lenm==1 && ((len[0][1]==1 && len[0][2]>=3) || (len[1][1]==1 && len[1][2]>=3)))return ans=SBlockedFour;

    // Assert(lenm<4);

    if(lenm==3 && len[0][1]>=1 && len[1][1]>=1 &&   len[0][1]+len[1][1]>=3)return ans=SThree;
    if(lenm==2 && len[0][1]>=1 && len[1][1]>=1 && ((len[0][1]==1 && len[0][2]>=1 && len[0][3]>=1) || (len[1][1]==1 && len[1][2]>=1 && len[1][3]>=1)))return ans=SThree;
    if(lenm==1 && len[0][1]>=1 && len[1][1]>=1 && ((len[0][1]==1 && len[0][2]>=2 && len[0][3]>=1) || (len[1][1]==1 && len[1][2]>=2 && len[1][3]>=1)))return ans=SThree;

    if(lenm==3 &&  (len[0][1]>=2 || len[1][1]>=2  || (len[0][1]==1 && len[1][1]==1)))return ans=SBolckedThree;
    if(lenm==2 && ((len[0][1]==1 && len[0][2]>=1) || (len[1][1]==1 && len[1][2]>=1) || (len[0][1]==2 && len[0][2]>=1) || (len[1][1]==2 && len[1][2]>=1)))return ans=SBolckedThree;
    if(lenm==1 && ((len[0][1]==1 && len[0][2]>=2) || (len[1][1]==1 && len[1][2]==2) || (len[0][1]==2 && len[0][2]>=2) || (len[1][1]==2 && len[1][2]>=2) || (len[0][1]==1 && len[0][2]>=1 && len[1][1]==1 && len[1][2]>=1)))return ans=SBolckedThree;
    
    // Assert(lenm<3);

    if(lenm==2 &&   len[0][1]>=1 &&   len[1][1]>=1 && len[0][1]+len[1][1]>=4)return ans=STwo;
    if(lenm==1 && ((len[0][1]>=1 && ((len[1][1]==1 && len[1][2]>=1 && len[1][3]>=1) || (len[1][1]==2 && len[1][2]==1 ))) || (len[1][1]>=1 && ((len[0][1]==1 && len[0][2]>=1 && len[0][3]>=1) || (len[0][1]==2 && len[0][2]==1)))))return ans=STwo;

    if(lenm==2)return ans=SBlockedTwo;
    if(lenm==1 && (len[1][1]<=3 && len[1][1]+len[1][3]>=3 && len[1][2]==1) || (len[0][1]<=3 && len[0][1]+len[0][3]>=3 && len[1][2]==1))return ans=SBlockedTwo;

    // Assert(lenm<2);
    return ans=10*(len[0][2]+lenm+len[1][2]);
}

int NewRisk(const bool &Color,const int &x,const int &y){
    int Sum=0;
    int Line[9];
    Line[4]=1;
    for(int d=0,nx,ny;d<4;++d){
        nx=x,ny=y;
        for(int i=3;~i;--i){
            nx-=dxx[d];
            ny-=dyy[d];
            if(nx>=N||nx<0||ny>=N||ny<0||Board[nx][ny]==(Color^1))Line[i]=-1;
            else Line[i]=(Board[nx][ny]==Color);
        }
        nx=x,ny=y;
        for(int i=5;i<9;++i){
            nx+=dxx[d];
            ny+=dyy[d];
            if(nx>=N||nx<0||ny>=N||ny<0||Board[nx][ny]==(Color^1))Line[i]=-1;
            else Line[i]=(Board[nx][ny]==Color);
        }
        Sum+=GetScore(Line);
    }
    return Sum;
}

#define DEBUG(x) for(int i=0;i<x.size();++i)printf("(%d,%d)\n",x[i].second.first,x[i].second.second);puts("-----------");

bool neighbor(const int &x,const int &y){
    for(int i=max(x-2,0);i<min(x+3,N);++i){
        for(int j=max(y-2,0);j<min(j+3,N);++j){
            if(~Board[i][j])return 1;
        }
    }
    return 0;
}

void GeneratePoint(vector<pair<int,pair<int,int> > > &Ans,const bool &Color,const int &Limit,const bool &flag){
    vector<pair<int,pair<int,int> > > Five[2];
    vector<pair<int,pair<int,int> > > Four[2];
    vector<pair<int,pair<int,int> > > BlockedFour[2];
    vector<pair<int,pair<int,int> > > TwoThree[2];
    vector<pair<int,pair<int,int> > > Three[2];
    vector<pair<int,pair<int,int> > > others;

    for(int i=0;i<N;++i){
        for(int j=0;j<N;++j){
            if(~Board[i][j])continue;
            if(!neighbor(i,j))continue;
            int s0=NewRisk(Color,i,j);
            int s1=NewRisk(Color^1,i,j);

            int v;
            if(s0>=SFive)v=1e9;
            else if(s0>=SFour)v=1e8*(s0/SFour);
            else if(s0>=2*SBlockedFour)v=9e7*(s0/(2*SBlockedFour));
            else if(s0>=SBlockedFour+SThree)v=8e7*(s0/(SBlockedFour+SThree));
            else if(s0>=SBlockedFour)v=5e5;
            else if(s0>=2*SThree)v=5e7*(s0/(2*SThree));
            else if(s0>=SThree)v=3e5;
            else if(s0>=SBolckedThree)v=1e4*(s0/SBolckedThree);
            else if(s0>=STwo)v=5e3*(s0/STwo);
            else if(s0>=SBlockedTwo)v=1e2*(s0/SBlockedTwo);
            else v=s0;
            v+=500*(N/2-max(abs(i-N/2),abs(j-N/2)))/(Step|1);
            // v+=s1;
            if(s0>=SFive)Five[0].push_back({v,{i,j}});
            else if(s1>=SFive)Five[1].push_back({v,{i,j}});
            else if(s0>=SFour)Four[0].push_back({v,{i,j}});
            else if(s1>=SFour)Four[1].push_back({v,{i,j}});
            else if(s0>=2*SBlockedFour)Four[0].push_back({v,{i,j}});
            else if(s1>=2*SBlockedFour)Four[1].push_back({v,{i,j}});
            else if(s0>=SBlockedFour+SThree)Four[0].push_back({v,{i,j}});
            else if(s1>=SBlockedFour+SThree)Four[1].push_back({v,{i,j}});
            else if(s0>=SBlockedFour)BlockedFour[0].push_back({v,{i,j}});
            else if(s1>=SBlockedFour)BlockedFour[1].push_back({v,{i,j}});
            else if(s0>=2*SThree)TwoThree[0].push_back({v,{i,j}});
            else if(s1>=2*SThree)TwoThree[1].push_back({v,{i,j}});
            else if(s0>=SThree)Three[0].push_back({v,{i,j}});
            else if(s1>=SThree)Three[1].push_back({v,{i,j}});
            else others.push_back({v,{i,j}});
        }
    }

    if(debug){
        Print();
        puts("Five[0]");DEBUG(Five[0]);
        puts("Five[1]");DEBUG(Five[1]);
        puts("Four[0]");DEBUG(Four[0]);
        puts("Four[1]");DEBUG(Four[1]);
        puts("BlockedFour[0]");DEBUG(BlockedFour[0]);
        puts("BlockedFour[1]");DEBUG(BlockedFour[1]);
        puts("TwoThree[0]");DEBUG(TwoThree[0]);
        puts("TwoThree[1]");DEBUG(TwoThree[1]);
        puts("Three[0]");DEBUG(Three[0]);
        puts("Three[1]");DEBUG(Three[1]);
        system("pause");
    }

    if(Five[0].size()){
        Ans=Five[0];
        return ;
    }
    if(Five[1].size()){
        Ans=Five[1];
        return ;
    }
    if(Four[0].size()){
        Ans=Four[0];
        return ;
    }
    if(Four[1].size()){
        Ans.insert(Ans.end(),Four[1].begin(),Four[1].end());
        Ans.insert(Ans.end(),BlockedFour[0].begin(),BlockedFour[0].end());
        if(flag)return ;
    }

    Ans.insert(Ans.end(),TwoThree[0].begin(),TwoThree[0].end());
    Ans.insert(Ans.end(),TwoThree[1].begin(),TwoThree[1].end());
    Ans.insert(Ans.end(),BlockedFour[0].begin(),BlockedFour[0].end());
    Ans.insert(Ans.end(),BlockedFour[1].begin(),BlockedFour[1].end());
    Ans.insert(Ans.end(),Three[0].begin(),Three[0].end());
    Ans.insert(Ans.end(),Three[1].begin(),Three[1].end());

    // sort(Ans.begin(),Ans.end(),greater<pair<int,pair<int,int> > >());
    if(flag)return ;
    // if(TwoThree[0].size()||TwoThree[1].size()||flag){
    //     return ;
    // }

    sort(others.begin(),others.end(),greater<pair<int,pair<int,int> > >());
    for(int i=0;i<min(others.size(),Limit-Ans.size());++i){
        Ans.push_back(others[i]);
    }   
    if(Ans.size()>Limit)Ans.resize(Limit);
}