#include<bits/stdc++.h>
using namespace std;
void hano(int n,char a,char b,char c)//n是准备移动的块数，a是起始柱，b是中间柱，c是目标柱； 
{
	if(n==0) return;
	hano(n-1,a,c,b);//先将第n个盘子上的n-1个盘子从a移到b；
	printf("将第%d号盘子从%c柱移动到%c柱\n",n,a,c);
	hano(n-1,b,c,a);//再将n-1个盘子从b移到c，完成任务； 
}
int main()
{
	cout<<"请输入盘子总数：";
	int n;
	cin>>n;
	hano(n,'A','B','C');
	return 0;
} 
