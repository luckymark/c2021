#include "menu.h"
/*************************************************
Function: Menu

Description: ���˵�������drawButton�������Ʋ˵������ڼ������¼���������Ӧ

Input: NULL

Return: NULL
********************************************/
void Menu() {
    setbkcolor(RGB(216, 150, 84)); //���ñ���ɫ
    cleardevice(); //Ӧ�ñ���ɫ
    drawButton(); //���ư�ť����Լ������
    MOUSEMSG mouse; //���ָ�룬���ڼ����궯������ť��Ӧ
    int button = 0, winner; 
    while (true) { 
        mouse = GetMouseMsg(); //��ȡһ�������Ϣ
        if (mouse.uMsg == WM_LBUTTONDOWN) { //���������
            for (int i = 0; i < 3; i++) { //�жϰ�������һ����ť
                if (abs(mouse.x - 300) < 50 && abs(mouse.y - (200 + 125 * i) < 25)) {
                    button = i + 1;
                    break;
                }
            }
            switch (button) {
            case 1: //�˻���ս
                initmap(); //��ʼ����ͼ
                winner = hum_VS_AI();  //hum_VS_AI ������Ϸʤ����
                if (winner == AIChessColor) { //AI���ʤ��
                    RECT r = { 480,300,580,350 };  
                    drawtext(_T("�ܱ�!"), &r, DT_CENTER); 
                }
                else if (winner == humChessColor) { //��һ��ʤ��
                    RECT r = { 480,300,580,350 }; 
                    drawtext(_T("��Ӯ��!"), &r, DT_CENTER); 
                }
                for (int i = 0; i < M_SIZE; i++) {
                    for (int j = 0; j < M_SIZE; j++)
                        gBoard[i][j] = SPACE; //��Ϸ��������������
                }
                _getch();
                return;
                break;
            case 2: //���˶�ս
                initmap();//��ʼ����ͼ
                winner = dPlayers(); //dPlayers������Ϸʤ����
                if (winner == Black) { //�ڷ���ʤ
                    RECT r = { 480,300,580,350 };
                    drawtext(_T("�ڷ�ʤ��!"), &r, DT_CENTER); 
                }
                else if (winner == White) {
                    RECT r = { 480,300,580,350 }; //�׷���ʤ
                    drawtext(_T("�׷�ʤ��!"), &r, DT_CENTER); 
                }
                for (int i = 0; i < M_SIZE; i++) {
                    for (int j = 0; j < M_SIZE; j++)
                        gBoard[i][j] = SPACE; //��Ϸ��������������
                }
                _getch();
                return;
                break;
            case 3: //��Ϸ����
                closegraph();
                exit(0); 
            }
        }
    }
}