/*
  Problem Name:Queen on Grid
  algorithm tag:DP,数字三角形变种   
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

const int N = 2e3 + 5;
char g[N][N];
ll dp[N][N][4];
int n, m;

int main()
{
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            char c;
            cin >> c;
            g[i][j] = c;
        }
    }

    dp[1][1][0] = dp[1][1][1] = dp[1][1][2] = dp[1][1][3] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (i == 1 && j == 1)
                continue;
            if (g[i][j] != '#') {
                dp[i][j][0] = (dp[i - 1][j][1] + dp[i][j - 1][2] + dp[i - 1][j - 1][3]) % mod;
                dp[i][j][1] = (dp[i - 1][j][1] + dp[i][j][0]) % mod;
                dp[i][j][2] = (dp[i][j - 1][2] + dp[i][j][0]) % mod;
                dp[i][j][3] = (dp[i - 1][j - 1][3] + dp[i][j][0]) % mod;
            } else {
                dp[i][j][0] = dp[i][j][1] = dp[i][j][2] = dp[i][j][3] = 0;
                continue;
            }
        }
    }

    cout << dp[n][m][0] << endl;
}
