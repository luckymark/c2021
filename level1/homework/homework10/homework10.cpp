#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<Windows.h>
#include<conio.h>

int main()
{
	FILE* fp = NULL;
	short readKey, currentX = 0, currentY = 0, endX[10], endY[10], t, rept, score;
	char x[29][100] = { 0 }, buff[100], scoreString[4] = { 0 };
	unsigned char numberOfLevel;
	short Y, X;
	fp = fopen("pushBoxes.txt", "r+");
	numberOfLevel = fgetc(fp);//读取关卡数
	fgets(buff, 255, (FILE*)fp);//忽略回车
	while (1) {
		fscanf(fp, "%s", buff);//读取行数
		if (strlen(buff) == 1) {
			Y = buff[0] - 48;
		}
		else if (strlen(buff) == 2) {
			Y = (buff[0] - 48) * 10 + buff[1] - 48;
		}
		else {
			fclose(fp);
			return 0;
		}
		fscanf(fp, "%s", buff);//读取列数
		if (strlen(buff) == 1) {
			X = buff[0] - 48;
		}
		else if (strlen(buff) == 2) {
			X = (buff[0] - 48) * 10 + buff[1] - 48;
		}
		else {
			fclose(fp);
			return 0;
		}
		fgets(buff, 255, (FILE*)fp);//忽略回车
		t = -1;
		for (int i = 0;i < Y;i++) {
			fgets(buff, 255, (FILE*)fp);
			for (int j = 0;j < strlen(buff);j++) {
				x[i][j] = buff[j];//读取关卡地图
				if (x[i][j] == 'l') {//记录玩家初始位置
					currentY = i;
					currentX = j;
				}
				if (x[i][j] == 'P') {//记录箱子终点
					t++;//记录箱子终点数目
					endY[t] = i;
					endX[t] = j;
				}
			}
		}
		rept = t;
		score = t * 30 + 30;
		while (1) {
			system("cls");
			t = rept;
			while (t >= 0) {//如果终点显示为空格，则使其显示P
				if (x[endY[t]][endX[t]] == ' ')
					x[endY[t]][endX[t]] = 'P';
				t--;
			}
			x[currentY][currentX] = 'l';
			for (int i = 0;i < Y + 1;)
				printf("%s", x[i++]);
			t = rept;
			while (t >= 0) {
				if (x[endY[t]][endX[t]] == 'o') {
					t--;
				}
				else break;
			}
			score--;
			if (t == -1) {
				if (score < 0)score = 0;
				itoa(score, scoreString, 10);//将分数转为字符串的形式
				fseek(fp, -(Y * (X + 2) + 5), SEEK_CUR);
				fputs(scoreString,fp);//写入分数
				if (score >= 10 && score < 99)
					fseek(fp, (Y * (X + 2) + 3), SEEK_CUR);
				else if (score >= 0 && score < 10)
					fseek(fp, (Y * (X + 2) + 4), SEEK_CUR);
				else if (score >= 100)
					fseek(fp, (Y * (X + 2) + 2), SEEK_CUR);
				numberOfLevel--;
				if (numberOfLevel > 48) {
					printf("You are win,and then you will enter next level.\n");
					printf("And you can put down any key to enter next level.\n");
					system("pause");
					break;
				}
				else {
					printf("You cross all levels!");
					fclose(fp);
					return 0;
				}
			}
			do {//控制玩家移动
				readKey = getch();
				switch (readKey) {
				case 72:
					if (currentY > 0) {
						if (x[currentY - 1][currentX] == ' ' || x[currentY - 1][currentX] == 'P') {
							x[currentY][currentX] = ' ';
							currentY--;
						}
						else if (x[currentY - 1][currentX] == 'o' && x[currentY - 2][currentX] != 'X') {
							x[currentY - 2][currentX] = 'o';
							x[currentY][currentX] = ' ';
							currentY--;
						}
						else readKey = 0;
					}
					break;
				case 80:
					if (currentY < Y) {
						if (x[currentY + 1][currentX] == ' ' || x[currentY + 1][currentX] == 'P') {
							x[currentY][currentX] = ' ';
							currentY++;
						}
						else if (x[currentY + 1][currentX] == 'o' && currentY < Y - 1 && x[currentY + 2][currentX] != 'X') {
							x[currentY + 2][currentX] = 'o';
							x[currentY][currentX] = ' ';
							currentY++;
						}
						else readKey = 0;
					}
					break;
				case 75:
					if (currentX > 0) {
						if (x[currentY][currentX - 1] == ' ' || x[currentY][currentX - 1] == 'P') {
							x[currentY][currentX] = ' ';
							currentX--;
						}
						else if (x[currentY][currentX - 1] == 'o' && currentX > 1 && x[currentY][currentX - 2] != 'X') {
							x[currentY][currentX - 2] = 'o';
							x[currentY][currentX] = ' ';
							currentX--;
						}
						else readKey = 0;
					}
					break;
				case 77:
					if (currentX < X + 1) {
						if (x[currentY][currentX + 1] == ' ' || x[currentY][currentX + 1] == 'P') {
							x[currentY][currentX] = ' ';
							currentX++;
						}
						else if (x[currentY][currentX + 1] == 'o' && currentX < X && x[currentY][currentX + 2] != 'X') {
							x[currentY][currentX + 2] = 'o';
							x[currentY][currentX] = ' ';
							currentX++;
						}
						else readKey = 0;
					}
					break;
				}
			} while (readKey != 72 && readKey != 80 && readKey != 75 && readKey != 77);
		}
	}
}
