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
int play_depth(int now[15][15],int depth);
int search_l(int now[15][15],int k);
int search_r(int now[15][15],int k);
int search_xsright(int now[15][15],int p_c);
int search_xsleft(int now[15][15],int p_c);
void print_qipan();
void com_play(int now[15][15]);

int main(){
	int a,b;
	print_qipan();
	while(scanf("%d %d/n",&a,&b)){
		qipan[a][b]=1;
		print_qipan();
		cout<<endl;
		c_x=0;c_y=0;
		if(win(qipan)==1){
			cout<<"You win!"<<endl;
			break;
		} 
		for(int t=0;t<15;t++){
            for(int k=0;k<15;k++){
                fuzhi[t][k]=qipan[t][k];
            }
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

int play_depth(int now[15][15],int depth){
    int copy[15][15];
    for(int t=0;t<15;t++){
        for(int k=0;k<15;k++){
            copy[t][k]=now[t][k];
        }
    }
    int com1=-value_com(copy),com2;
    int p_x,p_y,player,computer,x,y;
    for(int i=0;i<15;i++){
        for(int j=0;j<15;j++){
            if(now[i][j]==0){
                now[i][j]=1;
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
                if(player-computer>com1){
                    p_x=i;p_y=j;
                    com1=player-computer;
                    //cout<<i<<" "<<j<<": "<<player<<" "<<computer<<endl;
                }
                else if((player-computer)==com1&&(abs(i-7)+abs(j-7))<(abs(p_x-7)+abs(p_y-7))){
                    p_x=i; p_y=j;
                    //cout<<i<<" "<<j<<": "<<player<<" "<<computer<<endl;
                }
                player=0;computer=0;
            }
        }
    }
    now[p_x][p_y]=1;
    cout<<"player:"<<p_x<<" "<<p_y<<"  ";
    for(int t=0;t<15;t++){
        for(int k=0;k<15;k++){
            copy[t][k]=now[t][k];
        }
    }
    com2=-value_player(copy);
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
                if((computer-player)>com2){
                    com2=computer-player;
                    x=i; y=j;
                    //cout<<i<<" "<<j<<": "<<player<<" "<<computer<<endl;
                }
                if((computer-player)==com2&&(abs(i-7)+abs(j-7))<(abs(x-7)+abs(y-7))){
                    x=i; y=j;
                    //cout<<i<<" "<<j<<": "<<player<<" "<<computer<<endl;
                }
                player=0;computer=0;
            }
        }
    }
    cout<<"computer:"<<x<<" "<<y<<endl;
    return com2;
}

void com_play(int now[15][15]){
	int player,com;
	int computer,max,x,y;
	int copy[15][15];
	x=0;y=0;
	max=-value_player(now);
	for(int i=0;i<15;i++){
		for(int j=0;j<15;j++){
			if(now[i][j]==0){
				now[i][j]=-1;
				/*for(int t=0;t<15;t++){
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
				player=0;computer=0;*/
				com=play_depth(now,2);
				if(com>max){
				    max=com;
				    x=i;y=j;
				}
				else if(com==max&&(abs(i-7)+abs(j-7))<(abs(x-7)+abs(y-7))){
				    x=i;y=j;
				}
				now[i][j]=0;
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
	valuep=valuep+search_l(now,1);
	//cout<<"l: "<<valuep<<endl;
	valuep=valuep+search_r(now,1);
	//cout<<"r: "<<valuep<<endl;
	valuep=valuep+search_xsright(now,1);
	//cout<<"xr: "<<i<<" "<<j<<" "<<valuep<<endl;
	valuep=valuep+search_xsleft(now,1);
	//cout<<"xl: "<<i<<" "<<j<<" "<<valuep<<endl;
	
	return valuep;
}

int value_com(int now[15][15]){
	int valuep=0; 
	valuep=valuep+search_l(now,-1);
	//cout<<"l: "<<i<<" "<<j<<" "<<valuep<<endl;
	valuep=valuep+search_r(now,-1);
	//cout<<"r: "<<i<<" "<<j<<" "<<valuep<<endl;
	valuep=valuep+search_xsright(now,-1);
	//cout<<"xr: "<<i<<" "<<j<<" "<<valuep<<endl;
	valuep=valuep+search_xsleft(now,-1);
	//cout<<"xl: "<<i<<" "<<j<<" "<<valuep<<endl;
	valuep=valuep/2;
	return valuep;
}

int search_l(int now[15][15],int k){
	int value=0;
	int value_i,num;
	int cl;
	for(int i=0;i<=14;i++){
	    for(int j=0;j<=14;j++){
	        value_i=0;
	        if(now[i][j]==k){
	            value_i=10;
	            cl=0;
	            if((j>0&&now[i][j-1]==-k)||j==0){
	                value_i=value_i/10;
	                cl=j;
	            }
	            num=0;
	            do{
	                if(now[i][j]==k){
	                    value_i=value_i*10;
	                }
	                else{
	                    num++;
	                }
	                j=j+1;
	            }while((now[i][j]!=-k)&&num<=1&&j<15);
	            if(now[i][j]==-k){
	                if(j-cl<5){
	                    value_i=0;
	                }
	            }
	            if(j==15){
	            	break;
				}
	        }
	        value+=value_i;
	    }
	}
	return value;
}

int search_r(int now[15][15],int k){
    int value=0;
    int value_i,num,cl;
    for(int j=0;j<=14;j++){
        for(int i=0;i<=14;i++){
            value_i=0;
            if(now[i][j]==k){
                value_i=10;
                cl=0;
                if(now[i-1][j]==-k){
                    value_i=value_i/10;
                    cl=i;
                }
                num=0;
                do{
                    if(now[i][j]==k){
                        value_i=value_i*10;
                    }
                    else{
                        num++;
                    }
                    i++;
                }while((now[i][j]!=-k)&&num<=1&&i<15);
                if(now[i][j]==-k){
                    if(i-cl<5){
                        value_i=0;
                    }
                }
            }
            value+=value_i;
        }
    }
    return value;
}

int search_xsright(int now[15][15],int p_c){
    int value=0;
    int value_i,num,cl,i,j;
    for(int t=-14;t<15;t++){
        if(t<0){
            i=0;j=-t;
        }
        else{
            i=t;j=0;
        }
        for(int k=0;k<15-abs(t);k++){
            value_i=0;
            if(now[i+k][j+k]==p_c){
                value_i=10;
                cl=0;
                if(now[i+k-1][j+k-1]==-p_c){
                    value_i=value_i/10;
                    cl=k-1;
                }
                num=0;
                do{
                    if(now[i+k][j+k]==p_c){
                        value_i=value_i*10;
                    }
                    else{
                        num++;
                    }
                    k++;
                }while((now[i][j]!=-p_c)&&num<=1&&15-abs(t));
                if(now[i+k][j+k]==-p_c){
                    if(k-cl<5){
                        value_i=0;
                    }
                }
            }
            value+=value_i;
        }
    }
    return value;
}

int search_xsleft(int now[15][15],int p_c){
    int value=0;
    int value_i,num,cl,i,j;
    for(int t=0;t<29;t++){
        if(t<15){
            i=t;j=0;
        }
        else{
            i=14;j=t-14;
        }
        for(int k=0;k<15-abs(14-t);k++){
            value_i=0;
            if(now[i+k][j+k]==p_c){
                value_i=10;
                cl=0;
                if(now[i-k+1][j+k-1]==-p_c){
                    value_i=value_i/10;
                    cl=k-1;
                }
                num=0;
                do{
                    if(now[i-k][j+k]==p_c){
                        value_i=value_i*10;
                    }
                    else{
                        num++;
                    }
                    k++;
                }while((now[i-k][j+k]!=-p_c)&&num<=1&&k<15-abs(14-t));
                if(now[i-k][j+k]==-p_c){
                    if(k-cl<5){
                        value_i=0;
                    }
                }
            }
            value+=value_i;
        }
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
