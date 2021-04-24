/*
  Problem Name:一个简单的整数问题
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

const int N = 1e5 + 50;
int n, m;
int tr[N], a[N];

int lowbit(int x)
{
    return x & -x;
}

void add(int x, int c)
{
    for (int i = x; i <= n; i += lowbit(i))
        tr[i] += c;
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
    cin >> n >> m;

    for (int i = 1; i <= n; i++)
        cin >> a[i];

    while (m--) {
        char c;
        cin >> c;
        if (c == 'C') {
            int x, y, z;
            cin >> x >> y >> z;
            add(x, z);
            add(y + 1, -z);
        } else {
            int x;
            cin >> x;
            int t = query(x);
            cout << t + a[x] << endl;
        }
    }
}