/*
  Problem Name:MAD TEAM
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
#define x first
#define y second
#define iosf ios::sync_with_stdio(false), cin.tie(0), cout << fixed

const int N = 3005;
int n;
pii a[N], b[N], c[N], d[N], e[N];
struct Person
{
    int a, b, c, d, e;
} pson[N];

int get_min(int a, int b, int c, int d, int e)
{
    return min(min(a, b), min(min(c, d), e));
}
int get_max(int i, int j, pii a[])
{
    int tmp = n;
    for (int i = tmp; i >= 1; i--) {
        if (a[tmp].y != i && a[tmp].y != j)
            return a[tmp].x;
    }
    return -INF;
}

int main()
{
    iosf;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        a[i].y = b[i].y = c[i].y = d[i].y = e[i].y = i;
        cin >> a[i].x >> b[i].x >> c[i].x >> d[i].x >> e[i].x;
        pson[i] = {a[i].x, b[i].x, c[i].x, d[i].x, e[i].x};
    }

    sort(a + 1, a + n + 1);
    sort(b + 1, b + n + 1);
    sort(c + 1, c + n + 1);
    sort(d + 1, d + n + 1);
    sort(e + 1, e + n + 1);
    int ans = -INF;
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            int res = 0;
            int a1 = max(pson[i].a, pson[j].a);
            int b1 = max(pson[i].b, pson[j].b);
            int c1 = max(pson[i].c, pson[j].c);
            int d1 = max(pson[i].d, pson[j].d);
            int e1 = max(pson[i].e, pson[j].e);
            int mn = get_min(a1, b1, c1, d1, e1);
            if (mn == a1)
                res = get_min(get_max(i, j, a), b1, c1, d1, e1);
            if (mn == b1)
                res = get_min(a1, get_max(i, j, b), c1, d1, e1);
            if (mn == c1)
                res = get_min(a1, b1, get_max(i, j, c), d1, e1);
            if (mn == d1)
                res = get_min(a1, b1, c1, get_max(i, j, d), e1);
            if (mn == e1)
                res = get_min(a1, b1, c1, d1, get_max(i, j, e));
            ans = max(ans, res);
        }
    }

    cout << ans << endl;
}