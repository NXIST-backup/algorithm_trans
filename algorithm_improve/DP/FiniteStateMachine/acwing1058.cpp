/*
  Problem Name:股票买卖Ⅴ
  algorithm tag:状态机dp,linear dp
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
int w[N];
int dp[N][3];
int n;
int main()
{
    cin >> n;

    for (int i = 1; i <= n; i++)
        cin >> w[i];

    dp[0][0] = -1e9;

    for (int i = 1; i <= n; i++) {
        dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] - w[i]);
        dp[i][1] = max(dp[i - 1][1], dp[i - 1][2]);
        dp[i][2] = dp[i - 1][0] + w[i];
    }

    int res = 0;
    for (int i = 1; i <= n; i++) {
        int tmp = max(dp[i][0], dp[i][2]);
        res = max(res, tmp);
    }
    cout << res << endl;
}