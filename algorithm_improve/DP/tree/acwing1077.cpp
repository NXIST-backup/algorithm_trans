/*
  Problem Name:皇宫看守
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
const int mod = 1e9 + 7;
typedef pair<int, int> pii;

const int N = 1505;

int n;
vector<int> g[N];
int w[N];
bool st[N];
int dp[N][2];

void dfs(int u)
{
    dp[u][1] = mod, dp[u][0] = mod;
    int sum = 0;
    int cut = mod;
    bool flag = false;
    for (auto v : g[u]) {
        dfs(v);
        sum += min(dp[v][1], dp[v][0]);
        cut = min(cut, abs(dp[v][1] - dp[v][0]));
        if (dp[v][1] <= dp[v][0])
            flag = true;
    }
    if (cut == mod) {
        dp[u][1] = w[u];
        dp[u][0] = 0;
        return;
    }
    dp[u][1] = sum;
    if (flag)
        dp[u][0] = sum;
    else
        dp[u][0] = sum + cut;
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

    cout << min(dp[root][1], dp[root][0]) << endl;
}