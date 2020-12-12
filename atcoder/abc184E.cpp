/*
  Problem Name:Third Avenue
  algorithm tag:BFS
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
const int mod = 1e9 + 7;
typedef pair<int, int> pii;

const int N = 2e3 + 5;
char g[N][N];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
vector<pii> tel[140];
int n, m;
int st[N][N];

int bfs(int x1, int y1)
{
    queue<pii> q;
    q.push({x1, y1});
    st[x1][y1] = 1;
    while (q.size()) {
        auto t = q.front();
        q.pop();
        if (g[t.first][t.second] == 'G') {
            return st[t.first][t.second];
        }
        for (int i = 0; i < 4; i++) {
            int x = t.first + dx[i], y = t.second + dy[i];
            if (x <= n && x >= 1 && y >= 1 && y <= m && g[x][y] != '#' && !st[x][y]) {
                q.push({x, y});
                st[x][y] += st[t.first][t.second] + 1;
            }
        }
        if (g[t.first][t.second] <= 122 && g[t.first][t.second] >= 97 && tel[g[t.first][t.second]].size() > 1) {
            for (auto item : tel[g[t.first][t.second]]) {
                if (!st[item.first][item.second]) {
                    q.push({item.first, item.second});
                    st[item.first][item.second] += st[t.first][t.second] + 1;
                }
            }
            tel[g[t.first][t.second]].clear();
        }
    }
    return 0;
}

int main()
{
    cin >> n >> m;
    int x1, y1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            char c;
            cin >> c;
            if (c >= 97 && c <= 122)
                tel[c].push_back({i, j});
            if (c == 'S')
                x1 = i, y1 = j;
            g[i][j] = c;
        }
    }

    cout << bfs(x1, y1) - 1 << endl;
}