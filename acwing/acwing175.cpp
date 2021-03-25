/*
  Problem Name:电路维修
  algorithm tag:双端BFS
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
#define iosf ios::sync_with_stdio(false), cin.tie(0), cout << fixed

const int N = 505 * 505;
const int M = N << 2;

int t;
int n, m;
bool st[N];
int dist[N];
int h[N], e[M], ne[M], w[M], idx;

void add(int a, int b, int c)
{
    e[idx] = b;
    w[idx] = c;
    ne[idx] = h[a];
    h[a] = idx++;
}

void init()
{
    memset(h, -1, sizeof h);
    memset(st, 0, sizeof st);
    memset(dist, 0x3f, sizeof dist);
}

int dij()
{
    dist[0] = 0;
    priority_queue<pii, vector<pii>, greater<pii>> q;
    q.push({0, 0});

    while (q.size()) {
        int u = q.top().second;
        q.pop();

        if (st[u])
            continue;
        st[u] = 1;

        for (int i = h[u]; i != -1; i = ne[i]) {
            int j = e[i];
            if (dist[j] > dist[u] + w[i]) {
                dist[j] = dist[u] + w[i];
                q.push({dist[j], j});
            }
        }
    }

    return dist[(n + 1) * (m + 1) - 1];
}

int main()
{
    iosf;

    cin >> t;

    while (t--) {
        cin >> n >> m;
        init();
        for (int i = 0; i < n; i++) {
            string s;
            cin >> s;
            for (int j = 0; j < m; j++) {
                if (s[j] == '\\') {
                    add(i * (m + 1) + j, (i + 1) * (m + 1) + j + 1, 0);
                    add((i + 1) * (m + 1) + j + 1, i * (m + 1) + j, 0);
                    add(i * (m + 1) + j + 1, (i + 1) * (m + 1) + j, 1);
                    add((i + 1) * (m + 1) + j, i * (m + 1) + j + 1, 1);
                } else {
                    add(i * (m + 1) + j, (i + 1) * (m + 1) + j + 1, 1);
                    add((i + 1) * (m + 1) + j + 1, i * (m + 1) + j, 1);
                    add(i * (m + 1) + j + 1, (i + 1) * (m + 1) + j, 0);
                    add((i + 1) * (m + 1) + j, i * (m + 1) + j + 1, 0);
                }
            }
        }
        int ans = dij();
        if (ans == 0x3f3f3f3f)
            cout << "NO SOLUTION" << endl;
        else
            cout << ans << endl;
    }
}