/*编程解决下面的问题：
取自《希腊诗选》（Greek Anthology）：

丢番图的童年经过了他一生的六分之一，
青年经过了十二分之一，
又有七分之一的时间是单身汉。
结婚五年后得了个儿子，
儿子比父亲先死四年，
年级是他的一半。
问儿子死时丢番图多大？*/
#include<bits/stdc++.h>
using namespace std;
int age;
int main()
{
	for(int i=1;;++i)
		if(i*1.0/6+i*1.0/12+i*1.0/7+5+4+i*1.0/2==i){age=i;break;
		}
	cout<<age-4<<endl;
	return 0;
}
