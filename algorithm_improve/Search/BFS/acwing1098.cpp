/*
  Problem Name:城堡问题
  algorithm tag:Flood fill,BFS
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
#define iosf ios::sync_with_stdio(false), cin.tie(0), cout << fixed

int n, m;
int g[55][55][4];
int dx[4] = {0, -1, 0, 1};
int dy[4] = {-1, 0, 1, 0};
int vis[55][55];
void del(int x, int y, int w)
{
    int idx = 0;
    while (w) {
        if (w & 1)
            g[x][y][idx] = 0;
        else
            g[x][y][idx] = 1;
        idx++;
        w >>= 1;
    }
    while (idx < 4)
        g[x][y][idx++] = 1;
}
int bfs(int x1, int y1)
{
    queue<pii> q;
    q.push({x1, y1});
    vis[x1][y1] = 1;
    int path = 1;
    while (q.size()) {
        auto t = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            int x = t.first + dx[i], y = t.second + dy[i];
            if (g[t.first][t.second][i] && !vis[x][y]) {
                q.push({x, y});
                vis[x][y] = 1;
                path++;
            }
        }
    }
    return path;
}

int main()
{
    iosf;
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            int x;
            cin >> x;
            del(i, j, x);
        }
    }
    int res = 0;
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (!vis[i][j]) {
                ans = max(ans, bfs(i, j));
                res++;
            }
        }
    }
    cout << res << endl;
    cout << ans << endl;
}