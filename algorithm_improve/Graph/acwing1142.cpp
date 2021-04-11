/*
  Problem Name:繁忙的都市
  algorithm tag:最小生成树，prim，kruskal
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
//#define x first
//#define y second
#define iosf ios::sync_with_stdio(false), cin.tie(0), cout << fixed

const int N = 305;
int g[N][N];
int n, m;
int dist[N];
int res, cnt, ans;
bool st[N];

void prim()
{
    memset(dist, 0x3f, sizeof dist);
    priority_queue<pii, vector<pii>, greater<pii>> heap;
    heap.push({0, 1});
    dist[1] = 0;

    while (heap.size()) {
        int u = heap.top().second;
        int dis = heap.top().first;
        heap.pop();
        if (st[u])
            continue;
        st[u] = 1;
        cnt++;
        res = max(res, dis);

        for (int i = 1; i <= n; i++)
            if (!st[i] && dist[i] > g[u][i]) {
                dist[i] = g[u][i];
                heap.push({dist[i], i});
            }
    }
}

int main()
{
    iosf;
    cin >> n >> m;
    memset(g, 0x3f, sizeof g);
    for (int i = 1; i <= m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        g[a][b] = g[b][a] = min(g[a][b], c);
    }

    prim();

    cout << cnt - 1 << " " << res << endl;
}