/*
  Problem Name:距离
  algorithm tag:LCA,最近公共祖先，tarjan，
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

const int N = 1e4 + 5, M = N * 2;

int n, m, Q;
int h[N], ne[M], e[M], w[M], idx;
int dep[N];
int dist[N];
bool st[N];
int fa[N][16];
int root = 1;

void add(int a, int b, int c)
{
    e[idx] = b;
    ne[idx] = h[a];
    w[idx] = c;
    h[a] = idx++;
}

void dij()
{
    memset(dist, 0x3f, sizeof dist);
    priority_queue<pii, vector<pii>, greater<pii>> heap;
    dist[1] = 0, dep[1] = 1, dep[0] = 0;
    heap.push({0, 1});

    while (heap.size()) {
        int u = heap.top().second;
        int dis = heap.top().first;
        heap.pop();

        if (st[u])
            continue;
        st[u] = 1;

        for (int i = h[u]; ~i; i = ne[i]) {
            int v = e[i];

            if (dist[v] > dist[u] + w[i]) {
                dist[v] = dist[u] + w[i];
                dep[v] = dep[u] + 1;
                fa[v][0] = u;
                heap.push({dist[v], v});

                for (int i = 1; i <= 14; i++)
                    fa[v][i] = fa[fa[v][i - 1]][i - 1];
            }
        }
    }
}
int lca(int a, int b)
{
    if (dep[a] < dep[b])
        swap(a, b);

    for (int i = 14; i >= 0; i--)
        if (dep[fa[a][i]] >= dep[b])
            a = fa[a][i];
    if (a == b)
        return a;

    for (int i = 14; i >= 0; i--) {
        if (fa[b][i] != fa[a][i]) {
            a = fa[a][i];
            b = fa[b][i];
        }
    }

    return fa[a][0];
}

int main()
{
    iosf;
    cin >> n >> Q;
    memset(h, -1, sizeof h);
    for (int i = 1; i < n; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        add(a, b, c);
        add(b, a, c);
    }
    dij();

    while (Q--) {
        int a, b;
        cin >> a >> b;

        cout << dist[a] + dist[b] - dist[lca(a, b)] * 2 << endl;
    }
    return 0;
}
