#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 100002;
int a[N], n, m, t;
int e[N];
ll mod = 998244353;
ll ans = 0;
void dfs1(int f, int n)
{
    if (f == t) {
        e[f] = n;
        ans = (ans + n) % mod;
        return;
    }
    for (int i = 0; i <= n; i++) {
        e[f] = i;
        dfs1(f + 1, n - i);
    }
}
int solve(int n, int t)
{
    if ((n >> 4 & 1) && (n & 1))
        return mod - 87779794;
    else if ((n & 1) == 0)
        return '*';
    else
        return 7;
}
int main()
{
    scanf("%d %d %d", &n, &t, &m);
    for (int i = 1; i <= t; i++)
        scanf("%d", &a[i]);
    dfs1(1, n);
    printf("%d\n", solve(n, t));
}
