//背包问题求具体方案
//tag:背包九讲

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

const int N = 1005;

int n, m;
int dp[N][N];
int g[N][N];
int w[N], v[N];

void solve1()
{
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        cin >> v[i] >> w[i];
    }

    for (int i = n; i >= 1; i--) {
        for (int j = 0; j <= m; j++) {
            dp[i][j] = dp[i + 1][j];
            if (j >= v[i])
                dp[i][j] = max(dp[i][j], dp[i + 1][j - v[i]] + w[i]);
        }
    }

    int j = m;

    for (int i = 1; i <= n; i++)
        if (j >= v[i] && dp[i][j] == dp[i + 1][j - v[i]] + w[i]) {
            cout << i << " ";
            j -= v[i];
        }
}

void solve2()//非字典序求具体方案g数组求法
{
    cin >> n >> m;

    for (int i = 1; i <= n;i++){
        cin >> v[i] >> w[i];
    }

    for (int i = 1; i <= n;i++){
        for (int j = 0; j <= m;j++){
            int maxv = dp[i - 1][j];
            if(j>=v[i])
                maxv = max(maxv, dp[i - 1][j - v[i]] + w[i]);
            if(maxv==dp[i-1][j])
                g[i][j] = 0;
            else if(maxv==dp[i-1][j-v[i]]+w[i])
                g[i][j] = 1;
        }
    }

    cout << dp[n][m] << endl;

    int j = m;

    for (int i = n; i >= 1;i--){
        if (j >= v[i] && g[i][j] == 1){
            cout << i << " ";
            j -= v[i];
        }
    }
}

int main()
{
    solve1();
}