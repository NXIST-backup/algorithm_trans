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
    bool st[20005];
    int arrayNesting(vector<int> &nums)
    {
        memset(st, 0, sizeof st);
        int ans = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (st[i])
                continue;
            int res = 0;
            dfs(i, nums, res);
            ans = max(ans, res);
        }

        return ans;
    }
    void dfs(int i, vector<int> &nums, int &cnt)
    {
        st[i] = 1;
        cnt++;
        if (!st[nums[i]])
            dfs(nums[i], nums, cnt);
    }
};

int main()
{
    vector<int> nums = {0, 1, 2};
    Solution s;
    cout << s.arrayNesting(nums) << endl;
}
