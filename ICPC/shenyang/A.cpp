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
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;
const double eps = 1e-4;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define x first
#define y second
#define iosf ios::sync_with_stdio(false), cin.tie(0), cout << fixed

const int N = 115, M = 65, VV = N * M, EE = VV * VV;

int n, m, k1, k2, R, V;
int start, ed;
int st[N][M];
int h[VV], e[EE], ne[EE], idx;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int state[N][M];
int dist[VV];
void del_circu(int x, int y)
{
    for (int i = min(x - R, 0); i <= min(x + R, n); i++) {
        for (int j = min(y - R, 0); j <= min(y + R, m); j++) {
            double x1 = double(i), y1 = double(j);
            if (sqrt((x1 - x) * (x1 - x) + (y1 - y) * (y1 - y)) - R <= eps)
                st[i][j] = true;
        }
    }
}
void del_linear(int type, int x)
{
    if (type)
        for (int i = 0; i <= m; i++)
            st[x][i] = true;
    else
        for (int i = 0; i <= n; i++)
            st[i][x] = true;
}
void add(int a, int b)
{
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx++;
}

void out()
{
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++)
            cout << st[i][j] << " ";
        cout << endl;
    }
}
int pos(int x, int y)
{
    return x * (m + 1) + y;
}

void build(int x, int y)
{
    for (int i = 0; i <= V; i++) {
        for (int j = 0; j <= V - i; j++) {
        }
    }
}
void bfs()
{
}

int main()
{
    iosf;
    cin >> n >> m >> k1 >> k2 >> R >> V >> start >> ed;
    V = min(5000, V);
    for (int i = 1; i <= k1; i++) {
        int x, y;
        cin >> x >> y;
        del_circu(x, y);
    }
    for (int i = 1; i <= k2; i++) {
        int x, type;
        cin >> type >> x;
        del_linear(type, x);
    }
    //out();
    bfs();
}
