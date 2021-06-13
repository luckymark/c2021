#include "Chess.h"
#include "heuristic.h"

//���ɿ����������ھӵĿ�λ�ĺ���
int generator(int empty[][2],int now_board[L+2][L+2])//������������
{
    int empty_cnt = 0;
    for (int i = 1;i < L + 1;i += 1)
    {
        for (int j = 1;j < L + 1;j += 1)
        {
            if (neighbor(i, j,now_board)&&!now_board[i][j])
            {
                empty[empty_cnt][0] = i;
                empty[empty_cnt][1] = j;
                empty_cnt++;
            }
        }
    }
    return empty_cnt;
}
//������λ�õķ����ĺ��� 
int point_evaluate(int x, int y,int me, int now_board[L + 2][L + 2])
{
    now_board[x][y] = me;
    int n1=0, n2=0, t;
    int value=0;
    for (int i = 0;i < 4;i++)//i��ʾ�˸�����
    {
        for (int j = 0;j <= 5;j++)//j��ʾ������������˼���
        {
            int dx = x + j * dir[i][0];
            int dy = y + j * dir[i][1];
            if (now_board[dy][dx] == me)//AI_x,AI_y���������ϵ�x��y����ʾ����Ҫ������
                n1++;
            else
                break;
        }
        for (int j = 0;j <= 5;j++)//j��ʾ������������˼���
        {
            int dx = x + j * dir[7 - i][0];
            int dy = y + j * dir[7 - i][1];
            if (now_board[dy][dx] == me)
                n2++;
            else
                break;
        }
        t = n1 + n2;
        if (t > value)
        {
            value = t;
        }
    }
    //�ж��ǲ���ɱ��
    now_board[x][y] = 0;
    return value;
}
//�жϸ�λ������֮���Ƿ����ھӵĺ���
int neighbor(int x, int y, int now_board[L+2][L+2])//�жϿ�λ������֮���Ƿ����ھ�
{
    for (int di = 0;di < 8;di++)//i��ʾ�˸�����
        for (int dj = 1;dj < 3;dj++)//j��ʾ������������˼���
        {
            int dx = x + dj * dir[di][0];
            int dy = y + dj * dir[di][1];
            if (dx > 0 && dx < L + 1 && dy>0 && dy < L + 1)
                if (now_board[dx][dy] == red || now_board[dx][dy] == white)
                    return 1;
        }
    return 0;
}
//����ʽ��������
void heuristic_search(int point_value[][3], int empty_point[][2], int empty_cnt, int me, int now_board[L + 2][L + 2])
{
    int cnt = 0;
    int others;
    if (me == red)
        others = white;
    else
        others = red;
    for (int i = 0;i < empty_cnt;i++)
    {
        int x = empty_point[i][0];
        point_value[i][0] = x;
        int y = empty_point[i][1];
        point_value[i][1] = y;
        point_value[i][2] = point_evaluate(x, y, me, now_board) + point_evaluate(x, y, others, now_board);
    }

    qsort(point_value, empty_cnt, sizeof(int) * 3, comp);

}
/*
void heuristic_search(struct Point *p, int me, int now_board[L + 2][L + 2])
*/
//qsort����ıȽϹ�����
int comp(const void* a, const void* b)
{
    if (((int*)a)[2] < ((int*)b)[2])
        return 1;
    else return -1;
}

