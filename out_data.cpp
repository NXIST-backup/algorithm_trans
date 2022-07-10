
#include <bits/stdc++.h>
using namespace std;

#define int long long
const int SIZE = 200050;
const int mod = 1e9 + 7;

inline int read()
{
    int x = 0, f = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9') {
        if (ch == '-')
            f = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9') {
        x = (x << 1) + (x << 3) + (ch ^ 48);
        ch = getchar();
    }
    return f * x;
}

int n, ans;
int num[SIZE], siz[SIZE];

inline int quickpow(int a, int b)
{
    int res = 1;
    int base = a;
    while (b) {
        if (b & 1)
            res = res * base % mod;
        base = base * base % mod;
        b >>= 1;
    }
    return res;
}

inline int get_C(int a, int b)
{
    return siz[b] * quickpow(siz[a], mod - 2) % mod * quickpow(siz[b - a], mod - 2) % mod;
}

inline void solve_0()
{
    int top = (n - 2) / 2, opt = 1;
    for (int i = 1; i <= n; ++i) {
        ans += (get_C((i - 1) / 2, top) * opt * num[i]) % mod;
        ans = (ans + mod) % mod;
        opt = opt * -1;
    }
}

inline void solve_1()
{
    int top = (n - 1) / 2;
    bool opt = true;
    for (int i = 1; i <= n; ++i) {
        if (opt) {
            ans = (ans + get_C((i - 1) / 2, top) * num[i]) % mod;
            ans = (ans + mod) % mod;
            opt = false;
            continue;
        }
        opt = true;
    }
}

inline void solve_2()
{
    int top = (n - 2) / 2;
    for (int i = 1; i <= n; ++i) {
        ans += (get_C((i - 1) / 2, top) * num[i]) % mod;
        ans = (ans + mod) % mod;
    }
}

inline void solve_3()
{
    bool opt = true;
    for (int i = 1; i <= n; ++i) {
        if (opt) {
            num[i] = (num[i] + num[i + 1]) % mod;
        } else {
            num[i] = (num[i] - num[i + 1]) % mod;
        }
        opt = opt ^ true;
    }
    n--;
    solve_2();
}

signed main()
{
    // freopen("14.in","r",stdin);
    // freopen("14.out","w",stdout);
    n = read();
    for (int i = 1; i <= n; ++i) {
        num[i] = read();
    }
    siz[0] = siz[1] = 1;
    for (int i = 2; i <= n; ++i) {
        siz[i] = siz[i - 1] * i % mod;
    }
    bool opt = true;
    switch (n % 4) {
        case 0:
            solve_0();
            break;
        case 1:
            solve_1();
            break;
        case 2:
            solve_2();
            break;
        case 3:
            solve_3();
            break;
    }
    printf("%lld\n", ans);
}
