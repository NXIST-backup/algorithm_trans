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
#include <stack>
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
    vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
    {
        int q[1005] = {0};
        int hh = 0, tt = -1;
        vector<int> ans;
        map<int, int> mp;
        for (int i = 0; i < nums2.size(); i++) {
            while (hh <= tt && nums2[i] > nums2[q[tt]])
                mp[nums2[q[tt]]] = nums2[i], tt--;
            q[++tt] = i;
        }
        while (hh <= tt)
            mp[nums2[q[tt]]] = -1, tt--;

        for (int i = 0; i < nums1.size(); i++)
            ans.push_back(mp[nums1[i]]);
        return ans;
    }
};
int main()
{
    vector<int> a = {2, 4};
    vector<int> b = {1, 2, 3, 4};
    Solution s;
    auto t = s.nextGreaterElement(a, b);
    for (auto item : t)
        cout << item << " ";
    cout << endl;
}