#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
const int INF = 1e9;
typedef pair<int, int> pii;

bool cmp(pair<int, int> a, pair<int, int> b)
{
    if (a.first < b.first)
        return true;
    else if (a.first == b.first)
        return a.second < b.second;
    else
        return false;
}

class Solution
{
  public:
    int intersectionSizeTwo(vector<vector<int>> &intervals)
    {
        int dp[3005][2];
        memset(dp, 0x3f, sizeof dp);
        dp[0][1] = dp[0][0] = 0;
        vector<pair<int, int>> list;
        list.push_back({-1, -1});
        for (int i = 0; i < intervals.size(); i++)
            list.push_back({intervals[i][0], intervals[i][1]});

        sort(list.begin(), list.end(), cmp);

        for (int i = 1; i < list.size(); i++) {
            int a = list[i - 1].first, b = list[i - 1].second;
            int l = list[i].first, r = list[i].second;
            if (l < a) {
                dp[i][1] = min(dp[i - 1][0], dp[i - 1][1]) + 1;
            } else
                dp[i][1] = min(dp[i - 1][0], dp[i - 1][1]) + 2;
        }
    }
};
