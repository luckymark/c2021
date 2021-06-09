#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> pos;
typedef pair<int, pos> node;
inline node min(const node &x, const node &y){
    if (x.first == y.first)return x;
    return x.first < y.first ? x : y;
}
inline node max(const node &x, const node &y){
    if (x.first == y.first)return x;
    return x.first > y.first ? x : y;
}
bool board[2][16][16], computer, player;
bool mark[16][16];
vector<pos> getvaild(){
    vector<pos>result;
    memset(mark, 0, sizeof mark);
    for (int i = 1;i <= 15;++i)
        for (int j = 1;j <= 15;++j)
            if (board[0][i][j] || board[1][i][j])
                for (int x = max(1, i - 3);x <= min(15, i + 3);++x)
                    for (int y = max(1, j - 3);y <= min(15, j + 3);++y)
                        if (!mark[x][y] && !board[0][x][y] && !board[1][x][y]){
                            result.push_back({ x,y });
                            mark[x][y] = 1;
                        }
    if (result.empty())result.push_back({ 7,7 });
    return result;
}
const int mx[] = { 1,0,-1,1 };
const int my[] = { 0,1,1,1 };
inline bool isvaild(const int &x){
    return 1 <= x && x <= 15;
}
int sc(const int &cnt, const int &blk){
    if (cnt >= 5)return 1e8;
    if (blk >= 2 || cnt <= 1)return 0;
    switch (cnt){
        case 4:
            return blk ? 1280 : 2560;
        case 3:
            return blk ? 160 : 320;
        case 2:
            return blk ? 20 : 40;
    }
    return 0;
}
int assess_one(bool color, const int &x, const int &y){
    int tx, ty, cnt, blk, result = 0;
    for (int i = 0;i < 4;++i){
        tx = x;ty = y;cnt = blk = 0;
        while (isvaild(tx) && isvaild(ty) && board[color][tx][ty]){
            ++cnt;
            tx += mx[i];ty += my[i];
        }
        if (!isvaild(tx) || !isvaild(ty) || board[!color][tx][ty])++blk;
        tx = x;ty = y;
        while (isvaild(tx) && isvaild(ty) && board[color][tx][ty]){
            ++cnt;
            tx -= mx[i];ty -= my[i];
        }
        if (!isvaild(tx) || !isvaild(ty) || board[!color][tx][ty])++blk;
        result += sc(cnt - 1, blk);
    }
    return result;
}
int assess(bool color){
    memset(mark, 0, sizeof mark);
    int result = 0;
    for (int i = 1;i <= 15;++i)
        for (int j = 1;j <= 15;++j)
            if (board[color][i][j] && !mark[i][j])
                result += assess_one(color, i, j);
    return color == computer ? result : -result;
}
node minmaxdfs(int depth, bool color, int alpha, int beta){
    if (!depth)return { assess(color) + assess(!color),{0,0} };
    node score = { (depth & 1) ? INT_MAX : INT_MIN,{0,0} }, temp;
    for (pos t : getvaild()){
        board[color][t.first][t.second] = 1;
        temp = minmaxdfs(depth - 1, !color, alpha, beta);
        board[color][t.first][t.second] = 0;
        temp.second = t;
        if (temp.first >= 1e7 || temp.first <= -1e7)return temp;
        if (depth & 1){
            score = min(score, temp);
            if (temp.first < beta)break;
            alpha = min(alpha, temp.first);
        }
        else{
            score = max(score, temp);
            if (temp.first > alpha)break;
            beta = max(beta, temp.first);
        }
    }
    return score;
}
int px, py;
int main(){
    computer = !(player = 1);
    int round = 0;
    memset(board, 0, sizeof board);
    for (bool now = 0;;now = !now){
        printf("round %d\n", round);
        for (int i = 1;i <= 15;++i){
            for (int j = 1;j <= 15;++j){
                if (board[0][i][j])printf("B");
                else if (board[1][i][j])printf("W");
                else printf(" ");
            }
            printf("\n");
        }
        if (++round == 225){
            printf("pj");
            exit(0);
        }
        int scnow = assess(0) + assess(1);
        if (scnow > 1e7){
            printf("Black Win\n");
            exit(0);
        }
        else if (scnow < -1e7){
            printf("White Win\n");
            exit(0);
        }
        if (now == player){
        playerinput:;
            scanf("%d%d", &px, &py);
            if (px == -1 && py == -1)
                exit(0);
            if (isvaild(px) && isvaild(py) && !board[0][px][py] && !board[1][px][py]){
                board[now][px][py] = 1;
            }
            else goto playerinput;
        }
        else if (now == computer){
            clock_t start = clock();
            node result = minmaxdfs(4, now, INT_MAX, INT_MIN);
            printf("used time:%.2lfs\n", 1.0 * (clock() - start) / CLOCKS_PER_SEC);
            printf("computer(%d,%d)\n", result.second.first, result.second.second);
            board[now][result.second.first][result.second.second] = 1;
        }
    }
    return 0;
}