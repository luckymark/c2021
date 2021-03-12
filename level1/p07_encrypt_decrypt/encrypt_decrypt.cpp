/*只支持小写字母输入；输入的n,k英小于10000，防止溢出；
* 思路：用整除26作映射替换。其中奇数位置和偶数位置用不同的方法。
*/

#include<iostream>
#include <string.h>
using namespace std;
const int num = 10000;//明文最大空间限制
char a1[26] = { 'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z' };//加密用字母表
char a2[26] = { 'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z' };//解密用
char x[num] = { 0 };//储存明文
char x1[num / 2] = { 0 }, x2[num / 2] = { 0 }, x11[num / 2] = { 0 }, x22[num / 2] = { 0 }, mx[num] = { 0 }, jx[num] = { 0 }, jx2[num / 2] = { 0 }, jx22[num / 2] = { 0 }, jx1[num / 2] = { 0 }, jx11[num / 2] = { 0 }, jmx[num] = { 0 };
int n = 0, k = 0;//n和k密钥
int cnt1 = 0, jcnt1 = 0;
int cnt2 = 0, jcnt2 = 0;
void jiami()
{
    printf("请输入明文\n");
    gets_s(x, num);
    int len = strlen(x);
    printf("密匙n\n");
    cin >> n;
    printf("密匙k\n");
    cin >> k;
    for (int i = 0; i < len; i++)//分离奇数组和偶数组
    {
        if (i % 2 == 0)
        {
            x2[cnt2] = x[i];
            cnt2++;
        }
        else
        {
            x1[cnt1] = x[i];
            cnt1++;
        }
    }
    int duan1 = 0, duan2 = 0;//为加密做准备，判断最后一段不能整除也应算做一小段
    if (cnt1 % k == 0)
        duan1 = cnt1 / k;
    else
        duan1 = cnt1 / k + 1;
    if (cnt2 % n == 0)
        duan2 = cnt2 / n;
    else
        duan2 = cnt2 / n + 1;
    int qwq2 = 0;
    int qwq1 = 0;
    for (int duan = 0; duan < duan2; duan++)//对偶数组加密
    {
        for (int i = 0; i < n; i++)
        {
            x22[qwq2] = a1[(x2[qwq2] + n + k + duan - 97) % 26];
            qwq2++;
        }
    }
    for (int duan = 0; duan < duan1; duan++)//对奇数组加密
    {
        for (int i = 0; i < k; i++)
        {
            x11[qwq1] = a1[(x1[qwq1] + n * k + duan - 97) % 26];
            qwq1++;
        }
    }
    int i1 = 0, i2 = 0;
    for (int i = 0; i < len; i++)//组合加密后的奇数组和偶数组
    {

        if (i % 2 == 0)
        {
            mx[i] = x22[i2], i2++;
        }

        if (i % 2 == 1)
        {
            mx[i] = x11[i1], i1++;
        }

    }
    puts(mx);//得到密文 
}
void jiemi()
{
    ///////////////////
    //解密
    printf("请输入密文\n");
    getchar();
    gets_s(jmx, num);
    printf("密匙n\n");
    cin >> n;
    printf("密匙k\n");
    cin >> k;
    int len = strlen(jmx);
    for (int i = 0; i < len; i++)//分离密文的奇数组和偶数组
    {
        if (i % 2 == 0)
        {
            jx2[jcnt2] = jmx[i];
            jcnt2++;
        }
        else
        {
            jx1[jcnt1] = jmx[i];
            jcnt1++;
        }
    }
    int jduan1 = 0, jduan2 = 0;//准备解密，同上，判断最后一段划分的问题
    if (cnt1 % k == 0)
        jduan1 = jcnt1 / k;
    else
        jduan1 = jcnt1 / k + 1;
    if (cnt2 % n == 0)
        jduan2 = jcnt2 / n;
    else
        jduan2 = jcnt2 / n + 1;
    int jqwq2 = 0, jqwq1 = 0, tmp1, tmp2;
    for (int duan = 0; duan < jduan2; duan++)//偶数组解密
    {
        for (int i = 0; i < n; i++)
        {

            tmp2 = (jx2[jqwq2] - n - k - duan - 65);
            while (1)
            {
                if (tmp2 < 0)
                {
                    tmp2 = tmp2 + 26;
                }
                else
                {
                    break;
                }
            }
            jx22[jqwq2] = a2[(tmp2) % 26];
            jqwq2++;
        }
    }
    for (int duan = 0; duan < jduan1; duan++)//奇数组解密
    {
        for (int i = 0; i < k; i++)
        {
            tmp1 = (jx1[jqwq1] - n * k - duan - 65);
            while (1)
            {
                if (tmp1 < 0)
                {
                    tmp1 = tmp1 + 26;
                }
                else
                {
                    break;
                }
            }
            jx11[jqwq1] = a2[(tmp1) % 26];
            jqwq1++;
        }
    }
    int i1 = 0, i2 = 0;
    for (int i = 0; i < len; i++)//组合解密了的奇数组和偶数组
    {
        if (i % 2 == 0)
            jx[i] = jx22[i2], i2++;
        if (i % 2 == 1)
            jx[i] = jx11[i1], i1++;
    }
    puts(jx);//得到明文
}
int main()
{
    jiami();
    jiemi();
    return 0;
}
