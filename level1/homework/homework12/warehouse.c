#include <stdio.h>
#include<stdlib.h>
#include<string.h>

void PrintWareHouse(FILE* fp, const char fileName[], char buff[], int sizeOfBuff) {
	fp = fopen(fileName, "r");
	while (fgets(buff, sizeOfBuff, fp)) {
		printf("%s", buff);
	}
	fclose(fp);
}
void RepeatEnterHouse(FILE* fp, const char fileName[], const char numberForStop, char buff[], int sizeOfBuff) {
	FILE* temp = NULL;
	char type[50];
	int num, length, i, j;
	char hadHave;
	while (1) {
		printf("\n����������ͺ�\n");
		scanf("%s", &type);
		if (type[0] == numberForStop)
			return;
		printf("��⼸��\n");
		scanf("%d", &num);
		fp = fopen(fileName, "r");
		temp = fopen("temp.txt", "w");
		hadHave = 0;
		length = strlen(type);
		type[length] = ' ';
		type[length + 1] = '\0';
		while (fgets(buff, sizeOfBuff, fp)) {
			if (strncmp(buff, type, length + 1) == 0) {
				hadHave = 1;
				for (i = 0;buff[length + i] != 0;i++) {
					type[i] = buff[length + i + 1];
				}
				num += atoi(type);
				itoa(num, type, 10);
				for (j = 0;type[j] != 0;j++)
					buff[length + j + 1] = type[j];
				buff[length + j + 1] = '\n';
				buff[length + j + 2] = '\0';
				printf("���ɹ�\n");
			}
			fputs(buff, temp);
		}
		if (!hadHave)
			fprintf(temp, "%s %d\n", type, num);
		fclose(fp);
		fclose(temp);
		remove(fileName);
		rename("temp.txt", fileName);
	}
}
void RepeatExitHouse(FILE* fp, const char fileName[], const char numberForStop, char buff[], int sizeOfBuff) {
	FILE* temp = NULL;
	char type[50];
	int num, length, i, j;
	char have;
	while (1) {
		printf("\n����������ͺ�\n");
		scanf("%s", &type);
		if (type[0] == numberForStop)
			return;
		fp = fopen(fileName, "r");
		temp = fopen("temp.txt", "w");
		have = 0;
		length = strlen(type);
		type[length] = ' ';
		type[length + 1] = '\0';
		while (fgets(buff, sizeOfBuff, fp)) {
			if (strncmp(buff, type, length + 1) == 0) {
				have = 1;
				printf("���⼸��\n");
				scanf("%d", &num);
				for (i = 0;buff[length + i] != 0;i++) {
					type[i] = buff[length + i + 1];
				}
				num = atoi(type) - num;
				if (num > 0) {
					itoa(num, type, 10);
					for (j = 0;type[j] != 0;j++)
						buff[length + j + 1] = type[j];
					buff[length + j + 1] = '\n';
					buff[length + j + 2] = '\0';
					fputs(buff, temp);
					printf("����ɹ�\n");
				}
				else if (num < 0) {
					printf("����ʧ�ܣ��û����治��\n");
					fputs(buff, temp);
				}
			}
			else
				fputs(buff, temp);
		}
		if (!have)
			printf("����ʧ�ܣ������û�д˻���\n");
		fclose(fp);
		fclose(temp);
		remove(fileName);
		rename("temp.txt", fileName);
	}
}