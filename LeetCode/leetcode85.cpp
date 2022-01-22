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
    int pre[205][205];
    int n, m;
    bool check(int l, int w)
    {
        int right = l * w;
        for (int i = 0; i < n - l; i++) {
            for (int j = 0; j < m - w; j++) {
                int tmp = pre[i + l][j + w] - pre[i + l][j] - pre[i][j + w] + pre[i][j];
                if (tmp == right)
                    return true;
            }
        }
        return false;
    }
    int maximalRectangle(vector<vector<char>> &matrix)
    {
        memset(pre, 0, sizeof pre);

        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[i].size(); j++) {
                pre[i][j] = matrix[i][j];
                if (i)
                    pre[i][j] += matrix[i - 1][j];
                if (j)
                    pre[i][j] += matrix[i][j - 1];
                if (i && j)
                    pre[i][j] -= pre[i - 1][j - 1];
            }
        }
        int ans = 0;
        n = matrix.size(), m = matrix[0].size();

        for (int i = 1; i <= n; i++) {
            int l = 1, r = m;
            while (l < r) {
                int mid = l + r >> 1;
                if (check(i, mid)) {
                    ans = max(ans, mid * i);
                    l = mid + 1;
                } else
                    r = mid;
            }
        }

        return ans;
    }
};