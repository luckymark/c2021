/*只支持小写字母输入；输入的n,k小于10000，防止溢出；
* 思路：用整除26作映射替换。其中奇数位置和偶数位置用不同的方法。
* 密钥用于改变整除结果
*/
#include<iostream>
#include <string.h>
using namespace std;

const int N = 10000;//明文最大空间限制
char a1[26], a2[26];//密码本
int n = 0, k = 0;//n和k密钥

void encrypt();
void decrypt();

int main()
{
    for (int i = 0; i < 26; i++)
    {
        a1[i] = i + 'A';
        a2[i] = i + 'a';
    }
    encrypt();
    decrypt();
    return 0;
}

void encrypt()
{
    char plaintext_in[N] = { 0 };
    printf("请输入明文\n");
    gets_s(plaintext_in, N);
    int len = strlen(plaintext_in);
    printf("密钥1\n");
    cin >> n;
    printf("密钥2\n");
    cin >> k;
    int cnt1 = 0, cnt2 = 0;
    char group_1[N / 2] = { 0 }, group_2[N / 2] = { 0 };
    for (int i = 0; i < len; i++)//将输入的明文按位置的奇偶性，分成两组。注意和实际上的奇偶是错位的。
    {
        if (i % 2 != 0) group_1[cnt1++] = plaintext_in[i];
        else group_2[cnt2++] = plaintext_in[i];
    }

    int numberOfSections_1 = 0, numberOfSections_2 = 0;//将每一组的字符分成若干段，n和k是每一段的长度（如果这一段是完全的话）
    if (cnt2 % n == 0) numberOfSections_2 = cnt2 / n;
    else numberOfSections_2 = cnt2 / n + 1;
    if (cnt1 % k == 0)numberOfSections_1 = cnt1 / k;
    else numberOfSections_1 = cnt1 / k + 1;
    char encrypt_1[N / 2] = { 0 }, encrypt_2[N / 2] = { 0 }, ciphertext_out[N] = { 0 };
    int j = 0;
    for (int section = 0; section < numberOfSections_2; section++)//将偶数组进行映射。
    {
        for (int i = 0; i < n; i++)
        {
            encrypt_2[j++] = a1[(group_2[j] + n + k + section - 97) % 26];
            if (len / 2 + 1 == i) break;
        }
    }
    j = 0;
    for (int section = 0; section < numberOfSections_1; section++)//将奇数组进行映射。
    {
        for (int i = 0; i < k; i++)
        {
            encrypt_1[j] = a1[(group_1[j++] + n * k + section - 97) % 26];
            if (len / 2 + 1 == i)break;
        }
    }
    int i1 = 0, i2 = 0;
    for (int i = 0; i < len; i++)//组合加密后的奇数组和偶数组
    {
        if (i % 2 == 0) ciphertext_out[i] = encrypt_2[i2++];
        if (i % 2 == 1) ciphertext_out[i] = encrypt_1[i1++];
    }
    puts(ciphertext_out);//得到密文 
}
void decrypt()
{
    char ciphertext_in[N] = { 0 };
    char plaintext_out[N] = { 0 }, plaintext_2[N / 2] = { 0 }, plaintext_1[N / 2] = { 0 };
    printf("请输入密文\n");
    getchar();
    gets_s(ciphertext_in, N);
    printf("输入密钥1\n");
    cin >> n;
    printf("输入密钥2\n");
    cin >> k;
    int len = strlen(ciphertext_in);
    int cnt1 = 0, cnt2 = 0;
    char cipher_1[N / 2] = { 0 }, cipher_2[N / 2] = { 0 };
    for (int i = 0; i < len; i++)
    {
        if (i % 2 != 0)cipher_1[cnt1++] = ciphertext_in[i];
        else cipher_2[cnt2++] = ciphertext_in[i];
    }
    int numberOfSections_1 = 0, numberOfSections_2 = 0;//将每一组的字符分成若干段，n和k是每一段的长度（如果这一段是完全的话）
    if (cnt2 % n == 0) numberOfSections_2 = cnt2 / n;
    else numberOfSections_2 = cnt2 / n + 1;
    if (cnt1 % k == 0)numberOfSections_1 = cnt1 / k;
    else numberOfSections_1 = cnt1 / k + 1;

    int j = 0;
    for (int sections = 0; sections < numberOfSections_2; sections++)//偶数组解密
    {
        for (int i = 0; i < n; i++)
        {
            int tmp2 = (cipher_2[j] - n - k - sections - 65);
            while (tmp2 < 0)
            {
                tmp2 += 26;
            }
            plaintext_2[j++] = a2[(tmp2) % 26];
            if (i == len / 2 + 1)break;
        }
    }
    j = 0;
    for (int sections = 0; sections < numberOfSections_1; sections++)//奇数组解密
    {

        if (sections == 0)  j = 0;
        for (int i = 0; i < k; i++)
        {
            int tmp1 = (cipher_1[j] - n * k - sections - 65);
            while (tmp1 < 0)
            {
                tmp1 += 26;
            }
            plaintext_1[j++] = a2[(tmp1) % 26];
            if (i == len / 2 + 1)break;
        }
    }
    int i1 = 0, i2 = 0;
    for (int i = 0; i < len; i++)//组合解密了的奇数组和偶数组
    {
        if (i % 2 == 0) plaintext_out[i] = plaintext_2[i2], i2++;
        if (i % 2 == 1) plaintext_out[i] = plaintext_1[i1], i1++;
    }
    puts(plaintext_out);
}