/*
  Problem Name:
  algorithm tag:
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

const int N = 105;

int n, m;
int g[N][N];
int dist[N][N];
bool st[N][N];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int dij()
{
    memset(dist, 0x3f, sizeof dist);
    dist[1][1] = 0;
    priority_queue<pair<int, pii>, vector<pair<int, pii>>, greater<pair<int, pii>>> heap;
    heap.push({0, {1, 1}});

    while (heap.size()) {
        auto t = heap.top();
        heap.pop();
        pii ver = t.second;
        int dis = t.first;

        if (st[ver.first][ver.second])
            continue;
        st[ver.first][ver.second] = 1;

        for (int i = 0; i < 4; i++) {
            int x = ver.first + dx[i], y = ver.second + dy[i];
            if (!g[x][y])
                continue;
            if (dist[x][y] > max(dist[ver.first][ver.second], abs(g[ver.first][ver.second] - g[x][y]))) {
                dist[x][y] = max(dist[ver.first][ver.second], abs(g[ver.first][ver.second] - g[x][y]));
                heap.push({dist[x][y], {x, y}});
            }
        }
    }

    return dist[n][m];
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

    cout << dij() << endl;
}