/*
  Problem Name:Transformable Teacher
  algorithm tag:前缀和
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

const int N = 2e5 + 5;

ll min(ll a, ll b)
{
    if (a > b)
        return b;
    else
        return a;
}

int n, m;
int a[N];
int w[N];
ll pre[N], suf[N];

int main()
{
    cin >> n >> m;

    for (int i = 1; i <= n; i++)
        cin >> a[i];
    sort(a + 1, a + 1 + n);
    for (int j = 1; j <= m; j++)
        cin >> w[j];
    //sort(w + 1, w + 1 + n);
    int idx = 1;
    for (int i = 1; i <= n - 1; i += 2) {
        pre[idx] = pre[idx - 1] + a[i + 1] - a[i];
        idx++;
    }
    idx = 1;
    for (int i = n - 1; i >= 1; i -= 2) {
        suf[idx] = suf[idx - 1] + a[i + 1] - a[i];
        idx++;
    }
    ll ans = 1e18;
    for (int i = 1; i <= m; i++) {
        int t = lower_bound(a + 1, a + 1 + n, w[i]) - a;
        ll cur = 0;
        if (t % 2)
            cur = abs(a[t] - w[i]);
        else
            cur = abs(w[i] - a[t - 1]);
        ll res = 0;
        res = pre[(t - 1) / 2] + suf[n / 2 - (t - 1) / 2] + cur;
        ans = min(res, ans);
    }

    cout << ans << endl;
}