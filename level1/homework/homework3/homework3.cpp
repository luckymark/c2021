#include<stdio.h>

int main()
{
	float allAge=-1,youth=-1,teenage=-1,danShen=-1,haveSon=-1,sonDie=-1;
	do
	{
		allAge++;
		youth = allAge / 6;
		teenage = youth + allAge / 12;
		danShen = teenage + allAge / 7;
		haveSon = danShen + 5;
		sonDie = allAge - 4;
	} while (allAge / 2 != sonDie - haveSon);
	printf("%f", allAge);
}