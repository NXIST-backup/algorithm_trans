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
typedef pair<int, int> pii;

char g[155][155];
int st[155][155];
int n, m;
int dx[8] = {1, 1, -1, -1, 2, 2, -2, -2};
int dy[8] = {2, -2, 2, -2, 1, -1, 1, -1};
int cx[8] = {0, 0, 0, 0, 1, 1, -1, -1};
int cy[8] = {1, -1, 1, -1, 0, 0, 0, 0};

int bfs(int x1, int y1, int x2, int y2)
{
    queue<pii> q;
    q.push({x1, y1});
    st[x1][y1] = 1;

    while (q.size()) {
        auto t = q.front();
        q.pop();

        if (t.first == x2 && t.second == y2)
            break;

        for (int i = 0; i < 8; i++) {
            int x = t.first + dx[i], y = t.second + dy[i];
            int jx = t.first + cx[i], jy = t.second + dx[i];

            if (x < 0 || y < 0 || x > n || y > m || g[jx][jy] == '*' || st[x][y] || g[x][y] == '*')
                continue;

            q.push({x, y});
            st[x][y] += st[t.first][t.second] + 1;
        }
    }

    return st[x2][y2];
}
int main()
{
    cin >> m >> n;
    int x1, x2, y1, y2;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            char c;
            cin >> c;
            if (c == 'K')
                x1 = i, y1 = j;
            if (c == 'H')
                x2 = i, y2 = j;
            g[i][j] = c;
        }
    }

    int ans = bfs(x1, y1, x2, y2);

    cout << ans - 1 << endl;
}