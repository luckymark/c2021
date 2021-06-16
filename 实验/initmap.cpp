#include "initmap.h"

/*************************************************
Function: initmap

Description: ����EasyXͼ�ο⣬���ڳ�ʼ���������̣��������̡������ᡢ��Ԫ��

Input: null

Return: null
********************************************/
void initmap() {
    char letter[] = { 'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O' };
    TCHAR s[5];//���ڴ�ӡ���̱��ص�����
    LOGFONT f;
    gettextstyle(&f);						// ��ȡ��ǰ��������
    f.lfHeight = 20;						// ��������߶�Ϊ20
    settextstyle(&f);						// ����������ʽ    
    cleardevice();                          // Ӧ�ñ���ɫ
    setlinestyle(PS_SOLID, 1); //��ʵ�� ���2
    for (int i = 0; i < 13; i++) {
        line(112, 137 + i * 25, 462, 137 + i * 25); //�������ϵĺ���
        line(137 + i * 25, 112, 137 + i * 25, 462); //�������ϵ�����
    }
    for (int i = 0; i < 15; i++) {
        RECT r = { 87,100 + i * 25,112,125 + 25 * i }; //��ӡ���ֵ�����
        RECT m = { 99.5 + i * 25,462,124 + i * 25,487 }; //��ӡ��ĸ������
        _stprintf(s, _T("%d"), i + 1); //������ת�����ַ���
        drawtext(s, &r, DT_CENTER); // ��Ӧ������д�ӡ����
        drawtext(letter[i], &m, DT_CENTER); //��Ӧ������д�ӡ��ĸ
    }
    setlinestyle(PS_SOLID, 2); //��ʵ�� ���2
    setfillcolor(RGB(0, 0, 0)); //���������ɫΪ��ɫ
    line(112, 112, 112, 462); //�������߽�
    line(462, 112, 462, 462); //�����Ҳ�߽�
    line(112, 112, 462, 112); //�����Ϸ��߽�
    line(112, 462, 462, 462); //�����·��߽�
    solidcircle(187, 187, 2); //������Ԫ��
    solidcircle(187, 387, 2);
    solidcircle(287, 287, 2);
    solidcircle(387, 187, 2);
    solidcircle(387, 387, 2);
}

/*************************************************
Function: drawButton

Description: ����EasyXͼ�ο⣬���ڻ�����Ϸ�����Լ�3����ť

Input: NULL

Return: NULL
********************************************/
void drawButton() {
    int nR1[] = { 225, 175, 375, 225 };
    int nR2[] = { 225, 300, 375, 350 };
    int nR3[] = { 225, 425, 375, 475 };
    RECT R1 = { nR1[0], nR1[1], nR1[2], nR1[3] }; //����ָ��R1
    RECT R2 = { nR2[0], nR2[1], nR2[2], nR2[3] }; //����ָ��R2
    RECT R3 = { nR3[0], nR3[1], nR3[2], nR3[3] }; //����ָ��R3
    setfillcolor(RGB(228, 121, 21));  //���ð�ť��ɫ
    setlinecolor(RGB(0, 0, 0)); //����������ɫ
    setlinestyle(PS_SOLID, 2); //������������Ϊʵ�� ���2
    fillrectangle(nR1[0], nR1[1], nR1[2], nR1[3]); //���ư�ť
    fillrectangle(nR2[0], nR2[1], nR2[2], nR2[3]);
    fillrectangle(nR3[0], nR3[1], nR3[2], nR3[3]);
    LOGFONT f;
    gettextstyle(&f);						// ��ȡ��ǰ��������
    f.lfHeight = 30;						// ��������߶�Ϊ 30
    _tcscpy_s(f.lfFaceName, _T("����"));		// ��������Ϊ�����塱
    f.lfQuality = ANTIALIASED_QUALITY;		// �������Ч��Ϊ�����  
    settextstyle(&f);						// ����������ʽ
    setbkmode(TRANSPARENT);                 // ȥ�����ֱ���
    settextcolor(BLACK);                    // ����������ɫΪ��ɫ
    drawtext(_T("�˻���ս"), &R1, DT_CENTER | DT_VCENTER | DT_SINGLELINE);//�ھ�������R1�ڴ�ӡ���֣�ˮƽ���У���ֱ���У�������ʾ
    drawtext(_T("���˶�ս"), &R2, DT_CENTER | DT_VCENTER | DT_SINGLELINE);//�ھ�������R2�ڴ�ӡ���֣�ˮƽ���У���ֱ���У�������ʾ
    drawtext(_T("�˳���Ϸ"), &R3, DT_CENTER | DT_VCENTER | DT_SINGLELINE);//�ھ�������R3�ڴ�ӡ���֣�ˮƽ���У���ֱ���У�������ʾ
    f.lfHeight = 45; //��������߶�Ϊ45
    settextstyle(&f); //����������ʽ
    outtextxy(150, 75, _T("����������V1.0")); //��ӡ����
}