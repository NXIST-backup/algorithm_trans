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

const int N = 1005, M = 505, K = 105;

int n, m, k;
int w[K], val[K];
int dp[N][M];
int dp2[N][M];

int main()
{
    cin >> n >> m >> k;
    for (int i = 1; i <= k; i++) {
        cin >> w[i] >> val[i];
    }

    for (int i = 1; i <= k; i++) {
        for (int j = n; j >= w[i]; j--) {
            for (int l = m; l > val[i]; l--) {
                if (j >= w[i] && l >= val[i]) {
                    if (dp[j][l] < dp[j - w[i]][l - val[i]] + 1) {
                        dp[j][l] = dp[j - w[i]][l - val[i]] + 1;
                        dp2[j][l] = dp2[j - w[i]][l - val[i]] + val[i];
                    } else if (dp[j][l] == dp[j - w[i]][l - val[i]] + 1)
                        dp2[j][l] = min(dp2[j][l], dp2[j - w[i]][l - val[i]] + val[i]);
                }
            }
        }
    }
    cout << dp[n][m] << " " << m - dp2[n][m] << endl;
}
