#include<iostream>
#include<cstdio>
#include<stdlib.h>
#include<windows.h>
#include<math.h>
using namespace std;
int qipan[15][15]={0};
int fuzhi[15][15];
int c_x,c_y;

int value_player(int now[15][15],int k);
int value_com(int now[15][15],int k); 
int win(int now[15][15]);
int play_depth(int now[15][15],int depth);
int search_l(int now[15][15],int k);
int search_r(int now[15][15],int k);
int search_xsright(int now[15][15],int p_c);
int search_xsleft(int now[15][15],int p_c);
void print_qipan();
void com_play(int now[15][15]);
int nearb(int i,int j);

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
		//qipan[7][9]=-1;
		//cout<<value_player(fuzhi,0);
	}
} 

int nearb(int i,int j){
    int n=0;
	for(int t=-2;t<=2;t++){
		if(qipan[i+t][j]!=0)n=1;
		if(qipan[i][j+t]!=0)n=1;
		if(qipan[i+t][j+t]!=0)n=1;
		if(qipan[i+t][j-t]!=0)n=1;
	}
	return n;	
}

int play_depth(int now[15][15],int depth){
    int copy[15][15];
    int x,y,p_x,p_y; 
    int d;
    for(int t=0;t<15;t++){
        for(int k=0;k<15;k++){
            copy[t][k]=now[t][k];
        }
    }
    d=depth;
    int com1=-value_com(copy,0);
	int com2;
	int com;
    int player,computer;
    for(int t=0;t<15;t++){
        for(int k=0;k<15;k++){
            copy[t][k]=now[t][k];
        }
    }
    player=value_player(copy,0);
    for(int t=0;t<15;t++){
        for(int k=0;k<15;k++){
            copy[t][k]=now[t][k];
        }
    }
    computer=value_com(copy,0);
    com=computer-player;
    while(depth>1){
    	p_x=0;p_y=0;x=0;y=0;
    	for(int i=0;i<15;i++){
        for(int j=0;j<15;j++){
            if(now[i][j]==0){
                now[i][j]=1;
                for(int t=0;t<15;t++){
                    for(int k=0;k<15;k++){
                        copy[t][k]=now[t][k];
                    }
                }
                player=value_player(copy,1);
                //if(now[6][10]==-1&&i==6&&j==8)cout<<"1 "<<player<<endl;
                //if(now[6][10]==-1&&i==5&&j==9)cout<<"2 "<<player<<endl;
                for(int t=0;t<15;t++){
                    for(int k=0;k<15;k++){
                        copy[t][k]=now[t][k];
                    }
                }
                computer=value_com(copy,0);
                //if(now[6][10]==-1&&i==6&&j==8)cout<<"3 "<<computer<<endl;
                //if(now[6][10]==-1&&i==5&&j==9)cout<<"4 "<<computer<<endl;
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
    //if(now[6][8]==-1)cout<<com1<<" "<<p_x<<" "<<p_y<<endl;
    //if(now[6][10]==-1)cout<<com1<<" "<<p_x<<" "<<p_y<<endl;
    //cout<<"player:"<<p_x<<" "<<p_y<<"  "<<endl;
    for(int t=0;t<15;t++){
        for(int k=0;k<15;k++){
            copy[t][k]=now[t][k];
        }
    }
    com2=-value_player(copy,0);
    for(int i=0;i<15;i++){
        for(int j=0;j<15;j++){
            if(now[i][j]==0){
                now[i][j]=-1;
                for(int t=0;t<15;t++){
                    for(int k=0;k<15;k++){
                        copy[t][k]=now[t][k];
                    }
                }
                player=value_player(copy,0);
                for(int t=0;t<15;t++){
                    for(int k=0;k<15;k++){
                        copy[t][k]=now[t][k];
                    }
                }
                computer=value_com(copy,1);
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
    //cout<<"computer:"<<x<<" "<<y<<endl;
    now[x][y]=-1;
    depth=depth-1;
    com=com+com2/pow(5,2*(d-depth)-1);
    //com=(com*8+com2)/7;   
	}
    //if(now[6][8]==-1)cout<<com2<<" "<<x<<" "<<y<<endl;
    //if(now[6][10]==-1)cout<<com2<<" "<<x<<" "<<y<<endl;
    //cout<<"computer:"<<x<<" "<<y<<endl;
    return com;
}

void com_play(int now[15][15]){
	int player,comp;
	int computer,max,x,y;
	int copy[15][15];
	x=0;y=0;
	max=-value_player(now,0);
	for(int i=0;i<15;i++){
		for(int j=0;j<15;j++){
			if(now[i][j]==0&&nearb(i,j)==1){
				now[i][j]=-1;
				for(int t=0;t<15;t++){
			        for(int k=0;k<15;k++){
				        copy[t][k]=now[t][k];
			        }
		        }
				/*player=value_player(copy);
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
				comp=play_depth(copy,2); 
				//if(i==4&&j==8)cout<<com<<endl;
				//if(i==6&&j==8)cout<<com<<endl;
				if(comp>max){
				    max=comp;
				    c_x=i;c_y=j;
				    //cout<<i<<" "<<j<<endl;
			
				}
				else if(comp==max&&(abs(i-7)+abs(j-7))<(abs(x-7)+abs(y-7))){
				    c_x=i;c_y=j;
				    //cout<<i<<" "<<j<<endl;
				    
				}
				now[i][j]=0;
			} 
		}
	}
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

int value_player(int now[15][15],int k){
	int valuep=0; 
	valuep=valuep+search_l(now,1);
	//cout<<"l: "<<valuep<<endl;
	valuep=valuep+search_r(now,1);
	//cout<<"r: "<<valuep<<endl;
	valuep=valuep+search_xsright(now,1);
	//cout<<"xr: "<<i<<" "<<j<<" "<<valuep<<endl;
	valuep=valuep+search_xsleft(now,1);
	//cout<<"xl: "<<i<<" "<<j<<" "<<valuep<<endl;
	if(k==1)valuep=valuep/2;
	return valuep;
}

int value_com(int now[15][15],int k){
	int valuep=0; 
	valuep=valuep+search_l(now,-1);
	//cout<<"l: "<<i<<" "<<j<<" "<<valuep<<endl;
	valuep=valuep+search_r(now,-1);
	//cout<<"r: "<<i<<" "<<j<<" "<<valuep<<endl;
	valuep=valuep+search_xsright(now,-1);
	//cout<<"xr: "<<i<<" "<<j<<" "<<valuep<<endl;
	valuep=valuep+search_xsleft(now,-1);
	//cout<<"xl: "<<i<<" "<<j<<" "<<valuep<<endl;
	if(k==1)valuep=valuep/2;
	return valuep;
}

int search_l(int now[15][15],int k){
	int value=0;
	int value_i,num;
	int cl;
	for(int i=0;i<=14;i++){
	   int j=0;
	   while(j<=14){
	        value_i=0;
	        if(now[i][j]==k){
	            value_i=10;
	            cl=0;
	            if(j>0&&now[i][j-1]==-k){
	                value_i=value_i/10;
	                cl=j;
	                //cout<<i<<" "<<j<<endl;
	            }
	            num=0;
	            j++;
	            while((now[i][j]==k||(now[i][j]==0&&now[i][j+1]==k&&num==0))&&j<15){
	                if(now[i][j]==k){
	                    value_i=value_i*10;
	                }
	                else{
	                	num++;
					}
	                j++;
	            }
	            if(cl!=0||now[i][j]==-k)value_i=value_i-1;
	            if(now[i][j]==-k){
	                if(j-cl<5){
	                    value_i=0;
	                }
	                else{
	                	value_i=value_i/10;
					}
	            }
	            if(j==15){
	            	break;
				}
	        }
	        if(value_i>=10000)value_i=value_i*100;
	        value+=value_i;
	        j++;
	    }
	}
	return value;
}

int search_r(int now[15][15],int k){
    int value=0;
	int value_i,num;
	int cl;
	for(int j=0;j<=14;j++){
	   int i=0;
	   while(i<=14){
	        value_i=0;
	        if(now[i][j]==k){
	            value_i=10;
	            cl=0;
	            if(i>0&&now[i-1][j]==-k){
	                value_i=value_i/10;
	                cl=i;
	                //cout<<i<<" "<<j<<endl;
	            }
	            num=0;
	            i++;
	            while((now[i][j]==k||(now[i][j]==0&&now[i+1][j]==k&&num==0))&&i<15){
	                if(now[i][j]==k){
	                    value_i=value_i*10;
	                }
	                else{
	                	num++;
					}
	                i++;
	            }
	            if(cl!=0||now[i][j]==-k)value_i=value_i-1;
	            if(now[i][j]==-k){
	                if(i-cl<5){
	                    value_i=0;
	                }
	                else{
	                	value_i=value_i/10;
					}
	            }
	            if(i==15){
	            	break;
				}
	        }
	        if(value_i>=10000)value_i=value_i*100;
	        value+=value_i;
	        i++;
	    }
	}
	return value;
}

int search_xsright(int now[15][15],int p_c){
    int value=0;
	int value_i,num,i,j;
	int cl;
	for(int t=-14;t<15;t++){
		if(t<0){
            i=0;j=-t;
        }
        else{
            i=t;j=0;
        }
	   int k=0;
	   while(k<15-abs(t)){
	        value_i=0;
	        if(now[i+k][j+k]==p_c){
	            value_i=10;
	            cl=0;
	            if(k>0&&now[i+k-1][j+k-1]==-p_c){
	                value_i=value_i/10;
	                cl=k;
	                //cout<<i<<" "<<j<<endl;
	            }
	            num=0;
	            k++;
	            while((now[i+k][j+k]==p_c||(now[i+k][j+k]==0&&now[i+k+1][j+k+1]==p_c&&num==0))&&k<15-abs(t)){
	                if(now[i+k][j+k]==p_c){
	                    value_i=value_i*10;
	                }
	                else{
	                	num++;
					}
	                k++;
	            }
	            if(cl!=0||now[i+k][j+k]==-p_c)value_i=value_i-1;
	            if(now[i+k][j+k]==-p_c){
	                if(k-cl<5){
	                    value_i=0;
	                }
	                else{
	                	value_i=value_i/10;
					}
	            }
	            if(k==15-abs(t)){
	            	break;
				}
	        }
	        if(value_i>=10000)value_i=value_i*100;
	        value+=value_i;
	        k++;
	    }
	}
	return value;
}

int search_xsleft(int now[15][15],int p_c){
    int value=0;
	int value_i,num,i,j;
	int cl;
	for(int t=0;t<29;t++){
		if(t<15){
            i=t;j=0;
        }
        else{
            i=14;j=t-14;
        }
	   int k=0;
	   while(k<15-abs(14-t)){
	        value_i=0;
	        if(now[i-k][j+k]==p_c){
	            value_i=10;
	            cl=0;
	            if(k>0&&now[i-k+1][j+k-1]==-p_c){
	                value_i=value_i/10;
	                cl=k;
	                //cout<<i<<" "<<j<<endl;
	            }
	            num=0;
	            k++;
	            while((now[i-k][j+k]==p_c||(now[i-k][j+k]==0&&now[i-k-1][j+k+1]==p_c&&num==0))&&k<15-abs(14-t)){
	                if(now[i-k][j+k]==p_c){
	                    value_i=value_i*10;
	                }
	                else{
	                	num++;
					}
	                k++;
	            }
	            if(cl!=0||now[i-k][j+k]==-p_c)value_i=value_i-1;
	            if(now[i-k][j+k]==-p_c){
	                if(k-cl<5){
	                    value_i=0;
	                }
	                else{
	                	value_i=value_i/10;
					}
	            }
	            if(k==15-abs(14-t)){
	            	break;
				}
	        }
	        if(value_i>=10000)value_i=value_i*100;
	        value+=value_i;
	        k++;
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
