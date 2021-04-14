/*
  Problem Name:区间
  algorithm tag:图论，差分约束，spfa，前缀和
*/

#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <stack>
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

const int N = 5e4 + 50, M = 3 * N;
int n;
int h[N], e[M], ne[M], w[M], idx;
int dist[N], cnt[N];
bool st[N];

void add(int a, int b, int c)
{
    e[idx] = b;
    ne[idx] = h[a];
    w[idx] = c;
    h[a] = idx++;
}

void spfa()
{
    memset(dist, -0x3f, sizeof dist);
    queue<int> q;
    q.push(0);
    dist[0] = 0;
    st[0] = true;

    while (q.size()) {
        int u = q.front();
        q.pop();

        st[u] = false;

        for (int i = h[u]; ~i; i = ne[i]) {
            int v = e[i];
            if (dist[v] < dist[u] + w[i]) {
                dist[v] = dist[u] + w[i];
                if (!st[v]) {
                    q.push(v);
                    st[v] = true;
                }
            }
        }
    }
}

int main()
{
    iosf;
    cin >> n;
    memset(h, -1, sizeof h);
    for (int i = 1; i <= n; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        a++, b++;
        add(a - 1, b, c);
    }
    for (int i = 1; i <= 50001; i++)
        add(i - 1, i, 0), add(i, i - 1, -1); // S_i>=S_{i-1}  S_i-S_{i-1}<=1

    spfa();

    cout << dist[50001] << endl;
}