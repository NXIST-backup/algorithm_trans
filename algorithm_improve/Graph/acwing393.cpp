/*
  Problem Name:雇佣收银员
  algorithm tag:图论,差分约束,spfa
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

const int N = 30, M = 121;
int n;
int h[N], e[M], ne[M], w[M], idx;
int dist[N], cnt[N];
bool st[N];
int r[N], num[N];

void add(int a, int b, int c)
{
    e[idx] = b;
    ne[idx] = h[a];
    w[idx] = c;
    h[a] = idx++;
}
void build(int s24)
{
    memset(h, -1, sizeof h);
    idx = 0;

    for (int i = 1; i <= 24; i++) {
        add(i - 1, i, 0);
        add(i, i - 1, -num[i]);
    }
    for (int i = 9; i <= 24; i++)
        add(i - 8, i, r[i]);
    for (int i = 1; i <= 8; i++)
        add(i + 16, i, r[i] - s24);
    add(24, 0, -s24), add(0, 24, s24);
}
bool spfa()
{
    memset(dist, -0x3f, sizeof dist);
    memset(st, 0, sizeof st);
    memset(cnt, 0, sizeof cnt);
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
                cnt[v] = cnt[u] + 1;
                if (cnt[v] >= N)
                    return true;
                if (!st[v]) {
                    st[v] = true;
                    q.push(v);
                }
            }
        }
    }
    return false;
}
int main()
{
    iosf;
    int _;
    cin >> _;
    while (_--) {
        for (int i = 1; i <= 24; i++)
            cin >> r[i];

        cin >> n;
        for (int i = 1; i <= n; i++) {
            int a;
            cin >> a;
            num[++a]++;
        }
        bool flag = false;
        for (int i = 0; i <= 1000; i++) {
            build(i);
            if (!spfa()) {
                cout << i << endl;
                flag = true;
                break;
            }
        }
        if (!flag)
            cout << "No Solution" << endl;
    }
}