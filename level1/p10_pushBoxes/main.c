/*������С��Ϸ�������Կ����������У�
1. ��p09�Թ���Ϸ����Ϊ�������ӡ���Ϸ��
1. �ڵ�ͼ���������ӡ�����Ŀ��λ�õ�ͼ�Σ�
1. ����ҽ��������ӹ�λ������ʾ���Ӯ������Ϸ��
1. ������߶������Ƿ֣�
1. ��ƶ���ؿ���ÿһ�صĵ�ͼ���ļ��ж�ȡ�����ÿ�صķ�����¼���ļ��У�
ע�⣺����ǰ�뽫�����ļ��ŵ�ͬһ����Ŀ¼�£�
�������������У��뽫��д�ļ���·����Ϊ����·��*/ 

#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include "function.h" 

int main() {
    int(*map)[L];
    char c;
    while (1) {
        system("cls");
        printf("---------------------\n");
        printf("---��ӭ����������С��Ϸ---\n");
        printf("----1. �ؿ�1 -----\n");
        printf("----2. �ؿ�2 -----\n");
        printf("----3. �ؿ�3 -----\n");
        printf("----4. ��Ϸ˵��---\n");
        printf("----0. �˳���Ϸ -----\n");
        printf("--------------------\n");
        c = _getch();
        switch (c) {
            case '1':
                map= fileReader(1);
                start(map,1);
                break;
            case '2':
                map = fileReader(2);
                start(map,2);
                break;
            case '3':
                map = fileReader(3);
                start(map,3);
                break;
            case '4':
                explain();
                break;
            case '0':
                printf("��ӭ�´μ�������........\n");
                Sleep(1500);
                exit(0);
        }
    }
}

