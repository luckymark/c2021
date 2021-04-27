#include<iostream>
#include<cstdio>
#include<stdlib.h>
#include<windows.h>
using namespace std;
int qipan[15][15]={0};
int fuzhi[15][15];
int c_x,c_y;

int value_player(int now[15][15]);
int value_com(int now[15][15]); 
int win(int now[15][15]);
int search_l(int now[15][15],int x,int y,int k);
int search_r(int now[15][15],int x,int y,int k);
int search_xsright(int now[15][15],int x,int y,int k);
int search_xsleft(int now[15][15],int x,int y,int k);
void print_qipan();
void com_play(int now[15][15]);

int main(){
	int a,b;
	print_qipan();
	while(scanf("%d %d/n",&a,&b)){
		qipan[a][b]=1;
		print_qipan();
		cout<<endl;
		for(int i=0;i<15;i++){
			for(int j=0;j<15;j++){
				fuzhi[i][j]=qipan[i][j];
			}
		}
		c_x=0;c_y=0;
		if(win(qipan)==1){
			cout<<"You win!"<<endl;
			break;
		} 
		com_play(fuzhi);
		qipan[c_x][c_y]=-1;
	    print_qipan();
	    cout<<endl;
		if(win(qipan)==-1){
			cout<<"You lose!"<<endl;
			break;
		}
	}
} 

void com_play(int now[15][15]){
	int player;
	int computer,min,x,y;
	int copy[15][15];
	x=0;y=0;
	for(int i=0;i<15;i++){
		for(int j=0;j<15;j++){
			copy[i][j]=now[i][j];
		}
	}
	min=-value_player(copy);
	for(int i=0;i<15;i++){
		for(int j=0;j<15;j++){
			if(now[i][j]==0){
				now[i][j]=-1;
				for(int t=0;t<15;t++){
			        for(int k=0;k<15;k++){
				        copy[t][k]=now[t][k];
			        }
		        }
				player=value_player(copy);
				for(int t=0;t<15;t++){
			        for(int k=0;k<15;k++){
				        copy[t][k]=now[t][k];
			        }
		        }
				computer=value_com(copy);
				now[i][j]=0;
				if(computer-player>min){
					x=i;y=j;
					min=computer-player;
					//cout<<i<<" "<<j<<": "<<player<<" "<<computer<<endl;
				}
				else if(computer-player==min&&(abs(i-7)+abs(j-7))<(abs(x-7)+abs(y-7))){
					x=i; y=j;
					//cout<<i<<" "<<j<<": "<<player<<" "<<computer<<endl;
				}
				player=0;computer=0;
			} 
		}
	}
	c_x=x; c_y=y;
}

int win(int now[15][15]){
	int w=0;
	int i,j;
	for(int i=0;i<15;i++){
		for(int j=0;j<15;j++){
			if(now[i][j]==1){
				if(w<0){
					w=0;
					w++;
				}
				else{
					w++;
				}
				if(w>4){
					return 1;
				} 
			}
			else if(now[i][j]==-1){
				if(w>0){
					w=0;
					w--;
				}
				else{
					w--;
				}
				if(w<-4){
					return -1;
				} 
			}
		}
		w=0;
	}
	for(int j=0;j<15;j++){
		for(int i=0;i<15;i++){
			if(now[i][j]==1){
				if(w<0){
					w=0;
					w++;
				}
				else{
					w++;
				}
				if(w>4){
					return 1;
				} 
			}
			else if(now[i][j]==-1){
				if(w>0){
					w=0;
					w--;
				}
				else{
					w--;
				}
				if(w<-4){
					return -1;
				} 
			}
		}
		w=0;
	}
	for(int t=-14;t<15;t++){
		if(t<0){
			i=0;j=-t;
		}
		else{
			i=t;j=0;
		}
		for(int k=0;k<15-abs(t);k++){
			if(now[i+k][j+k]==1){
				if(w<0){
					w=0;
					w++;
				}
				else{
					w++;
				}
				if(w>4){
					return 1;
				} 
			}
			else if(now[i+k][j+k]==-1){
				if(w>0){
					w=0;
					w--;
				}
				else{
					w--;
				}
				if(w<-4){
					return -1;
				} 
			}
		}
		w=0;
	}
	for(int t=0;t<29;t++){
		if(t<15){
			i=t;j=0;
		}
		else{
			i=14;j=t-14;
		}
		for(int k=0;k<15-abs(14-t);k++){
			if(now[i-k][j+k]==1){
				if(w<0){
					w=0;
					w++;
				}
				else{
					w++;
				}
				if(w>4){
					return 1;
				} 
			}
			else if(now[i-k][j+k]==-1){
				if(w>0){
					w=0;
					w--;
				}
				else{
					w--;
				}
				if(w<-4){
					return -1;
				} 
			}
		}
		w=0;
	}
	return 0;
}

int value_player(int now[15][15]){
	int valuep=0; 
	for(int i=0;i<15;i++){
		for(int j=0;j<15;j++){
			if(now[i][j]==1){
				valuep=valuep+search_l(now,i,j,1);
				//cout<<"l: "<<i<<" "<<j<<" "<<valuep<<endl;
				valuep=valuep+search_r(now,i,j,1);
				//cout<<"r: "<<i<<" "<<j<<" "<<valuep<<endl;
				valuep=valuep+search_xsright(now,i,j,1);
				//cout<<"xr: "<<i<<" "<<j<<" "<<valuep<<endl;
				valuep=valuep+search_xsleft(now,i,j,1);
				//cout<<"xl: "<<i<<" "<<j<<" "<<valuep<<endl;
				now[i][j]=0; 
			}
		}
	}
	return valuep;
}

int value_com(int now[15][15]){
	int value=0; 
	for(int i=0;i<15;i++){
		for(int j=0;j<15;j++){
			if(now[i][j]==-1){
				value+=search_l(now,i,j,-1);
				//cout<<i<<" "<<j<<" :l "<<value<<endl;
				value+=search_r(now,i,j,-1);
				//cout<<i<<" "<<j<<" :r "<<value<<endl;
				value+=search_xsright(now,i,j,-1);
				//cout<<i<<" "<<j<<" :xr "<<value<<endl;
				value+=search_xsleft(now,i,j,-1);
				//cout<<i<<" "<<j<<" :xl "<<value<<endl;
				now[i][j]=0; 
			}
		}
	}
	return value;
}

int search_l(int now[15][15],int i,int j,int k){
	int head,tail,num;
	int value=100;
	head=5; tail=5;
	num=1;
    for(int t=1;t<=4;t++){
    	if(j-t>=0){
    		if(now[i][j-t]==k){
    			value=value*20;
    			num=num+1;
			}
			else if(now[i][j-t]==-k){
				value=value/10;
				head=t;
				break;
			}
		}
		else{
			value=value/10;
			head=t;
			break;
		}
	}
	for(int t=1;t<=4;t++){
    	if(j+t<15){
    		if(now[i][j+t]==k){
    			value=value*20;
    			num++;
			}
			else if(now[i][j+t]==-k){
				value=value/10;
				tail=t;
				//cout<<"-#"<<k<<" "<<i<<" "<<j+t<<" "<<value<<endl;
				break;
			}
		}
		else{
			value=value/10;
			tail=t;
			break;
		}
	}
	if(num>=3){
		if(num==4){
			value=value*(5+k);
		}
		else{
			value=value*(3+k);
		}
	}
	if(head+tail<6){
		value=0;
	}
	return value;
}

int search_r(int now[15][15],int i,int j,int k){
	int head,tail,num;
	int value=100;
	head=5; tail=5;
	num=1;
	//cout<<i<<" "<<j<<" "<<head<<" "<<" "<<tail<<endl;
    for(int t=1;t<=4;t++){
    	if(i-t>=0){
    		if(now[i-t][j]==k){
    			value=value*20;
    			num++;
			}
			else if(now[i-t][j]==-k){
				value=value/10;
				head=t;
				break;
			}
		}
		else{
		    value=value/10;
			head=t;
			break;
	    }
	}
	for(int t=1;t<=4;t++){
    	if(i+t<15){
    		if(now[i+t][j]==k){
    			value=value*20;
    			num++;
			}
			else if(now[i+t][j]==-k){
				value=value/10;
				tail=t;
				//if(tail!=5) cout<<i<<" "<<j<<" "<<tail<<endl;
				break;
			}
		}
		else{
			value=value/10;
			tail=t;
			break;
		}
	}
	if(num>=3){
		if(num==4){
			value=value*(5+k);
		}
		else{
			value=value*(3+k);
		}
	}
	//cout<<i<<" "<<j<<" "<<value<<endl;
	if(head+tail<6){
		value=0;
	}
	//cout<<i<<" "<<j<<" "<<value<<endl;
	return value;
}

int search_xsright(int now[15][15],int i,int j,int k){
	int head,tail,num;
	int value=100;
	head=5; tail=5;
	num=1;
    for(int t=1;t<=4;t++){
    	if(i-t>=0&&j+t<15){
    		if(now[i-t][j+t]==k){
    			value=value*20;
    			num++;
			}
			else if(now[i-t][j+t]==-k){
				value=value/10;
				head=t;
				break;
			}
		}
		else{
			value=value/10;
			head=t;
			break;
		}
	}
	for(int t=1;t<=4;t++){
    	if(i+t<15&&j-t>=0){
    		if(now[i+t][j-t]==k){
    			value=value*20;
    			num++;
			}
			else if(now[i+t][j-t]==-k){
				value=value/10;
				tail=t;
				break;
			}
		}
		else{
			value=value/10;
			tail=t;
			break;
		}
	}
	if(num>=3){
		if(num==4){
			value=value*(5+k);
		}
		else{
			value=value*(3+k);
		}
	}
	if(head+tail<6){
		value=0;
	}
	return value;
}

int search_xsleft(int now[15][15],int i,int j,int k){
	int head,tail,num;
	int value=100;
	head=5; tail=5;
	num=1;
    for(int t=1;t<=4;t++){
    	if(i-t>=0&&j-t>=0){
    		if(now[i-t][j-t]==k){
    			value=value*20;
    			num++;
			}
			else if(now[i-t][j-t]==-k){
				value=value/10;
				head=t;
				break;
			}
		}
		else{
			value=value/10;
			head=t;
			break;
		}
	}
	for(int t=1;t<=4;t++){
    	if(i+t<15&&j+t<15){
    		if(now[i+t][j+t]==k){
    			value=value*20;
    			num++;
			}
			else if(now[i+t][j+t]==-k){
				value=value/10;
				tail=t;
				break;
			}
		}
		else{
			value=value/10;
			tail=t;
			break;
		}
	}
	if(num>=3){
		if(num==4){
			value=value*(5+k);
		}
		else{
			value=value*(3+k);
		}
	}
	if(head+tail<6){
		value=0;
	}
	return value;
}

void print_qipan(){
	for(int i=0;i<15;i++){
		for(int j=0;j<15;j++){
			if(qipan[i][j]==0){
				cout<<"0 ";
			}
			if(qipan[i][j]==1){
				cout<<"P ";
			}
			if(qipan[i][j]==-1){
				cout<<"U ";
			}
		}
		cout<<endl;
	}
}
