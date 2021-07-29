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
    vector<int> pathInZigZagTree(int label)
    {
        vector<int> re;
        re.push_back(label);
        while (label != 1) {
            int j = label;
            int res = 1;
            int ans = 0;
            while (j) {
                ans += res;
                res <<= 1;
                j >>= 1;
            }
            res >>= 1;
            label = ans - label + res;
            label >>= 1;
            re.push_back(label);
        }
        reverse(re.begin(), re.end());
        return re;
    }
};

int main()
{
    Solution a;
    a.pathInZigZagTree(26);
}
