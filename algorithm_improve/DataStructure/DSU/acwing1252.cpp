/*
  Problem Name:搭配购买
  algorithm tag:并查集,01背包问题
*/

#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <unordered_map>
#include <vector>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;
const double eps = 1e-4;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
//#define x first
//#define y second
#define iosf ios::sync_with_stdio(false), cin.tie(0), cout << fixed

const int N = 1e4 + 5;
int val[N], w[N], dp[N];
int n, m, V;
int p[N];
bool st[N];
int find(int x)
{
    if (p[x] != x)
        p[x] = find(p[x]);
    return p[x];
}

int main()
{
    iosf;
    cin >> n >> m >> V;

    for (int i = 1; i <= n; i++)
        cin >> val[i] >> w[i];

    for (int i = 1; i <= n; i++)
        p[i] = i;

    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        u = find(u), v = find(v);
        if (u < v)
            swap(u, v);
        if (u != v)
            p[u] = v, w[v] += w[u], val[v] += val[u];
    }

    for (int i = 1; i <= n; i++) {
        if (!st[find(i)])
            for (int j = V; j >= val[i]; j--)
                dp[j] = max(dp[j], dp[j - val[i]] + w[i]);
        st[i] = true;
    }

    cout << dp[V] << endl;
}