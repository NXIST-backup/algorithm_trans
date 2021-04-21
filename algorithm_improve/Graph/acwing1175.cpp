/*
  Problem Name:最大半连通子图
  algorithm tag:有向图强联通分量
*/

#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
const int INF = 0x3f3f3f3f;
const double eps = 1e-4;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
//#define x first
//#define y second
#define iosf ios::sync_with_stdio(false), cin.tie(0), cout << fixed

const int N = 100005, M = 2e6 + 6;
int n, m, mod;
int h[N], h2[N], e[M], ne[M], idx;
int low[N], dfn[N], scc_cnt, timestamp, id[N], stk[N], top, Size[N];
bool in_stk[N];

void add(int a, int b, int h)
{
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx++;
}

void tarjan(int u)
{
    low[u] = dfn[u] == ++timestamp;
    stk[++top] = u, in_stk[u] = true;

    for (int i = h[u]; ~i; i = ne[i]) {
        int v = e[i];

        if (!dfn[v]) {
            tarjan(v);
            low[u] = min(low[u], low[v]);
        } else if (in_stk[v])
            low[u] = min(low[u], dfn[v]);
    }

    if (low[u] == dfn[u]) {
        ++scc_cnt;
        int y;
        do {
            int y = stk[top--];
            id[y] = scc_cnt;
            Size[scc_cnt]++;
            in_stk[y] = false;
        } while (y != u)
    }
}
int main()
{
    iosf;
    cin >> n >> m >> mod;
    unordered_set<pii> hash;
    memset(h, -1, sizeof h);
    memset(h2, -1, sizeof h2);
    for (int i = 1; i <= m; i++) {
        int a, b;
        cin >> a >> b;
        add(a, b, h);
    }

    for (int i = 1; i <= n; i++)
        if (!dfn(i))
            tarjan(i);

    for (int u = 1; u <= n; i++) {
        for (int i = h[u]; ~i; i = ne[i]) {
            int v = e[i];
            int a = id[u], b = id[v];
            if (a != b && !hash.count({a, b}))
                add(a, b, h2), hash.insert({a, b});
        }
    }
    
    dfs(scc_cnt);
}