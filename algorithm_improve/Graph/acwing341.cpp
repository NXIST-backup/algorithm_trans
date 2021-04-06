/*
  Problem Name:最优贸易
  algorithm tag:DP
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
//#define x first
//#define y second
#define iosf ios::sync_with_stdio(false), cin.tie(0), cout << fixed
//三种做法
//spfa分层图
//dfs 记忆化搜索
//spfa

const int N = 1e5 + 5, M = 1e6 + 5;
int h[N], hb[N], e[M], ne[M], idx;
int val[N];
int n, m;
bool is_valid[N];

void add(int h[], int a, int b)
{
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx++;
}
void dfs(int u)
{
    is_valid[u] = 1;

    for (int i = hb[u]; ~i; i = ne[i]) {
        int j = e[i];
        if (!is_valid[j])
            dfs(j);
    }
}

int main()
{
    iosf;
    cin >> n >> m;

    for (int i = 1; i <= n; i++)
        cin >> val[i];

    for (int i = 1; i <= m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        add(h, a, b);
        add(hb, b, a);
        if (c == 2)
            add(h, b, a), add(hb, a, b);
    }

    dfs(n);

}