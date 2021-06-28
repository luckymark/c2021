#include<stdio.h>
#include <graphics.h>
#include <conio.h>  //��Ҫ��������Ԥ����ͷ�ļ�
#define L 15
typedef struct chess //������һ����type �Ľṹ����
{
	int x;
	int y;
}CHESS;
//ȫ�ֱ���
CHESS bla;
int judge[19 * 30][19 * 30];
int count = 0;//���������ж�����������
int flag = 0;//�ж���Ϸ�Ƿ����
void chessboard()//�����̱���
{
	int step = 30;
	// ��ʼ����ͼ����
	initgraph(800, 600);
	// ���ñ���ɫΪ��ɫ
	setbkcolor(YELLOW);
	// �ñ���ɫ�����Ļ
	cleardevice();

	setlinestyle(PS_SOLID, 2);  // ��ʵ�ߣ����Ϊ2������
	setcolor(RGB(0, 0, 0));  // ����Ϊ��ɫ
	outtextxy(600, 100, _T("W,A,S,Dʵ��λ���ƶ�"));
	outtextxy(600, 120, _T("G��������"));

	int i, j;
	for (i = 1; i <= L; i++)  // �����ߺ�����
	{
		line(i * step, 1 * step, i * step, L * step);
		line(1 * step, i * step, L * step, i * step);

	}
	for (i = 0; i <= L; i++)
		for (j = 0; j <= L; j++)
			judge[i][j] = 0;//��ʼ�������ж�
	bla.x = 10 * 30;
	bla.y = 10 * 30;//��ʼ����������
}
int inputchess(CHESS temp, int color, int t)
{
	bla = temp;
	setcolor(color);
	setfillcolor(color);
	if (bla.x <= L * 30 && bla.y <= L * 30)
		fillcircle(bla.x, bla.y, 12);
	judge[bla.x][bla.y] = t;//�����
	int i, j, f;
	for (i = 0; i < L; i++) //�ж��Ƿ���һ��ʤ��
	{/*����*/
		j = f = 0;
		while (f < 5 && j < L)
		{
			if (judge[i * 30][j * 30] == t) f++;
			else f = 0;
			j++;
		}
		if (f == 5) return  t;
	}
	for (j = 0; j < L; j++)
	{/*����*/
		i = f = 0;
		while (f < 5 && i < L)
		{
			if (judge[i * 30][j * 30] == t) f++;
			else f = 0;
			i++;
		}
		if (f == 5) return t;
	}
	for (i = 0; i < 12; i++)
	{/*��б*/
		j = f = 0;
		while (f < 5 && j < 15)
		{
			if (judge[(i + f) * 30][(j + f) * 30] == t) f++;
			else { f = 0; j++; }
		}
		if (f == 5) return  t;
	}
	for (i = 4; i < 19; i++)
	{/*��б*/
		j = f = 0;
		while (f < 5 && j < 12)
		{
			if (judge[(i - f) * 30][(j + f) * 30] == t) f++;
			else { f = 0; j++; }
		}
		if (f == 5) return  t;
	}
	return 0;
}

void cursor()//��꺯��
{
	setcolor(RED);
	setfillcolor(WHITE);
	setwritemode(R2_XORPEN);//������ģʽ��ͼ�����ڹ������
	CHESS cur = bla;
	char c = ' ';
	fillcircle(cur.x, cur.y, 4);
	while (c != 'g')
	{
		c = _getch();
		switch (c)
		{
		case 'a':fillcircle(cur.x, cur.y, 4); cur.x -= 30; fillcircle(cur.x, cur.y, 4); break;
		case 'd':fillcircle(cur.x, cur.y, 4); cur.x += 30; fillcircle(cur.x, cur.y, 4); break;
		case 'w':fillcircle(cur.x, cur.y, 4); cur.y -= 30; fillcircle(cur.x, cur.y, 4); break;
		case 's':fillcircle(cur.x, cur.y, 4); cur.y += 30; fillcircle(cur.x, cur.y, 4); break;
		}
	}
	if (judge[cur.x][cur.y] != 0)
	{
		count--;
		fillcircle(cur.x, cur.y, 4);
	}
	else
	{
		int i, j, f;
		if (count % 2 == 0)
		{
			fillcircle(cur.x, cur.y, 4);
			flag = inputchess(cur, YELLOW, 2);
			if (flag == 2)
			{
				setcolor(BLACK);
				outtextxy(640, 300, _T("����Ӯ��"));
				printf("\n\n\n����Ӯ����\n\n\n\n\n\n");
			}
		}
		else
		{
			fillcircle(cur.x, cur.y, 4);
			flag = inputchess(cur, GREEN, 1);
			if (flag == 1)
			{
				outtextxy(640, 300, _T("����Ӯ��"));
				printf("\n\n\n����Ӯ����\n\n\n\n");

			}
		}
	}
	count++;
}

int main()
{
	chessboard();
	while (true)
	{
		cursor();
		if (flag == 1 || flag == 2)
			break;
	}
	_getch();
	closegraph();
	return 0;
}
