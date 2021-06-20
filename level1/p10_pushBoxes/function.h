#ifndef __FUNCTION_H__
#define __FUNCTION_H__

#define ROUTE 0 //路径
#define WALL 1 //墙
#define PLAYER 2 //玩家
#define BOX 3 //箱子
#define DESTINATION 4 //终点
#define FINSHED 7// 表示已完成的箱子
#define PFINSHED 6 // 人加终点
#define L 8 //规定的地图大小（文件中的地图也将按这个尺寸编写）

void start(int map[][L],int nmap);
void print(int map[][L],int score,int bestscore);
int (*tuidong(int map[][L]))[L];
int (*fileReader(int num))[L];
int check(int map[][L]);
void explain();
void write(int bestscore,int num);

#endif

