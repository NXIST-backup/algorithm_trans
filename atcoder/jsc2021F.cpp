/*
  Problem Name:	F - Max Matrix
  algorithm tag: 线段树，离散化，平衡树
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
typedef pair<ll, int> pli;
//#define x first
//#define y second
#define iosf ios::sync_with_stdio(false), cin.tie(0), cout << fixed

const int N = 2e5 + 5;
int n, m, Q;
int a[N], b[N];
map<int, int> mp;
map<int, int> mp1;
int idx;
struct Node
{
    int l, r;
    ll sum;
    int num;
} tr1[N * 4], tr2[N * 4];
// a           b
void pushup(int u, Node tr[])
{
    tr[u].sum = tr[u << 1].sum + tr[u << 1 | 1].sum;
    tr[u].num = tr[u << 1].num + tr[u << 1 | 1].num;
}

void build(int u, int l, int r, Node tr[])
{
    tr[u] = {l, r};
    if (l == r)
        return;
    int mid = l + r >> 1;
    build(u << 1, l, mid, tr), build(u << 1 | 1, mid + 1, r, tr);
    pushup(u, tr);
}
void modify(int u, int x, int v, Node tr[])
{
    if (tr[u].l == x && tr[u].r == x) {
        tr[u].num += v;
        tr[u].sum = (ll)tr[u].num * mp1[x];
    } else {
        int mid = tr[u].l + tr[u].r >> 1;
        if (x <= mid)
            modify(u << 1, x, v, tr);
        else
            modify(u << 1 | 1, x, v, tr);
        pushup(u, tr);
    }
}
pli query(int u, int l, int r, Node tr[])
{
    if (tr[u].l >= l && tr[u].r <= r)
        return {tr[u].sum, tr[u].num};
    int mid = tr[u].l + tr[u].r >> 1;
    pli res = {0, 0};
    if (l <= mid)
        res = query(u << 1, l, r, tr);
    if (r > mid) {
        auto temp = query(u << 1 | 1, l, r, tr);
        res.first += temp.first;
        res.second += temp.second;
    }
    return res;
}
struct quest
{
    int t, x, y;
} seg[N];

int main()
{
    iosf;
    cin >> n >> m >> Q;

    ll ans = 0;
    build(1, 0, N, tr1);
    build(1, 0, N, tr2);
    for (int i = 1; i <= n; i++)
        modify(1, 0, 1, tr1);
    for (int i = 1; i <= m; i++)
        modify(1, 0, 1, tr2);
    priority_queue<int, vector<int>, greater<int>> heap;
    for (int i = 1; i <= Q; i++) {
        int t, x, y;
        cin >> t >> x >> y;
        heap.push(y);
        seg[i] = {t, x, y};
    }
    int ls = -1;
    while (heap.size()) {
        int t = heap.top();
        heap.pop();
        if (t != ls) {
            mp[t] = ++idx;
            mp1[idx] = t;
        }
        ls = t;
    }
    for (int i = 1; i <= Q; i++) {
        int t = seg[i].t, x = seg[i].x, y = seg[i].y;
        if (t == 1) {
            int last = a[x];
            a[x] = y;
            int pnum = query(1, 0, mp[last], tr2).second;
            ll psum = query(1, mp[last] + 1, N, tr2).first;
            modify(1, mp[last], -1, tr1);
            modify(1, mp[y], 1, tr1);
            int snum = query(1, 0, mp[y], tr2).second;
            ll ssum = query(1, mp[y] + 1, N, tr2).first;
            ans += (ll)snum * y + ssum - (ll)pnum * last - psum;
        } else {
            int last = b[x];
            b[x] = y;
            int pnum = query(1, 0, mp[last], tr1).second;
            ll psum = query(1, mp[last] + 1, N, tr1).first;
            modify(1, mp[last], -1, tr2);
            modify(1, mp[y], 1, tr2);
            int snum = query(1, 0, mp[y], tr1).second;
            ll ssum = query(1, mp[y] + 1, N, tr1).first;
            ans += (ll)snum * y + ssum - (ll)pnum * last - psum;
        }

        cout << ans << endl;
    }
}