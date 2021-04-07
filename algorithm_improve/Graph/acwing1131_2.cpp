/*
  Problem Name:拯救大兵瑞恩
  algorithm tag:拆点，分层图,DP
*/

#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
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
//分层图做法

const int P = 1 << 10, N = P * 11, M = P * 11 * 11 * 4;

int n, m, p, k, S;
int h[N], e[M], ne[M], w[M], idx;
int dist[N];
int st[N];
set<pii> edges;
int g[11][11];
int key[11 * 11];
void add(int a, int b, int c)
{
    e[idx] = b;
    ne[idx] = h[a];
    w[idx] = c;
    h[a] = idx++;
}
void addedge(int a, int b, int c)
{
    for (int i = 0, t = n; i < P; i++) {
        add(a + i * t, b + i * t, c);
    }
}
void build()
{
    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {1, 0, -1, 0};
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            for (int u = 0; u < 4; u++) {
                int x = i + dx[u], y = j + dy[u];
                int a = g[i][j], b = g[x][y];
                if (!x || !y || x > n || y > m)
                    continue;
                if (!edges.count({a, b}))
                    addedge(a, b, 1);
            }
        }
    }
}

int main()
{
    iosf;

    cin >> n >> m >> p >> k;
    memset(h, -1, sizeof h);
    for (int i = 1, t = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            g[i][j] = t++;
        }
    }

    for (int i = 1; i <= k; i++) {
        int x1, y1, x2, y2, c;
        cin >> x1 >> y1 >> x2 >> y2 >> c;
        int a = g[x1][y1], b = g[x2][y2];
        edges.insert({a, b}), edges.insert({b, a});
        if (c)
            addedge(a, b, c), addedge(b, a, c);
    }

    build();

    cin >> S;
    while (S--) {
        int a, b, c;
        cin >> a >> b >> c;

        int t = 1 << c - 1;
        int x = g[a][b], y = g[a + c * n][b + c * n];
        add(x, y, 0);
    }
}