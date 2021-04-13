/*
  Problem Name:单词环
  algorithm tag:负环,spfa，01分数规划
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
const double eps = 1e-4;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
//#define x first
//#define y second
#define iosf ios::sync_with_stdio(false), cin.tie(0), cout << fixed

const int N = 26 * 26 + 25, M = 1e5 + 5;

int n;
int h[N], e[M], ne[M], w[M], idx;
double dist[N];
bool st[N];
int cnt[N];
int iter;
map<string, int> mp;

void add(int a, int b, int c)
{
    e[idx] = b;
    ne[idx] = h[a];
    w[idx] = c;
    h[a] = idx++;
}
bool spfa(double mid)
{
    memset(dist, 0, sizeof dist);
    memset(st, 0, sizeof st);
    memset(cnt, 0, sizeof cnt);
    int count = 0;
    queue<int> q;
    for (int i = 1; i <= iter; i++)
        q.push(i), st[i] = true;

    while (q.size()) {
        int u = q.front();
        q.pop();

        st[u] = false;

        for (int i = h[u]; ~i; i = ne[i]) {
            int v = e[i];
            if (dist[v] < dist[u] + w[i] - mid) {
                dist[v] = dist[u] + w[i] - mid;
                if (++count > 10000) //trick
                    return true;
                cnt[v] = cnt[u] + 1;
                if (cnt[v] >= iter) //记住是大于点数
                    return true;
                if (!st[v]) {
                    q.push(v);
                    st[v] = true;
                }
            }
        }
    }
    return false;
}

int main()
{
    iosf;
    while (cin >> n, n) {
        idx = 0;
        iter = 0;
        mp.clear();
        memset(h, -1, sizeof h);
        for (int i = 1; i <= n; i++) {
            string s, a, b;
            cin >> s;
            a = s.substr(0, 2), b = s.substr(s.size() - 2, 2);
            int x, y;
            if (!mp[a])
                mp[a] = ++iter;
            x = mp[a];
            if (!mp[b])
                mp[b] = ++iter;
            y = mp[b];
            add(x, y, s.size());
        }
        double l = 0, r = 1e6;
        while (r - l > eps) {
            double mid = (l + r) / 2;
            if (spfa(mid))
                l = mid;
            else
                r = mid;
        }
        if (l < eps)
            cout << "No solution" << endl;
        else
            printf("%.2lf\n", l);
    }
}