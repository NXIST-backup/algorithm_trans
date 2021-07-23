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
    int len[55];
    bool isCovered(vector<vector<int>> &ranges, int left, int right)
    {
        memset(len, 0, sizeof len);

        for (int i = 0; i < ranges.size(); i++) {
            int l = ranges[i][0], r = ranges[i][1];
            for (int i = l; i <= r; i++)
                len[i] = 1;
        }
        for (int i = left; i <= right; i++)
            if (len[i] == 0)
                return 0;
        return 1;
    }
};
