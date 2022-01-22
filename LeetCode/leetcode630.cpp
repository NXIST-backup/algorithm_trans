/*
  Problem Name:课程表Ⅲ
  algorithm tag:最长上升子序列，贪心
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
const int mod = 1e9 + 7;
typedef pair<int, int> pii;

bool cmp(pair<int, int> a, pair<int, int> b)
{
    if (a.second < b.second)
        return true;
    else if (a.second == b.second)
        return a.first < b.first;
    else
        return false;
}
class Solution
{
  public:
    int dp[10005];
    pair<int, int> w[10005];
    int scheduleCourse(vector<vector<int>> &courses)
    {
        w[0] = {0, 0};
        memset(dp, 0, sizeof dp);
        int m = 0;
        int n = 0;
        for (int i = 0; i < courses.size(); i++) {
            if (courses[i][0] <= courses[i][1])
                w[i + 1] = {courses[i][0], courses[i][1]}, n++;
            m = max(m, courses[i][1]);
        }
        sort(w + 1, w + 1 + n, cmp);
        for (int i = 1; i <= n; i++)
            for (int j = w[i].second; j >= w[i].first; j--)
                dp[j] = max(dp[j], dp[j - w[i].first] + 1);

        int ans = 0;
        for (int i = 0; i <= m; i++)
            ans = max(ans, dp[i]);

        return ans;
    }
};
int main()
{
    vector<vector<int>> a = {{7, 16},
                             {2, 3},
                             {3, 12},
                             {3, 14},
                             {10, 19},
                             {10, 16},
                             {6, 8},
                             {6, 11},
                             {3, 13},
                             {6, 16}};
    Solution s;
    cout << s.scheduleCourse(a) << endl;
}