/*��ӡ������3λˮ�ɻ���
ˮ�ɻ�����nλ����ÿ����λ��n�η�֮�͵��ڸ�nλ������

���磺153=1^3+5^3+3^3*/
#include<bits/stdc++.h>
using namespace std;
int a,b,c,cnt;
int main()
{
	for(int i=100;i<1000;++i)
	{
		a=i/100;
		b=i/10%10;
		c=i%10;
		if(i==a*a*a+b*b*b+c*c*c)printf("��%d��ˮ�ɻ���:%d\n",++cnt,i);
	}
	return 0;
}
