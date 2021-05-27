#ifndef frostylight_gobang_game
#define frostylight_gobang_game

#include<cstring>
#include<vector>
#include "DEBUG.h"
#include "gamebase.h"
using namespace std;

struct node{
    int sc;
    pos p;
    node(const int &x, const pos &y):sc(x), p(y){}
    inline node operator-()const{ return node(-sc, p); }
    inline bool operator>(const node &o)const{ return sc > o.sc; }
};

struct board{
    chess b[boardsize][boardsize];
    bool mark[boardsize][boardsize];

    // set the board to empty
    board(){ memset(b, 0, sizeof b); }

    // board copying from existing board
    board(const board &ob){ memcpy(b, ob.b, sizeof b); }

    // reset the board to empty
    void reset(){ memset(b, 0, sizeof b); }

    // get the color of chess in pos
    inline chess getboard(const pos &x)const{ return x.isVaild() ? b[x.x][x.y] : chess::empty; }

    // set the color of chess in pos
    inline void setboard(const pos &x, const chess &color){
        if (!x.isVaild())return;
        b[x.x][x.y] = color;
    }

    // return the score
    int score(const int &cnt, const int &block)const{
        if (cnt >= 5)return 1e8;
        if (block == 2 || cnt <= 1)return 0;
        switch (cnt){
            case 2:
                return block ? 20 : 40;
            case 3:
                return block ? 80 : 160;
            case 4:
                return block ? 320 : 640;
        }
        /* TODO fix the table of score */
        return 0;
    }

    // calculate the changing score of pos
    int assess(const pos &x)const{
        DEBUG_INFO("assess(%d,%d)->\n", x.x, x.y);
        int result = 0;
        pos t(x);
        for (int i = 0, cnt, block;i < 4;++i){
            cnt = 1;block = 0;
            t = x;
            while (t.move(direction[i]) && getboard(t) == getboard(x))++cnt;
            block += !t.isVaild() || getboard(t) != chess::empty;
            t = x;
            while (t.move(-direction[i]) && getboard(t) == getboard(x))++cnt;
            block += !t.isVaild() || getboard(t) != chess::empty;
            result += score(cnt, block);
            DEBUG_INFO("\tcount=%d, block=%d\n", cnt, block);
        }
        return result;
    }

    // get the vaild pos around the existing chess
    vector<pos> getVaildPos(const int &areaSize = AIConsiderAreaSize){
        memset(mark, 0, sizeof mark);
        vector<pos> result;
        for (int i = 1;i <= 15;++i)
            for (int j = 1;j <= 15;++j){
                if (!getboard({ i,j }))continue;
                for (int x = max(1, i - areaSize);x <= min(15, i + areaSize);++x)
                    for (int y = max(1, j - areaSize);y <= min(15, j + areaSize);++y){
                        if (getboard({ x,y }) || mark[x][y])continue;
                        mark[i][j] = true;
                        result.push_back({ i,j });
                    }
            }
        return result;
    }
};

struct game{
    // the board in this game
    board now;

    // the color of player/ai
    chess player, ai;

    // set the color of players
    game(chess pla, chess com):player(pla), ai(com){}

    // restart the game
    void restart(chess pla, chess com){
        player = pla;ai = com;
        now.reset();
    }

    // get the pos AI choose to place
    node minmaxdfs(int depth, int scorenow){
        // depth: even(AI),odd(Player)
        chess role = (depth & 1) ? player : ai;
        node result({ INT_MIN,{0,0} });
        for (pos x : now.getVaildPos()){
            now.setboard(x, role);
            node t = minmaxdfs(depth - 1, scorenow + now.assess(x));
            now.setboard(x, chess::empty);
            if (-t > result){
                result = -t;
            }
            /* TODO finish */
        }

    }

    // show the board
    void show();
};

#endif