#include<bits/stdc++.h>
using namespace std;
//<行,列>
typedef pair<int, int> pos;
//<分数,位置>
typedef pair<int, pos> topos;
//返回分数更小的
inline topos min(const topos &x, const topos &y){
    if (x.first == y.first)return x;
    return x.first < y.first ? x : y;
}
//返回分数更大的
inline topos max(const topos &x, const topos &y){
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
            if (board[0][i][j] || board[1][i][j])//把以存在的棋子为中心的5*5区域内的空位纳入考虑范围
                for (int x = max(1, i - 2);x <= min(15, i + 2);++x)
                    for (int y = max(1, j - 2);y <= min(15, j + 2);++y)
                        if (!mark[x][y] && !board[0][x][y] && !board[1][x][y]){
                            result.emplace_back(x, y);
                            mark[x][y] = 1;
                        }
    if (result.empty())result.emplace_back(8, 8);//先手先下正中心
    random_shuffle(result.begin(), result.end());//打乱位置顺序
    return result;
}
//4个方向的坐标变化
const int movex[] = { 1,0,-1,1 };
const int movey[] = { 0,1,1,1 };
//坐标是否合法
inline bool isvaild(const int &x){ return 1 <= x && x <= 15; }
//简易的评分方式
int score(const int &cnt, const int &block){
    if (cnt >= 5)return 1e8;//五子
    if (block >= 2)return 0;//两端被堵住
    switch (cnt){
        case 4:
            return block ? 1e5 : 1e6;
        case 3:
            return block ? 1e3 : 1e4;
        case 2:
            return block ? 1e2 : 1e3;
        case 1:
            return block ? 0 : 10;
    }
    return 0;
}
int assess_one(bool color, const int &x, const int &y){//与这个位置相连的棋子
    int tox, toy, cnt, block, result = 0;
    for (int i = 0;i < 4;++i){//四个方向
        tox = x;toy = y;cnt = block = 0;
        while (isvaild(tox) && isvaild(toy) && board[color][tox][toy]){//正方向
            ++cnt;
            mark[tox][toy] = 1;
            tox += movex[i];toy += movey[i];
        }
        if (!isvaild(tox) || !isvaild(toy) || board[!color][tox][toy])++block;
        tox = x;toy = y;
        while (isvaild(tox) && isvaild(toy) && board[color][tox][toy]){//反方向
            ++cnt;
            mark[tox][toy] = 1;
            tox -= movex[i];toy -= movey[i];
        }
        if (!isvaild(tox) || !isvaild(toy) || board[!color][tox][toy])++block;
        result += score(cnt - 1, block);
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
//判断是否一方胜利
int checkwin(){
    memset(mark, 0, sizeof mark);
    int color;
    for (int i = 1;i <= 15;++i)
        for (int j = 1;j <= 15;++j){
            if (mark[i][j])continue;
            if (board[0][i][j])color = 0;
            else if (board[1][i][j])color = 1;
            else continue;
            if (assess_one(color, i, j) > 1e7)return color;
        }
    return 233;
}
//带Alpha-Beta剪枝的极大极小值搜索
topos minmaxdfs(int depth, bool color, int alpha, int beta){
    if (!depth)return { assess(color) + assess(!color),{0,0} };//返回棋盘局势
    topos score = { (depth & 1) ? INT_MAX : INT_MIN,{0,0} }, temp;
    for (pos t : getvaild()){//考虑落子位置
        board[color][t.first][t.second] = 1;
        temp = minmaxdfs(depth - 1, !color, alpha, beta);
        board[color][t.first][t.second] = 0;//回溯
        temp.second = t;
        if (temp.first >= 1e7 || temp.first <= -1e7)return temp;//连成五子
        if (depth & 1){
            score = min(score, temp);
            if (temp.first < beta)break;//alpha剪枝
            alpha = min(alpha, temp.first);
        }
        else{
            score = max(score, temp);
            if (temp.first > alpha)break;//beta剪枝
            beta = max(beta, temp.first);
        }
    }
    return score;//返回较优解
}
//显示棋盘
void showboard(){
    printf("   1 2 3 4 5 6 7 8 9 0 1 2 3 4 5\n");//列号
    for (int i = 1;i <= 15;++i){//行号
        printf("%2d ", i);
        for (int j = 1;j <= 15;++j){
            if (j != 1)printf("─");
            if (board[0][i][j])printf("●");//黑棋
            else if (board[1][i][j])printf("○");//白棋
            else if (i == 1 && j == 1)printf("┌");
            else if (i == 1 && j == 15)printf("┐");
            else if (i == 15 && j == 1)printf("└");
            else if (i == 15 && j == 15)printf("┘");
            else if (i == 1)printf("┬");
            else if (i == 15)printf("┴");
            else if (j == 1)printf("├");
            else if (j == 15)printf("┤");
            else printf("┼");
        }
        putchar('\n');
    }
}
int main(){
    system("chcp 65001");//切换编码UTF-8
    system("cls");
    computer = !(player = 1);//玩家为白子后手
    int round = 0, scnow, px, py;
    memset(board, 0, sizeof board);
    for (bool now = 0;;now = !now){
        if (round)showboard();
        if (++round == 225){//平局
            printf("平局");
            exit(0);
        }
        scnow = checkwin();
        if (scnow == player){//黑棋胜利
            printf("你胜利了!\n");
            exit(0);
        }
        else if (scnow == computer){//白棋胜利
            printf("AI胜利了!\n");
            exit(0);
        }
        if (now == player){//玩家输入坐标
            printf("输入落子坐标(-1 -1 退出)\n");
        playerinput:;
            scanf("%d%d", &px, &py);
            if (px == -1 && py == -1)
                exit(0);
            if (isvaild(px) && isvaild(py) && !board[0][px][py] && !board[1][px][py])
                board[now][px][py] = 1;
            else goto playerinput;
        }
        else if (now == computer){//计算AI落子
            clock_t start = clock();
            topos result = minmaxdfs(4, now, INT_MAX, INT_MIN);
            printf("计算用时:%.2lfs\n", 1.0 * (clock() - start) / CLOCKS_PER_SEC);//计算用时
            printf("AI落子于(%d,%d)\n", result.second.first, result.second.second);//输出AI落子位置
            board[now][result.second.first][result.second.second] = 1;
        }
    }
    return 0;
}