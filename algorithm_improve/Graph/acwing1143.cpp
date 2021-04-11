/*
  Problem Name:联络员
  algorithm tag:最小生成树，kruskal，prim
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

const int N = 2005, M = 10005;

int fa[M];
int n, m;
bool st[N][N];

struct Edge
{
    int a, b, w;

    bool operator<(const Edge &W) const
    {
        return w < W.w;
    }
};
vector<Edge> edge;
struct Tex
{
    int p, a, b, c;

    bool operator<(const Tex &W) const
    {
        return p < W.p;
    }
} tex[M];
int find(int x)
{
    if (fa[x] != x)
        fa[x] = find(fa[x]);
    return fa[x];
}
int main()
{
    iosf;
    cin >> n >> m;
    int res = 0;
    for (int i = 1; i <= m; i++) {
        int p, a, b, c;
        cin >> p >> a >> b >> c;
        tex[i] = {p, a, b, c};
    }
    sort(tex + 1, tex + 1 + m);

    for (int i = 1; i <= m; i++) {
        int p = tex[i].p, a = tex[i].a, b = tex[i].b, c = tex[i].c;
        if (p == 1) {
            st[a][b] = 1;
            st[b][a] = 1;
            res += c;
            a = find(a), b = find(b);
            if (a != b)
                fa[a] = b;
        } else if (!st[a][b])
            edge.push_back({a, b, c});
    }
    sort(edge.begin(), edge.end());

    for (auto item : edge) {
        int a = item.a, b = item.b, c = item.w;
        a = find(a), b = find(b);
        if (a != b) {
        }
    }
}
