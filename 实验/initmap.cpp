#include "initmap.h"

/*************************************************
Function: initmap

Description: 基于EasyX图形库，用于初始化绘制棋盘，包括棋盘、坐标轴、天元点

Input: null

Return: null
********************************************/
void initmap() {
    char letter[] = { 'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O' };
    TCHAR s[5];//用于打印棋盘边沿的数字
    LOGFONT f;
    gettextstyle(&f);						// 获取当前字体设置
    f.lfHeight = 20;						// 设置字体高度为20
    settextstyle(&f);						// 设置字体样式    
    cleardevice();                          // 应用背景色
    setlinestyle(PS_SOLID, 1); //画实线 宽度2
    for (int i = 0; i < 13; i++) {
        line(112, 137 + i * 25, 462, 137 + i * 25); //画棋盘上的横线
        line(137 + i * 25, 112, 137 + i * 25, 462); //画棋盘上的竖线
    }
    for (int i = 0; i < 15; i++) {
        RECT r = { 87,100 + i * 25,112,125 + 25 * i }; //打印数字的区域
        RECT m = { 99.5 + i * 25,462,124 + i * 25,487 }; //打印字母的区域
        _stprintf(s, _T("%d"), i + 1); //将数字转换成字符串
        drawtext(s, &r, DT_CENTER); // 对应区域居中打印数字
        drawtext(letter[i], &m, DT_CENTER); //对应区域居中打印字母
    }
    setlinestyle(PS_SOLID, 2); //画实线 宽度2
    setfillcolor(RGB(0, 0, 0)); //设置填充颜色为黑色
    line(112, 112, 112, 462); //棋盘左侧边界
    line(462, 112, 462, 462); //棋盘右侧边界
    line(112, 112, 462, 112); //棋盘上方边界
    line(112, 462, 462, 462); //棋盘下方边界
    solidcircle(187, 187, 2); //绘制天元点
    solidcircle(187, 387, 2);
    solidcircle(287, 287, 2);
    solidcircle(387, 187, 2);
    solidcircle(387, 387, 2);
}

/*************************************************
Function: drawButton

Description: 基于EasyX图形库，用于绘制游戏标题以及3个按钮

Input: NULL

Return: NULL
********************************************/
void drawButton() {
    int nR1[] = { 225, 175, 375, 225 };
    int nR2[] = { 225, 300, 375, 350 };
    int nR3[] = { 225, 425, 375, 475 };
    RECT R1 = { nR1[0], nR1[1], nR1[2], nR1[3] }; //矩形指针R1
    RECT R2 = { nR2[0], nR2[1], nR2[2], nR2[3] }; //矩形指针R2
    RECT R3 = { nR3[0], nR3[1], nR3[2], nR3[3] }; //矩形指针R3
    setfillcolor(RGB(228, 121, 21));  //设置按钮颜色
    setlinecolor(RGB(0, 0, 0)); //设置线条颜色
    setlinestyle(PS_SOLID, 2); //设置线条属性为实线 宽度2
    fillrectangle(nR1[0], nR1[1], nR1[2], nR1[3]); //绘制按钮
    fillrectangle(nR2[0], nR2[1], nR2[2], nR2[3]);
    fillrectangle(nR3[0], nR3[1], nR3[2], nR3[3]);
    LOGFONT f;
    gettextstyle(&f);						// 获取当前字体设置
    f.lfHeight = 30;						// 设置字体高度为 30
    _tcscpy_s(f.lfFaceName, _T("楷体"));		// 设置字体为“楷体”
    f.lfQuality = ANTIALIASED_QUALITY;		// 设置输出效果为抗锯齿  
    settextstyle(&f);						// 设置字体样式
    setbkmode(TRANSPARENT);                 // 去掉文字背景
    settextcolor(BLACK);                    // 设置文字颜色为黑色
    drawtext(_T("人机对战"), &R1, DT_CENTER | DT_VCENTER | DT_SINGLELINE);//在矩形区域R1内打印文字，水平居中，垂直居中，单行显示
    drawtext(_T("人人对战"), &R2, DT_CENTER | DT_VCENTER | DT_SINGLELINE);//在矩形区域R2内打印文字，水平居中，垂直居中，单行显示
    drawtext(_T("退出游戏"), &R3, DT_CENTER | DT_VCENTER | DT_SINGLELINE);//在矩形区域R3内打印文字，水平居中，垂直居中，单行显示
    f.lfHeight = 45; //设置字体高度为45
    settextstyle(&f); //设置字体样式
    outtextxy(150, 75, _T("天天五子棋V1.0")); //打印标题
}