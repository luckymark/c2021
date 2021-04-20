#include<stdio.h>
#include<math.h>
#include<time.h>
#include<windows.h>
#include<stdlib.h>
#include<conio.h>

#define wall 0
#define road 1
#define L 44

void creatmaze(int **maze,int x,int y);

int main(void)
{
	srand((unsigned)time(NULL));
	int **maze=(int**)malloc(L*sizeof(int*));
	for (int i=0;i<L;i++){
		maze[i]=(int*)calloc(L,sizeof(int));
	}
	for (int i=0;i<L;i++){
		maze[i][0]=road;
		maze[0][i]=road;
		maze[i][L-1]=road;
		maze[L-1][i]=road;
	}
	creatmaze(maze,2,2);
	maze[2][1]=road;
	for (int i=L-3;i>=0;i--){
		if (maze[i][L-3]==road){
			maze[i][L-2]=road;
			break;
		}
	}
	
	for (int i=0;i<L;i++){
		for (int j=0;j<L;j++){
			if (maze[i][j]==road){
				maze[i][j]=' ';
			}else {
				maze[i][j]='#';
			}
		} 
	}
	maze[2][1]='o';
	for (int i=0;i<L;i++){
		free(maze[i]);
	}
	free(maze);

	int m,n,dm,dn;
	m=2;n=1;dm=41;dn=43;
	int getch(void);
	for (int i=0;i<L;++i){
		for (int j=0;j<L;++j){
			printf("%c",maze[i][j]);
		} 
		printf("\n");
	}
	while (m!=dm || n!=dn){
		char ch=_getch();
		if (ch=='s'||ch=='S'){
			if(maze[m+1][n]!='#'){
				maze[m][n]=' ';
				m++;
				maze[m][n]='o';
			}
		}
		if (ch=='w'||ch=='W'){
			if(maze[m-1][n]!='#'){
				maze[m][n]=' ';
				m--;
				maze[m][n]='o';
			}
		}
		if (ch=='a'||ch=='A'){
			if(maze[m][n-1]!='#'){
				maze[m][n]=' ';
				n--;
				maze[m][n]='o';
			}
		}
		if (ch=='d'||ch=='D'){
			if(maze[m][n+1]!='#'){
				maze[m][n]=' ';
				n++;
				maze[m][n]='o';
			}
		}
		system("cls");
		for (int i=0;i<L;++i){
			for (int j=0;j<L;++j){
				printf("%c",maze[i][j]);
			} 	
		printf("\n");
		}
	}
	system("cls");
	printf("you win!\n");
	Sleep(200);
	return 0;
}

void creatmaze(int **maze,int x,int y)
{
	maze[x][y] = road;
	int dire[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
	for (int i=0;i<4;i++){
		int r=rand()%4;
		int temp=dire[0][0];
		dire[0][0]=dire[r][0];
		dire[r][0]=temp;
		temp=dire[0][1];
		dire[0][1]=dire[r][1];
		dire[r][1]=temp;
	}
	for (int i=0;i<4;i++){
		int dx=x;
		int dy=y;
		int range=1;
		while (range>0){
			dx+=dire[i][0];
			dy+=dire[i][1];
			if (maze[dx][dy]==road){
				break;
			}
			int count =0;
			for (int j=dx-1;j<dx+2;j++){
				for (int k=dy-1;k<dy+2;k++){
					if (abs(j-dx)+abs(k-dy)==1 && maze[j][k]==road){
						count++;
					}
				}
			}
			if (count>1){
				break;
			}
			--range;
			maze[dx][dy]=road;
		}
		if (range<=0){
			creatmaze(maze,dx,dy);
		}
	}
 } 
