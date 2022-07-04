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
    vector<vector<int>> minimumAbsDifference(vector<int> &arr)
    {
        vector<vector<int>> ans;
        sort(arr.begin(), arr.end());
        int mi = 0x3f3f3f3f;
        for (int i = 1; i < arr.size(); i++)
            mi = min(mi, arr[i] - arr[i - 1]);

        for (int i = 1; i < arr.size(); i++)
            if (arr[i] - arr[i - 1] == mi) {
                vector<int> res = {arr[i - 1], arr[i]};
                ans.push_back(res);
            }
        return ans;
    }
};
