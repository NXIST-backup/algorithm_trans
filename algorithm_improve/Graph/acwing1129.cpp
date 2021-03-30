/*
  Problem Name:热浪
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

const int N = 2505, M = 6250;

int n, m;
int st, ed;
vector<pii> g[N];
int dist[N];
bool state[N];

int dij(int st)
{
    memset(dist, 0x3f, sizeof dist);
    priority_queue<pii, vector<pii>, greater<pii>> heap;
    heap.push({0, st});
    dist[st] = 0;

    while (heap.size()) {
        auto t = heap.top();
        heap.pop();

        if (t.y == ed)
            return dist[ed];
        if (state[t.y])
            continue;

        for (auto v : g[t.y]) {
            if (dist[v.y] > dist[t.y] + v.x) {
                dist[v.y] = dist[t.y] + v.x;
                heap.push({dist[v.y], v.y});
            }
        }
    }

    return dist[ed];
}

int main()
{
    iosf;
    cin >> n >> m >> st >> ed;

    for (int i = 1; i <= m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        g[a].push_back({c, b});
        g[b].push_back({c, a});
    }

    cout << dij(st) << endl;
}
