/*
  Problem Name:环形石子合并
  algorithm tag:区间DP
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

const int N = 205;
int n;
int a[N * 2];
int dp[2 * N][2 * N];
int dp2[2 * N][2 * N];
int main()
{
    cin >> n;

    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        a[i] = a[n + i] = x;
    }
    for (int i = 1; i < 2 * n; i++)
        a[i + 1] += a[i];

    for (int len = 2; len <= n; len++) {
        for (int i = 1; len + i - 1 <= 2 * n; i++) {
            int l = i, r = len + i - 1;
            dp[l][r] = 1e9;
            dp2[l][r] = -1e9;
            for (int k = l; k < r; k++) {
                dp[l][r] = min(dp[l][r], dp[l][k] + dp[k + 1][r] + a[r] - a[l - 1]);
                dp2[l][r] = max(dp2[l][r], dp2[l][k] + dp2[k + 1][r] + a[r] - a[l - 1]);
            }
        }
    }
    int ans1 = 1e9;
    int ans2 = -1e9;
    for (int i = 1; i <= n + 1; i++) {
        ans1 = min(dp[i][i + n - 1], ans1);
        ans2 = max(dp2[i][i + n - 1], ans2);
    }
    cout << ans1 << endl;
    cout << ans2 << endl;
}