/*
  Problem Name:维护序列
  algorithm tag:线段树,懒标记
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
int n, p, m;
int a[N];
struct Node
{
    int l, r;
    ll sum, add, mul;
} tr[N * 4];

void pushup(int u)
{
    tr[u].sum = (tr[u << 1].sum + tr[u << 1 | 1].sum) % p;
}
void eval(Node &t, ll add, ll mul)
{
    t.sum = (t.sum * mul % p + (ll)(t.r - t.l + 1) * add % p) % p;
    t.mul = t.mul * mul % p;
    t.add = (t.add * mul % p + add) % p;
}
void pushdown(int u)
{
    eval(tr[u << 1], tr[u].add, tr[u].mul);
    eval(tr[u << 1 | 1], tr[u].add, tr[u].mul);
    tr[u].add = 0, tr[u].mul = 1;
}
void build(int u, int l, int r)
{
    if (l == r)
        tr[u] = {l, r, a[l], 0, 1};
    else {
        tr[u] = {l, r, 0, 0, 1};
        int mid = l + r >> 1;
        build(u << 1, l, mid), build(u << 1 | 1, mid + 1, r);
        pushup(u);
    }
}
void modify(int u, int l, int r, ll add, ll mul)
{
    if (tr[u].l >= l && tr[u].r <= r)
        eval(tr[u], add, mul);
    else {
        pushdown(u);
        int mid = tr[u].l + tr[u].r >> 1;
        if (l <= mid)
            modify(u << 1, l, r, add, mul);
        if (r > mid)
            modify(u << 1 | 1, l, r, add, mul);
        pushup(u);
    }
}
int query(int u, int l, int r)
{
    if (tr[u].l >= l && tr[u].r <= r)
        return tr[u].sum;
    pushdown(u);
    int v = 0;
    int mid = tr[u].l + tr[u].r >> 1;
    if (l <= mid)
        v = query(u << 1, l, r);
    if (r > mid)
        v = (v + query(u << 1 | 1, l, r)) % p;
    return v;
}

int main()
{
    iosf;
    cin >> n >> p;

    for (int i = 1; i <= n; i++)
        cin >> a[i];

    build(1, 1, n);

    cin >> m;

    while (m--) {
        int t, l, r, d;
        cin >> t >> l >> r;
        if (t == 1) {
            cin >> d;
            modify(1, l, r, 0, d);
        } else if (t == 2) {
            cin >> d;
            modify(1, l, r, d, 1);
        } else
            cout << query(1, l, r) << endl;
    }
}