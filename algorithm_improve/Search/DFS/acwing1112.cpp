/*
  Problem Name:迷宫
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

const int N = 105;
char g[N][N];
int T;
int n;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};
int x2, y2;
int st[N][N];
bool is_valid;

void dfs(int x1, int y1)
{
    if (st[x1][y1])
        return;
    st[x1][y1] = 1;
    if (x1 == x2 && y1 == y2) {
        is_valid = true;
        return;
    }

    for (int i = 0; i < 4; i++) {
        int x = x1 + dx[i], y = y1 + dy[i];
        if (x >= n || y >= n || x < 0 || y < 0 || g[x][y] == '#')
            continue;
        dfs(x, y);
    }
}

int main()
{
    iosf;

    cin >> T;

    while (T--) {
        int x1, y1;
        memset(st, 0, sizeof st);
        is_valid = false;
        cin >> n;
        for (int i = 0; i < n; i++) {
            scanf("%s", g[i]);
        }
        cin >> x1 >> y1 >> x2 >> y2;
        if (g[x1][y1] == '#') {
            cout << "NO" << endl;
            continue;
        }
        dfs(x1, y1);

        if (is_valid)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
}