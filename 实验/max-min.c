#include "go.h"
int evaluate(int me, int others);
void generator(int me, int others);
  
//��ô��ʾƲ�ࣿ������������һά���飬б�ŵ��ٽ�����ά����


int evaluate(int me,int others)
{   
    int  k=0, score=0;
    int  T = me, F = others;

    for (int i = 1;i < L + 1;i++)//������
        for (int j = 1;j < L + 1;j++)
        {
            if (board[i][j] == T)
            {  

                k = 1;
                int t = j;//��t��ʱ�洢j,����֮����ǰ��������Ȼ��j++,�����ظ����
                j++;
                while (board[i][j] == T)
                {
                    j++;
                    k++;
                }                 
                if (board[i][j] == F || board[i][t - 1] == F || board[i][j] == wall || board[i][t - 1] == wall)
                    k--;
                if ((board[i][j] == F && board[i][t - 1] == F) || (board[i][j] == wall && board[i][t - 1] == wall))
                    k = -1;//�����������һ
                if (k >= 0)
                    score = score + pow(10, k);
                j = t;
            }
        }

    for (int i = 1;i < L + 1;i++)//������
        for (int j = 1;j < L + 1;j++)
        {
            if (board[i][j] == T)
            {     
                k = 1;
                int t = i;
                i++;
                while (board[i][j] == T)//i=16,���ﾭ��һ��i++��i�Ѿ�������ĺ���һ����
                {
                    i++;
                    k++;
                }
                if (board[t - 1][j] == F || board[i][j] == F || board[t - 1][j] == wall || board[i][j] == wall)
                    k--;
                if ((board[t - 1][j] == F && board[i][j] == F )|| (board[t - 1][j] == wall && board[i + 1][j] == wall))
                    k = -1;//�����������һ
                if (k >= 0)
                    score = score + pow(10, k);
                i = t;
            }
        }

    for (int i = 1;i < L + 1;i += 1)//������Խ���
        for (int j = 1;j < L + 1;j += 1)
        {
            if (board[i][j] == T)
            {           
                k = 1;
                int t1 = i, t2 = j;
                i++; 
                j++;
                while (board[i][j] == T)
                {
                    i++; 
                    j++;
                    k++;
                }                    
                if (board[t1 - 1][t2 - 1] == F || board[i][j] == F || board[t1 - 1][t2 - 1] == wall || board[i][j] == wall)
                    //�жϲ��Ǳ߽�
                    k--;
                if ((board[t1 - 1][t2 - 1] == F && board[i][j] == F )|| (board[t1 - 1][t2 - 1] == wall && board[i][j] == wall))
                    k = -1;//�����������һ
                if (k >= 0)
                    score = score + pow(10, k);
                i = t1;
                j = t2;
            }
        }

    for (int i = 1;i < L + 1;i += 1)//��鷴�Խ���
        for (int j = 1;j < L + 1;j += 1)
        {
            if (board[i][j] == T)
            {
                k = 1;
                int t1 = i, t2 = j;
                i += 1;
                j -= 1;
                while (board[i][j] == T)
                {
                    i += 1;
                    j -= 1;
                    k++;
                }
                if (board[t1 - 1][t2 + 1] == F || board[i][j] == F || board[i][j] == wall || board[i][j] == wall)
                    k--;//�����߽�Ҳ�൱��������
                if ((board[t1 - 1][t2 + 1] == F && board[i][j] == F )|| (board[i][j] == wall && board[i][j] == wall))
                    k = -1;//�����������һ
                if (k >= 0)
                    score = score + pow(10, k);
                i = t1;
                j = t2;
            }
        }
    return score;
}

void generator(int me,int others)//�Ȳ����ھӣ�ֱ�ӱ���
{
    int my_score = 0;
    int t = 0;
    int m, n;
    for (int i = 1;i < L + 1;i += 1)
        for (int j = 1;j < L + 1;j += 1)
        {   
            if (!board[i][j])//�����������������������֮��ĵ÷�
            {
                board[i][j] = me;
                t=evaluate(me, others)- evaluate(others, me);
                n = evaluate(me, others);
                m = evaluate(others, me);
                board[i][j] = 0;
            }
            if (t > my_score)
            {
                board[i][j] = me;
                my_score = t;
                AI_x = j;//�����ʾ������������ʾ�Ƿ���
                AI_y = i;
            }
        }
}

//��ʲô���ݽṹ�������ھӵ�λ��
/*
void neighbor()
{
    for (int i = 0;i < 15;i++)
        for (int j = 0;j < 15;j++)
        {
            if (!board[i][j])
            {

            }

        }
    

}
*/

