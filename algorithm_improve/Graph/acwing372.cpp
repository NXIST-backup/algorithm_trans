/*
  Problem Name:棋盘覆盖
  algorithm tag:图论,二分图,最大匹配匈牙利算法
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
int n, m;
int g[N][N];
int st[N][N];
pii match[N][N];
int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};

bool find(int x, int y)
{
    for (int i = 0; i < 4; i++) {
        int x1 = x + dx[i], y1 = y + dy[i];
        if (x1 < 1 || x1 > n || y1 < 1 || y1 > n || g[x1][y1])
            continue;
        if (st[x1][y1])
            continue;
        st[x1][y1] = true;
        pii t = match[x1][y1];
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
    cin >> n >> m;

    for (int i = 1; i <= m; i++) {
        int a, b;
        cin >> a >> b;
        g[a][b] = true;
    }
    int res = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (!g[i][j] && (i + j) % 2) {
                memset(st, 0, sizeof st);
                if (find(i, j))
                    res++;
            }

    cout << res << endl;
}