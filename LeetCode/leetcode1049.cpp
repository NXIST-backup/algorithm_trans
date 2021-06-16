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
class Solution
{
  public:
    int dp[3005];
    int w[35];
    int lastStoneWeightII(vector<int> &stones)
    {
        memset(dp, 0, sizeof dp);
        memset(w, 0, sizeof w);
        int sum = 0;
        for (int i = 1; i <= stones.size(); i++)
            w[i] = stones[i - 1], sum += w[i];

        for (int i = 1; i <= stones.size(); i++)
            for (int j = sum / 2; j >= w[i]; j--)
                dp[j] = max(dp[j], dp[j - w[i]] + w[i]);
        return sum - 2 * dp[sum / 2];
    }
};
int main()
{
    iosf;
    vector<int> a = {6, 6, 3, 6, 3, 2, 5, 1};
    Solution A;
    cout << A.lastStoneWeightII(a) << endl;
}