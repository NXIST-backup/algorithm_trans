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
    long long a[1005];
    long long dp[1005];
    map<long long, long long> sum[1005];
    int numberOfArithmeticSlices(vector<int> &nums)
    {
        for (int i = 0; i < nums.size(); i++)
            a[i + 1] = nums[i];
        int n = nums.size();
        // for (int i = 1; i <= n; i++)
        //     for (int j = 1; j < i; j++) {
        //         sum[i][a[i] - a[j]] += 1;
        //     }

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j < i; j++) {
                if (a[i] - a[j])
                    sum[i][a[i] - a[j]] += sum[j][a[i] - a[j]] + 1;
                else
                    sum[i][a[i] - a[j]] = sum[j][a[i] - a[j]] * 2 + 1;
                dp[i] += sum[j][a[i] - a[j]];
            }
        }
        int cnt = 0;
        for (int i = 1; i <= n; i++)
            cnt += dp[i];
        return cnt;
    }
};

int main()
{
    Solution a;
    vector<int> s = {2, 4, 6, 8, 10};
    cout << a.numberOfArithmeticSlices(s) << endl;
}
