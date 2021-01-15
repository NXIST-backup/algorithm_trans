/*
  Problem Name:树的中心
  algorithm tag:树形DP
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

const int N = 1e5 + 5;

int n;
vector<pii> g[N];
int d1[N], d2[N], p1[N], up[N];
bool is_leaf[N];
int dfs_d(int u, int father)
{
    d1[u] = -mod;
    d2[u] = -mod;
    for (auto v : g[u]) {
        if (v.first == father)
            continue;
        int d = dfs_d(v.first, u) + v.second;
        if (d > d1[u]) {
            d2[u] = d1[u];
            d1[u] = d;
            p1[u] = v.first;
        } else if (d > d2[u])
            d2[u] = d;
    }
    if (d1[u] == -mod) {
        d1[u] = 0;
        d2[u] = 0;
        is_leaf[u] = true;
    }
    return d1[u];
}

void dfs_u(int u, int father)
{
    for (auto v : g[u]) {
        if (v.first == father)
            continue;
        if (p1[u] == v.first)
            up[v.first] = max(up[u], d2[u]) + v.second;
        else
            up[v.first] = max(up[u], d1[u]) + v.second;

        dfs_u(v.first, u);
    }
}

int main()
{
    cin >> n;

    for (int i = 1; i <= n - 1; i++) {
        int a, b, c;
        cin >> a >> b >> c;

        g[a].push_back({b, c});
        g[b].push_back({a, c});
    }
    dfs_d(1, -1);
    dfs_u(1, -1);
    int res = d1[1];
    for (int i = 2; i <= n; i++) {
        if (is_leaf[i])
            res = min(up[i], res);
        else
            res = min({max(up[i], d1[i]), res});
    }

    cout << res << endl;
}