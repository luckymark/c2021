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
	int readKey,currentX,currentY=1,map,startX,endX,findX,findY;
	unsigned char x[Y+1][X+2];
	printf("Londing map");
	memset(x, 'X', sizeof(x));	
	for (int i = 0;i < Y+1;i++)
		x[i][X+1] = 0;
	map = random(X-1);
	x[0][map + 1] = ' ';
	x[1][map + 1] = ' ';
	currentX = map+1;
	startX = currentX;//记录开始坐标
	while (1) {//随机生成地图
		map = random(7);
		switch (map) {
		case 4:
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
		case 5:
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
		case 6:
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
				if (currentY > 0 && x[currentY - 1][currentX] != 'X') {
					x[currentY][currentX] = ' ';
					currentY--;
				}
				else readKey = 0;
				break;
			case 80:
				if (currentY < Y && x[currentY + 1][currentX] != 'X') {
					x[currentY][currentX] = ' ';
					currentY++;
				}
				else readKey = 0;
				break;
			case 75:
				if (currentX > 0 && x[currentY][currentX - 1] != 'X') {
					x[currentY][currentX] = ' ';
					currentX--;
				}
				else readKey = 0;
				break;
			case 77:
				if (currentX < X + 1 && x[currentY][currentX + 1] != 'X') {
					x[currentY][currentX] = ' ';
					currentX++;
				}
				else readKey = 0;
				break;
			//case 102://寻路，没有实现
			//	int t , re = 1, crossRoadDirection[200], num = 0;
			//	bool isOK = true;
			//	int crossRoadX[200] = { 0 }, crossRoadY[200], recross[200];
			//	crossRoadX[0] = currentX;
			//	crossRoadY[0] = currentY;
			//	crossRoadDirection[0] = re;
			//	recross[0] = re;
			//	findX = currentX;
			//	findY = currentY;
			//	while (findX != endX && findY != Y) {
			//		if (findX != crossRoadX[num] || findY != crossRoadY[num]) {
			//			t = 0;
			//			if (x[findY + 1][findX] == ' ')t++;
			//			if (x[findY - 1][findX] == ' ')t++;
			//			if (x[findY][findX + 1] == ' ')t++;
			//			if (x[findY][findX - 1] == ' ')t++;
			//			if (t >= 3) {
			//				num++;
			//				crossRoadX[num] = findX;
			//				crossRoadY[num] = findY;
			//				recross[num] = re;
			//				crossRoadDirection[num] = recross[num];
			//			}
			//		}
			//		if (!isOK) {
			//			crossRoadDirection[num]++;
			//			re = crossRoadDirection[num] % 4;
			//			if (re == recross[num]) {
			//				num--;
			//				re = recross[num];
			//			}
			//			isOK = true;
			//		}
			//		switch (re) {
			//		case 0:
			//			if (findY > 0 && x[findY - 1][findX] == ' ') {
			//				findY--;
			//				isOK = true;
			//				re = 0;
			//			}
			//			else if (findX > 0 && x[findY][findX - 1] == ' ') {
			//				findX--;
			//				isOK = true;
			//				re = 2;
			//			}
			//			else if (findX < X && x[findY][findX + 1] == ' ') {
			//				findX++;
			//				isOK = true;
			//				re = 3;
			//			}
			//			else {
			//				isOK = false;
			//				findY = crossRoadY[num];
			//				findX = crossRoadX[num];
			//			}
			//			break;
			//		case 1:
			//			if (findY < Y && x[findY + 1][findX] == ' ') {
			//				findY++;
			//				isOK = true;
			//				re = 1;
			//			}
			//			else if (findX > 0 && x[findY][findX - 1] == ' ') {
			//				findX--;
			//				isOK = true;
			//				re = 2;
			//			}
			//			else if (findX < X && x[findY][findX + 1] == ' ') {
			//				findX++;
			//				isOK = true;
			//				re = 3;
			//			}
			//			else {
			//				isOK = false;
			//				findY = crossRoadY[num];
			//				findX = crossRoadX[num];
			//			}
			//			break;
			//		case 2:
			//			if (findY < Y && x[findY + 1][findX] == ' ') {
			//				findY++;
			//				isOK = true;
			//				re = 1;
			//			}
			//			else if (findX > 0 && x[findY][findX - 1] == ' ') {
			//				findX--;
			//				isOK = true;
			//				re = 2;
			//			}
			//			else if (findY > 0 && x[findY - 1][findX] == ' ') {
			//				findY--;
			//				isOK = true;
			//				re = 0;
			//			}
			//			else {
			//				isOK = false;
			//				findY = crossRoadY[num];
			//				findX = crossRoadX[num];
			//			}
			//			break;
			//		case 3:
			//			if (findY < Y && x[findY + 1][findX] == ' ') {
			//				findY++;
			//				isOK = true;
			//				re = 1;
			//			}
			//			else if (findX < X && x[findY][findX + 1] == ' ') {
			//				findX++;
			//				isOK = true;
			//				re = 3;
			//			}
			//			else if (findY > 0 && x[findY - 1][findX] == ' ') {
			//				findY--;
			//				isOK = true;
			//				re = 0;
			//			}
			//			else {
			//				isOK = false;
			//				findY = crossRoadY[num];
			//				findX = crossRoadX[num];
			//			}
			//			break;
			//		}
			//	}
			//	int printY, printX, i = 0;
			//	printY = currentY;
			//	printX = currentX;
			//	re = 1;
			//	while (crossRoadX[i] != 0) {
			//		if (printY == crossRoadY[i]) {
			//			switch (crossRoadDirection[i]) {
			//			case 0:printY--;break;
			//			case 1:printY++;break;
			//			case 2:printX--;break;
			//			case 3:printX++;break;
			//			}
			//			i++;
			//			x[printY][printX] = '.';
			//			switch (re) {
			//			case 0:
			//				if (printY > 0 && x[printY - 1][printX] == ' ') {
			//					printY--;
			//					x[printY][printX] = '.';
			//					re = 0;
			//				}
			//				else if (printX > 0 && x[printY][printX - 1] == ' ') {
			//					printX--;
			//					x[printY][printX] = '.';
			//					re = 2;
			//				}
			//				else if (printX < X && x[printY][printX + 1] == ' ') {
			//					printX++;
			//					x[printY][printX] = '.';
			//					re = 3;
			//				}
			//				break;
			//			case 1:
			//				if (printY < Y && x[printY + 1][printX] == ' ') {
			//					printY++;
			//					x[printY][printX] = '.';
			//					re = 1;
			//				}
			//				else if (printX > 0 && x[printY][printX - 1] == ' ') {
			//					printX--;
			//					x[printY][printX] = '.';
			//					re = 2;
			//				}
			//				else if (printX < X && x[printY][printX + 1] == ' ') {
			//					printX++;
			//					x[printY][printX] = '.';
			//					re = 3;
			//				}
			//				break;
			//			case 2:
			//				if (printY < Y && x[printY + 1][printX] == ' ') {
			//					printY++;
			//					x[printY][printX] = '.';
			//					re = 1;
			//				}
			//				else if (printX > 0 && x[printY][printX - 1] == ' ') {
			//					printX--;
			//					x[printY][printX] = '.';
			//					re = 2;
			//				}
			//				else if (printY > 0 && x[printY - 1][printX] == ' ') {
			//					printY--;
			//					x[printY][printX] = '.';
			//					re = 0;
			//				}
			//				break;
			//			case 3:
			//				if (printY < Y && x[printY + 1][printX] == ' ') {
			//					printY++;
			//					x[printY][printX] = '.';
			//					re = 1;
			//				}
			//				else if (printX < X && x[printY][printX + 1] == ' ') {
			//					printX++;
			//					x[printY][printX] = '.';
			//					re = 3;
			//				}
			//				else if (printY > 0 && x[printY - 1][printX] == ' ') {
			//					printY--;
			//					x[printY][printX] = '.';
			//					re = 0;
			//				}
			//				break;
			//			}
			//		}
			//	}
			}
		} while (readKey != 72&&readKey!=80&&readKey!=75&&readKey!=77);
	}
}
