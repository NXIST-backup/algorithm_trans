#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 20000002;
ll fac[N], mod = 1e9 + 7;
ll qpow(ll n, ll m)
{
    ll ans = 1;
    for (; m; m >>= 1) {
        if (m & 1)
            ans = ans * n % mod;
        n = n * n % mod;
    }
    return ans;
}
int main()
{
    int n;
    scanf("%d", &n);
    n = n / 2 + 1;
    int m = 2 * n - 1;
    fac[0] = 1;
    for (int i = 1; i <= m; i++)
        fac[i] = fac[i - 1] * i % mod;
    ll ans = fac[m] * qpow(fac[n - 1], mod - 2) % mod * qpow(fac[n], mod - 2) % mod;
    printf("%lld\n", ans);
}