/*
  Problem Name:能量石
  algorithm tag:背包,贪心
*/

#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
#include <map>
#include <unordered_map>
#include <cmath>
#include <cstdio>
#include <vector>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
const int INF = 1e9;
typedef pair<int,int> pii;
int t;
int f[10005];

struct Stone
{
    int s, e, l;
    bool operator<(const Stone &x) const
    {
        return s * x.l < x.s * l;
    }
} stone[105];

int main()
{
    cin >> t;
    int idx = 0;

    while (t--) {
        int n;
        cin >> n;
        int m = 0;
        memset(f, 0xcf, sizeof f);
        f[0] = 0;
        for (int i = 1; i <= n; i++) {
            int s, e, l;
            cin >> s >> e >> l;
            stone[i] = {s, e, l};
            m += s;
        }

        //贪心缩小枚举范围
        sort(stone + 1, stone + 1 + n);
        //为什么使用"恰好j"而不是"不超过j"
        //我的理解是这样的：首先"恰好j"加上遍历体积也是可以算出"不超过j"的最大值的
        //事实上"不超过j"的是包含f[0~m]的最值，
        //而我们取max的f[j-s]+"e-(j-s)*l"<-这里的j是确定的。
        //所以得出来的结果会是有错的。
        for (int i = 1; i <= n; i++) {
            int s = stone[i].s;
            int e = stone[i].e;
            int l = stone[i].l;
            for (int j = m; j >= s; j--) {
                f[j] = max(f[j], max(f[j - s] + e - (j - s) * l, 0));
            }
        }

        int res = 0;
        for (int i = 1; i <= m; i++)
            res = max(res, f[i]);

        printf("Case #%d: %d\n", ++idx, res);
    }
}