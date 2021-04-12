/*
  Problem Name:秘密的牛奶运输
  algorithm tag:最小生成树扩展，次小生成树，kruskal
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

const int N = 505, M = 1e4 + 5;
int n, m;
int fa[N];
bool state[M];
int dist1[N][N], dist2[N][N];
int h[N], e[M], ne[M], w[M], idx;
bool st[N];
struct Edge
{
    int a, b, w;

    bool operator<(const Edge &W) const
    {
        return w < W.w;
    }
} edges[M];
int find(int x)
{
    if (fa[x] != x)
        fa[x] = find(fa[x]);
    return fa[x];
}
void add(int a, int b, int c)
{
    e[idx] = b;
    ne[idx] = h[a];
    w[idx] = c;
    h[a] = idx++;
}
void dfs(int u, int fa, int maxd1, int maxd2, int d1[], int d2[])
{
    d1[u] = maxd1, d2[u] = maxd2;
    for (int i = h[u]; ~i; i = ne[i]) {
        int j = e[i];
        if (j != fa) {
            int td1 = maxd1, td2 = maxd2;
            if (w[i] > td1)
                td2 = td1, td1 = w[i];
            else if (w[i] < td1 && w[i] > td2)
                td2 = w[i];
            dfs(j, u, td1, td2, d1, d2);
        }
    }
}

int main()
{
    iosf;
    cin >> n >> m;
    memset(h, -1, sizeof h);

    for (int i = 1; i <= n; i++)
        fa[i] = i;
    for (int i = 1; i <= m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        edges[i] = {a, b, c};
    }
    sort(edges + 1, edges + 1 + m);
    ll res = 0;
    for (int i = 1; i <= m; i++) {
        int a = edges[i].a, b = edges[i].b, w = edges[i].w;

        int x = find(a), y = find(b);

        if (x != y) {
            res += w;
            state[i] = 1;
            fa[x] = y;
            add(a, b, w), add(b, a, w);
        }
    }
    ll ans = 1e18, tmp = res;
    for (int i = 1; i <= n; i++)
        dfs(i, -1, -1e9, -1e9, dist1[i], dist2[i]);

    for (int i = 1; i <= m; i++) {
        if (!state[i]) {
            int a = edges[i].a, b = edges[i].b, w = edges[i].w;
            if (w > dist1[a][b])
                res += w - dist1[a][b];
            else if (w > dist2[a][b])
                res += w - dist2[a][b];
            ans = min(res, ans);
            res = tmp;
        }
    }

    cout << ans << endl;
}