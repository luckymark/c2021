#include <stdio.h>
#include <math.h>
int main()
{
	int m,s,t=0,k,i;
	printf("��λ��ˮ�ɻ����У�"); 
	for(m=100;m<1000;m++)
	{
	    k=m;
		s=0;//s��i��k��Ҫ��ʼ����ע���ʼ����λ��Ӧ����ѭ���ڻ�����	
		for(i=0;k>0;i++)
		{ 
			t=k%10;
			s+=pow(t,3);
			k=k/10;	
		}
		if(m==s)
		{
			printf("%d\t",m);
		}
	}
	
	return 0;
} 
