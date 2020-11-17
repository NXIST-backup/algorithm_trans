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

const int N = 55;
int n, m;
int g[N][N];
int dp[N][N][N][N];
int main()
{
    cin >> n >> m;

    for (int i = 1; i <= n;i++){
        for (int j = 1; j <= m;j++)
            cin >> g[i][j];
    }

    for (int i = 1; i <= n;i++){
        for (int j = 1; j <= m;j++){
            for (int l = 1; l <= n;l++){
                for (int r = 1; r <= m;r++){
                    int t = g[i][j];
                    if(i!=l&&j!=r)
                        t += g[l][r];
                    dp[i][j][l][r] = max(dp[i][j][l][r], dp[i - 1][j][l - 1][r] + t);
                    dp[i][j][l][r] = max(dp[i][j][l][r], dp[i][j - 1][l - 1][r] + t);
                    dp[i][j][l][r] = max(dp[i][j][l][r], dp[i - 1][j][l][r - 1] + t);
                    dp[i][j][l][r] = max(dp[i][j][l][r], dp[i][j - 1][l][r - 1] + t);
                }
            }
        }
    }
    cout << dp[n][m][n][m] << endl;
}