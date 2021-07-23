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

const int M = 300050, N = 505;
ll f[M], dp[M];
int n, m, r;
int day[M];
int d[N], k[N], c[N], idx = 0;
int q[M];
bool mp[M];
vector<pii> days;
int main()
{
    scanf("%d %d %d", &n, &m, &r);
    for (int i = 1; i <= n; i++)
        scanf("%d %d %d", &d[i], &k[i], &c[i]);
    int sum = 0;
    for (int i = 1; i <= m; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        days.push_back({x, y});
        for (int j = 1; j <= y; j++)
            day[++idx] = x;
    }
    sort(days.begin(), days.end());
    sort(day + 1, day + idx + 1);

    for (auto item : days) {
        sum += item.second;
        mp[sum] = 1;
    }

    for (int i = 1; i <= idx; i++)
        f[i] = 1ll * i * r;
    k[n + 1] = 1, c[n + 1] = r;

    for (int i = 1; i <= idx; i++)
        dp[i] = 1e17;

    for (int i = 1; i <= n + 1; i++) {
        for (int j = 0; j <= idx; j++)
            dp[j] = min(dp[j], dp[max(0, j - k[i])] + c[i]);
    }
    int last = 0;
    for (int i = 1; i <= n; i++) {
        int hh = 0, tt = 0;
        for (int j = 1; j <= idx; j++) {
            while (hh <= tt && (j - q[hh] > k[i] || day[j] - day[q[hh] + 1] + 1 > d[i]))
                hh++;
            f[j] = min(f[j], f[q[hh]] + c[i]);
            if (mp[j] && i == n) {
                int bag = j - last;
                f[j] = min(f[j], f[last] + dp[bag]);
                last = j;
            }
            while (hh <= tt && f[j] <= f[q[tt]])
                tt--;
            q[++tt] = j;
        }
    }
    printf("%lld\n", f[idx]);
}
