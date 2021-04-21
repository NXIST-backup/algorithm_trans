/*
  Problem Name:受欢迎的牛
  algorithm tag:有向图强联通分量,Tarjan算法
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

const int N = 1e4 + 5, M = 5e4 + 5;
int n, m;
int h[N], e[M * 2], ne[M * 2], idx, h2[N];
int stk[N], id[N], top;
int low[N], dfn[N], scc_cnt, timestamp;
bool in_stk[N];
int dout[N];
void add(int a, int b, int h[])
{
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx++;
}

void tarjan(int u)
{
    dfn[u] = low[u] = ++timestamp;
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
            y = stk[top--];
            id[y] = scc_cnt;
            in_stk[y] = false;
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
        add(a, b, h);
    }
    for (int i = 1; i <= n; i++)
        if (!dfn[i])
            tarjan(i);
    int ans = 0;
    for (int u = 1; u <= n; u++) {
        for (int i = h[u]; ~i; i = ne[i]) {
            int v = e[i];
            if (id[u] != id[v])
                dout[id[u]]++;
        }
    }
    int flag = 0;
    for (int i = 1; i <= scc_cnt; i++)
        if (!dout[i])
            flag++;
    if (flag > 1)
        cout << 0 << endl;
    else {
        for (int i = 1; i <= n; i++)
            if (id[i] == 1)
                ans++;
        cout << ans << endl;
    }
    return 0;
}