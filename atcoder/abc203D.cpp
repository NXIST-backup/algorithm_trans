/*
  Problem Name:Pond
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

const int N = 805;
int n, k;
int g[N][N];
int pre[N][N];

int main()
{
    iosf;
    cin >> n >> k;

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> g[i][j];

    int l = 0, r = 1e9;
    while (l < r) {
        int mid = l + r >> 1;

        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                pre[i][j] = pre[i - 1][j] + pre[i][j - 1] - pre[i - 1][j - 1] + (g[i][j] <= mid);
        bool flag = false;
        int res = 0;
        for (int i = k; i <= n; i++) {
            for (int j = k; j <= n; j++)
                if (pre[i][j] - pre[i - k][j] - pre[i][j - k] + pre[i - k][j - k] >= (k * k - 1) / 2 + 1) {
                    flag = true;
                    break;
                }
            if (flag)
                break;
        }
        if (flag)
            r = mid;
        else
            l = mid + 1;
    }
    cout << l << endl;
}