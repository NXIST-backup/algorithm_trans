/*
  Problem Name:烽火传递
  algorithm tag:queue
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
#define iosf ios::sync_with_stdio(false), cin.tie(0), cout << fixed

const int N = 2e5 + 50;
int n, m;
int f[N], q[N], a[N];

int main()
{
    iosf;

    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        a[i] = x;
    }

    int hh = 0, tt = 0;

    for (int i = 1; i <= n; i++) {
        while (q[hh] < i - m)
            hh++;
        f[i] = f[q[hh]] + a[i];
        while (tt >= hh && f[q[tt]] >= f[i])
            tt--;
        q[++tt] = i;
    }
    int res = INF;

    for (int i = n - m + 1; i <= n; i++)
        res = min(res, f[i]);

    cout << res << endl;
}