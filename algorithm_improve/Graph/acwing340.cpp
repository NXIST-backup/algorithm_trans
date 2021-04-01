/*
  Problem Name:通信线路
  algorithm tag:二分,dijkstra
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

const int N = 1005, M = 10005;

int n, m, k;
vector<pii> g[N];
int dist[N];
int len[M];
bool state[N];

bool dij(int length)
{
    memset(dist, 0x3f, sizeof dist);
    memset(state, 0, sizeof state);
    priority_queue<pii, vector<pii>, greater<pii>> heap;
    heap.push({0, 1});
    dist[1] = 0;

    while (heap.size()) {
        auto u = heap.top();
        heap.pop();

        if (state[u.y])
            continue;
        state[u.y] = 1;

        for (auto v : g[u.y]) {
            int tmp = 0;
            if (v.x > length)
                tmp = 1;
            if (dist[v.y] > dist[u.y] + tmp) {
                dist[v.y] = dist[u.y] + tmp;
                heap.push({dist[v.y], v.y});
            }
        }
    }
    if (dist[n] > k)
        return false;
    else
        return true;
}

int main()
{
    iosf;
    cin >> n >> m >> k;

    for (int i = 1; i <= m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        len[i] = c;
        g[a].push_back({c, b});
        g[b].push_back({c, a});
    }
    int l = 0, r = m;
    int ans = -1;
    sort(len + 1, len + m + 1);
    while (l < r) {
        int mid = l + r >> 1;
        if (dij(len[mid])) {
            ans = len[mid];
            r = mid;
        } else
            l = mid + 1;
    }

    cout << ans << endl;
}