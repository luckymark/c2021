//RSA

#include <bits/stdc++.h>
#include <time.h>
#include <windows.h>
using namespace std;
#define maxn 100001
#define LL long long
LL p, q, n, phi, e, d;
LL code[maxn], encode[maxn];

inline LL fast_pow(LL s, LL t)
{
    LL base = s, ans = 1;
    while (t)
    {
        if (t % 2)
        {
            ans = ans * base % n;
            --t;
        }
        t >>= 1;
        base = base * base % n;
    }
    return ans;
}

LL prime()
{
    LL k = rand() % 100 + 2;
    if (k == p)
        return prime();
    for (LL i = 2; i <= sqrt(p); ++i)
        if (!(k % i))
            return prime();
    return k;
}

LL gcd(LL a, LL b)
{
    if (a < b)
        swap(a, b);
    if (b == 0)
        return a;
    return gcd(b, a % b);
}
LL exgcd(LL a, LL b, LL &x, LL &y)
{
    if (!b)
    {
        x = 1;
        y = 0;
        return a;
    }
    LL r = exgcd(b, a % b, x, y);
    LL temp = y;
    y = x - (a / b) * y;
    x = temp;
    return r;
}

void init()
{
    p = prime();
    q = prime();
    n = p * q;
    phi = (p - 1) * (q - 1);
    for (LL i = 2; i <= phi - 1; ++i)
    {
        if (gcd(i, phi) == 1)
        {
            e = i;
            break;
        }
    }
    LL y;
    exgcd(e, phi, d, y);
    d = abs(d);
}

inline const LL Encode(LL s)
{
    return fast_pow(s, e);
}

inline const LL Decode(LL c)
{
    return fast_pow(c, d);
}

int main()
{
    //freopen("in.txt", "r", stdin);
    srand(time(NULL));
    init();
    string s, k;
    while (getline(cin, k))
        s.append(k);
    cout << "the string is:" << endl
         << s;
    cout << endl
         << "after coding, the string now is:" << endl;
    for (int i = 0; i < (int)s.size(); ++i)
    {
        code[i] = (LL)s[i];
        encode[i] = Encode(code[i]);
        cout << code[i] << ' ';
    }
    cout << endl
         << "after encoding, the string now is:" << endl;
    for (int i = 0; i < (int)s.size(); ++i)
        cout << encode[i] << ' ';
    cout << endl
         << "after decoding, the string now is:" << endl;
    for (int i = 0; i < (int)s.size(); ++i)
        cout << Decode(encode[i]) << ' ';
    cout << endl
         << "then the string was recoding now:" << endl;
    for (int i = 0; i < (int)s.size(); ++i)
        putchar(char(Decode(encode[i])));
    return 0;
}