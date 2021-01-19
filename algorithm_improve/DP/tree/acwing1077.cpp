/*
  Problem Name:皇宫看守
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
const int INF = 1e9;
typedef pair<int, int> pii;

const int N = 1505;

int n;
vector<int> g[N];
int w[N];
bool st[N];
int dp[N][3];

void dfs(int u)
{
    int cut = INF;
    bool flag = 0;
    for (auto v : g[u]) {
        dfs(v);
        dp[u][0] += min(dp[v][2], dp[v][1]);
        dp[u][2] += min({dp[v][1], dp[v][2], dp[v][0]});
        cut = min(cut, abs(dp[v][2] - dp[v][1]));
        if (dp[v][2] <= dp[v][1]) {
            flag = 1;
        }
    }
    if (cut == INF) {
        dp[u][0] = 0;
        dp[u][1] = INF;
        dp[u][2] = w[u];
        return;
    }
    dp[u][2] += w[u];
    if (flag)
        dp[u][1] = dp[u][0];
    else
        dp[u][1] = dp[u][0] + cut;
}

int main()
{
    cin >> n;

    for (int i = 1; i <= n; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        w[a] = b;
        while (c--) {
            int x;
            cin >> x;
            g[a].push_back(x);
            st[x] = true;
        }
    }
    int root = 1;
    while (st[root])
        root++;
    dfs(root);
    if (n == 1)
        cout << w[root] << endl;
    else
        cout << min(dp[root][1], dp[root][2]) << endl;
}