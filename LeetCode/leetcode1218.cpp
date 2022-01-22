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
    int longestSubsequence(vector<int> &arr, int difference)
    {
        vector<pair<int, int>> a;
        vector<int> dp;

        for (int i = 0; i < arr.size(); i++) {
            if (difference < 0)
                a.push_back({-arr[i], i});
            else
                a.push_back({arr[i], i});
            dp.push_back(1);
        }
        if (difference < 0)
            difference = -difference;
        sort(a.begin(), a.end());
        for (int i = 0; i < a.size(); i++) {
            if (!i)
                continue;
            int x = a[i].first - difference;
            int l = 0, r = i - 1;
            while (l < r) {
                int mid = l + r >> 1;
                if (a[mid].first < x)
                    l = mid + 1;
                else
                    r = mid;
            }
            while (a[r].first == x && a[r].second < a[i].second) {
                dp[i] = max(dp[i], dp[r++] + 1);
            }
        }
        int ans = 0;
        for (int i = 0; i < a.size(); i++)
            ans = max(ans, dp[i]);
        return ans;
    }
};

int main()
{
    vector<int> arr = {1, 3, 5, 7};
    Solution s;

    cout << s.longestSubsequence(arr, 1) << endl;
}