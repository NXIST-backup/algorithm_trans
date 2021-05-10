/*
  Problem Name:
  algorithm tag:
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
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;
const double eps = 1e-4;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
//#define x first
//#define y second
#define iosf ios::sync_with_stdio(false), cin.tie(0), cout << fixed

const int N = 10 + 5;
int n;
int dp[N][N][4];
int w[N];

int max(int a, int b, int c)
{
    return max(a, max(b, c));
}

int main()
{
    iosf;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> w[i];
    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= n; j++)
            dp[i][j][2] = -INF;

    for (int j = 1; j <= n; j++) {
        for (int i = 1; i <= n; i++) {
            if (i < j)
                continue;
            dp[i][j][0] = max(dp[i - 1][j][0], dp[i - 1][j - 1][3]);
            dp[i][j][1] = max(dp[i - 1][j][1], dp[i - 1][j][0] + w[i]);
            dp[i][j][2] = max(dp[i - 1][j][2], dp[i - 1][j][0] - w[i]);
            dp[i][j][3] = max(dp[i - 1][j][3], dp[i - 1][j][1] - w[i], dp[i - 1][j][2] + w[i]);
        }
    }

    for (int i = 1; i <= n; i++)
        cout << dp[n][i][3] << endl;
}
