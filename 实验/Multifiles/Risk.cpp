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
const int SBolckedTwo=1e2;

int GetScore(int *A){
    // string s="";
    // for(int i=0;i<9;++i){
    //     if(A[i]==1)s+="1";
    //     else if(A[i])s+="#";
    //     else s+="0";
    // if(s.find("11111"))return SFive;
    // if(S.find("011110"))return SFour;
    // if(S.find("#11110"))return SBlockedFour;
    // if(S.find("01111#"))return SBlockedFour;
    // if(S.find("10111"))return SBlockedFour;
    // if(S.find("11011"))return SBlockedFour;
    // if(S.find("11101"))return SBlockedFour;
    // if(S.find("01110"))return SThree;
    // if(S.find("010110"))return SThree;
    // if(S.find("011010"))return SThree;
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

    if(lenm>=5)return SFive;

    if(lenm==4&&len[0][1]&&len[1][1])return SFour;
    if(lenm==3&&len[0][1]==1&&len[0][2]>=1&&len[1][1]==1&&len[1][2]>=1)return SBlockedFour;
    if(lenm==2&&len[0][1]==1&&len[0][2]>=2&&len[1][1]==1&&len[1][2]>=2)return SBlockedFour;
    if(lenm==1&&len[0][1]==1&&len[0][2]>=3&&len[1][1]==1&&len[1][2]>=3)return SBlockedFour;

    if(lenm==4&&(len[0][1]||len[1][1]))return SBlockedFour;
    if(lenm==3&&((len[0][1]==1&&len[0][2]>=1)||(len[1][1]==1&&len[1][2]>=1)))return SBlockedFour;
    if(lenm==2&&((len[0][1]==1&&len[0][2]>=2)||(len[1][1]==1&&len[1][2]>=2)))return SBlockedFour;
    if(lenm==1&&((len[0][1]==1&&len[0][2]>=3)||(len[1][1]==1&&len[1][2]>=3)))return SBlockedFour;

    if(lenm==3&&len[0][1]&&len[1][1]&&(len[0][1]+len[1][1]>=3))return SThree;
    if(lenm==2&&len[0][1]>=1&&len[1][1]>=1&&(len[0][2]>=1||len[1][2]>=1))return SThree;
    if(lenm==1&&len[0][1]>=1&&len[1][1]>=1&&(len[0][2]>=2||len[1][2]>=2))return SThree;

    if(lenm==3&&(len[0][1]>=2||len[1][1]>=2||(len[0][1]==1&&len[1][1]==1)))return SBolckedThree;
    if(lenm==2&&((len[0][1]==1&&len[0][2]==1&&len[0][3]>=1)||(len[1][1]==1&&len[1][2]==1&&len[1][3]>=1)||(len[0][1]==2&&len[0][2]>=1)||(len[1][1]==2&&len[1][2]>=1)))return SBolckedThree;
    if(lenm==1&&((len[0][1]==1&&len[0][2]==2&&len[0][3]>=1)||(len[1][1]==1&&len[1][2]==2&&len[1][3]>=1)||(len[0][1]==2&&len[0][2]>=2)||(len[1][1]==2&&len[1][2]>=2)||(len[0][1]==1&&len[0][2]==1&&len[1][1]==1&&len[1][2]==1)))return SBolckedThree;
    
    if(lenm==2&&len[0][1]&&len[1][1]&&(len[0][1]+len[1][1]>=4))return STwo;
    if(lenm==1&&((len[0][1]>=1&&((len[1][1]==1&&len[1][2]==1&&len[1][3]>=1)||(len[1][1]==2&&len[1][2]==1)))||(len[1][1]>=1&&((len[0][1]==1&&len[0][2]==1&&len[0][3]>=1)||len[0][1]==2&&len[0][2]==1))))return STwo;

    if(lenm==2&&(len[0][1]>=3||len[1][1]>=3))return SBolckedTwo;
    if(lenm==1&&(len[1][1]<=3&&len[1][1]+len[1][3]>=3&&len[1][2]==1)||(len[0][1]<=3&&len[0][1]+len[0][3]>=3&&len[1][2]==1))return SBolckedTwo;

    return 10*(len[0][2]+lenm+len[1][2]);
    // int cnt[2]={0},len[2][3]={0};
    // for(int i=3;~i;--i){
    //     if(A[i]==-1)break;
    //     if(cnt[0]&&!A[i]&&!A[i+1])break;
    //     if(A[i])++len[0][cnt[0]];
    //     else ++cnt[0];
    // }
    // for(int i=5;i<9;++i){
    //     if(A[i]==-1)break;
    //     if(cnt[1]&&!A[i]&&!A[i-1])break;
    //     if(A[i])++len[1][cnt[1]];
    //     else ++cnt[1];
    // }
    // int lenm=len[0][0]+1+len[1][0];
    // if(lenm>=5)return SFive;
    // // for(int i=4;i;--i){
    // //  if(lenm==i&&cnt[0]&&cnt[1]&&len[0][1]>=4-i&&len[1][1]>=4-i)return SFour;
    // // }
    // if(lenm==4&&cnt[0]&&cnt[1])return SFour;
    // if(lenm==3&&cnt[0]&&cnt[1]&&len[0][1]>=1&&len[1][1]>=1)return SFour;
    // if(lenm==2&&cnt[0]&&cnt[1]&&len[0][1]>=2&&len[1][1]>=2)return SFour;
    // if(lenm==1&&cnt[0]&&cnt[1]&&len[0][1]>=3&&len[1][1]>=3)return SFour;

    // if(lenm==4&&(cnt[0]+cnt[1])==1)return SBlockedFour;
    // if(lenm==3&&(len[0][1]>=1||len[1][1]>=1))return SBlockedFour;
    // if(lenm==2&&(len[0][1]>=2||len[1][1]>=2))return SBlockedFour;
    // if(lenm==1&&(len[0][1]>=3||len[1][1]>=3))return SBlockedFour;

    // if(lenm==3&&cnt[0]&&cnt[1])return SThree;
    // if(lenm==2&&cnt[0]&&cnt[1]&&((cnt[0]>=2&&len[0][1]>=1)||(cnt[1]>=2&&len[1][1]>=1)))return SThree;
    // if(lenm==1&&cnt[0]&&cnt[1]&&((cnt[0]>=2&&len[0][1]>=2)||(cnt[1]>=2&&len[1][1]>=2)))return SThree;

    // if(lenm==3&&(cnt[0]+cnt[1])==1)return SBolckedThree;
    // if(lenm==2&&(len[0][1]>=1||len[1][1]>=1))return SBolckedThree;
    // if(lenm==1&&(len[0][1]>=2||len[1][1]>=2))return SBolckedThree;
    // if(lenm==1&&len[0][1]>=1&&len[1][1]>=1)return SBolckedThree;

    // return 0;
}

int NewRisk(const bool &Color,const int &x,const int &y){
    // if(debug){
    //     printf("%d %d\n",x,y);
    // }
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
        // if(debug&&x==9&&y==6){
        //     for(int i=0;i<9;++i){
        //         printf("%d ",Line[i]);
        //     }
        //     puts("");
        //     printf("%d\n",GetScore(Line));
        // }
        Sum+=GetScore(Line);
    }
    return Sum-max(abs(x-N/2),abs(y-N/2));
}

#define DEBUG(x) for(int i=0;i<x.size();++i)printf("(%d,%d)\n",x[i].first,x[i].second);puts("-----------");

bool neighbor(const int &x,const int &y){
    for(int i=max(x-3,0);i<min(x+4,N);++i){
        for(int j=max(y-3,0);j<min(j+4,N);++j){
            if(~Board[i][j])return 1;
        }
    }
    return 0;
}

void GeneratePoint(vector<pair<int,int> > &Ans,const bool &Color,const int &Limit,const bool &flag){
    vector<pair<int,int> > Five[2];
    vector<pair<int,int> > Four[2];
    vector<pair<int,int> > BlockedFour[2];
    vector<pair<int,int> > TwoThree[2];
    vector<pair<int,int> > Three[2];
    vector<pair<int,pair<int,int> > > others;

    // if(debug){
    //     int val;
    //     for(int i=0;i<N;++i,puts("")){
    //         for(int j=0;j<N;++j){
    //             if(~Board[i][j])val=0;
    //             else if(!neighbor(i,j))val=0;
    //             else val=NewRisk(Color,i,j);
    //             printf("%d\t",val);
    //         }
    //     }
    //     puts("");
    //     system("pause");
    //     for(int i=0;i<N;++i,puts("")){
    //         for(int j=0;j<N;++j){
    //             if(~Board[i][j])val=0;
    //             else if(!neighbor(i,j))val=0;
    //             else val=NewRisk(Color^1,i,j);
    //             printf("%d\t",val);
    //         }
    //     }
    //     puts("");
    //     system("pause");
    // }

    int score[2];
    for(int i=0;i<N;++i){
        for(int j=0;j<N;++j){
            if(~Board[i][j])continue;
            if(!neighbor(i,j))continue;
            score[0]=NewRisk(Color,i,j);
            score[1]=NewRisk(Color^1,i,j);
            if(score[0]>=SFive)Five[0].push_back({i,j});
            else if(score[1]>=SFive)Five[1].push_back({i,j});
            else if(score[0]>=SFour)Four[0].push_back({i,j});
            else if(score[1]>=SFour)Four[1].push_back({i,j});
            else if(score[0]>=2*SBlockedFour)Four[0].push_back({i,j});
            else if(score[1]>=2*SBlockedFour)Four[1].push_back({i,j});
            else if(score[0]>=SBlockedFour+SThree)Four[0].push_back({i,j});
            else if(score[1]>=SBlockedFour+SThree)Four[1].push_back({i,j});
            else if(score[0]>=SBlockedFour)BlockedFour[0].push_back({i,j});
            else if(score[1]>=SBlockedFour)BlockedFour[1].push_back({i,j});
            else if(score[0]>=2*SThree)TwoThree[0].push_back({i,j});
            else if(score[1]>=2*SThree)TwoThree[1].push_back({i,j});
            else if(score[0]>=SThree)Three[0].push_back({i,j});
            else if(score[1]>=SThree)Three[1].push_back({i,j});
            else others.push_back({score[0]+score[1],{i,j}});
        }
    }

    if(debug){
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
        return ;
    }

    Ans.insert(Ans.end(),TwoThree[0].begin(),TwoThree[0].end());
    Ans.insert(Ans.end(),TwoThree[1].begin(),TwoThree[1].end());
    Ans.insert(Ans.end(),BlockedFour[0].begin(),BlockedFour[0].end());
    Ans.insert(Ans.end(),BlockedFour[1].begin(),BlockedFour[1].end());
    Ans.insert(Ans.end(),Three[0].begin(),Three[0].end());
    Ans.insert(Ans.end(),Three[1].begin(),Three[1].end());

    if(TwoThree[0].size()||TwoThree[1].size()||flag){
        return ;
    }

    sort(others.begin(),others.end(),greater<pair<int,pair<int,int> > >());
    for(int i=0;i<min(others.size(),Limit-Ans.size());++i){
        Ans.push_back(others[i].second);
    }   
    if(Ans.size()>Limit)Ans.resize(Limit);
}