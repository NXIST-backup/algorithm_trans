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

const int N = 1e5 + 5;
int n, m;
int a[N];
struct Node
{
    int l, r;
    ll sum, add;
} tr[N * 4];

void pushup(int u)
{
    tr[u].sum = tr[u << 1].sum + tr[u << 1 | 1].sum;
}
void build(int u, int l, int r)
{
    tr[u] = {l, r};
    if (l == r)
        tr[u].sum = a[l];
    else {
        int mid = l + r >> 1;
        build(u << 1, l, mid), build(u << 1 | 1, mid + 1, r);
        pushup(u);
    }
}
void pushdown(int u)
{
    Node &root = tr[u], &left = tr[u << 1], &right = tr[u << 1 | 1];
    if (root.add) {
        left.add += root.add, right.add += root.add;
        left.sum += (ll)(left.r - left.l + 1) * root.add;
        right.sum += (ll)(right.r - right.l + 1) * root.add;
        root.add = 0;
    }
}
void modify(int u, int l, int r, int v)
{
    if (tr[u].l >= l && tr[u].r <= r) {
        tr[u].sum += (ll)(tr[u].r - tr[u].l + 1) * v;
        tr[u].add += v;
    } else {
        pushdown(u);
        int mid = tr[u].l + tr[u].r >> 1;
        if (l <= mid)
            modify(u << 1, l, r, v);
        if (r > mid)
            modify(u << 1 | 1, l, r, v);
        pushup(u);
    }
}
ll query(int u, int l, int r)
{
    if (tr[u].l >= l && tr[u].r <= r)
        return tr[u].sum;
    pushdown(u);
    int mid = tr[u].l + tr[u].r >> 1;
    ll res = 0;
    if (l <= mid)
        res = query(u << 1, l, r);
    if (r > mid)
        res += query(u << 1 | 1, l, r);
    return res;
}

int main()
{
    iosf;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    build(1, 1, n);

    while (m--) {
        char c;
        cin >> c;
        if (c == 'C') {
            int x, y, z;
            cin >> x >> y >> z;
            modify(1, x, y, z);
        } else {
            int x, y;
            cin >> x >> y;
            cout << query(1, x, y) << endl;
        }
    }
}