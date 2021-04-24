/*
  Problem Name:一个简单的整数问题2
  algorithm tag:树状数组,线段树,分块
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

const int N = 1e5 + 50;

int n, m;
ll a[N], tr1[N], tr2[N];

int lowbit(int x)
{
    return x & -x;
}
void add(ll tr[], int x, ll v)
{
    for (int i = x; i <= n; i += lowbit(i))
        tr[i] += v;
}
ll query(ll tr[], int x)
{
    ll res = 0;
    for (int i = x; i; i -= lowbit(i))
        res += tr[i];
    return res;
}
ll get_sum(int x)
{
    return query(tr1, x) * (x + 1) - query(tr2, x);
}
int main()
{
    iosf;
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        int x = a[i] - a[i - 1];
        add(tr1, i, x), add(tr2, i, (ll)x * i);
    }

    while (m--) {
        char c;
        cin >> c;
        if (c == 'C') {
            int l, r, d;
            cin >> l >> r >> d;
            add(tr1, l, d), add(tr2, l, (ll)l * d);
            add(tr1, r + 1, -d), add(tr2, r + 1, (ll)(r + 1) * -d);
        } else {
            int l, r;
            cin >> l >> r;
            cout << get_sum(r) - get_sum(l - 1) << endl;
        }
    }
}