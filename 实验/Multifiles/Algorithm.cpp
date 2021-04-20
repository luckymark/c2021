#include "Algorithm.h"

// pair<int,pair<int,int> > dfs2(int dep,bool Color,int MaxLimit,ull state){
//     if(F.count(state))return F[state];
//     vector<pair<pair<int,int>,pair<int,int> > >Points;
//     for(int i=0;i<N;++i){
//         for(int j=0;j<N;++j){
//             if(~Board[i][j])continue;
//             int Rating=Risk(Color,i,j);
//             if(Rating==INF)return F[state]={INF,{i,j}};
//             if(dep&&Rating==INF/10){
//                 Board[i][j]=Color;
//                 int tmp=dfs2(0,Color^1,INF,state^Hash[Color][i][j]).first;
//                 Board[i][j]=-1;
//                 if(tmp!=INF){
//                     return F[state]={INF,{i,j}};
//                 }
//                 Rating=-INF;
//             }
//             Points.push_back({{Rating+Risk(Color^1,i,j),Rating},{i,j}});
//         }
//     }
//     sort(Points.begin(),Points.end(),greater<pair<pair<int,int>,pair<int,int> > >());
//     if(Points.size()>CountLimit2)Points.resize(CountLimit2);
//     int x=-1,y=-1;
//     int Max=-1e9;
//     for(auto P:Points){
//         int i=P.second.first;
//         int j=P.second.second;
//         int Rating=P.first.second;
//         if(dep){
//                 Board[i][j]=Color;
//                 Rating-=dfs2(dep-1,Color^1,Rating-Max,state^Hash[Color][i][j]).first;
//                 Rating=min(Rating,INF);
//                 Rating=max(Rating,-INF);
//                 Board[i][j]=-1;
//         } 
//         if(Rating>Max)x=i,y=j,Max=Rating;
//         if(Max>=MaxLimit){
//             return F[state]={Max,{x,y}};
//         }
//     }
//     return F[state]={Max,{x,y}};
// }

pair<int,pair<int,int> > olddfs(int dep,bool Color,int MaxLimit,ull state){
    if(F.count(state))return F[state];
    vector<pair<pair<int,int>,pair<int,int> > >Points;
    for(int i=0;i<N;++i){
        for(int j=0;j<N;++j){
            if(~Board[i][j])continue;
            int Rating=Risk(Color,i,j);
            if(Rating==INF)return F[state]={INF,{i,j}};
            if(dep&&Rating==INF/10){
                Board[i][j]=Color;
                int tmp=olddfs(0,Color^1,INF,state^Hash[Color][i][j]).first;
                Board[i][j]=-1;
                if(tmp!=INF){
                    return F[state]={INF,{i,j}};
                }
                Rating=-INF;
            }
            Points.push_back({{Rating+Risk(Color^1,i,j),Rating},{i,j}});
        }
    }
    sort(Points.begin(),Points.end(),greater<pair<pair<int,int>,pair<int,int> > >());
    if(Points.size()>dep*5+25)Points.resize(dep*5+25);
    int x=-1,y=-1;
    int Max=-1e9;
    for(auto P:Points){
        int i=P.second.first;
        int j=P.second.second;
        int Rating=P.first.second;
        if(dep){
            Board[i][j]=Color;
            Rating-=olddfs(dep-1,Color^1,Rating-Max,state^Hash[Color][i][j]).first;
            Rating=min(Rating,INF);
            Rating=max(Rating,-INF);
            Board[i][j]=-1;
        }
        // else if(Step>=10){
        //     Board[i][j]=Color;
        //     Rating-=dfs2(DeepLimit2,Color^1,Rating-Max,state^Hash[i][j]).first;
        //     Rating=min(Rating,INF);
        //     Rating=max(Rating,-INF);
        //     Board[i][j]=-1;
        // }
        if(Rating>Max)x=i,y=j,Max=Rating;
        if(Max>=MaxLimit){
            return F[state]={Max,{x,y}};
        }
    }
    return F[state]={Max,{x,y}};
}

pair<int,pair<int,int> > newdfs(int dep,bool Color,int MaxLimit,ull state){
    if(F.count(state))return F[state];
    vector<pair<int,int> >Points;
    // if(dep==7)debug=1;
    GeneratePoint(Points,Color,20,0);
    // debug=0;
    if(!Points.size())return {2*INF,{-1,-1}};
    if(Points.size()==1)return F[state]={NewRisk(Color,Points[0].first,Points[0].second),Points[0]};
    int x=-1,y=-1;
    int Max=-1e9;
    for(auto P:Points){
        int i=P.first;
        int j=P.second;
        int Rating=NewRisk(Color,i,j);
        if(dep){
            Board[i][j]=Color;
            Rating-=newdfs(dep-1,Color^1,Rating-Max,state^Hash[Color][i][j]).first;
            Rating=min(Rating,INF);
            Rating=max(Rating,-INF);
            Board[i][j]=-1;
        }
        if(Rating>Max)x=i,y=j,Max=Rating;
        if(Max>=MaxLimit){
            return F[state]={Max,{x,y}};
        }
    }
    return F[state]={Max,{x,y}};
}
