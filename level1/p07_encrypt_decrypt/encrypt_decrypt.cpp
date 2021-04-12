#include <ctime>
#include <iostream>

using namespace std;

using ull = unsigned long long;

const int MAX_N = 700;  //不能太大

ull k, d, e, n, fn;

inline ull gcd(ull a, ull b) { return b == 0 ? a : gcd(b, a % b); }  //求最大公约数

ull powMod(ull base, ull pow, ull mod) {  //幂模运算
    ull res = 1;

    while (pow) {
        if (pow & 1) res = (res * base) % mod;
        pow >>= 1;
        base = (base * base) % mod;
    }
    return res;
}

void allPrimes(int *list, int &cnt) {  //寻找质数
    int i, n;

    for (n = 2; n < MAX_N; ++n) {
        for (i = 0; i < cnt; ++i)
            if (n % list[i] == 0) goto end;
        list[cnt++] = n;
    end:
        continue;
    }
}

void RSA_Initialize() {  //简易RSA算法加密初始化
    int Primes[MAX_N / 5];
    int cnt = 0;
    allPrimes(Primes, cnt);
    cnt /= 2;
    srand((unsigned)time(NULL));
    int p = Primes[rand() % cnt + cnt], q = Primes[rand() % cnt + cnt];
    n = p * q, fn = (p - 1) * (q - 1);

    e = 7, k = 7;
    while (gcd(e, fn) != 1) e += 777;
    d = k * fn + 1;

    cout << "公开的: n = " << n << "  e = " << e << endl;  //公开n, e
    cout << "不公开的: d = " << d << endl;
}

void encrypt(wstring ws, int e, int n) {  //加密
    for (int i = 0; i < ws.size(); ++i) {
        wcout << powMod(ws[i], e, n) << ' ';  //输出密文
        ws[i] = powMod(ws[i], e, n);
    }
    wcout << endl;
}

void decrypt(wstring ws, int d, int n) {  //解密
    for (int i = 0; i < ws.size(); ++i) {
        wcout << powMod(ws[i], d, n) << ' ';  //输出明文
        ws[i] = powMod(ws[i], d, n);
    }
    wcout << endl;
}

int main() {
    wstring wstr = L"bilibili.com/video/BV1FX4y1g7u8";

    for (int i = 0; i < wstr.size(); ++i) wcout << wstr[i];
    cout << endl;

    // RSA
    RSA_Initialize();
    encrypt(wstr, e, n);
    cout << endl;
    decrypt(wstr, d, n);

    for (int i = 0; i < wstr.size(); ++i) wcout << (wchar_t)wstr[i];
    cout << endl;

    return 0;
}