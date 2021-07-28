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
    map<int, int> st;
    int a[100005], q[100005];
    int minOperations(vector<int> &target, vector<int> &arr)
    {
        int idx = 0;
        for (auto i : target)
            st[i] = ++idx;
        idx = 0;
        for (auto i : arr)
            if (st[i])
                a[idx++] = st[i];

        int len = 0;
        for (int i = 0; i < idx; i++) {
            int l = 0, r = len;
            while (l < r) {
                int mid = l + r + 1 >> 1;
                if (q[mid] < a[i])
                    l = mid;
                else
                    r = mid - 1;
            }
            len = max(len, r + 1);
            q[r + 1] = a[i];
        }

        return target.size() - len;
    }
};