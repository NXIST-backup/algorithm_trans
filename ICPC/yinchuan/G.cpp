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

const int N = 1e5 + 5;

int n, q, idx;
int h[N];
int id[N], order[N];
int ans;
struct Node
{
    int h, l, r;
} lis[N], lis2[N];

int sqr(int x)
{
    return x * x;
}

void del(int idd)
{
    Node &a = lis[idd];
    Node ln = lis[a.l], rn = lis[a.r];
    if (a.l != 0)
        ans -= sqr(ln.h - a.h);
    if (a.r != n + 1)
        ans -= sqr(rn.h - a.h);
    if (a.l != 0 && a.r != n + 1)
        ans += sqr(ln.h - rn.h);
    ln.r = a.r;
    rn.l = a.l;
}

int main()
{
    iosf;
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> h[i];
        if (i > 1)
            ans += (h[i] - h[i - 1]) * (h[i] - h[i - 1]);
    }
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        order[i] = x;
        id[x] = i;
    }
    for (int i = 1; i <= n; i++) {
        int height = h[id[i]];
        lis[i] = {height, i - 1, i + 1};
    }

    while (q--) {
        int k;
        cin >> k;
        k = (k + ans) % n;
        // k+1~n~1~k
        int res = ans;
        int tmp = ans;
        memcpy(lis2, lis, sizeof lis2);
        for (int i = k; i >= 1; i--) {
            int idd = order[i];
            del(idd);
            res += ans;
        }
        for (int i = n; i >= k + 1; i--) {
            int idd = order[i];
            del(idd);
            res += ans;
        }

        cout << res << endl;
    }
}
