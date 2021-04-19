/*
  Problem Name:次小生成树
  algorithm tag:图论,LCA的综合应用，最小生成树，次小生成树
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

const int N = 1e5 + 5, M = N * 2, E = 3e5 + 5;
int n, m;
int p[N], h[N], ne[M], w[M], e[M], idx;
int fa[N][20], d1[N][20], d2[N][20];
int dep[N];
struct Edge
{
    int a, b, w;
    bool used;
    bool const operator<(const Edge &W)
    {
        return w < W.w;
    }
} edge[E];

void add(int a, int b, int c)
{
    e[idx] = b;
    ne[idx] = h[a];
    w[idx] = c;
    h[a] = idx++;
}
int find(int x)
{
    if (p[x] != x)
        p[x] = find(p[x]);
    return p[x];
}
ll kruskal()
{
    sort(edge + 1, edge + 1 + m);
    for (int i = 1; i <= n; i++)
        p[i] = i;
    ll res = 0;
    for (int i = 1; i <= m; i++) {
        int a = edge[i].a, b = edge[i].b, w = edge[i].w;
        a = find(a), b = find(b);
        if (a != b) {
            res += w;
            p[a] = b;
            edge[i].used = 1;
        }
    }
    return res;
}
void build()
{
    memset(h, -1, sizeof h);

    for (int i = 1; i <= m; i++) {
        int a = edge[i].a, b = edge[i].b, w = edge[i].w;
        if (edge[i].used)
            add(a, b, w), add(b, a, w);
    }
}
void bfs()
{
    memset(dep, 0x3f, sizeof dep);
    queue<int> q;
    q.push(1);
    dep[1] = 1, dep[0] = 0;

    while (q.size()) {
        int u = q.front();
        q.pop();

        for (int i = h[u]; ~i; i = ne[i]) {
            int v = e[i];

            if (dep[v] > dep[u] + 1) {
                dep[v] = dep[u] + 1;
                q.push(v);
                fa[v][0] = u;
                d1[v][0] = w[i], d2[v][0] = -INF;
                for (int j = 1; j <= 16; j++) {
                    int anc = fa[v][j - 1];
                    fa[v][j] = fa[anc][j - 1];

                    int dis[4] = {d1[v][j - 1], d1[anc][j - 1], d2[v][j - 1], d2[anc][j - 1]};
                    //更新d1、d2[v][k]
                    d1[v][j] = d2[v][j] = -INF;
                    for (int k = 0; k < 4; k++) {
                        int d = dis[k];
                        if (d > d1[v][j])
                            d2[v][j] = d1[v][j], d1[v][j] = d;
                        else if (d != d1[v][k] && d > d2[v][j])
                            d2[v][j] = d;
                    }
                }
            }
        }
    }
}
int lca(int a, int b, int w)
{
    //倍增的区间最值存下来
    int cnt = 0;
    static int distance[300];

    if (dep[a] < dep[b])
        swap(a, b);

    for (int i = 16; i >= 0; i--) {
        if (dep[fa[a][i]] >= dep[b]) {
            distance[cnt++] = d1[a][i];
            distance[cnt++] = d2[a][i];
            a = fa[a][i];
        }
    }
    if (a != b) {
        for (int i = 16; i >= 0; i--) {
            if (fa[a][i] != fa[b][i]) {
                distance[cnt++] = d1[a][i];
                distance[cnt++] = d2[a][i];
                distance[cnt++] = d1[b][i];
                distance[cnt++] = d2[b][i];
                a = fa[a][i];
                b = fa[b][i];
            }
        }
        distance[cnt++] = d1[a][0];
        distance[cnt++] = d1[b][0];
    }
    int dist1 = -INF, dist2 = -INF;
    for (int i = 0; i < cnt; i++) {
        int d = distance[i];
        if (d > dist1)
            dist2 = dist1, dist1 = d;
        else if (d != dist1 && d > dist2)
            dist2 = d;
    }

    if (w > dist1)
        return w - dist1;
    else if (w > dist2)
        return w - dist2;
    return INF;
}

int main()
{
    iosf;
    cin >> n >> m;

    for (int i = 1; i <= m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        edge[i] = {a, b, c};
    }
    ll sum = kruskal();
    build();
    bfs();
    ll ans = 1e18;
    for (int i = 1; i <= m; i++)
        if (!edge[i].used) {
            int a = edge[i].a, b = edge[i].b, w = edge[i].w;
            ans = min(ans, sum + lca(a, b, w));
        }

    cout << ans << endl;
    return 0;
}