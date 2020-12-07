/*
  Problem Name:股票买卖Ⅳ
  algorithm tag:状态机dp
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

const int N = 1e5 + 5;

int dp[105][2];
int w[N];
int n, k;

int main()
{
    cin >> n >> k;

    for (int i = 1; i <= n;i++)
        cin >> w[i];
    memset(dp, 0xcf, sizeof dp);
    dp[0][0] = 0;
    for (int i = 1; i <= n;i++){
        for (int j = k; j >= 1;j--){
            dp[j][0] = dp[j][0];
            dp[j][0] = max(dp[j][0], dp[j][1] + w[i]);
            dp[j][1] = dp[j][1];
            dp[j][1] = max(dp[j][1], dp[j - 1][0] - w[i]);
        }
    }
    int res = 0;
    for (int i = 0; i <= k;i++){
        res = max(res, dp[i][0]);
    }

    cout << res << endl;
}
