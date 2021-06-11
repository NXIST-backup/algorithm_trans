/*
  Problem Name:零钱兑换 II
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
int dp[5005];
class Solution
{
  public:
    int change(int amount, vector<int> &coins)
    {
        dp[0] = 1;

        for (int i = 0; i < coins.size(); i++)
            for (int j = coins[i]; j <= amount; j++)
                dp[j] = dp[j] + dp[j - coins[i]];
        return dp[amount];
    }
};

int main()
{
    int n;
    cin >> n;
    vector<int> a = {10};

    Solution A;
    cout << A.change(n, a) << endl;
}