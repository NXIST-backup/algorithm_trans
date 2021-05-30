/*
  Problem Name:冗余路径
  algorithm tag:图论,Tarjan算法,桥,无向图的边双连通分量
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

//proof: 缩点将树中最长距离的两点加边，让两点再缩成为树，然后再加边，明显看出ans=(cnt+1)/2

const int N = 5e3 + 5, M = 1e4 + 5;
int n, m;
int h[N], e[M], ne[M], idx;
int dfn[N], low[N], dcc_cnt, timestamp, top;
int d[N], stk[N], id[N];
bool is_bridge[M];
void add(int a, int b)
{
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx++;
}
void tarjan(int u, int from)
{
    dfn[u] = low[u] = ++timestamp;
    stk[++top] = u;

    for (int i = h[u]; ~i; i = ne[i]) {
        int j = e[i];
        if (!dfn[j]) {
            tarjan(j, i);
            low[u] = min(low[u], low[j]);
            if (dfn[u] < low[j])
                is_bridge[i] = is_bridge[i ^ 1] = true;
        } else if (i != (from ^ 1))
            low[u] = min(low[u], dfn[j]);
    }
    if (dfn[u] == low[u]) {
        ++dcc_cnt;
        int y;
        do {
            y = stk[top--];
            id[y] = dcc_cnt;
        } while (y != u);
    }
}
int main()
{
    iosf;
    cin >> n >> m;
    memset(h, -1, sizeof h);
    for (int i = 1; i <= m; i++) {
        int a, b;
        cin >> a >> b;
        add(a, b), add(b, a);
    }

    tarjan(1, -1);

    for (int i = 0; i < idx; i++)
        if (is_bridge[i])
            d[id[e[i]]]++;
    int ans = 0;
    for (int i = 1; i <= dcc_cnt; i++)
        if (d[i] == 1)
            ans++;
    cout << (ans + 1) / 2 << endl;
}