#include<stdio.h>
#include<stdlib.h>
#include"warehouse.h"

int main() {
	int control = -1;
	char buff[256];
	FILE* fp = NULL, * temp = NULL;
	printf("Menu\n\n");
	printf("1:显示存货列表\n\n");
	printf("2:入库\n\n");
	printf("3:出库\n\n");
	printf("4:退出程序\n\n");
	while (1) {
		printf("\n按数字键继续\n");
		scanf("%d", &control);
		printf("\n");
		switch (control) {
		case 1:
			PrintWareHouse(fp, "warehouse.txt", buff, 256);
			break;
		case 2:
			printf("再次按“0”以结束入库\n");
			RepeatEnterHouse(fp, "warehouse.txt", '0', buff, 256);
			break;
		case 3:
			printf("再次按“0”以结束出库\n");
			RepeatExitHouse(fp, "warehouse.txt", '0', buff, 256);
			break;
		case 4:return 0;
		default:printf("请输入1~4的数字\n");
		}
	}

}
