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

const int N = 105;

int g[N][N];
int n;
int dp[N][N];
int main()
{
    cin >> n;

    for (int i = 1; i <= n;i++){
        for (int j = 1; j <= n;j++)
            cin >> g[i][j];
    }
    for (int i = 2; i <= n;i++) {
        g[0][i] = INF;
        g[i][0] = INF;
    }

    for (int i = 1; i <= n;i++){
        for (int j = 1; j <= n;j++){
            dp[i][j] = min(dp[i - 1][j] + g[i - 1][j], dp[i][j - 1] + g[i][j - 1]);
        }
    }

    cout << dp[n][n]+g[n][n] << endl;
}