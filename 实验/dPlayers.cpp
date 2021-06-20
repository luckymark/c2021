#include "dPlayers.h"

/*******************************************
Function: d_Players

Description: ���˶�ս�����������Ĺ��ܾ��ǶԵ�ǰ���ֵ�����¼�������Ӧ��ÿһ������󶼼���Ƿ��������顣
             Ps��������ʽ���������Ǻ������£���˳�ʼ������Ϊ�ڷ���֮������ת��

Input: NULL

Return: ʤ����������ɫ
********************************************/
int dPlayers() {
    int x, y, i, j, is_find = 0; //is_find���ڼ���Ƿ��ҵ��������ʱ��Ӧ�����ϵ�λ��
    int player = Black; //����������
    MOUSEMSG mouse;
    chess_t chess;
    RECT r = { 480,250,580,300 };
    LOGFONT f;
    gettextstyle(&f);						// ��ȡ��ǰ��������
    f.lfHeight = 20;						// ��������߶�Ϊ20 
    settextstyle(&f);						// ����������ʽ
    while (true) {
        if (player == Black) 
            drawtext(_T("�ڷ�����"), &r, DT_CENTER); //��ʾ��ǰ�غ��Ǻ�ɫ�������� 
        else
            drawtext(_T("�׷�����"), &r, DT_CENTER); //��ʾ��ǰ�غ��ǰ�ɫ�������� 
        mouse = GetMouseMsg(); //��ȡһ�������Ϣ
        if (mouse.uMsg == WM_LBUTTONDOWN) { //�ж��������Ƿ���
            for (i = 0; i < 15 && is_find != 1; i++) {
                for (j = 0; j < 15 && is_find != 1; j++) {
                    if (abs(mouse.x - (112 + i * 25)) < 12 && abs(mouse.y - (112 + j * 25)) < 12) {//Ѱ�Ҿ������������ĵ�
                        x = 112 + i * 25; //��Ӧ��ĺ�����
                        y = 112 + j * 25; //��Ӧ���������
                        is_find = 1;
                    }
                }
            }
            if (is_find == 1) {
                i--; //��������forѭ����ʱ��++�ˣ������Ҫ-1����������
                j--;
                if(gBoard[j][i]==SPACE) {
                    if (player == Black)
                        setfillcolor(RGB(0, 0, 0)); //���������ɫΪ��ɫ
                    else
                        setfillcolor(RGB(255, 255, 255)); //���������ɫΪ��ɫ
                    solidcircle(x, y, 10); //��������
                    gBoard[j][i] = player; //���̼�¼��ǰ������µ�����
                    clearrectangle(480, 250, 580, 300);
                    if (is_win(j, i, player)) //�ж�����Ƿ��Ѿ�ʤ��
                        return player;
                    player = player % 2 + 1; //����
                }
            }
            is_find = 0;
        }
    }
}