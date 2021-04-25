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

const int N = 2e5 + 5;
int n;
struct Node
{
    int l, r;
    int num;
} tr[N * 4];

void pushup(int u)
{
    tr[u].num = tr[u << 1].num + tr[u << 1 | 1].num;
}
void build(int u, int l, int r)
{
    tr[u] = {l, r};
    if (l == r)
        return;
    int mid = tr[u].l + tr[u].r >> 1;
    build(u << 1, l, mid), build(u << 1 | 1, mid + 1, r);
    pushup(u);
}
void modify(int u, int x, int v)
{
    if (tr[u].l == x && tr[u].r == x)
        tr[u].num += v;
    else {
        int mid = tr[u].l + tr[u].r >> 1;
        if (x <= mid)
            modify(u << 1, x, v);
        else
            modify(u << 1 | 1, x, v);
    }
}
int query(int u, int l, int r)
{
    if (tr[u].l >= l && tr[u].r <= r)
        return tr[u].num;
    int mid = tr[u].l + tr[u].r >> 1;
    int v = 0;
    if (l <= mid)
        v = query(u << 1, l, r);
    if (r > mid)
        v += query(u << 1, l, r);
    return v;
}
int main()
{
    iosf;
    cin >> n;
    build(1, 1, N);
    for (int i = 1; i <= n; i++)
        modify(1, 0, 1);

    cout << query(1, 2, 10) << endl;
}