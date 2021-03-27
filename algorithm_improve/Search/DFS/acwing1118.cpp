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
const int INF = 1e9;
const int mod = 1e9 + 7;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
//#define x first
//#define y second
#define iosf ios::sync_with_stdio(false), cin.tie(0), cout << fixed

int n;
int g[15];
int ans;
int res;
int st[15];

bool check()
{
    for (int i = 1; i <= n; i++) {
        if (!st[i])
            return false;
    }
    return true;
}

void dfs(int x)
{
    if (check()) {
        ans = min(ans, res);
    }

    for (int i = 1; i <= n; i++) {
        if (i == x)
            continue;
        if (__gcd(g[i], g[x]) && st[i]) {
            st[x] = st[i];
            for (int j = 1; j <= n; j++) {
                if (!st[i])
                    dfs(j);
            }
            st[x] = 0;
        }
    }
    st[x] = ++res;
    for (int i = 1; i <= n; i++)
        if (!st[i])
            dfs(i);
}

int main()
{
    iosf;

    cin >> n;

    for (int i = 1; i <= n; i++)
        cin >> g[i];

    ans = n;

    dfs(1);

    cout << ans << endl;
}