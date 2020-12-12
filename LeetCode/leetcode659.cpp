/*
  Problem Name:分割数组为连续子序列
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
const int mod = 1e9 + 7;
typedef pair<int, int> pii;
class Solution
{
  public:
    bool isPossible(vector<int> &nums)
    {
        map<int, int> mp;
        int idx = 1;
        for (int i = 0; i < nums.size(); i++) {
            if (!mp[nums[i]]) {
                mp[nums[i]] = idx++;
            }
        }
        priority_queue<int, vector<int>, greater<int>> heap[10005];
        heap[mp[nums[0]]].push(1);
        bool is_valid = true;
        for (int i = 1; i < nums.size(); i++) {
            if (heap[mp[nums[i] - 1]].size()) {
                int t = heap[mp[nums[i] - 1]].top();
                heap[mp[nums[i] - 1]].pop();
                t++;
                heap[mp[nums[i]]].push(t);
            } else
                heap[mp[nums[i]]].push(1);
        }

        for (int i = 1; i <= nums.size(); i++) {
            if (heap[i].size()) {
                if (heap[i].top() < 3) {
                    is_valid = false;
                    break;
                }
            }
        }
        return is_valid;
    }
};
int main()
{
    vector<int> s;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        s.push_back(x);
    }
    Solution a;
    cout << a.isPossible(s) << endl;
}