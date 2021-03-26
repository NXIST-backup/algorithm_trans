/*
  Problem Name:池塘计数
  algorithm tag:Flood fill
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

const int N = 1050;
int n, m;
char g[N][N];
int dx[8] = {0, 1, 0, -1, 1, 1, -1, -1};
int dy[8] = {1, 0, -1, 0, -1, 1, 1, -1};

void bfs(int x, int y)
{
    queue<pii> q;
    q.push({x, y});
    g[x][y] = '.';

    while (q.size()) {
        auto t = q.front();
        q.pop();

        for (int i = 0; i < 8; i++) {
            int x = t.first + dx[i], y = t.second + dy[i];
            if (g[x][y] == 'W') {
                g[x][y] = '.';
                q.push({x, y});
            }
        }
    }
}

int main()
{
    iosf;

    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> g[i][j];
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (g[i][j] == 'W') {
                bfs(i, j);
                ans++;
            }
        }
    }

    cout << ans << endl;
}
