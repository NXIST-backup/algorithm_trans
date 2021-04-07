/*
  Problem Name:最优贸易
  algorithm tag:DP,spfa,dijkstra,分层图
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
#define x first
#define y second
#define iosf ios::sync_with_stdio(false), cin.tie(0), cout << fixed
//dijkstra做法

const int N = 1e5 + 5, M = 1e6 + 5;
int h[N], hb[N], e[M], ne[M], idx;
int val[N];
int n, m;
bool is_valid[N];
int dist[N];
bool st[N];

void add(int h[], int a, int b)
{
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx++;
}
void dfs(int u)
{
    is_valid[u] = 1;

    for (int i = hb[u]; ~i; i = ne[i]) {
        int j = e[i];
        if (!is_valid[j])
            dfs(j);
    }
}
void dij()
{
    memset(dist, 0x3f, sizeof dist);
    priority_queue<pii, vector<pii>, greater<pii>> heap;
    for (int i = 1; i <= n; i++) {
        dist[i] = val[i];
        heap.push({dist[i], i});
    }

    while (heap.size()) {
        int u = heap.top().y;
        heap.pop();

        if (st[u])
            continue;
        st[u] = 1;

        for (int i = h[u]; ~i; i = ne[i]) {
            int v = e[i];

            if (dist[v] > dist[u]) {
                dist[v] = dist[u];
                heap.push({dist[v], v});
            }
        }
    }
}
int main()
{
    iosf;
    cin >> n >> m;
    memset(h, -1, sizeof h);
    memset(hb, -1, sizeof hb);
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        val[i] = x + 1000;
    }
    for (int i = 1; i <= m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        add(h, a, b);
        add(hb, b, a);
        if (c == 2)
            add(h, b, a), add(hb, a, b);
    }

    dfs(n);

    dij();
    int ans = -0x3f3f3f3f;
    for (int i = 1; i <= n; i++) {
        if (is_valid[i])
            ans = max(ans, val[i] - dist[i]);
    }

    cout << ans << endl;
}