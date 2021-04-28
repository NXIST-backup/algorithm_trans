/*
  Problem Name:第K小数
  algorithm tag:权值线段树,可持久化线段树
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
int root[N], idx;
vector<int> lis;
struct Node
{
    int l, r;
    int cnt;
} tr[N * 32];

int find(int x)
{
    return lower_bound(lis.begin(), lis.end(), x) - lis.begin() + 1;
}

int insert(int l, int r, int pre, int x)
{
    int now = ++idx;
    tr[now] = tr[pre];
    if (l == r) {
        tr[now].cnt++;
        return now;
    }
    int mid = l + r >> 1;
    if (x <= mid)
        tr[now].l = insert(l, mid, tr[pre].l, x);
    else
        tr[now].r = insert(mid + 1, r, tr[pre].r, x);
    tr[now].cnt = tr[tr[now].l].cnt + tr[tr[now].r].cnt;
    return now;
}

int query(int l, int r, int pre, int now, int k)
{
    if (l == r)
        return l;
    int cnt = tr[tr[now].l].cnt - tr[tr[pre].l].cnt;
    int mid = l + r >> 1;
    if (k <= cnt)
        return query(l, mid, tr[pre].l, tr[now].l, k);
    else
        return query(mid + 1, r, tr[pre].r, tr[now].r, k - cnt);
}
int main()
{
    iosf;
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        lis.push_back(a[i]);
    }
    sort(lis.begin(), lis.end());
    lis.erase(unique(lis.begin(), lis.end()), lis.end());

    for (int i = 1; i <= n; i++)
        root[i] = insert(1, lis.size(), root[i - 1], find(a[i]));

    while (m--) {
        int l, r, k;
        cin >> l >> r >> k;

        cout << lis[query(1, lis.size(), root[l - 1], root[r], k) - 1] << endl;
    }
}