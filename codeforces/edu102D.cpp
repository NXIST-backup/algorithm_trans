/*
  Problem Name:Program
  algorithm tag:RMQ,线段树
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
const int mod = 1e9 + 7;
typedef pair<int, int> pii;

const int N = 2e5 + 5;
int t;
int n, m;
int pre[N];
int a[N];
int sum[N];
struct Node
{
    int l, r;
    int maxv;
    int minv;
} tr[N * 4];

void build(int u, int l, int r)
{
    if (l == r)
        tr[u] = {l, r, pre[r], pre[r]};
    else {
        tr[u] = {l, r};
        int mid = l + r >> 1;
        build(u << 1, l, mid), build(u << 1 | 1, mid + 1, r);
        tr[u].maxv = max(tr[u << 1].maxv, tr[u << 1 | 1].maxv);
        tr[u].minv = min(tr[u << 1].minv, tr[u << 1 | 1].minv);
    }
}
int querymx(int u, int l, int r)
{
    if (tr[u].l >= l && tr[u].r <= r)
        return tr[u].maxv;
    int mid = tr[u].l + tr[u].r >> 1;
    int maxv = INT_MIN;
    if (l <= mid)
        maxv = querymx(u << 1, l, r);
    if (r > mid)
        maxv = max(maxv, querymx(u << 1 | 1, l, r));
    return maxv;
}
int querymn(int u, int l, int r)
{
    if (tr[u].l >= l && tr[u].r <= r)
        return tr[u].minv;
    int mid = tr[u].l + tr[u].r >> 1;
    int minv = INT_MAX;
    if (l <= mid)
        minv = querymn(u << 1, l, r);
    if (r > mid)
        minv = min(minv, querymn(u << 1 | 1, l, r));
    return minv;
}
int main()
{
    cin >> t;

    while (t--) {
        cin >> n >> m;

        for (int i = 1; i <= n; i++) {
            char c;
            cin >> c;
            a[i] = c;
            if (a[i] == '+')
                pre[i] = pre[i - 1] + 1;
            else
                pre[i] = pre[i - 1] - 1;
            sum[i] = pre[i];
        }

        build(1, 1, n);

        while (m--) {
            int l, r;
            cin >> l >> r;
            int ans_l = 0, ans_r = 0;
            if (l == 1 && r == n) {
                cout << 1 << endl;
                continue;
            }
            if (l > 1) {
                int mx = querymx(1, 1, l - 1);
                int mn = querymn(1, 1, l - 1);
                ans_l = min(ans_l, mn);
                ans_r = max(ans_r, mx);
            }
            if (r < n) {
                int mx = querymx(1, r + 1, n);
                int mn = querymn(1, r + 1, n);

                mx -= sum[r] - sum[l - 1];
                mn -= sum[r] - sum[l - 1];
                ans_l = min(ans_l, mn);
                ans_r = max(ans_r, mx);
            }

            cout << ans_r - ans_l + 1 << endl;
        }
    }
}