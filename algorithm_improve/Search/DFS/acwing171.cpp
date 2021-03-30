/*
  Problem Name:送礼物
  algorithm tag:Meet in the middle
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
const int INF = 1e9;
const int mod = 1e9 + 7;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
//#define x first
//#define y second
#define iosf ios::sync_with_stdio(false), cin.tie(0), cout << fixed

const int N = 50;
vector<ll> a1, a2;
map<ll, ll> mp1, mp2;
int w, n;
ll g[N];

ll max(ll a, ll b)
{
    if (a > b)
        return a;
    else
        return b;
}

void dfs(int u, ll cnt, int ed)
{
    if (u > ed) {
        if (!mp1[cnt]) {
            a1.push_back(cnt);
            mp1[cnt]++;
        }
        return;
    }
    if (cnt + g[u] <= w)
        dfs(u + 1, cnt + g[u], ed);
    dfs(u + 1, cnt, ed);
}
void dfs2(int u, ll cnt, int ed)
{
    if (u > ed) {
        if (!mp2[cnt]) {
            a2.push_back(cnt);
            mp2[cnt]++;
        }
        return;
    }
    if (cnt + g[u] <= w)
        dfs2(u + 1, cnt + g[u], ed);
    dfs2(u + 1, cnt, ed);
}

int main()
{
    iosf;
    cin >> w >> n;

    for (int i = 1; i <= n; i++)
        cin >> g[i];

    dfs(1, 0, n / 2);

    dfs2(n / 2 + 1, 0, n);

    sort(a1.begin(), a1.end());
    sort(a2.begin(), a2.end());
    reverse(a2.begin(), a2.end());
    ll ans = 0;
    for (auto item : a2) {
        if (item > w)
            continue;
        int t = lower_bound(a1.begin(), a1.end(), w - item) - a1.begin() - 1;
        if (a1[t] + item <= w)
            ans = max(ans, a1[t] + item);
    }

    cout << ans << endl;
}