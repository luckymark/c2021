#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
struct pos{
	int x, y;
	pos(const int &X, const int &Y):x(X), y(Y){}
	inline bool isVaild(){ return 1 <= x && x <= 15 && 1 <= y && y <= 15; }
};
enum{ black = 1, white = 2 };
int board[16][16];
bool vis[16][16];

//这点在不在棋盘上
bool isVaild(int x, int y){ return 1 <= x && x <= 15 && 1 <= y && y <= 15; }
//另一方
int otherside(int role){
	if(role == black)return white;
	else return black;
}
//评估部分
int f[] = {0,10,100,1000};
int acesstable(int tot, int block){
	if(tot == 5)return INT_MAX >> 3;
	if(!block)
		return f[tot];
	else if(block == 1)
		return f[tot - 1];
	return 0;

}
//返回某点相连的子的得分
int score(int x, int y, int role){
	//down
	int result = 0, block = 0, tot = 1;
	if(!isVaild(x - 1, y) || board[x - 1][y] == otherside(role))++block;
	while(isVaild(x + tot, y) && board[x + tot][y] == role)vis[x + tot][y] = 1, ++tot;
	if(!isVaild(x + tot, y) || board[x + tot][y] == otherside(role))++block;
	if(result += acesstable(tot, block) >= (INT_MAX) >> 3)return result;

	//right
	block = 0; tot = 1;
	if(!isVaild(x, y - 1) || board[x][y - 1] == otherside(role))++block;
	while(isVaild(x, y + tot) && board[x][y + tot] == role)vis[x][y + tot] = 1, ++tot;
	if(!isVaild(x, y + tot) || board[x][y + tot] == otherside(role))++block;
	if(result += acesstable(tot, block) >= (INT_MAX) >> 3)return result;

	//right-down
	block = 0; tot = 1;
	if(!isVaild(x - 1, y - 1) || board[x - 1][y - 1] == otherside(role))++block;
	while(isVaild(x + tot, y + tot) && board[x + tot][y + tot] == role)vis[x + tot][y + tot] = 1, ++tot;
	if(!isVaild(x + tot, y + tot) || board[x + tot][y + tot] == otherside(role))++block;
	if(result += acesstable(tot, block) >= (INT_MAX) >> 3)return result;

	return result;
}
//返回整个棋盘的得分
int acess(int role){
	int result = 0, t;
	memset(vis, 0, sizeof vis);
	for(int i = 1; i <= 15; ++i)
		for(int j = 1; j <= 15; ++j)
			if(board[i][j] == role && !vis[i][j])
				if(result += score(i, j, role) >= (INT_MAX >> 3))return result;
	for(int i = 1; i <= 15; ++i)
		for(int j = 1; j <= 15; ++j)
			if(board[i][j] == otherside(role) && !vis[i][j])
				result -= score(i, j, otherside(role));
	return result;
}
int main(){

	return 0;
}