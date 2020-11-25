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

const int N = 3005;
int a[N], b[N];
int dp[N][N];
int n;

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
        cin >> b[i];

    for (int i = 1; i <= n; i++) {
        int maxv = 1;
        for (int j = 1; j <= n; j++) {
            dp[i][j] = dp[i - 1][j];
            if (a[i] == b[j])
                dp[i][j] = max(dp[i][j], maxv);
            if (a[i] > b[j])
                maxv = max(maxv, dp[i][j] + 1);
        }
    }
    int res = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            res = max(res, dp[i][j]);
    cout << res << endl;
}
//无优化
void solve()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
        cin >> b[i];

    for (int i = 1; i <= n;i++){
        for (int j = 1; j <= n;j++){
            dp[i][j] = dp[i - 1][j];
            if(a[i]==b[j]){
                dp[i][j] = max(dp[i][j], 1);
                for (int k = 1; k < j;k++)
                    if(b[j]>b[k])
                        dp[i][j] = max(dp[i][j], dp[i][k] + 1);
            }
        }
    }
    int res = 0;
    for (int i = 1; i <= n;i++)
        res = max(res, dp[n][i]);
    cout << res << endl;
}