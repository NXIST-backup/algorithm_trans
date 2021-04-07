/*
  Problem Name:选择最佳线路
  algorithm tag:dijkstra
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

const int N = 1005, M = 20005;
int n, m, ed, W;
int dist[N];
int st[N];
vector<pii> g[N];

void dij()
{
    memset(dist, 0x3f, sizeof dist);
    memset(st, 0, sizeof st);
    priority_queue<pii, vector<pii>, greater<pii>> heap;
    dist[0] = 0;
    heap.push({0, 0});

    while (heap.size()) {
        int u = heap.top().y;
        heap.pop();

        if (st[u])
            continue;
        st[u] = 1;

        for (auto v : g[u]) {
            if (dist[v.y] > dist[u] + v.x) {
                dist[v.y] = dist[u] + v.x;
                heap.push({dist[v.y], v.y});
            }
        }
    }
}

int main()
{
    while (cin >> n >> m >> ed) {
        for (int i = 1; i <= m; i++) {
            int a, b, c;
            cin >> a >> b >> c;
            g[a].push_back({c, b});
        }

        cin >> W;

        while (W--) {
            int x;
            cin >> x;
            g[0].push_back({0, x});
        }

        dij();

        if (dist[ed] != 0x3f3f3f3f)
            cout << dist[ed] << endl;
        else
            cout << -1 << endl;
        for (int i = 0; i <= n; i++)
            g[i].clear();
    }
}