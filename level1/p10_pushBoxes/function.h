#ifndef __FUNCTION_H__
#define __FUNCTION_H__

#define ROUTE 0 //·��
#define WALL 1 //ǽ
#define PLAYER 2 //���
#define BOX 3 //����
#define DESTINATION 4 //�յ�
#define FINSHED 7// ��ʾ����ɵ�����
#define PFINSHED 6 // �˼��յ�
#define L 8 //�涨�ĵ�ͼ��С���ļ��еĵ�ͼҲ��������ߴ��д��

void start(int map[][L],int nmap);
void print(int map[][L],int score,int bestscore);
int (*tuidong(int map[][L]))[L];
int (*fileReader(int num))[L];
int check(int map[][L]);
void explain();
void write(int bestscore,int num);

#endif

