/*
  Problem Name:欧拉回路
  algorithm tag:欧拉回路
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

const int N = 1e5 + 5, M = 4e5 + 5;

int n, m, t;
int h[N], e[M], ne[M], idx;
bool used[M];
int ans[M / 2], cnt;
int din[N], dout[N];

void add(int a, int b)
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

int main()
{
    iosf;
    memset(h, -1, sizeof h);
    cin >> t;
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        int a, b;
        cin >> a >> b;
        if (t == 1)
            add(a, b), add(b, a);
        else
            add(a, b);
        dout[a]++, dout[b]++;
    }
}