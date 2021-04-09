/*
  Problem Name:牛的旅行
  algorithm tag:floyd,多源最短路
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
const double INF = 100000000.0;
const int mod = 1e9 + 7;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define x first
#define y second
#define iosf ios::sync_with_stdio(false), cin.tie(0), cout << fixed

const int N = 155, M = N * N;

int n;
int h[N], e[M], ne[M], idx;
double w[M];
pii g[N];
double dist[N][N];
int st[N];
vector<int> A, B;
double Mb[N];
vector<int> edges;
void floyd()
{
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++)
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
        }
    }
}
void dfs(int u, int id)
{
    st[u] = id;
    for (int i = h[u]; ~i; i = ne[i]) {
        int j = e[i];
        if (!st[j])
            dfs(j, id);
    }
}
void add(int a, int b, double c)
{
    e[idx] = b;
    ne[idx] = h[a];
    w[idx] = c;
    h[a] = idx++;
}
int main()
{
    iosf;
    cin >> n;
    memset(h, -1, sizeof h);

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == j)
                dist[i][j] = 0;
            else
                dist[i][j] = INF;
        }
    }

    for (int i = 1; i <= n; i++) {
        int x, y;
        cin >> x >> y;
        g[i] = {x, y};
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            char c;
            cin >> c;
            if (c == '1') {
                edges.push_back(i);
                double x1 = g[i].x, y1 = g[i].y;
                double x2 = g[j].x, y2 = g[j].y;
                double t = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
                add(i, j, t);
                add(j, i, t);
                dist[i][j] = min(dist[i][j], t);
                dist[j][i] = min(dist[j][i], t);
            }
        }
    }
    int cnt = 0;

    for (int i = 1; i <= n; i++) {
        if (!st[i])
            dfs(i, ++cnt);
    }

    if (!edges.size()) {
        double anss = INF;
        for (int i = 1; i <= n; i++) {
            for (int j = i + 1; j <= n; j++) {
                double x1 = g[i].x, y1 = g[i].y;
                double x2 = g[j].x, y2 = g[j].y;
                double t = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
                anss = min(anss, t);
            }
        }
        cout << anss << endl;
        return 0;
    }

    for (int i = 1; i <= n; i++) {
        if (st[i] == 1)
            A.push_back(i);
        else if (st[i] == 2)
            B.push_back(i);
    }

    floyd();

    double mxa = 0;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (dist[i][j] != INF)
                mxa = max(mxa, dist[i][j]);
        }
    }
    for (auto i : A) {
        for (auto j : A) {
            Mb[i] = max(Mb[i], dist[i][j]);
        }
    }
    for (auto i : B) {
        for (auto j : B) {
            Mb[i] = max(Mb[i], dist[i][j]);
        }
    }
    double ans = INF;
    for (auto i : A) {
        for (auto j : B) {
            double x1 = g[i].x, y1 = g[i].y;
            double x2 = g[j].x, y2 = g[j].y;
            double t = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2)) + Mb[i] + Mb[j];
            ans = min(ans, t);
        }
    }
    ans = max(mxa, ans);
    cout << ans << endl;
}