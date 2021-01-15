/*
  Problem Name: 树的最长路径
  algorithm tag: 树形DP
*/
//边权为负的求树的直径的做法(dp做法)
//用dp[i]以i的根的子树中和从i出发的最长长度

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

vector<pii> g[N];
int n;
int ans;

int dfs(int u, int father)
{
    int dist = 0;
    int d1 = 0, d2 = 0;

    for (auto v : g[u]) {
        if (v.first == father)
            continue;
        int d = dfs(v.first, u) + v.second;
        dist = max(dist, d);
        if (d1 <= d) {
            d2 = d1;
            d1 = d;
        } else if (d2 < d)
            d2 = d;
    }

    ans = max(ans, d1 + d2);
    return dist;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed;
    cin >> n;
    for (int i = 1; i <= n - 1; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        g[a].push_back({b, c});
        g[b].push_back({a, c});
    }

    dfs(1, -1);

    cout << ans << endl;
}