/*
  Problem Name:谜一样的牛
  algorithm tag:树状数组
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
int n;
int tr[N], a[N];
vector<int> ans;

int lowbit(int x)
{
    return x & -x;
}
void add(int x, int v)
{
    for (int i = x; i <= n; i += lowbit(i))
        tr[i] += v;
}
int query(int x)
{
    int res = 0;
    for (int i = x; i; i -= lowbit(i))
        res += tr[i];
    return res;
}

int main()
{
    iosf;
    cin >> n;

    for (int i = 2; i <= n; i++)
        cin >> a[i];

    for (int i = 1; i <= n; i++)
        add(i, 1);
    ans.push_back(a[n] + 1);
    add(a[n] + 1, -1);
    for (int i = n - 1; i >= 1; i--) {
        int key = a[i] + 1;
        int l = 1, r = n;
        while (l < r) {
            int mid = l + r >> 1;
            if (query(mid) < key)
                l = mid + 1;
            else
                r = mid;
        }
        ans.push_back(l);
        add(l, -1);
    }
    reverse(ans.begin(), ans.end());

    for (auto item : ans)
        cout << item << endl;
}