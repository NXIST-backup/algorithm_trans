//有依赖的背包
//泛化背包

#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
#include <map>
#include <unordered_map>
#include <cmath>
#include <cstdio>
#include <vector>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
const int INF = 1e9;
typedef pair<int,int> pii;

const int N = 104;

int n, m;
int v[N], w[N];
int h[N], e[N], ne[N], idx;
int dp[N][N];

void add(int a,int b)
{
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx++;
}

void dfs(int u)
{
    for (int i = h[u]; ~i;i=ne[i]){
        
        int son = e[i];
        
        dfs(son);

        for (int j = m - v[u]; j >= 0;j--)
            for (int k = 0; k <= j;k++)
                dp[u][j] = max(dp[u][j], dp[u][j - k] + dp[son][k]);
    }
    for (int i = m; i >= v[u];i--)
        dp[u][i] = dp[u][i - v[u]] + w[u];
    for (int i = 0; i < v[u];i++)
        dp[u][i] = 0;
}

int main()
{
    cin >> n >> m;
    int root = 0;
    memset(h, -1, sizeof h);
    for (int i = 1; i <= n;i++){
        int p;
        cin >> v[i] >> w[i] >> p;
        if(p==-1)
            root = i;
        else
            add(p, i);
    }
    dfs(root);

    cout << dp[root][m] << endl;
}