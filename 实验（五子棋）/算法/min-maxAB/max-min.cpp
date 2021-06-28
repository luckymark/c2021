#include "Chess.h"
#include "max-min.h"
#include "heuristic.h"
//��ô��ʾƲ�ࣿ������������һά���飬б�ŵ��ٽ�����ά����

//�����������͵ĺ�������������evaluate����search�����ϵĴ��
int search(int x, int y,int me,int vis[][L+2],int copy[][L+2])//�����ж��ٿ�����
{
    int value = 0;
    int maxdir = 0;
    int T, F;

    if (me == 1)
    {
        T = red;
        F = white;
    }
    else
    {
        F = red;
        T = white;
    }

    for (int i = 0;i < 8;i++)//i��ʾ�˸�����
        for (int j = 1;j <= 5;j++)//j��ʾ������������˼���
        {
            int dx = x + j*dir[i][0];
            int dy = y + j*dir[i][1];
            if (copy[dx][dy] != T)
            {
                if (j > value)
                {
                    value = j;//��¼��������������ķ��򣬼�¼������Ϊ��֮���Ѱ��
                    maxdir = i;
                }
                break;
            }       
        }
   
    if (value == 5)//���������������ȣ�����Ҫ�ٿ�����ͷ������
        ;
    else
    {
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
        if (dx1 < 0 || dy1 < 0)
            value--;
        else
            if (copy[dx1][dy1] == F || copy[dx1][dy1] == wall)
            {
                value--;
                if (copy[dx2][dy2] == F || copy[dx2][dy2] == wall)
                    value = 0;//��ͷ�����£�����Ϊ0
            }               
        if (copy[dx2][dy2] == F || copy[dx2][dy2] == wall)//��һͷ���·���-1
            value--;
    }
    return value;    
}
//ȫ�ַ�����������
int evaluate(int me,int copy[][L+2])//ȫ������ĳһ���ķ���,turn=1����red��a=2����white
{   
    int  k=0, score=0;
    int value = 0;
    int vis[17][17] = { {0},{0} };
 
    //�����ҵ��ҷ����ӿ�ʼsearch ����
    for (int i = 1;i < L + 1;i++)
        for (int j = 1;j < L + 1;j++)
        {
            if (copy[i][j] == me && (!vis[i][j]))//���ҷ���û�б�������
            {
                value = search(i, j, me, vis, copy);
                //�Ʒַ�ʽ��n���ӣ�10^n����һ������n-1
                score = score + pow(10, value);
            }
        }
    return score;
}
//������������
int IDDFS()
{
    for (int i = 2;i <= rank;i++)
    {
        if (!minMax_AB(i, red, NGIF, PTIF, board))break;
    }
    return 0;
}

//����ֵ��Сֵ�����������¼�֦��
int minMax_AB(int depth, int me, int Alpha, int Beta, int tmp_board[][L+2])
//��������,tΪ1��ʾ���壬Ϊ2��ʾ����,����ʱAlpha��Beta��ΪNGIF,PTIF
{
    int c[L+2][L+2];
    int minmax;
    int rival;
    Tree tree;
    Point point[200];
    tree.Alpha = Alpha;
    tree.Beta = Beta;
    tree.X = 0;
    tree.Y = 0;
    if (me == 1)
        rival = 2;
    else
        rival = 1;
    if (judge_winner(tree.X, tree.Y, me) == me|| depth == 0)
        return evaluate(me, tmp_board)-evaluate(rival,tmp_board);
    if (depth % 2)//�ж���min�㻹��max��
    {
        //min��
        int empty_cnt = generator(point,tmp_board);
        int kill_cnt;
        kill_cnt =heuristic_search(point, empty_cnt,white, tmp_board);
        //������ȳ����Ĳ�Ϳ�����ɱ��ֻ����������ߵ�ǰ����ڵ�
        if (depth > 4)
        {
            if (kill_cnt)
                empty_cnt = kill_cnt;
            else 
                empty_cnt = 5;
        }
        for (int k = 0;k < empty_cnt;k++)
        {
            //�������ɱ�壬�����֦ȫ������
            /*�������ԣ�������֦Ч���������룬��������Ϊ����˫�����ߵ�ԭ����Щɱ���޷����
            if (kill_cnt)
            {
                int i = point[k].X;
                int j = point[k].Y;
                empty_cnt = kill_cnt;
            }
            */
            int i = point[k].X;
            int j = point[k].Y;
            if (tree.Alpha < tree.Beta)
            {
                memcpy(c, tmp_board, sizeof(int) * L * L);//��������
                c[i][j] = me;
                minmax = minMax_AB(depth - 1, rival, tree.Alpha, tree.Beta, c);
                c[i][j] = 0;
                if (minmax < tree.Beta)
                {
                    tree.Beta = minmax;
                    tree.X = j;
                    tree.Y = i;
                    if (tree.Alpha >= tree.Beta)
                        return tree.Alpha;//����֦�����������ڵ�
                }
            }
        }
        return tree.Beta;
    }
    else
    {
        //max��
        int empty_cnt = generator(point, tmp_board);
        heuristic_search(point, empty_cnt, red, tmp_board);
        if (depth > 4)
        {
            if (empty_cnt > 5)
                empty_cnt = 5;
        }
        for (int k = 0;k < empty_cnt;k++)
        {
            int i = point[k].X;
            int j = point[k].Y;
            if (tree.Alpha < tree.Beta)
            {
                memcpy(c, tmp_board, sizeof(int) * L * L);
                //��һ���µ������ʾ���̣������ƻ�ԭ����
                c[i][j] = me; 
                minmax = minMax_AB(depth - 1, rival, tree.Alpha, tree.Beta,c);
                c[i][j] = 0;
                if (minmax > tree.Alpha)
                {
                    tree.Alpha = minmax;
                    tree.X = j;
                    tree.Y = i;
                    if (tree.Alpha >= tree.Beta)
                        return tree.Beta;//����֦�����������ڵ�
                }
            }
        }
        AI_x = tree.X;
        AI_y = tree.Y;
        return tree.Alpha;
    }
    
}









