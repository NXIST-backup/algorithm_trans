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
const int N = 3e5 + 5;

int n, m, k;
ll f[N];
int a[505], b[505], c[505];
int d[N];

int bs(int x)
{
    int l = 1, r = 3e5;
    while (l < r) {
        int mid = l + r >> 1;
        if (d[mid] >= x)
            r = mid;
        else
            l = mid + 1;
    }
    return l;
}

int main()
{
    iosf;
    cin >> n >> m >> k;

    for (int i = 1; i <= n; i++)
        cin >> a[i] >> b[i] >> c[i];
    int sum = 0;
    for (int i = 1; i <= m; i++) {
        int x, y;
        cin >> x >> y;
        d[x] = y;
        sum += y;
    }
    for (int i = 1; i <= 3e5; i++)
        d[i] += d[i - 1];
    f[0] = 0;
    for (int i = 1; i <= sum; i++) {
        int day = bs(i);
        f[i] = f[i - 1] + k;
        for (int j = 1; j <= n; j++) {
            int r = d[day];
            int l = d[max(0, day - a[j])];
            while (l < r) {
                int mid = l + r >> 1;
                if (mid >= i - b[j])
                    r = mid;
                else
                    l = mid + 1;
            }
            if (l >= i - b[j])
                f[i] = min(f[i], f[l] + c[j]);
        }
    }

    cout << f[sum] << endl;
}