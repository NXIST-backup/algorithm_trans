/*
  Problem Name:战略游戏
  algorithm tag:树形dp，状态机
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
int dp[N][2];
bool st[N];
void dfs(int u)
{
    dp[u][0] = 0, dp[u][1] = 1;

    for (auto v : g[u]) {
        dfs(v);
        dp[u][0] += dp[v][1];
        dp[u][1] += min(dp[v][0], dp[v][1]);
    }
}

int main()
{
    while (cin >> n) {
        memset(dp, 0, sizeof dp);
        memset(st, 0, sizeof st);
        for (int i = 0; i < n; i++) {
            g[i].clear();
        }
        for (int i = 1; i <= n; i++) {
            int a, b;
            scanf("%d:(%d)", &a, &b);
            while (b--) {
                int x;
                cin >> x;
                g[a].push_back(x);
                st[x] = true;
            }
        }
        int root = 0;
        while (st[root])
            root++;
        dfs(root);

        cout << min(dp[root][0], dp[root][1]) << endl;
    }
}