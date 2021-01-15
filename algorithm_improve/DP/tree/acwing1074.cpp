/*
  Problem Name:二叉苹果树
  algorithm tag:树上背包，树形DP
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

const int N = 105;

vector<pii> g[N];
int n, m;
int dp[N][N];

void dfs(int u, int fa)
{
    for (auto v : g[u]) {
        if (v.first == fa)
            continue;
        dfs(v.first, u);

        for (int i = m; i >= 0; i--) {
            for (int j = 0; j <= i - 1; j++)
                dp[u][i] = max(dp[u][i], dp[u][i - j - 1] + dp[v.first][j] + v.second);
        }
    }
}
int main()
{
    cin >> n >> m;

    for (int i = 1; i <= n - 1; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        g[a].push_back({b, c});
        g[b].push_back({a, c});
    }
    dfs(1, -1);
    cout << dp[1][m] << endl;
}