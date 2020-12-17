/*
  Problem Name:愤怒的小鸟
  algorithm tag:状态压缩DP，最小重复覆盖问题，dancing link 
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
typedef pair<double, double> pdd;

#define fi first
#define se second

const int N = 18, M = 1 << 18;
const double eps = 1e-8;

int n, m;
pdd q[N];
int path[N][N];
int f[M];

int cmp(double x, double y)
{
    if (fabs(x - y) < eps)
        return 0;
    if (x < y)
        return -1;
    return 1;
}
int main()
{
    int t;
    cin >> t;
    while (t--) {
        cin >> n >> m;

        for (int i = 0; i < n; i++)
            cin >> q[i].fi >> q[i].se;

        memset(path, 0, sizeof path);
        for (int i = 0; i < n; i++) {
            path[i][i] = 1 << i;
            for (int j = 0; j < n; j++) {
                double x1, x2, y1, y2;
                x1 = q[i].fi, x2 = q[j].fi;
                y1 = q[i].se, y2 = q[j].se;
                if (!cmp(x1, x2)) //两个点不能相等否则斜率为无穷大
                    continue;
                double a = (y1 / x1 - y2 / x2) / (x1 - x2);
                double b = y1 / x1 - a * x1;

                if (cmp(a, 0) >= 0)
                    continue;
                int state = 0;
                for (int k = 0; k < n; k++) {
                    double x = q[k].fi, y = q[k].se;
                    if (!cmp(a * x * x + b * x, y))
                        state += 1 << k;
                }
                path[i][j] = state; //path存的是两点经过的猪的状态
            }
        }

        memset(f, 0x3f, sizeof f);
        f[0] = 0;
        for (int i = 0; i + 1 < 1 << n; i++) {
            int x = 0;
            for (int j = 0; j < n; j++)
                if (!(i >> j & 1)) {
                    x = j;
                    break;
                }
            for (int j = 0; j < n; j++) {
                f[i | path[x][j]] = min(f[i] + 1, f[i | path[x][j]]);
            }
        }
        cout << f[(1 << n) - 1] << endl;
    }
}
