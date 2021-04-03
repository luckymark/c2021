#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<Windows.h>
#include<conio.h>
#include<time.h>
#define random(x) (rand()%(x))
#define Y 9
#define X 13

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
	startX = currentX;
	while (1) {//随机生成地图
		map = random(4);
		switch (map) {
		case 0:
			if ((currentY > 1 && currentX > 0 && currentX < X
				&& x[currentY - 1][currentX - 1] != ' '
				&& x[currentY - 1][currentX + 1] != ' ')
				|| x[currentY - 1][currentX] == ' ')
				currentY--;
			break;
		case 1:
			if ((currentY < Y-1 && currentX > 0 && currentX < X
				&& x[currentY + 1][currentX - 1] != ' '
				&& x[currentY + 1][currentX + 1] != ' ')
				|| x[currentY + 1][currentX] == ' '
				|| currentY == 8)
				currentY++;
			break;
		case 2:
			if ((currentX > 1 && currentY > 0 && currentY < Y 
				&& x[currentY - 1][currentX - 1] != ' '
				&& x[currentY + 1][currentX - 1] != ' ')
				|| x[currentY][currentX - 1] == ' ')
				currentX--;
			break;
		case 3:
			if ((currentX < X-1 && currentY > 0 && currentY < Y
				&& x[currentY - 1][currentX + 1] != ' '
				&& x[currentY + 1][currentX + 1] != ' ')
				|| x[currentY][currentX + 1] == ' ')
				currentX++;
			break;
		}
		x[currentY][currentX] = ' ';
		if (currentY == Y) {
			x[currentY][currentX] = 'P';
			break;
		}
	}
	currentY = 0;
	endX = currentX;
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
