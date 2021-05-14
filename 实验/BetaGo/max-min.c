#include "go.h"
int evaluate(int me, int others);
void generator(int me, int others);
  
//��ô��ʾƲ�ࣿ������������һά���飬б�ŵ��ٽ�����ά����
typedef struct node
{
    int x, y;
}Node;

int dfs(int x, int y,int T,int F,int vis[][17])
{
    int value = 0;
    int maxdir = 0;
    for (int i = 0;i < 8;i++)//i��ʾ�˸�����
        for (int j = 1;j <= 5;j++)//j��ʾ������������˼���
        {
            int dx = x + j*dir[i][0];
            int dy = y + j*dir[i][1];
            if (board[dx][dy] != T)
            {
                if (j > value)
                {
                    value = j;//��¼��������������ķ���
                    maxdir = i;
                }
                break;
            }       
        }
 
    //�����������
   
    //����Ѿ������������·���ϵĽڵ㣬�����ظ�����
    for (int j = 0;j <= value;j++)
    {
        int dx = x + j * dir[maxdir][0];
        int dy = y + j * dir[maxdir][1];
        vis[dx][dy] = 1;
    }
   
    //�ж����ӵ�����
    int dx1 = x + value * dir[maxdir][0];
    int dy1 = y + value * dir[maxdir][1];
    int dx2 = x - dir[maxdir][0];
    int dy2 = y - dir[maxdir][1];
    if(dx1<0||dy1<0)
        value--;
    else 
        if (board[dx1][dy1] == F || board[dx1][dy1] == wall)
            value--;
    if (board[dx2][dy2] == F || board[dx2][dy2] == wall)
        value--;
    return value;    
}

int evaluate(int me,int others)//ȫ������ĳһ���ķ���
{   
    int  k=0, score=0;
    int  T = me, F = others;
    int value = 0;
    int vis[17][17] = { {0},{0} };
   
    //�����ҵ��ҷ����ӿ�ʼdfs
    for (int i = 1;i < L + 1;i++)
        for (int j = 1;j < L + 1;j++)
        {
            if (board[i][j] == T && (!vis[i][j]))//���ҷ���û�б�������
            {
                value = dfs(i, j, T, F, vis);
                score = score + pow(10, value);
            }
        }
    return score;
}

void generator()//����AI�����ӵĺ���
{
    int my_score = -100;
    int t = -1000;
    int m, n;
    for (int i = 1;i < L + 1;i += 1)
        for (int j = 1;j < L + 1;j += 1)
        {   
            int is_nei = neighbor(i, j);//���Ӹ�������֮��������
            if (board[i][j]==0 && is_nei)//�����������������������֮��ĵ÷�
            {
                board[i][j] = red;
                t=evaluate(red, white)- evaluate(white, red);
                board[i][j] = 0;
            }
            if (t > my_score)
            {
                my_score = t;
                AI_x = j;//�����ʾ������������ʾ�Ƿ���
                AI_y = i;
            }
        }
}


int neighbor(int x,int y)
{
    for (int di = 0;di < 8;di++)//i��ʾ�˸�����
        for (int dj = 1;dj < 3;dj++)//j��ʾ������������˼���
        {
            int dx = x + dj * dir[di][0];
            int dy = y + dj * dir[di][1];
            if (dx > 0 && dx < L + 1 && dy>0 && dy < L + 1)
                if (board[dx][dy] == red || board[dx][dy] == white)
                    return 1;
        }
    return 0;
}




