#include <stdio.h>
#include "def.h"
#include <windows.h>
#include <math.h>
int win(int **board, int x, int y) //胜利判断函数
{
    int dir[8][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}, {1, -1}, {-1, 1}, {1, 1}, {-1, -1}};
    int obj = board[x][y];
    int times = 4; //横竖两斜四个方向共四次
    for (int i = 0; i < times; i++)
    {
        int deep1 = 0; //一个方向上
        int deep2 = 0; //另一个方向上
        int dx = x;
        int dy = y;
        for (int j = 0; j < 5; j++)
            if (board[dx + dir[2 * i][0]][dy + dir[2 * i][1]] == obj)
            {
                deep1++;
                dx = dx + dir[2 * i][0];
                dy = dy + dir[2 * i][1];
            }
            else
                break;
        if (deep1 == 4)
        {
            return 1;
        } //在一个方向上已经达到5
        else
        {
            dx = x;
            dy = y;
            for (int j = 0; j < 5; j++)
                if (board[dx + dir[2 * i + 1][0]][dy + dir[2 * i + 1][1]] == obj)
                {
                    deep2++;
                    dx = dx + dir[2 * i + 1][0];
                    dy = dy + dir[2 * i + 1][1];
                }
                else
                    break; //找同一直线的另一个方向
            int deep = deep1 + deep2 + 1;
            if (deep >= 5)
            {
                return 1;
            }
        }
    }
    return 0;
}
int board_scores(int **board, int user) //对棋盘进行全局打分判断
{

    int sum = 0;
    int role = 0;
    int robot = 0;
    int end = 1;
    //横着搜
    for (int i = 1; i <= 15; i++)
    {
        for (int j = 1; j <= 15; j++)
        {
            if ((board[i][j] == empty || board[i][j] == useful) && robot == 0 && role == 0)
            {
                end = 0;
            }
            else if (board[i][j] == user && robot == 0)
            {
                role++;
            }
            else if (board[i][j] == abs(1 - user) && role == 0)
            {
                robot++;
            }
            else if (board[i][j] == user)
            {
                end++;
                sum = sum + scores(robot, end);
                end = 1;
                robot = 0;
                role++;
            }
            else if (board[i][j] == abs(1 - user))
            {
                end++;
                sum = sum - scores(role, end) * 1.1;
                end = 1;
                role = 0;
                robot++;
            }
            else if (board[i][j] == empty || board[i][j] == useful)
            {
                sum = sum - scores(role, end) * 1.1;
                sum = sum + scores(robot, end);
                end = 0;
                role = 0;
                robot = 0;
            }
        }
        end = 1;
        role = 0;
        robot = 0;
    }
    //竖着搜
    for (int j = 1; j <= 15; j++)
    {
        for (int i = 1; i <= 15; i++)
        {
            if ((board[i][j] == empty || board[i][j] == useful) && robot == 0 && role == 0)
            {
                end = 0;
            }
            else if (board[i][j] == user && robot == 0)
            {
                role++;
            }
            else if (board[i][j] == abs(1 - user) && role == 0)
            {
                robot++;
            }
            else if (board[i][j] == user)
            {
                end++;
                sum = sum + scores(robot, end);
                end = 1;
                robot = 0;
                role++;
            }
            else if (board[i][j] == abs(1 - user))
            {
                end++;
                sum = sum - scores(role, end) * 1.1;
                end = 1;
                role = 0;
                robot++;
            }
            else if (board[i][j] == empty || board[i][j] == useful)
            {
                sum = sum - scores(role, end) * 1.1;
                sum = sum + scores(robot, end);
                end = 0;
                role = 0;
                robot = 0;
            }
        }
        end = 1;
        role = 0;
        robot = 0;
    }
    //斜着搜
    for (int k = 2; k <= 16; k++)
    {
        for (int j = 1; j <= k - 1; j++)
        {
            if ((board[k - j][j] == empty || board[k - j][j] == useful) && robot == 0 && role == 0)
            {
                end = 0;
            }
            else if (board[k - j][j] == user && robot == 0)
            {
                role++;
            }
            else if (board[k - j][j] == abs(1 - user) && role == 0)
            {
                robot++;
            }
            else if (board[k - j][j] == user)
            {
                end++;
                sum = sum + scores(robot, end);
                end = 1;
                robot = 0;
                role++;
            }
            else if (board[k - j][j] == abs(1 - user))
            {
                end++;
                sum = sum - scores(role, end) * 1.1;
                end = 1;
                role = 0;
                robot++;
            }
            else if (board[k - j][j] == empty || board[k - j][j] == useful)
            {
                sum = sum - scores(role, end) * 1.1;
                sum = sum + scores(robot, end);
                end = 0;
                role = 0;
                robot = 0;
            }
        }
        end = 1;
        role = 0;
        robot = 0;
    }
    for (int k = 17; k <= 30; k++)
    {
        for (int j = 15; j >= k - 15; j--)
        {
            if ((board[k - j][j] == empty || board[k - j][j] == useful) && robot == 0 && role == 0)
            {
                end = 0;
            }
            else if (board[k - j][j] == user && robot == 0)
            {
                role++;
            }
            else if (board[k - j][j] == abs(1 - user) && role == 0)
            {
                robot++;
            }
            else if (board[k - j][j] == user)
            {
                end++;
                sum = sum + scores(robot, end);
                end = 1;
                robot = 0;
                role++;
            }
            else if (board[k - j][j] == abs(1 - user))
            {
                end++;
                sum = sum - scores(role, end) * 1.1;
                end = 1;
                role = 0;
                robot++;
            }
            else if (board[k - j][j] == empty || board[k - j][j] == useful)
            {
                sum = sum - scores(role, end) * 1.1;
                sum = sum + scores(robot, end);
                end = 0;
                role = 0;
                robot = 0;
            }
        }
        end = 1;
        role = 0;
        robot = 0;
    }
    //再斜着搜
    for (int k = 14; k >= 0; k--)
    {
        for (int j = 1; j <= 15 - k; j++)
        {
            if ((board[k + j][j] == empty || board[k + j][j] == useful) && robot == 0 && role == 0)
            {
                end = 0;
            }
            else if (board[k + j][j] == user && robot == 0)
            {
                role++;
            }
            else if (board[k + j][j] == abs(1 - user) && role == 0)
            {
                robot++;
            }
            else if (board[k + j][j] == user)
            {
                end++;
                sum = sum + scores(robot, end);
                end = 1;
                robot = 0;
                role++;
            }
            else if (board[k + j][j] == abs(1 - user))
            {
                end++;
                sum = sum - scores(role, end) * 1.1;
                end = 1;
                role = 0;
                robot++;
            }
            else if (board[k + j][j] == empty || board[k + j][j] == useful)
            {
                sum = sum - scores(role, end) * 1.1;
                sum = sum + scores(robot, end);
                end = 0;
                role = 0;
                robot = 0;
            }
        }
        end = 1;
        role = 0;
        robot = 0;
    }
    for (int k = -1; k >= -14; k--)
    {
        for (int j = -k; j <= 15; j++)
        {
            if ((board[k + j][j] == empty || board[k + j][j] == useful) && robot == 0 && role == 0)
            {
                end = 0;
            }
            else if (board[k + j][j] == user && robot == 0)
            {
                role++;
            }
            else if (board[k + j][j] == abs(1 - user) && role == 0)
            {
                robot++;
            }
            else if (board[k + j][j] == user)
            {
                end++;
                sum = sum + scores(robot, end);
                end = 1;
                robot = 0;
                role++;
            }
            else if (board[k + j][j] == abs(1 - user))
            {
                end++;
                sum = sum - scores(role, end) * 1.1;
                end = 1;
                role = 0;
                robot++;
            }
            else if (board[k + j][j] == empty || board[k + j][j] == useful)
            {
                sum = sum - scores(role, end) * 1.1;
                sum = sum + scores(robot, end);
                end = 0;
                role = 0;
                robot = 0;
            }
        }
        end = 1;
        role = 0;
        robot = 0;
    }
    return sum;
}
int scores(int chesses, int ends) //估值函数
{
    int sum = 0;
    if (chesses == 0)
    {
        return 0;
    }
    if (ends == 0)
    {
        switch (chesses)
        {
        case 1:
            sum += 10;
            break;
        case 2:
            sum += 100;
            break;
        case 3:
            sum += 1000;
            break;
        case 4:
            sum += 10000;
            break;
        case 5:
            sum += 100000000;
            break;
        default:
            break;
        }
    }
    else if (ends == 1)
    {
        switch (chesses)
        {
        case 1:
            sum += 1;
            break;
        case 2:
            sum += 10;
            break;
        case 3:
            sum += 100;
            break;
        case 4:
            sum += 1000;
            break;
        case 5:
            sum += 100000000;
            break;
        default:
            break;
        }
    }
    else
    {

        switch (chesses)
        {
        case 1:
            sum += 0;
            break;
        case 2:
            sum += 1;
            break;
        case 3:
            sum += 10;
            break;
        case 4:
            sum += 100;
            break;
        case 5:
            sum += 100000000;
            break;
        default:
            break;
        }
    }
    return sum;
}
