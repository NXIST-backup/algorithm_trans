/*
  Problem Name:北极通讯网络
  algorithm tag:最小生成树扩展，kruskal
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
#define x first
#define y second
#define iosf ios::sync_with_stdio(false), cin.tie(0), cout << fixed

const int N = 505, M = N * N;

int n, k;
int fa[N];
vector<pii> pos;
struct Edge
{
    int a, b;
    double w;

    bool operator<(const Edge &W) const
    {
        return w < W.w;
    }
};
vector<Edge> edges;
int find(int x)
{
    if (fa[x] != x)
        fa[x] = find(fa[x]);
    return fa[x];
}
double get_dist(int x1, int y1, int x2, int y2)
{
    return sqrt(double(x1 - x2) * (x1 - x2) + double(y1 - y2) * (y1 - y2));
}
int main()
{
    iosf;

    cin >> n >> k;

    for (int i = 1; i <= n; i++) {
        int a, b;
        cin >> a >> b;
        pos.push_back({a, b});
    }

    for (int i = 0; i < pos.size(); i++) {
        for (int j = i + 1; j < pos.size(); j++) {
            int x1 = pos[i].x, y1 = pos[i].y;
            int x2 = pos[j].x, y2 = pos[j].y;
            edges.push_back({i + 1, j + 1, get_dist(x1, y1, x2, y2)});
        }
    }

    sort(edges.begin(), edges.end());
    for (int i = 1; i <= n; i++)
        fa[i] = i;
    int cnt = 0;
    double ans = 0;
    for (int i = 0; i < edges.size(); i++) {
        int a = edges[i].a, b = edges[i].b;
        double w = edges[i].w;
        a = find(a), b = find(b);

        if (a != b) {
            fa[a] = b;
            if (n - ++cnt == k)
                ans = w;
        }
    }
    printf("%.2lf", ans);
}
