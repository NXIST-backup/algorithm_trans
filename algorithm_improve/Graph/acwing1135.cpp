/*
  Problem Name:新年好
  algorithm tag:dijkstra,dfs
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
typedef pair<double, int> pdl;
#define x first
#define y second
#define iosf ios::sync_with_stdio(false), cin.tie(0), cout << fixed

const int N = 50005;

int n, m;
int a, b, c, d, e;
vector<pii> g[N];
int sour[6];
int dist[6][N];
bool state[N];
vector<int> list;
int ans = INF;
bool state2[7];

void dij(int st, int dist[])
{
    memset(dist, 0x3f, N * 4);
    memset(state, 0, sizeof state);
    priority_queue<pii, vector<pii>, greater<pii>> heap;
    dist[st] = 0;
    heap.push({0, st});

    while (heap.size()) {
        auto u = heap.top();
        heap.pop();

        if (state[u.y])
            continue;
        state[u.y] = 1;

        for (auto v : g[u.y]) {
            if (dist[v.y] > dist[u.y] + v.x) {
                dist[v.y] = dist[u.y] + v.x;
                heap.push({dist[v.y], v.y});
            }
        }
    }
}

void dfs(int u)
{
    if (u == 6) {
        int res = 0;
        int last = 0;
        for (auto item : list) {
            res += dist[last][sour[item]];
            last = item;
        }
        ans = min(ans, res);
    }

    for (int i = 1; i <= 5; i++) {
        if (!state2[i]) {
            state2[i] = 1;
            list.push_back(i);
            dfs(u + 1);
            list.pop_back();
            state2[i] = 0;
        }
    }
}
int main()
{
    iosf;
    ans = INF;
    cin >> n >> m;

    for (int i = 1; i <= 5; i++) {
        cin >> sour[i];
    }
    sour[0] = 1;
    for (int i = 1; i <= m; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        g[x].push_back({z, y});
        g[y].push_back({z, x});
    }

    for (int i = 0; i <= 5; i++) {
        dij(sour[i], dist[i]);
    }

    dfs(1);

    cout << ans << endl;
}