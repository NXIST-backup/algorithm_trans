/*
  Problem Name:香甜的黄油
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

const int P = 505, N = 805, M = 1500;

int park[N];
int p, n, m;
vector<pii> g[N];
int dist[N];
bool state[N];

int dij(int st)
{
    memset(dist, 0x3f, sizeof dist);
    memset(state, 0, sizeof state);
    priority_queue<pii, vector<pii>, greater<pii>> heap;
    heap.push({0, st});
    dist[st] = 0;

    while (heap.size()) {
        auto t = heap.top();
        heap.pop();

        if (state[t.y])
            continue;
        state[t.y] = 1;

        for (auto v : g[t.y]) {
            if (dist[v.y] > dist[t.y] + v.x) {
                dist[v.y] = dist[t.y] + v.x;
                heap.push({dist[v.y], v.y});
            }
        }
    }
    int res = 0;
    for (int i = 1; i <= n; i++) {
        if (!park[i])
            continue;
        if (dist[i] == 0x3f3f3f3f)
            return -1;
        else
            res += dist[i] * park[i];
    }

    return res;
}

int main()
{
    iosf;

    cin >> p >> n >> m;

    for (int i = 1; i <= p; i++) {
        int x;
        cin >> x;
        park[x]++;
    }

    for (int i = 1; i <= m; i++) {
        int a, b, c;
        cin >> a >> b >> c;

        g[a].push_back({c, b});
        g[b].push_back({c, a});
    }
    int ans = 0x3f3f3f3f;
    for (int i = 1; i <= n; i++) {
        int res = dij(i);

        if (res != -1)
            ans = min(ans, res);
    }
    if (ans == 0x3f3f3f3f)
        cout << -1 << endl;
    else
        cout << ans << endl;
}