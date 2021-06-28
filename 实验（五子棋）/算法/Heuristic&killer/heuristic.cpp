#include "Chess.h"
#include "heuristic.h"

//生成可下棋且有邻居的空位的函数
int generator(Point empty_point[200],int now_board[L+2][L+2])//产生空子序列
{
    int empty_cnt = 0;
    for (int i = 1;i < L + 1;i += 1)
    {
        for (int j = 1;j < L + 1;j += 1)
        {
            if (neighbor(i, j,now_board)&&!now_board[i][j])
            {
                empty_point[empty_cnt].X = i;
                empty_point[empty_cnt].Y = j;
                empty_point[empty_cnt].is_killer = 0;
                empty_cnt++;
            }
        }
    }
    return empty_cnt;
}
//评估该位置的分数的函数 
int point_evaluate(int x, int y,int me, int now_board[L + 2][L + 2])
{
    now_board[x][y] = me;
    int n1=0, n2=0, t;
    int value=0;
    for (int i = 0;i < 4;i++)//i表示八个方向
    {
        for (int j = 0;j <= 5;j++)//j表示沿这个方向走了几步
        {
            int dx = x + j * dir[i][0];
            int dy = y + j * dir[i][1];
            if (now_board[dy][dx] == me)//AI_x,AI_y都是坐标上的x，y，表示数组要反过来
                n1++;
            else
            {
                if (!now_board[dy + dir[i][1]][dx + dir[i][0]])
                    n1--;
                break;
            }                
        }
        for (int j = 0;j <= 5;j++)//j表示沿这个方向走了几步
        {
            int dx = x + j * dir[7 - i][0];
            int dy = y + j * dir[7 - i][1];
            if (now_board[dy][dx] == me)
                n2++;
            else
            {
                if (!now_board[dy+ dir[7 - i][1]][dx+ dir[7 - i][0]])
                    n2--;
                break;
            }      
        }
        t = n1 + n2;
        if (t > value)
        {
            value = t;
        }
    }
    now_board[x][y] = 0;
    return value;
}
//判断该位置两步之内是否有邻居的函数
int neighbor(int x, int y, int now_board[L+2][L+2])//判断空位置两步之内是否有邻居
{
    for (int di = 0;di < 8;di++)//i表示八个方向
        for (int dj = 1;dj < 3;dj++)//j表示沿这个方向走了几步
        {
            int dx = x + dj * dir[di][0];
            int dy = y + dj * dir[di][1];
            if (dx > 0 && dx < L + 1 && dy>0 && dy < L + 1)
                if (now_board[dx][dy] == red || now_board[dx][dy] == white)
                    return 1;
        }
    return 0;
}
//启发式搜索函数
int heuristic_search(Point empty_point[200], int empty_cnt, int me, int now_board[L + 2][L + 2])
{
    int cnt = 0;
    int kill_cnt=0;
    int others;
    if (me == red)
        others = white;
    else
        others = red;
    for (int i = 0;i < empty_cnt;i++)
    {
        int x = empty_point[i].X;
        int y = empty_point[i].Y;
        int me_value = point_evaluate(x, y, me, now_board);
        int others_value = point_evaluate(x, y, others, now_board);
        empty_point[i].value = me_value + others_value;

        //判断是不是杀棋
        is_killer(&empty_point[i], me_value, others_value);
        if (empty_point[i].is_killer)
            kill_cnt++;        
    }
    
   if(!kill_cnt)
        qsort(empty_point, empty_cnt, sizeof(empty_point[0]), comp1);
    else
        qsort(empty_point, kill_cnt, sizeof(empty_point[0]), comp2);
    return kill_cnt;
}

//判断是否是杀棋并评定等级
void is_killer(Point* p, int me_value, int others_value)
{
    if (me_value > 4)
        p->is_killer = 4;
    else
    {
        if (others_value > 4)
            p->is_killer = 3;
        else
        {
            if (me_value > 3)
                p->is_killer = 2;
            else
            {
                if (others_value > 3)
                    p->is_killer = 1;
            }
        }
    }
}

//qsort排序的比较规则函数
//没有杀棋就用评估分数比较
int comp1(const void* a, const void* b)
{
    return (*(Point*)a).value < (*(Point*)b).value ? 1 : -1;
}
//有杀棋就用杀棋的级别比较
int comp2(const void* a, const void* b)
{
    return (*(Point*)a).is_killer < (*(Point*)b).is_killer ? 1 : -1;
}

