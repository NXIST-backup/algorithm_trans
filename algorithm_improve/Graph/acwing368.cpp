/*
  Problem Name:银河
  algorithm tag:图论,Tarjan算法,有向图的强连通分量,SPFA,差分约束
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

const int N = 1e5 + 5, M = 2e5 + 5;
int n, m;
int h[N], e[M], ne[M], w[M], idx;
int low[N], dfn[N], scc_cnt, stamp, id[N], stk[N];
bool in_stk[N];

void add(int a, int b, int c)
{
    e[idx] = b;
    ne[idx] = h[a];
    w[idx] = c;
    h[a] = idx++;
}

int main()
{
    iosf;
    cin >> n >> m;
    memset(h, -1, sizeof h);
    for (int i = 1; i <= m; i++) {
        int t, a, b;
        cin >> t >> a >> b;
        if (t == 1)
            add(a, b, 0), add(b, a, 0);
        else if (t == 2)
            add(a, b, 1);
        else if (t == 3)
            add(b, a, 0);
        else if (t == 4)
            add(b, a, 1);
        else
            add(a, b, 0);
    }

    for (int i = 1; i <= n; i++)
        add(0, i, 1);
}
