/*
  Problem Name:牛站
  algorithm tag:类floyd,矩阵乘法,快速幂,倍增
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
const int INF = 1e9;
const int mod = 1e9 + 7;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
//#define x first
//#define y second
#define iosf ios::sync_with_stdio(false), cin.tie(0), cout << fixed

const int N = 205;
int g[N][N];
int n, m, S, E, k;
map<int, int> mp;
int res[N][N];

void mul(int c[][N], int a[][N], int b[][N])
{
    static int temp[N][N];
    memset(temp, 0x3f, sizeof temp);

    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                temp[i][j] = min(temp[i][j], a[i][k] + b[k][j]);

    memcpy(c, temp, sizeof temp);
}

void qmi()
{
    memset(res, 0x3f, sizeof res);
    for (int i = 1; i <= n; i++)
        res[i][i] = 0;

    while (k) {
        if (k & 1)
            mul(res, res, g);
        mul(g, g, g);
        k >>= 1;
    }
}

int main()
{
    iosf;
    cin >> k >> m >> S >> E;
    if (!mp.count(S))
        mp[S] = ++n;
    if (!mp.count(E))
        mp[E] = ++n;
    S = mp[S], E = mp[E];
    memset(g, 0x3f, sizeof g);
    for (int i = 1; i <= m; i++) {
        int c, a, b;
        cin >> c >> a >> b;
        if (!mp.count(a))
            mp[a] = ++n;
        if (!mp.count(b))
            mp[b] = ++n;
        a = mp[a], b = mp[b];
        g[a][b] = g[b][a] = min(g[a][b], c);
    }
    qmi();

    cout << res[S][E] << endl;
}