/*
  Problem Name:Programming Contest
  algorithm tag:meet in the middle
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

const int N = 42;

int n, t;
int w[N];
vector<int> a, b;
ll max(ll a, ll b)
{
    if (a > b)
        return a;
    else
        return b;
}
void dfs(int l, int r, int sum)
{
    if (sum > t)
        return;
    if (l == r) {
        a.push_back(sum);
        return;
    }
    dfs(l + 1, r, sum + w[l + 1]);
    dfs(l + 1, r, sum);
}

int main()
{
    cin >> n >> t;

    for (int i = 1; i <= n; i++)
        cin >> w[i];
    dfs(0, n / 2, 0);
    swap(a, b);
    dfs(n / 2, n, 0);
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    ll ans = 0;
    for (int i = 0; i < a.size(); i++) {
        int tnp = lower_bound(b.begin(), b.end(), t - a[i] + 1) - b.begin() - 1;
        ans = max(b[tnp] + a[i], ans);
    }
    cout << ans << endl;
}