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

class Solution
{
  public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>> &stations)
    {
        int n = stations.size();
        int dp[505];
        memset(dp, 0, sizeof dp);
        dp[0] = startFuel;

        for (int i = 0; i < n; i++) {
            for (int j = i; j >= 0; j--) {
                if (dp[j] >= stations[i][0]) {
                    dp[j + 1] = max(dp[j + 1], dp[j] + stations[i][1]);
                }
            }
        }

        for (int i = 0; i <= n; i++)
            if (dp[i] >= target)
                return i;
        return -1;
    }
};
int main()
{
    Solution s;
    vector<vector<int>> list = {{13, 21},
                                {26, 115},
                                {100, 47},
                                {225, 99},
                                {299, 141},
                                {444, 198},
                                {608, 190},
                                {636, 157},
                                {647, 255},
                                {841, 123}};
    s.minRefuelStops(1000, 299, list);
}
