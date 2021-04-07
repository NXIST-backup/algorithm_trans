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

const int N = 11, M = N * N, E = 4 * N * N, P = 1 << 10;
int n, m, p, k;
int h[M], e[E], ne[E], w[E], idx;
int dist[M][P];
int st[M][P];
int g[N][N];
set<pii> edges;
int key[M];
void add(int a, int b, int c)
{
    e[idx] = b;
    ne[idx] = h[a];
    w[idx] = c;
    h[a] = idx++;
}
void build()
{
    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {1, 0, -1, 0};

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            for (int k = 0; k < 4; k++) {
                int x = i + dx[k], y = j + dy[k];
                if (!x || !y || x > n || y > m)
                    continue;
                if (edges.count({g[i][j], g[x][y]}) == 0) {
                    add(g[i][j], g[x][y], 0);
                }
            }
        }
    }
}
int bfs()
{
    memset(dist, 0x3f, sizeof dist);
    deque<pii> q;
    dist[1][0] = 0;
    q.push_back({0, 1});

    while (q.size()) {
        int u = q.front().y;
        int state = q.front().x;
        q.pop_front();

        if (st[u][state])
            continue;
        st[u][state] = 1;

        if (u == n * m)
            return dist[u][state];

        if (key[u]) {
            int ss = state | key[u];
            if (dist[u][ss] > dist[u][state]) {
                dist[u][ss] = dist[u][state];
                q.push_front({ss, u});
            }
        }

        for (int i = h[u]; ~i; i = ne[i]) {
            int j = e[i];
            if (w[i] && !(state >> w[i] - 1 & 1))
                continue;
            if (dist[j][state] > dist[u][state] + 1) {
                dist[j][state] = dist[u][state] + 1;
                q.push_back({state, j});
            }
        }
    }

    return -1;
}
int main()
{
    iosf;
    cin >> n >> m >> p >> k;

    for (int i = 1, t = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            g[i][j] = t++;
    memset(h, -1, sizeof h);
    for (int i = 1; i <= k; i++) {
        int x1, y1, x2, y2, c;
        cin >> x1 >> y1 >> x2 >> y2 >> c;
        int a = g[x1][y1], b = g[x2][y2];
        edges.insert({a, b});
        edges.insert({b, a});
        if (c)
            add(a, b, c), add(b, a, c);
    }

    build();
    int S;
    cin >> S;
    while (S--) {
        int a, b, c;
        cin >> a >> b >> c;
        key[g[a][b]] |= 1 << c - 1;
    }

    cout << bfs() << endl;
}