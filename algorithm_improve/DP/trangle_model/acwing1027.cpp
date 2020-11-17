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

const int N = 15;
int n;
int dp[N + 10][N][N];
int g[N][N];

int main()
{
    cin >> n;

    int a, b, c;

    while (cin >> a >> b >> c, a && b && c) {
        g[a][b] += c;
    }

    for (int k = 2; k <= n+n; k++) {
        for (int i1 = 1; i1 <= n; i1++) {
            for (int i2 = 1; i2 <= n; i2++) {
                int j1 = k - i1, j2 = k - i2;
                if(j1>=1&&j1<=n&&j2>=1&&j2<=n){
                    int t = g[i1][j1];
                    if (i1 != i2)
                        t += g[i2][j2];
                    dp[k][i1][i2] = max(dp[k][i1][i2], dp[k-1][i1 - 1][i2 - 1] + t);
                    dp[k][i1][i2] = max(dp[k][i1][i2], dp[k-1][i1 - 1][i2] + t);
                    dp[k][i1][i2] = max(dp[k][i1][i2], dp[k-1][i1][i2 - 1] + t);
                    dp[k][i1][i2] = max(dp[k][i1][i2], dp[k-1][i1][i2] + t);
                }
            }
        }
    }

    cout << dp[n + n][n][n] << endl;
}
