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
 
