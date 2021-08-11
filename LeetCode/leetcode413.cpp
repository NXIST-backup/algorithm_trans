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
    int q[5005];
    int numberOfArithmeticSlices(vector<int> &nums)
    {
        int dif = 0x3f3f3f3f;
        int ans = 0;
        int ss = 0, tt = 0;
        q[tt] = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            int t = nums[i] - nums[i - 1];
            if (t == dif || dif == 0x3f3f3f3f) {
                q[++tt] = nums[i];
                dif = t;
            } else {
                int cnt = tt - ss - 1;
                if (cnt)
                    ans += (cnt + 1) * cnt / 2;

                ss = tt;
                dif = nums[i] - q[tt];
                q[++tt] = nums[i];
            }
        }

        int cnt = tt - ss - 1;
        if (cnt)
            ans += (cnt + 1) * cnt / 2;
        return ans;
    }
};
int main()
{
    Solution a;
    vector<int> s = {1, 2, 3, 4, 9, 8, 7};
    cout << a.numberOfArithmeticSlices(s) << endl;
}