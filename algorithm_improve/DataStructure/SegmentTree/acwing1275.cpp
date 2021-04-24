/*
  Problem Name:最大数
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

const int N = 2e5 + 4;

int m, p;
struct Node
{
    int l, r;
    int v;
} tr[N * 4];

void pushup(int u)
{
    tr[u].v = max(tr[u << 1].v, tr[u << 1 | 1].v);
}
void build(int u, int l, int r)
{
    tr[u] = {l, r};
    if (l == r)
        return;
    int mid = l + r >> 1;
    build(u << 1, l, mid), build(u << 1 | 1, mid + 1, r);
    pushup(u);
}
int query(int u, int l, int r)
{
    if (tr[u].l >= l && tr[u].r <= r)
        return tr[u].v;
    int mid = tr[u].l + tr[u].r >> 1;
    int v = 0;
    if (l <= mid)
        v = query(u << 1, l, r);
    if (r > mid)
        v = max(v, query(u << 1 | 1, l, r));
    return v;
}
void modify(int u, int x, int v)
{
    if (tr[u].l == tr[u].r && tr[u].l == x)
        tr[u].v = v;
    else {
        int mid = tr[u].l + tr[u].r >> 1;
        if (x <= mid)
            modify(u << 1, x, v);
        else
            modify(u << 1 | 1, x, v);
        pushup(u);
    }
}
int main()
{
    iosf;
    cin >> m >> p;
    build(1, 1, m);
    int idx = 0;
    int last = 0;
    for (int i = 1; i <= m; i++) {
        char c;
        int a;
        cin >> c >> a;
        if (c == 'A')
            modify(1, idx + 1, (last + a) % p), idx++;
        else {
            last = query(1, idx - a + 1, idx);
            cout << last << endl;
        }
    }
}