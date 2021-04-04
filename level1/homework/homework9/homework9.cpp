#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<Windows.h>
#include<conio.h>
#include<time.h>
#define random(x) (rand()%(x))
#define Y 28 //设置地图行数
#define X 45 //设置地图列数

int main()
{
	srand((int)time(0));
	int readKey,currentX,currentY=1,map,startX,endX;
	char x[Y+1][X+2];
	printf("Londing map");
	memset(x, 'x', sizeof(x));	
	for (int i = 0;i < Y+1;i++)
		x[i][X+1] = 0;
	map = random(X-1);
	x[0][map + 1] = ' ';
	x[1][map + 1] = ' ';
	currentX = map+1;
	startX = currentX;//记录开始坐标
	while (1) {//随机生成地图
		map = random(4);
		switch (map) {
		case 0://上
			if (currentX > 0 && currentX < X) {
				if (currentY > 2) {
					if ((x[currentY - 2][currentX] != ' '
						&& x[currentY - 1][currentX - 1] != ' '
						&& x[currentY - 1][currentX + 1] != ' ')
						|| x[currentY - 1][currentX] == ' ')
						currentY--;
				}
				else if (currentY > 1) {
					if ((x[currentY - 1][currentX - 1] != ' '
						&& x[currentY - 1][currentX + 1] != ' ')
						|| x[currentY - 1][currentX] == ' ')
						currentY--;
				}
			}
			break;
		case 1://下
			if (currentX > 0 && currentX < X) {
				if (currentY < Y - 2) {
					if ((x[currentY + 2][currentX] != ' '
						&& x[currentY + 1][currentX - 1] != ' '
						&& x[currentY + 1][currentX + 1] != ' ')
						|| x[currentY + 1][currentX] == ' ')
						currentY++;
				}
				else if (currentY < Y - 1) {
					if ((x[currentY + 1][currentX - 1] != ' '
						&& x[currentY + 1][currentX + 1] != ' ')
						|| x[currentY + 1][currentX] == ' ')
						currentY++;
				}
				else if (currentY == Y - 1)//终点设置
					currentY++;
			}
			break;
		case 2://左
			if (currentY > 0 && currentY < Y) {
				if (currentX > 2) {
					if ((x[currentY][currentX - 2] != ' '
						&& x[currentY - 1][currentX - 1] != ' '
						&& x[currentY + 1][currentX - 1] != ' ')
						|| x[currentY][currentX - 1] == ' ')
						currentX--;
				}
				else if (currentX > 1) {
					if ((x[currentY - 1][currentX - 1] != ' '
						&& x[currentY + 1][currentX - 1] != ' ')
						|| x[currentY][currentX - 1] == ' ')
						currentX--;
				}
			}
			break;
		case 3://右
			if (currentY > 0 && currentY < Y) {
				if (currentX < X - 2) {
					if (
						(x[currentY][currentX + 2] != ' '
							&& x[currentY - 1][currentX + 1] != ' '
							&& x[currentY + 1][currentX + 1] != ' ')
						|| x[currentY][currentX + 1] == ' ')
						currentX++;
				}
				else if (currentX < X - 1) {
					if ((x[currentY - 1][currentX + 1] != ' '
						&& x[currentY + 1][currentX + 1] != ' ')
						|| x[currentY][currentX + 1] == ' ')
						currentX++;
				}
			}
			break;
		}
		x[currentY][currentX] = ' ';
		if (currentY == Y) {
			x[currentY][currentX] = 'P';
			break;
		}
	}
	currentY = 0;
	endX = currentX;//记录终点坐标
	currentX = startX;
	while (1) {
		system("cls");
		x[currentY][currentX] = 'l';
		for (int i = 0;i < Y+1;)
			printf("%s\n", x[i++]);
		if (currentX == endX && currentY == Y) {
			printf("You win!");
			return 0;
		}
		getch();//忽略换行符
		do {//控制玩家移动
			readKey = getch();
			switch (readKey) {
			case 72:
				if (currentY > 0 && x[currentY - 1][currentX] != 'x') {
					x[currentY][currentX] = ' ';
					currentY--;
				}
				else readKey = 0;
				break;
			case 80:
				if (currentY < Y && x[currentY + 1][currentX] != 'x') {
					x[currentY][currentX] = ' ';
					currentY++;
				}
				else readKey = 0;
				break;
			case 75:
				if (currentX > 0 && x[currentY][currentX - 1] != 'x') {
					x[currentY][currentX] = ' ';
					currentX--;
				}
				else readKey = 0;
				break;
			case 77:
				if (currentX < X + 1 && x[currentY][currentX + 1] != 'x') {
					x[currentY][currentX] = ' ';
					currentX++;
				}
				else readKey = 0;
				break;
			}
		} while (readKey != 72&&readKey!=80&&readKey!=75&&readKey!=77);
	}
}
