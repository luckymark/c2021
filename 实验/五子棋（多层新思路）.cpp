#include<iostream>
#include<cstdio>
#include<stdlib.h>
#include<windows.h>
#include<math.h>
using namespace std;
int qipan[15][15]={0};
int fuzhi[15][15];
int c_x,c_y;
int maxmax=9999999;
int minmax=999999;

int value_player(int now[15][15]);
int value_com(int now[15][15]); 
int win(int now[15][15]);
int min_v(int now[15][15],int depth,int a,int b);
int max_v(int now[15][15],int depth,int a,int b);
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
	}
} 

int nearb(int i,int j){
    int n=0;
	for(int t=-2;t<=2;t++){
		if(qipan[i+t][j]!=0&&i+t>=0&&i+t<15) return 1;
		if(qipan[i][j+t]!=0&&j+t>=0&&j+t<15) return 1;
		if(qipan[i+t][j+t]!=0&&i+t>=0&&i+t<15&&j+t>=0&&j+t<15) return 1;
		if(qipan[i+t][j-t]!=0&&i+t>=0&&i+t<15&&j-t>=0&&j-t<15) return 1;
	}
	return 0;	
}

int max_v(int now[15][15],int depth,int a,int b){
    int v;
    int vl[5],x[5],y[5];
	int copy[15][15];
	for(int t=0;t<15;t++){
		for(int k=0;k<15;k++){
			copy[t][k]=now[t][k];
		}
	}
	if(depth<=0||win(copy)!=0){
		int v_f;
		if(win(copy)==1){
			v_f=-minmax;
		}
		else if(win(copy)==-1){
			v_f=minmax;
		}
		else{
			v_f=value_com(copy)-value_player(copy);
		}
		return v_f;
	}
	for(int i=0;i<5;i++){
		vl[i]=-maxmax;
		x[i]=15;
		y[i]=15;
	}
	int best=-maxmax;
	for(int i=0;i<15;i++){
		for(int j=0;j<15;j++){
			if(now[i][j]==0&&nearb(i,j)==1){
				now[i][j]=-1;
				for(int t=0;t<15;t++){
			        for(int k=0;k<15;k++){
				        copy[t][k]=now[t][k];
			        }
		        }
				v=value_com(copy)-value_player(copy);
				for(int t=0;t<5;t++){
					if(vl[t]<v||(vl[t]==v&&abs(i-7)+abs(j-7)<abs(x[t]-7)+abs(y[t]-7))){
						for(int k=4;k>t;k--){
							vl[k]=vl[k-1];
							x[k]=x[k-1];
							y[k]=y[k-1];
						}
						vl[t]=v;
						x[t]=i;
						y[t]=j;
					}
				}
				now[i][j]=0;
			} 
		}
	} 
	for(int i=0;i<5;i++){
		if(x[i]<15){
		now[x[i]][y[i]]=-1;
		for(int t=0;t<15;t++){
			for(int k=0;k<15;k++){
				copy[t][k]=now[t][k];
			}
		}
		vl[i]=min_v(copy,depth-1,a,b);
		if(vl[i]<a){
			a=vl[i];
		}
		now[x[i]][y[i]]=0;
		if(vl[i]>best){
			best=vl[i];
			//cout<<x[i]<<" "<<y[i]<<" depth:"<<depth<<" value:"<<vl[i]<<endl;
		}
		if(vl[i]<b){
			return best;
		}
	}
	}
	return best;
}

int min_v(int now[15][15],int depth,int a,int b){
    int v;
    int vl[5],x1[5],y1[5];
	int copy[15][15];
	for(int t=0;t<15;t++){
		for(int k=0;k<15;k++){
			copy[t][k]=now[t][k];
		}
	}
	if(depth<=0||win(copy)!=0){
		int v_f;
		if(win(copy)==1){
			v_f=-minmax;
		}
		else if(win(copy)==-1){
			v_f=minmax;
		}
		else{
			v_f=value_com(copy)-value_player(copy);
		}
		return v_f;
	}
	for(int i=0;i<5;i++){
		vl[i]=maxmax;
		x1[i]=15;
		y1[i]=15;
	}
	int best=maxmax; 
	for(int i=0;i<15;i++){
		for(int j=0;j<15;j++){
			if(now[i][j]==0&&nearb(i,j)==1){
				now[i][j]=1;
				for(int t=0;t<15;t++){
			        for(int k=0;k<15;k++){
				        copy[t][k]=now[t][k];
			        }
		        }
				v=value_com(copy)-value_player(copy);
				for(int t=0;t<5;t++){
					if(vl[t]>v||(vl[t]==v&&abs(i-7)+abs(j-7)<abs(x1[t]-7)+abs(y1[t]-7))){
						for(int k=4;k>t;k--){
							vl[k]=vl[k-1];
							x1[k]=x1[k-1];
							y1[k]=y1[k-1];
						}
						vl[t]=v;
						x1[t]=i;
						y1[t]=j;
					}
				}
				now[i][j]=0;
			} 
		}
	} 
	for(int i=0;i<5;i++){
		if(x1[i]<15){
		now[x1[i]][y1[i]]=1;
		for(int t=0;t<15;t++){
			for(int k=0;k<15;k++){
				copy[t][k]=now[t][k];
			}
		}
		vl[i]=max_v(copy,depth-1,a,b);
		if(vl[i]>b){
			b=vl[i];
		}
		now[x1[i]][y1[i]]=0;
		if(vl[i]<best){
			best=vl[i];
			//if(depth==2)cout<<x1[i]<<" "<<y1[i]<<" value:"<<vl[i]<<endl;
		}
		if(vl[i]<a){
			return best;
		}
	}
	}
	return best;
}
  
void com_play(int now[15][15]){
	int player,comp;
	int computer,max;
	int x[5],y[5],vl[5]; 
	int v;
	int copy[15][15];
	max=-maxmax;
	for(int i=0;i<5;i++){
		vl[i]=max;
		x[i]=15;
		y[i]=15;
	}
	for(int i=0;i<15;i++){
		for(int j=0;j<15;j++){
			if(now[i][j]==0&&nearb(i,j)==1){
				now[i][j]=-1;
				for(int t=0;t<15;t++){
			        for(int k=0;k<15;k++){
				        copy[t][k]=now[t][k];
			        }
		        }
				v=value_com(copy)-value_player(copy);
				for(int t=0;t<5;t++){
					if(vl[t]<v||(vl[t]==v&&abs(i-7)+abs(j-7)<abs(x[t]-7)+abs(y[t]-7))){
						for(int k=4;k>t;k--){
							vl[k]=vl[k-1];
							x[k]=x[k-1];
							y[k]=y[k-1];
						}
						vl[t]=v;
						x[t]=i;
						y[t]=j;
					}
				}
				now[i][j]=0;
			} 
		}
	} 
	for(int i=0;i<5;i++){
		if(x[i]<15){
		now[x[i]][y[i]]=-1;
		for(int t=0;t<15;t++){
			for(int k=0;k<15;k++){
				copy[t][k]=now[t][k];
			}
		}
		vl[i]=min_v(copy,6,maxmax,-maxmax);
		//cout<<vl[i]<<endl;
		now[x[i]][y[i]]=0;
		if(vl[i]>max){
			max=vl[i];
			c_x=x[i];
			c_y=y[i];
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
	return valuep/2;
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
	            while((now[i][j]==k||(now[i][j]==0&&now[i][j+1]==k&&num==0&&j<14))&&j<15){
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
	        if(value_i>=1000&&num==0)value_i=value_i*2;
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
	            while((now[i][j]==k||(now[i][j]==0&&now[i+1][j]==k&&num==0&&i<14))&&i<15){
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
	        if(value_i>=1000&&num==0)value_i=value_i*2;
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
	            while((now[i+k][j+k]==p_c||(now[i+k][j+k]==0&&now[i+k+1][j+k+1]==p_c&&num==0&&(k<14-abs(t))))&&k<15-abs(t)){
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
	        if(value_i>=1000&&num==0)value_i=value_i*2;
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
	            while((now[i-k][j+k]==p_c||(now[i-k][j+k]==0&&now[i-k-1][j+k+1]==p_c&&num==0&&k<14-abs(14-t)))&&k<15-abs(14-t)){
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
	        if(value_i>=1000&&num==0)value_i=value_i*2;
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
