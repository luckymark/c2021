#include<stdio.h>
#include<conio.h>
#include<Windows.h>

//	case 72:left
//	case 80:right
//	case 75:up
//	case 77:down



int main(){
	int step=0;
	int x=1,y=1,i=0,j=0;
	int ch1=0,ch2=0;
	int maze[8][10]={   //¡¾ÐÐ¡¿¡¿¡¾ÁÐ¡¿ 

	{1,1,1,1,1,1,1,1,2,1},
	{1,0,1,0,0,0,0,1,0,1},
	{1,0,0,0,0,0,1,0,0,1},
	{1,0,0,1,1,0,0,1,0,1},
	{1,0,0,1,0,0,0,0,0,1},
	{1,0,1,0,1,1,0,1,0,1},
	{1,0,0,0,0,0,0,1,0,1},
	{1,1,1,1,1,1,1,1,1,1}};
							
	for(i=0;i<8;i++){
				for(j=0;j<10;j++){
					if(x==i&&y==j){
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
	
	
	while(1){
		
		
		
		if (ch1=getch()){

			ch2=getch();
			switch (ch2){
				case 75:if(maze[x][y-1]!=1){y-=1;}break;//up 
				case 77:if(maze[x][y+1]!=1){y+=1;}break;//down
				case 72:if(maze[x-1][y]!=1){x-=1;}break;//left
				case 80:if(maze[x+1][y]!=1){x+=1;}break;//right
				default:break;break;
				}
			
			COORD crd = {0, 0};
			HANDLE hndl = GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleCursorPosition(hndl, crd);//------ÇåÆÁ 
			
			for(i=0;i<8;i++){
				for(j=0;j<10;j++){
					if(maze[x][y]==2){
						system("cls");
						printf("You win!");
						break;
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
			
			if(maze[x][y]==2){
				break;
			}


		}
	}
			
	}




