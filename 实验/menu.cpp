#include "menu.h"
/*************************************************
Function: Menu

Description: 主菜单，调用drawButton函数绘制菜单后用于检测鼠标事件并给予响应

Input: NULL

Return: NULL
********************************************/
void Menu() {
    setbkcolor(RGB(216, 150, 84)); //设置背景色
    cleardevice(); //应用背景色
    drawButton(); //绘制按钮组件以及标题等
    MOUSEMSG mouse; //鼠标指针，用于检测鼠标动作，按钮响应
    int button = 0, winner; 
    while (true) { 
        mouse = GetMouseMsg(); //获取一条鼠标消息
        if (mouse.uMsg == WM_LBUTTONDOWN) { //鼠标左键点击
            for (int i = 0; i < 3; i++) { //判断按的是哪一个按钮
                if (abs(mouse.x - 300) < 50 && abs(mouse.y - (200 + 125 * i) < 25)) {
                    button = i + 1;
                    break;
                }
            }
            switch (button) {
            case 1: //人机对战
                initmap(); //初始化地图
                winner = hum_VS_AI();  //hum_VS_AI 返回游戏胜利方
                if (winner == AIChessColor) { //AI获得胜利
                    RECT r = { 480,300,580,350 };  
                    drawtext(_T("败北!"), &r, DT_CENTER); 
                }
                else if (winner == humChessColor) { //玩家获得胜利
                    RECT r = { 480,300,580,350 }; 
                    drawtext(_T("你赢了!"), &r, DT_CENTER); 
                }
                for (int i = 0; i < M_SIZE; i++) {
                    for (int j = 0; j < M_SIZE; j++)
                        gBoard[i][j] = SPACE; //游戏结束，重置棋盘
                }
                _getch();
                return;
                break;
            case 2: //人人对战
                initmap();//初始化地图
                winner = dPlayers(); //dPlayers返回游戏胜利方
                if (winner == Black) { //黑方获胜
                    RECT r = { 480,300,580,350 };
                    drawtext(_T("黑方胜利!"), &r, DT_CENTER); 
                }
                else if (winner == White) {
                    RECT r = { 480,300,580,350 }; //白方获胜
                    drawtext(_T("白方胜利!"), &r, DT_CENTER); 
                }
                for (int i = 0; i < M_SIZE; i++) {
                    for (int j = 0; j < M_SIZE; j++)
                        gBoard[i][j] = SPACE; //游戏结束，重置棋盘
                }
                _getch();
                return;
                break;
            case 3: //游戏结束
                closegraph();
                exit(0); 
            }
        }
    }
}