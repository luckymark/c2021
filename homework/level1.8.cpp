#include <stdio.h>

void move(int n, char a, char b, char c);

int main()
{
	int n;
	printf("please input the number of your disks:");
	scanf("%d", &n);
	move(n, 'A', 'B', 'C');


}
void move(int m, char a, char b, char c)//move�����������ǰ�m�������Ƶ�Ŀ���� 
{
	if(1==m)
	    printf("move disk %d from %c to %c\n", m, a, c); //�ݹ��ֹ����
	else
	{
		move(m-1,a,c,b);//�� m-1�������ȷŵ��м��������ڵ�m�飩�ϣ�������m-1�飩��ʱ��ʼ����a��Ŀ������b 
	    printf("move disk %d from %c to %c\n", m, a, c);//��A���ϵ�ʣ�µ�һ�����ƶ���C����
		move(m-1,b,a,c);//��m-1���̴��м����ƶ���Ŀ������ 
	}
	


