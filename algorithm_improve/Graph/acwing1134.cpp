/*
  Problem Name:最短路计数
  algorithm tag:最短路
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
const int mod = 100003;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
//#define x first
//#define y second
#define iosf ios::sync_with_stdio(false), cin.tie(0), cout << fixed

const int N = 1e5 + 5;

int n, m;
int h[N], e[N * 4], ne[N * 4], idx;
int dis[N];
ll ans[N];

void add(int a, int b)
{
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx++;
}
void bfs()
{
    queue<int> q;
    q.push(1);
    dis[1] = 1;
    ans[1] = 1;
    while (q.size()) {
        int u = q.front();
        q.pop();
        for (int i = h[u]; ~i; i = ne[i]) {
            int j = e[i];
            if (dis[j]) {
                if (dis[u] + 1 == dis[j])
                    ans[j] = (ans[j] + ans[u]) % mod;
                continue;
            }

            dis[j] = dis[u] + 1;
            ans[j] = ans[u];
            q.push(j);
        }
    }
}

int main()
{
    iosf;
    cin >> n >> m;
    memset(h, -1, sizeof h);
    for (int i = 1; i <= m; i++) {
        int a, b;
        cin >> a >> b;
        add(a, b), add(b, a);
    }

    bfs();
    for (int i = 1; i <= n; i++)
        cout << ans[i] << endl;
}