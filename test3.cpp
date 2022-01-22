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
    int largestSumAfterKNegations(vector<int> &nums, int k)
    {
        int ans = 0;
        vector<int> neg, pos;
        sort(nums.begin(), nums.end());
        for (auto i : nums) {
            if (i >= 0)
                pos.push_back(i);
            else
                neg.push_back(i);
        }
        for (auto i : neg) {
            if (k)
                ans += -i, k--;
            else
                ans += i;
        }
        for (auto i : pos)
            ans += i;

        if (k && k % 2) {
            if (neg.size() == 0)
                return ans -= 2 * pos[0];
            if (pos.size() == 0)
                return ans -= 2 * neg.back();
            if (neg.size() && pos.size()) {
                return ans -= 2 * abs(neg.back()) > pos[0] ? pos[0] : abs(neg.back());
            }
        }
    }
};