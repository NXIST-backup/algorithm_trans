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
const int MOD = 1e9 + 7;
typedef pair<int, int> pii;

const int N = 1e3 + 50;
int n, s, a, b;
int dp[N][N];
int sum[N][N];
int main()
{
    cin >> n >> s >> a >> b;

    for (int j = 0;j<=n;j++) {
        dp[0][j] = 1;
    }
    for (int i = 1; i <= n; i++) {//a的个数
        for (int j = 1;j<=n;j++){//长度

            dp[i][j] = dp[i - 1][j - 1] + dp[i][j - 1]&MOD;
            
        }
    }
    ll ans = 0;
    for (int i = 0; i <= n; i++) {
        ans += dp[i][n] % MOD;
    }
    cout << ans << endl;
}