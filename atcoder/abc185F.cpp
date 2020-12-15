/*
  Problem Name:Range Xor Query
  algorithm tag:树状数组 线段树
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

const int N = 3e5 + 5;

int n, q;
int a[N], tr[N];

int lowbit(int x)
{
    return x & -x;
}
void add(int x, int v)
{
    for (int i = x; i <= n; i += lowbit(i))
        tr[i] ^= v;
}
int query(int x)
{
    int res = 0;
    for (int i = x; i; i -= lowbit(i))
        res ^= tr[i];
    return res;
}
int main()
{
    cin >> n >> q;

    for (int i = 1; i <= n; i++)
        cin >> a[i];

    for (int i = 1; i <= n; i++)
        add(i, a[i]);

    while (q--) {
        int t, x, y;
        cin >> t >> x >> y;

        if (t == 1) {
            add(x, y);
        } else {
            int ans = query(y) ^ query(x - 1);
            cout << ans << endl;
        }
    }
}