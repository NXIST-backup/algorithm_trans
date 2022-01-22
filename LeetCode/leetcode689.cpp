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
    int n;
    int pre[20005];
    int f[20005][15];
    void init(vector<int> sum)
    {
        memset(f, 0, sizeof f);
        int m = sum.size();
        for (int j = 0; j < 15; j++) {
            for (int i = 0; i + (1 << j) - 1 < m; i++) {
                if (!j)
                    f[i][j] = sum[i];
                else
                    f[i][j] = max(f[i][j - 1], f[i + (1 << (j - 1))][j - 1]);
            }
        }
    }
    int query(int l, int r)
    {
        int len = r - l + 1;
        int k = log(len) / log(2);
        return max(f[l][k], f[r - (1 << k) + 1][k]);
    }
    vector<int> maxSumOfThreeSubarrays(vector<int> &nums, int k)
    {
        vector<int> sum;
        memset(pre, 0, sizeof pre);
        n = nums.size();
        for (int i = 0; i < n; i++)
            pre[i + 1] = pre[i] + nums[i];

        for (int i = k; i <= n; i++)
            sum.push_back(pre[i] - pre[i - k]);

        init(sum);
        for (int i = 1; i < sum.size() - k; i++) {
            int l = query(0, i - 1);
            int r = query(i + 1, sum.size() - 1);

            if ()
        }
    }
};
