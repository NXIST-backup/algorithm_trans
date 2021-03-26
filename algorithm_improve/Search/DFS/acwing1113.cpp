/*
  Problem Name:红与黑
  algorithm tag:DFS
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

char g[25][25];
int n, m;
int st[25][25];
int cnt;
int dx[4] = {0, -1, 0, 1};
int dy[4] = {1, 0, -1, 0};

void dfs(int xa, int ya)
{
    if (st[xa][ya])
        return;
    st[xa][ya] = 1;
    cnt++;

    for (int i = 0; i < 4; i++) {
        int x = xa + dx[i], y = ya + dy[i];
        if (x < 0 || y < 0 || x >= n || y >= m || g[x][y] == '#')
            continue;
        dfs(x, y);
    }
}

int main()
{
    while (cin >> m >> n, n && m) {
        cnt = 0;
        memset(st, 0, sizeof st);
        for (int i = 0; i < n; i++)
            scanf("%s", g[i]);

        int xa, ya;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++)
                if (g[i][j] == '@') {
                    xa = i, ya = j;
                    break;
                }
        }

        dfs(xa, ya);

        cout << cnt << endl;
    }
}