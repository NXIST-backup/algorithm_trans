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
const int N = 10005;
const int MOD = 1e9 + 7;
int dp[105][N];
class Solution
{
  public:
    int profitableSchemes(int n, int minProfit, vector<int> &group, vector<int> &profit)
    {
        memset(dp, 0, sizeof dp);
        for (int i = 0; i <= n; i++)
            dp[i][0] = 1;

        for (int i = 0; i < group.size(); i++)
            for (int j = n; j >= group[i]; j--)
                for (int k = minProfit; k >= 0; k--)
                    dp[j][k] = (dp[j][k] + dp[j - group[i]][max(0, k - profit[i])]) % MOD;

        return dp[n][minProfit];
    }
};

int main()
{
    iosf;
    int n, m;
    cin >> n >> m;
    vector<int> a = {2, 3, 5};
    vector<int> b = {6, 7, 8};

    Solution A;
    cout << A.profitableSchemes(n, m, a, b) << endl;
}