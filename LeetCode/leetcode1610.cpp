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
    vector<pair<double, int>> pre;
    const double Pi = 3.141592;
    int visiblePoints(vector<vector<int>> &points, int angle, vector<int> &location)
    {
        int x = location[0], y = location[1];
        int val = 180.0 / Pi;
        for (int i = 0; i < points.size(); i++) {
            int a = points[i][0], b = points[i][1];
            double k = asin((y * 1.0 - b) / (x - a)) * val;
            pre.push_back({k, 1});
        }
        sort(pre.begin(), pre.end());

        for (int i = 0; i < pre.size(); i++)
            if (!i)
                pre[i].first = pre[i].second + pre[i - 1].second;
        }
};