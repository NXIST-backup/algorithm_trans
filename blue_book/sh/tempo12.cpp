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

const int N = 1e6 + 5;
int n;
vector<int> lis;
int idx;
int a[N], b[N];
int f[N][21];
int pos[N];
void init()
{
    for (int j = 0; j < 20; j++)
        for (int i = 1; i + (1 << j) - 1 <= lis.size(); i++)
            if (!j)
                f[i][j] = pos[i];
            else
                f[i][j] = min(f[i][j - 1], f[i + (1 << j - 1)][j - 1]);
}
int query(int l, int r)
{
    int len = r - l + 1;
    int k = log(len) / log(2);
    return min(f[l][k], f[r - (1 << k) + 1][k]);
}
int find(int x)
{
    int l = 0;
    int r = lis.size() - 1;
    while (l < r) {
        int mid = l + r >> 1;
        if (lis[mid] >= x)
            r = mid;
        else
            l = mid + 1;
    }
    return r + 1;
}
int main()
{
    iosf;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        lis.push_back(a[i]);
    }
    sort(lis.begin(), lis.end());
    lis.erase(unique(lis.begin(), lis.end()), lis.end());
    for (int i = n; i >= 1; i--)
        a[i] = find(a[i]);
    for (int i = 1; i <= n; i++)
        if (!pos[a[i]])
            pos[a[i]] = i;
    init();
    int ans = 0;
    int min_l = 1e6 + 19;
    for (int r = n; r >= 1; r--) {
        int l = r;
        if (a[r] + 1 <= lis.size())
            l = query(a[r] + 1, lis.size());
        if (r < min_l)
            ans++;
        if (l < min_l)
            min_l = l;
    }
    cout << ans << endl;
}