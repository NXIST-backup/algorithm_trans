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
    string dp[5005];
    int cmp_s(string s1, string s2)
    {
        if (s1[0] != 'A' && s2[0] == 'A')
            return 1;
        if (s1[0] == 'A' && s2[0] != 'A')
            return -1;
        if (s1.size() > s2.size())
            return 1;
        else if (s1.size() < s2.size())
            return -1;

        for (int i = s1.size() - 1; i >= 0; i++) {
            if (s1[i] > s2[i])
                return 1;
            else if (s1[i] < s2[i])
                return -1;
        }
        return 0;
    }
    string largestNumber(vector<int> &cost, int target)
    {
        for (int i = 1; i <= target; i++)
            dp[i].push_back('A');
        for (int i = 1; i <= cost.size(); i++) {
            int w = cost[i - 1];
            for (int j = w; j <= target; j++) {
                string s = dp[j - w];
                s.push_back(i + '0');
                if (cmp_s(s, dp[j]) == 1)
                    dp[j] = s;
            }
        }
        string ans;
        if (dp[target][0] != 'A')
            ans = dp[target];
        else
            ans.push_back('0');
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

int main()
{
    vector<int> cost = {2, 4, 6, 2, 4, 6, 4, 4, 4};
    int target = 5;
    Solution a;
    cout << a.largestNumber(cost, target) << endl;
}