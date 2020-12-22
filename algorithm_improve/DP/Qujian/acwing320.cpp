/*
  Problem Name:能量项链
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

const int N = 210;
int n;
pii a[N];
int pre[N];
int dp[N][N];

int main()
{
    cin >> n;

    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        a[i].second = x;
        if (i < n) {
            a[i + 1].first = x;
        } else
            a[1].first = x;
    }
    for (int i = n + 1; i <= 2 * n; i++) {
        a[i] = a[i - n];
    }

    for (int i = 1; i <= 2 * n; i++) {
        cout << "(" << a[i].first << "," << a[i].second << ")"
             << " ";
    }
    cout << endl;
    pre[1] = a[1].first * a[1].second;
    for (int i = 2; i <= 2 * n; i++) {
        pre[i] = pre[i - 1] * a[i].second;
    }
    for (int i = 1; i <= 2 * n; i++) {
        cout << pre[i] << " ";
    }
    cout << endl;
    for (int i = 0; i <= 2 * n; i++) {
        for (int j = 0; j <= 2 * n; j++)
            dp[i][j] = 1;
    }

    pre[0] = 1;
    pre[2 * n + 1] = 1;
    for (int len = 2; len <= n; len++) {
        for (int i = 1; len + i - 1 <= 2 * n; i++) {
            int l = i, r = len + i - 1;
            dp[l][r] = -1e9;
            for (int k = l; k < r; k++) {
                dp[l][r] = max(dp[l][r], dp[l][k] * dp[k + 1][r] + pre[r] / pre[l - 1]);
            }
        }
    }
    int ans = -1e9;
    for (int i = 1; i <= n + 1; i++) {
        ans = max(ans, dp[i][n + i - 1]);
    }
    cout << ans << endl;
}
