/*
  Problem Name:山峰和山谷
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

const int N = 1005;
int n;
int g[N][N];
int dx[8] = {0, 1, 0, -1, 1, 1, -1, -1};
int dy[8] = {1, 0, -1, 0, -1, 1, -1, 1};
bool vis[N][N];

int bfs(int x1, int y1)
{
    queue<pii> q;
    q.push({x1, y1});
    vis[x1][y1] = 1;
    bool sg = 0, sf = 0;
    while (q.size()) {
        auto t = q.front();
        q.pop();
        for (int i = 0; i < 8; i++) {
            int x = t.first + dx[i], y = t.second + dy[i];
            if (x == 0 || y == 0 || x > n || y > n)
                continue;
            if (g[x][y] > g[t.first][t.second] && !sg)
                sg = 1;
            if (g[x][y] < g[t.first][t.second] && !sf)
                sf = 1;
            if (vis[x][y])
                continue;
            if (g[x][y] == g[t.first][t.second]) {
                q.push({x, y});
                vis[x][y] = 1;
            }
        }
    }
    if (sg && sf)
        return 0;
    if (sf)
        return 1;
    if (sg)
        return 2;
}

int main()
{
    cin >> n;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++)
            cin >> g[i][j];
    }
    int ans = 0, res = 0;
    int cnt = 0;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (!vis[i][j]) {
                int t = bfs(i, j);
                if (t == 1)
                    ans++;
                if (t == 2)
                    res++;
                cnt++;
            }
        }
    }

    if (cnt == 1) {
        cout << 1 << " " << 1 << endl;
    } else {
        cout << ans << " " << res << endl;
    }
}