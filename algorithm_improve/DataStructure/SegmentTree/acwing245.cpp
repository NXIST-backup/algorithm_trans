/*
  Problem Name:你能回答这些问题吗
  algorithm tag:线段树
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

const int N = 5e5 + 50;
int n, m;
struct Node
{
    int l, r;
    int tmax;
    int lmax, rmax;
    int sum;
} tr[N * 4];
int w[N];

void pushup(Node &u, Node &l, Node &r)
{
    u.sum = l.sum + r.sum;
    u.lmax = max(l.lmax, l.sum + r.lmax);
    u.rmax = max(r.rmax, r.sum + l.rmax);
    u.tmax = max(max(l.tmax, r.tmax), l.rmax + r.lmax);
}

void pushup(int u)
{
    pushup(tr[u], tr[u << 1], tr[u << 1 | 1]);
}

void build(int u, int l, int r)
{
    if (l == r)
        tr[u] = {l, r, w[r], w[r], w[r], w[r]};
    else {
        tr[u] = {l, r};
        int mid = l + r >> 1;
        build(u << 1, l, mid), build(u << 1 | 1, mid + 1, r);
        pushup(u);
    }
}

void modify(int u, int x, int v)
{
    if (tr[u].l == x && tr[u].r == x)
        tr[u] = {x, x, v, v, v, v};
    else {
        int mid = tr[u].l + tr[u].r >> 1;
        if (x <= mid)
            modify(u << 1, x, v);
        else
            modify(u << 1 | 1, x, v);
        pushup(u);
    }
}

Node query(int u, int l, int r)
{
    if (tr[u].l >= l && tr[u].r <= r)
        return tr[u];
    else {
        int mid = tr[u].l + tr[u].r >> 1;
        Node left = {0, 0, -INF, -INF, -INF}, right = {0, 0, -INF, -INF, -INF}, res;
        if (l <= mid)
            left = query(u << 1, l, r);
        if (r > mid)
            right = query(u << 1 | 1, l, r);
        pushup(res, left, right);
        return res;
    }
}
int main()
{
    iosf;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> w[i];
    build(1, 1, n);

    while (m--) {
        int t, a, b;
        cin >> t >> a >> b;

        if (t == 1) {
            if (a > b)
                swap(a, b);
            cout << query(1, a, b).tmax << endl;
        } else
            modify(1, a, b);
    }
}