#include<stdio.h>
#include<conio.h>
#include<Windows.h>

//	case 72:up
//	case 80:down
//	case 75:left
//	case 77:right


int main(){
	int step=0;
	int x,y,i=0,j=0;
	int x1,y1;
	int ch1=0,ch2=0;
	int maze[8][10];
	char stage;
	printf("Chose stage 1 or 2 or 3");
	stage=getch();
	system("cls");
	switch(stage){
	case '1':freopen("maze1.txt","r",stdin);break;
	case '2':freopen("maze2.txt","r",stdin);break;
	case '3':freopen("maze3.txt","r",stdin);break;
	}
	scanf("%d",&x);
	scanf("%d",&y);
	scanf("%d",&x1);
	scanf("%d",&y1);
	for(i=0;i<8;i++){
		for(j=0;j<10;j++){
			scanf("%d",&maze[i][j]);
		}
	}	
	
						
	for(i=0;i<8;i++){
				for(j=0;j<10;j++){
					if(x==i&&y==j){
						printf("x");
					}else if(x1==i&&y1==j){
						printf("#");
					}else if(maze[i][j]==0){
						printf(" ");
					}else if(maze[i][j]==2){
						printf("!");
					}else{
						printf("@");
					}
				}
				printf("\n");
			}	
			
	printf("\n#������ x��С��\n����������������");
	
	
	while(1){
		
			ch1=getch();
//			if(ch1=='r'){
//				x=1,y=1;
//				x1=2,y1=2;
//			}else 
	if (ch1==0xe0||ch1==0x00){
			ch2=getch();
			switch (ch2){
				case 72:
					if(x-1==x1&&y==y1&&maze[x1-1][y1]!=1){
					x-=1;
					x1-=1;	
				}else if(maze[x-1][y]==0&&x-1!=x1|y!=y1){
					x-=1;
				}
					break;//up
				case 80:
					if(x+1==x1&&y==y1&&maze[x1+1][y1]!=1){
					x+=1;
					x1+=1;	
				}else if(maze[x+1][y]==0&&x+1!=x1|y!=y1){
					x+=1;
				}
						break;//down
				case 75:
					if(x==x1&&y-1==y1&&maze[x1][y1-1]!=1){
					y-=1;
					y1-=1;	
				}else if(maze[x][y-1]==0&&y-1!=y1|x!=x1){
					y-=1;
				}
						break;//left
				case 77:
					if(x==x1&&y+1==y1&&maze[x1][y1+1]!=1){
					y+=1;
					y1+=1;	
				}else if(maze[x][y+1]==0&&y+1!=y1|x!=x1){
					y+=1;
				}
						break;//right

				default:break;break;
				}
		}
			COORD crd = {0, 0};
			HANDLE hndl = GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleCursorPosition(hndl, crd);//------���� 
			
			for(i=0;i<8;i++){
				for(j=0;j<10;j++){
					if(maze[x1][y1]==2){
						break;
					}else if(x1==i&&y1==j){
						printf("#");
					}else if(x==i&&y==j){
						printf("x");
					}else if(maze[i][j]==0){
						printf(" ");
					}else if(maze[i][j]==2){
						printf("!");
					}else{
						printf("@");
					}
				}
				printf("\n");
			}
			

			
		if(maze[x1][y1]==2){
			break;
		}

		}
		system("cls");
		printf("You win!");
		Sleep(2);
		return 0;
	}
			





