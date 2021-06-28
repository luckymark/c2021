#include<stdio.h>
void hanoi(int n, char A, char B, char C);//�����ŵ������ĺ���
void move(int i, char A, char B);//��ʾ�ƶ�

int main()
{
    int n, t;
    char a='a', c='c', b='b';
    printf("please input the number of diskes that you want to move\n");
    scanf_s("%d", &n);
    hanoi(n, a, b, c);
    return 0;
}

void hanoi(int n, char A, char B, char C)
//A����ʼ����B���м���ʱ���õ����ӣ�C��Ŀ����
{
    int t = n;
    if (t > 0)
    //�ݹ���ֹ��������ע��ݹ鲻��ѭ����д��������Ĺ����Ǽ��������ɵ�
    {
        //���n�����ӵ����������
        hanoi(t - 1, A, C, B);//��n-1�����Ӵ���ʼ���ƶ����м���
        move(t, A, C);//�������ӣ���n��������ʼ���ƶ���Ŀ����
        hanoi(t - 1, B, A, C);//��n-1�����Ӵ��м����ƶ���Ŀ����
        t--;
    }  
}
void move(int i, char A, char B)
{
    printf("move disk %d from %c to %c\n", i, A, B);
}