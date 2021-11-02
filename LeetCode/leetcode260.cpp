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
    vector<int> singleNumber(vector<int> &nums)
    {
        int xo = 0;
        for (int i = 0; i < nums.size(); i++)
            xo ^= nums[i];
        int num1 = 0, num2 = 0;
        int bit = 0;
        while (!(xo >> bit & 1))
            bit++;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] >> bit & 1)
                num1 ^= nums[i];
            else
                num2 ^= nums[i];
        }

        vector<int> ans;
        ans.push_back(num1);
        ans.push_back(num2);
        return ans;
    }
};