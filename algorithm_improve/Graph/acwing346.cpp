/*
  Problem Name:走廊泼水节
  algorithm tag:最小生成树扩展，kruskal,完全图
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
const int INF = 1e9;
const int mod = 1e9 + 7;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define x first
#define y second
#define iosf ios::sync_with_stdio(false), cin.tie(0), cout << fixed

const int N = 6005, M = N * N / 2;

int fa[N];
int num[N];
int n;
struct Edge
{
    int a, b, w;

    bool operator<(const Edge &W) const
    {
        return w < W.w;
    }
} edge[M];

int find(int x)
{
    if (fa[x] != x)
        fa[x] = find(fa[x]);
    return fa[x];
}

int main()
{
    iosf;

    int _;
    cin >> _;
    while (_--) {
        cin >> n;
        for (int i = 1; i <= n; i++)
            fa[i] = i, num[i] = 1;

        for (int i = 1; i < n; i++) {
            int a, b, w;
            cin >> a >> b >> w;
            edge[i] = {a, b, w};
        }

        sort(edge + 1, edge + n);
        int res = 0;
        for (int i = 1; i <= n - 1; i++) {
            int a = edge[i].a, b = edge[i].b, w = edge[i].w;
            a = find(a), b = find(b);

            if (a != b) {
                res += (num[a] * num[b] - 1) * (w + 1); //一定要加1否则树不唯一
                fa[a] = b;
                num[b] += num[a];
            }
        }

        cout << res << endl;
    }
}