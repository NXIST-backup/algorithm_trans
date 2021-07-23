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

const int N = 20, M = N * N + N;

int n, m, q;
int fa1[M], fa2[M], fa3[M];
string g[N];
int st[M];

int find(int x, int fa[])
{
    if (x != fa[x])
        fa[x] = find(fa[x], fa);
    return fa[x];
}

int pos(int x, int y)
{
    return x * m + y;
}

void bfs(int x, int y, int t)
{
    queue<pii> q;
    q.push({x, y});

    while (q.size()) {
        auto u = q.front();
        q.pop();

        if (t == 1) {
            int a = u.x + 1, b = u.y;
            if (a >= n || b >= m || a < 0 || b < 0 || g[a][b] == '1')
                continue;
            if (!st[pos(a, b)]) {
                q.push({a, b});
                st[pos(a, b)] = 1;
            }
            int pa = find(pos(u.x, u.y), fa1), pb = find(pos(a, b), fa1);
            if (pa != pb)
                fa1[pb] = pa;
        } else if (t == 2) {
            int a = u.x, b = u.y + 1;
            if (a >= n || b >= m || a < 0 || b < 0 || g[a][b] == '1')
                continue;
            if (!st[pos(a, b)]) {
                q.push({a, b});
                st[pos(a, b)] = 1;
            }
            int pa = find(pos(u.x, u.y), fa2), pb = find(pos(a, b), fa2);
            if (pa != pb)
                fa2[pb] = pa;
        } else {
            int a = u.x + 1, b = u.y;
            if (a < n && b < m && a >= 0 && b >= 0 && g[a][b] != '1') {
                if (!st[pos(a, b)]) {
                    q.push({a, b});
                    st[pos(a, b)] = 1;
                }
                int pa = find(pos(u.x, u.y), fa3), pb = find(pos(a, b), fa3);
                if (pa != pb)
                    fa3[pb] = pa;
            }
            a = u.x, b = u.y + 1;
            if (a < n && b < m && a >= 0 && b >= 0 && g[a][b] != '1') {
                if (!st[pos(a, b)]) {
                    q.push({a, b});
                    st[pos(a, b)] = 1;
                }
                int pa = find(pos(u.x, u.y), fa3), pb = find(pos(a, b), fa3);
                if (pa != pb)
                    fa3[pb] = pa;
            }
        }
    }
}

int main()
{
    iosf;
    cin >> n >> m;
    for (int i = 1; i <= N * N; i++)
        fa1[i] = fa2[i] = fa3[i] = i;

    for (int i = 0; i < n; i++)
        cin >> g[i];

    for (int k = 1; k <= 3; k++) {
        memset(st, 0, sizeof st);
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (!st[pos(i, j)] && g[i][j] == '0')
                    bfs(i, j, k);
    }

    cin >> q;
    while (q--) {
        int t, x1, y1, x2, y2;
        cin >> t >> x1 >> y1 >> x2 >> y2;
        x1--, y1--, x2--, y2--;
        if (t == 1) {
            int pa = find(pos(x1, y1), fa1), pb = find(pos(x2, y2), fa1);
            if (pa == pb)
                cout << "Y" << endl;
            else
                cout << "N" << endl;
        } else if (t == 2) {
            int pa = find(pos(x1, y1), fa2), pb = find(pos(x2, y2), fa2);
            if (pa == pb)
                cout << "Y" << endl;
            else
                cout << "N" << endl;
        } else {
            int pa = find(pos(x1, y1), fa3), pb = find(pos(x2, y2), fa3);
            if (pa == pb)
                cout << "Y" << endl;
            else
                cout << "N" << endl;
        }
    }

    return 0;
}