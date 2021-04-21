/*
  Problem Name:学校网络
  algorithm tag:图论,Tarjan算法,有向图的强连通分量
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

const int N = 105, M = N * N * 2;
int n;
int h[N], e[M], ne[M], idx, h2[N];
int low[N], dfn[N], scc_cnt, id[N], timestamp, stk[N], top;
bool in_stk[N];
int din[N], dout[N];
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
            low[u] = min(low[v], low[u]);
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
    cin >> n;
    memset(h, -1, sizeof h);
    memset(h2, -1, sizeof h2);
    for (int i = 1; i <= n; i++) {
        int x;
        while (cin >> x, x)
            add(i, x, h);
    }
    int num = 0;
    for (int i = 1; i <= n; i++)
        if (!dfn[i]) {
            num++;
            tarjan(i);
        }

    for (int u = 1; u <= n; u++)
        for (int i = h[u]; ~i; i = ne[i]) {
            int v = e[i];
            int a = id[u], b = id[v];
            if (a != b) {
                add(a, b, h2);
                din[b]++;
                dout[a]++;
            }
        }

    int res = 0, ans = 0;
    for (int i = 1; i <= scc_cnt; i++) {
        if (!din[i])
            res++;
        if (dout[i] == 0)
            ans++;
    }

    cout << res << endl;
    if (scc_cnt == 1)
        cout << 0 << endl;
    else
        cout << max(ans, res) << endl; //notice:若想DAG变成一个强连通分量，需要max(din,dout)条边
}