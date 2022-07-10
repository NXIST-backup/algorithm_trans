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

// class Solution
// {
//   public:
//     int lenLongestFibSubseq(vector<int> &arr)
//     {
//         int n = arr.size();
//         vector<int> a;
//         a.push_back(0);
//         for (int i = 0; i < n; i++)
//             a.push_back(arr[i]);

//         map<int, int> dp[1005];

//         for (int i = 1; i <= n; i++) {
//             for (int j = 1; j < i; j++) {
//                 int dif = a[i] - a[j];
//                 dp[i][dif] = 1;
//                 int last = dp[j][dif];
//                 if (j == 1)
//                     last = 1;
//                 dp[i][dif] = max(dp[i][dif], last + 1);
//             }
//         }
//         int ans = 2;
//         for (auto v : dp[n]) {
//             ans = max(ans, v.second);
//         }
//         return ans;
//     }
// };
int dp[1005][1005];
class Solution
{
  public:
    int lenLongestFibSubseq(vector<int> &arr)
    {
        int n = arr.size();
        for (int i = 2; i <= 1000; i++)
            dp[1][i] = 1;
        int ans = 2;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                int k = lower_bound(arr.begin(), arr.end(), arr[i] - arr[j]) - arr.begin();
                dp[i][j] = 2;
                dp[i][j] = max(dp[i][j], dp[j][k] + 1);
                ans = max(ans, dp[i][j]);
            }
        }
        return ans > 2 ? ans : 0;
    }
};
int main()
{
    vector<int> arr = {1, 3, 7, 11, 12, 14, 18};
    Solution s;
    cout << s.lenLongestFibSubseq(arr) << endl;
}
