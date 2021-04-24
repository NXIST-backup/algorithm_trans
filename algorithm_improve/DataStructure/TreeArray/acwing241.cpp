/*
  Problem Name:楼兰图腾
  algorithm tag:树状数组,线段树,分块
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

const int N = 2e5 + 50;
int n;
ll a[N], tr[N];

int lowbit(int x)
{
    return x & -x;
}

void add(int x, int c)
{
    for (int i = x; i <= n; i += lowbit(i))
        tr[i] += c;
}

int sum(int x)
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

    for (int i = 1; i <= n; i++)
        cin >> a[i];

    ll anx = 0, any = 0;

    for (int i = 1; i <= n; i++) {
        anx += (ll)sum(a[i]) * (a[i] - sum(a[i]) - 1);
        int t = sum(n) - sum(a[i]);
        any += (ll)t * (n - a[i] - t);
        add(a[i], 1);
    }

    cout << any << " " << anx << endl;
}