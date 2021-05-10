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

int jobs[15];
int n, k;
vector<int> lis;
int ans;
void dfs(int u, int last)
{
    if (u == k) {
        int res = 0, iter = 0;
        last = ((1 << n) - 1) ^ last;
        while (last) {
            if (last & 1)
                res += jobs[iter];
            iter++;
            last >>= 1;
        }
        for (auto item : lis)
            res = max(item, res);
        ans = min(ans, res);
        return;
    }
    int res = 0;
    for (int i = 0; i < 1 << n; i++) {
        res = 0;
        if ((i & last) > 0)
            continue;
        int j = i, iter = 0;
        while (j) {
            if (j & 1)
                res += jobs[iter];
            j >>= 1;
            iter++;
        }
        lis.push_back(res);
        dfs(u + 1, i + last);
        lis.pop_back();
    }
}
int main()
{
    iosf;
    cin >> n >> k;
    ans = INF;
    for (int i = 0; i < n; i++)
        cin >> jobs[i];

    dfs(1, 0);
    cout << ans << endl;
}