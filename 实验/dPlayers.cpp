#include "dPlayers.h"

/*******************************************
Function: d_Players

Description: 人人对战主函数，核心功能就是对当前棋手的鼠标事件做出响应，每一次下棋后都检测是否五子连珠。
             Ps：由于正式比赛中总是黑棋先下，因此初始化棋手为黑方，之后依次转换

Input: NULL

Return: 胜利方棋子颜色
********************************************/
int dPlayers() {
    int x, y, i, j, is_find = 0; //is_find用于检测是否找到了鼠标点击时对应棋盘上的位置
    int player = Black; //黑子先下棋
    MOUSEMSG mouse;
    chess_t chess;
    RECT r = { 480,250,580,300 };
    LOGFONT f;
    gettextstyle(&f);						// 获取当前字体设置
    f.lfHeight = 20;						// 设置字体高度为20 
    settextstyle(&f);						// 设置字体样式
    while (true) {
        if (player == Black) 
            drawtext(_T("黑方下棋"), &r, DT_CENTER); //提示当前回合是黑色棋子下棋 
        else
            drawtext(_T("白方下棋"), &r, DT_CENTER); //提示当前回合是白色棋子下棋 
        mouse = GetMouseMsg(); //获取一个鼠标消息
        if (mouse.uMsg == WM_LBUTTONDOWN) { //判断鼠标左键是否按下
            for (i = 0; i < 15 && is_find != 1; i++) {
                for (j = 0; j < 15 && is_find != 1; j++) {
                    if (abs(mouse.x - (112 + i * 25)) < 12 && abs(mouse.y - (112 + j * 25)) < 12) {//寻找距离鼠标点击最近的点
                        x = 112 + i * 25; //对应点的横坐标
                        y = 112 + j * 25; //对应点的纵坐标
                        is_find = 1;
                    }
                }
            }
            if (is_find == 1) {
                i--; //由于跳出for循换的时候++了，因此需要-1抵消这个误差
                j--;
                if(gBoard[j][i]==SPACE) {
                    if (player == Black)
                        setfillcolor(RGB(0, 0, 0)); //设置填充颜色为黑色
                    else
                        setfillcolor(RGB(255, 255, 255)); //设置填充颜色为白色
                    solidcircle(x, y, 10); //绘制棋子
                    gBoard[j][i] = player; //棋盘记录当前玩家所下的棋子
                    clearrectangle(480, 250, 580, 300);
                    if (is_win(j, i, player)) //判断玩家是否已经胜利
                        return player;
                    player = player % 2 + 1; //换手
                }
            }
            is_find = 0;
        }
    }
}