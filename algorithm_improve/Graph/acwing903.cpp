/*
  Problem Name:昂贵的聘礼
  algorithm tag:
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

int n, m;
vector<pii> g[105];
int dist[105];
int st[105];
int level[105];
int dij(int up, int down)
{
    memset(dist, 0x3f, sizeof dist);
    memset(st, 0, sizeof st);
    priority_queue<pii, vector<pii>, greater<pii>> heap;
    dist[0] = 0;
    heap.push({0, 0});

    while (heap.size()) {
        auto u = heap.top();
        heap.pop();
        if (st[u.y])
            continue;
        st[u.y] = 1;

        for (auto v : g[u.y]) {
            if (level[v.y] > up || level[v.y] < down)
                continue;
            if (dist[v.y] > dist[u.y] + v.x) {
                dist[v.y] = dist[u.y] + v.x;
                heap.push({dist[v.y], v.y});
            }
        }
    }

    return dist[1];
}

int main()
{
    iosf;
    cin >> m >> n;
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        g[0].push_back({a, ++cnt});
        level[cnt] = b;
        while (c--) {
            int x, y;
            cin >> x >> y;
            g[x].push_back({y, cnt});
        }
    }
    // int res = INF;
    // for (int i = level[1] - m; i <= level[1]; i++)
    //     res = min(res, dij(i + m, i));

    // cout << res << endl;

    cout << dij(level[1] + m, level[1] - m) << endl;
}