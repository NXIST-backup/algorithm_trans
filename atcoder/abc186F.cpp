/*
  Problem Name:Rook on Grid
  algorithm tag:树状数组，线段树
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

int a[N], tr[N];
int n, m, w;
int col[N], row[N];
vector<int> ot[N];
int lowbit(int x)
{
    return x & -x;
}

void add(int x)
{
    for (int i = x; i <= m; i += lowbit(i))
        tr[i]++;
}
ll query(int x)
{
    ll res = 0;
    for (int i = x; i; i -= lowbit(i))
        res += tr[i];
    return res;
}

int main()
{
    cin >> n >> m >> w;
    for (int i = 1; i <= n; i++) {
        row[i] = m + 1;
    }
    for (int i = 1; i <= m; i++) {
        col[i] = n + 1;
    }
    for (int i = 1; i <= w; i++) {
        int x, y;
        cin >> x >> y;
        row[x] = min(row[x], y);
        col[y] = min(col[y], x);
        ot[x].push_back(y);
    }
    ll ans = 0;
    for (int i = 1; i <= row[1] - 1; i++) {
        ans += col[i] - 1;
    }
    for (int i = row[1]; i <= m; i++) {
        add(i);
    }
    for (int i = 2; i <= col[1] - 1; i++) {
        ans += query(row[i] - 1);
        for (auto item : ot[i]) {
            if (!(query(item) - query(item - 1)))
                add(item);
        }
    }

    cout << ans << endl;
}