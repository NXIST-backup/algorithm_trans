/*
  Problem Name:局域网
  algorithm tag:kruskal,prim,最小生成树,MST
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

const int N = 105, M = 410;
int n, m;
int g[N][N];
int dist[N];
bool st[N];
vector<int> edge;
int prim(int start)
{
    int res = 0;
    int cnt = 0;
    memset(dist, 0x3f, sizeof dist);
    priority_queue<pii, vector<pii>, greater<pii>> heap;
    heap.push({0, start});
    dist[start] = 0;

    while (heap.size()) {
        int u = heap.top().second;
        int dis = heap.top().first;
        heap.pop();

        if (st[u])
            continue;
        st[u] = 1;
        res += dis;

        for (int i = 1; i <= n; i++) {
            if (!st[i] && dist[i] > g[u][i]) {
                dist[i] = g[u][i];
                heap.push({dist[i], i});
            }
        }
    }
    return res;
}

int main()
{
    iosf;
    cin >> n >> m;
    int sum = 0;
    memset(g, 0x3f, sizeof g);
    for (int i = 1; i <= m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        g[a][b] = g[b][a] = min(g[a][b], c);
        sum += g[a][b];
    }
    int ans = 0;
    for (int i = 1; i <= n; i++)
        if (!st[i])
            ans += prim(i);
    cout << sum - ans << endl;
}