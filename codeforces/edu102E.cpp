/*
  Problem Name:Minimum Path
  algorithm tag:最短路,分层图
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
const int mod = 1e9 + 7;
typedef pair<ll, int> pli;
typedef pair<int, int> pii;

const int N = 2e5 + 5;

int n, m;
vector<pii> g[N * 4];
ll dist[N * 4];
void dij()
{
    priority_queue<pli, vector<pli>, greater<pli>> heap;
    for (int i = 1; i <= 4 * n; i++)
        dist[i] = 1e18;
    heap.push({0, 1});
    dist[1] = 0;
    while (heap.size()) {
        ll w = heap.top().first;
        int u = heap.top().second;
        heap.pop();

        if (w > dist[u])
            continue;
        for (auto v : g[u]) {
            if (v.second + w < dist[v.first]) {
                dist[v.first] = (ll)v.second + w;
                heap.push({dist[v.first], v.first});
            }
        }
    }
    for (int i = 3 * n + 2; i <= 4 * n; i++) {
        cout << dist[i] << " ";
    }
    cout << endl;
}

int main()
{
    cin >> n >> m;

    for (int i = 1; i <= m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        g[a].push_back({b, c});
        g[b].push_back({a, c});
        g[a + n].push_back({b + n, c});
        g[b + n].push_back({a + n, c});
        g[a + 2 * n].push_back({b + 2 * n, c});
        g[b + 2 * n].push_back({a + 2 * n, c});
        g[a + 3 * n].push_back({b + 3 * n, c});
        g[b + 3 * n].push_back({a + 3 * n, c});
        g[a].push_back({b + n, 0});
        g[b].push_back({a + n, 0});
        g[a].push_back({b + 2 * n, 2 * c});
        g[b].push_back({a + 2 * n, 2 * c});
        g[a].push_back({b + 3 * n, c});
        g[b].push_back({a + 3 * n, c});
        g[a + n].push_back({b + 3 * n, 2 * c});
        g[b + n].push_back({a + 3 * n, 2 * c});
        g[a + 2 * n].push_back({b + 3 * n, 0});
        g[b + 2 * n].push_back({a + 3 * n, 0});
    }
    dij();
}