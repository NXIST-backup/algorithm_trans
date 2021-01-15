//有依赖的背包
//泛化背包

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
typedef pair<int, int> pii;

const int N = 104;

int n, m;
int v[N], w[N];
int h[N], e[N], ne[N], idx;
int dp[N][N];

void add(int a, int b)
{
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx++;
}

void dfs(int u)
{
    for (int i = m; i >= v[u]; i--)
        dp[u][i] = w[u];
    for (int i = h[u]; ~i; i = ne[i]) {
        int son = e[i];

        dfs(son);

        for (int j = m; j >= v[u]; j--)
            for (int k = 0; k <= j - v[u]; k++) //分配的体积
                dp[u][j] = max(dp[u][j], dp[u][j - k] + dp[son][k]);
    }
}

int main()
{
    cin >> n >> m;
    int root = 0;
    memset(h, -1, sizeof h);
    for (int i = 1; i <= n; i++) {
        int p;
        cin >> v[i] >> w[i] >> p;
        if (p == -1)
            root = i;
        else
            add(p, i);
    }
    dfs(root);

    cout << dp[root][m] << endl;
}