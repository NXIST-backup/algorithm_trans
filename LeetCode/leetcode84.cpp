/*
  Problem Name:
  algorithm tag: 单调栈
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
    int largestRectangleArea(vector<int> &heights)
    {
        int tt = 0;
        int q[100005], w[100005];
        memset(q, 0, sizeof q);
        memset(w, 0, sizeof w);
        for (int i = 0; i < heights.size(); i++) {
            while (tt && heights[q[tt]] >= heights[i])
                tt--;
            if (tt)
                w[i] += i - q[tt] - 1;
            else
                w[i] += i - q[tt];
            q[++tt] = i;
        }
        tt = 0;
        reverse(heights.begin(), heights.end());
        for (int i = 0; i < heights.size(); i++) {
            while (tt && heights[q[tt]] >= heights[i])
                tt--;
            if (tt)
                w[heights.size() - 1 - i] += i - q[tt] - 1;
            else
                w[heights.size() - 1 - i] += i - q[tt];
            q[++tt] = i;
        }

        reverse(heights.begin(), heights.end());
        int ans = 0;
        for (int i = 0; i < heights.size(); i++)
            ans = max(ans, heights[i] * (w[i] + 1));
        return ans;
    }
};
int main()
{
    vector<int> h = {2, 4};
    Solution s;
    cout << s.largestRectangleArea(h) << endl;
}