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

const int N = 1e5 + 5;

int n, m, k;
int dp[15][N];
int f[N];
int a[15], b[15], c[15];
int cost[N];
int main()
{
    iosf;

    cin >> n >> m >> k;

    a[1] = 1, b[1] = 1, c[1] = k;
    for (int i = 2; i <= n + 1; i++)
        cin >> a[i] >> b[i] >> c[i];

    memset(dp, 0x3f, sizeof dp);
    dp[0][0] = 0;
    for (int i = 1; i <= n + 1; i++) {
        for (int j = 0; j <= 1e5; j++) {
            dp[i][j] = dp[i - 1][j];
            if (j - b[i] >= 0)
                dp[i][j] = min(dp[i][j], dp[i][j - b[i]] + c[i]);
            else
                dp[i][j] = min(dp[i][j], dp[i][0] + c[i]);
        }
    }

    for (int i = 1; i <= m; i++) {
        int x, y;
        cin >> x >> y;
        cost[x] = y;
    }
    memset(f, 0x3f, sizeof f);
    f[0] = 0;
    for (int i = 1; i <= m; i++) {
        f[i] = f[i - 1] + dp[n + 1][cost[i]];
    }
    cout << f[m] << endl;
}