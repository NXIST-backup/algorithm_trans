/*
  Problem Name:骑士放置
  algorithm tag:图论,二分图,最大独立集,匈牙利算法
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
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;
const double eps = 1e-4;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define x first
#define y second
#define iosf ios::sync_with_stdio(false), cin.tie(0), cout << fixed

const int N = 105;
int n, m, t;
int g[N][N];
int st[N][N];
pii match[N][N];

int dx[8] = {1, 1, -1, -1, 2, 2, -2, -2};
int dy[8] = {2, -2, 2, -2, 1, -1, 1, -1};

bool find(int x, int y)
{
    for (int i = 0; i < 8; i++) {
        int x1 = x + dx[i], y1 = y + dy[i];
        if (x1 < 1 || x1 > n || y1 < 1 || y1 > m || g[x1][y1] || st[x1][y1])
            continue;
        st[x1][y1] = true;
        auto t = match[x1][y1];
        if (t.x == 0 || find(t.x, t.y)) {
            match[x1][y1] = {x, y};
            return true;
        }
    }
    return false;
}
int main()
{
    iosf;
    cin >> n >> m >> t;

    for (int i = 1; i <= t; i++) {
        int a, b;
        cin >> a >> b;
        g[a][b] = 1;
    }
    int res = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if (!g[i][j] && (i + j) % 2) {
                memset(st, 0, sizeof st);
                if (find(i, j))
                    res++;
            }
    cout << n * m - t - res << endl;
    return 0;
}
