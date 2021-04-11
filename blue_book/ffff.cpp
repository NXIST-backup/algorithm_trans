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
//#define x first
//#define y second
#define iosf ios::sync_with_stdio(false), cin.tie(0), cout << fixed

const int N = 1e3 + 5, M = 1e6 + 5;

struct Edge
{
    int a, b, w, idx;

    bool operator<(const Edge &W) const
    {
        return w < W.w;
    }
} edge[M];
int n, m, Q;
bool st[M];
int fa[N];
pii list[6];
int ans = 0x3f3f3f3f;
int find(int x)
{
    if (fa[x] != x)
        fa[x] = find(fa[x]);
    return fa[x];
}

void dfs(int u)
{
    if (u == Q) {
        for (int i = 1; i <= n; i++)
            fa[i] = i;
        int res = 0, cnt = 0;
        for (int i = 1; i <= m; i++) {
            int t = edge[i].idx;
            if (st[t])
                continue;
            int a = edge[i].a, b = edge[i].b, w = edge[i].w;

            a = find(a), b = find(b);
            if (a != b) {
                fa[a] = b;
                res += w;
                cnt++;
            }
        }
        if (cnt < n - 1)
            return;
        else
            ans = min(ans, res);
    }
    for (int i = 1; i <= Q; i++) {
        int a = list[i].first, b = list[i].second;
        if (st[a] && st[b])
            return;
        if (st[a] || st[b])
            continue;
        else {
            st[a] = 1;
            dfs(u + 1);
            st[a] = 0;
            st[b] = 1;
            dfs(u + 1);
            st[b] = 0;
        }
    }
}

int main()
{
    iosf;
    cin >> n >> m;

    for (int i = 1; i <= m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        edge[i] = {a, b, c, i};
    }

    sort(edge + 1, edge + 1 + m);

    cin >> Q;
    for (int i = 1; i <= Q; i++) {
        int a, b;
        cin >> a >> b;
        list[i] = {a, b};
    }

    dfs(0);

    cout << ans << endl;
}