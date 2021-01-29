/*
  Problem Name:绿色通道
  algorithm tag:queue DP
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

const int N = 5e4 + 50;

int n, t;
int f[N];
int a[N], q[N];

bool check(int m)
{
    int hh = 0, tt = 0;
    for (int i = 1; i <= n; i++) {
        if (q[hh] < i - m - 1) //烽火那题是包括i这题是不包括i
            hh++;
        f[i] = f[q[hh]] + a[i];
        while (tt >= hh && f[q[tt]] >= f[i])
            tt--;
        q[++tt] = i;
    }

    for (int i = n - m; i <= n; i++) {
        if (f[i] <= t)
            return true;
    }
    return false;
}

int main()
{
    iosf;

    cin >> n >> t;

    for (int i = 1; i <= n; i++)
        cin >> a[i];

    int l = 0, r = n;
    while (l < r) {
        int mid = l + r >> 1;
        if (check(mid))
            r = mid;
        else
            l = mid + 1;
    }

    cout << r << endl;
}