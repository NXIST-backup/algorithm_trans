/*
  Problem Name:最优乘车
  algorithm tag:BFS
*/
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <sstream>
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

int n, m;
vector<int> g[505];
int st[505];
int stop[505];

void bfs()
{
    queue<int> q;
    q.push(1);
    st[1] = 0;
    while (q.size()) {
        int u = q.front();
        q.pop();
        st[u]++;
        if (u == n)
            return;
        for (auto v : g[u]) {
            if (st[v])
                continue;
            st[v] = st[u];
            // cout << u << " " << st[u] << " " << v << " " << st[v] << endl;
            q.push(v);
        }
    }
}

int main()
{
    cin >> m >> n;
    string line;
    getline(cin, line);
    while (m--) {
        getline(cin, line);
        stringstream ssin(line);
        int cnt = 0, p;
        while (ssin >> p)
            stop[cnt++] = p;
        for (int j = 0; j < cnt; j++)
            for (int k = j + 1; k < cnt; k++) {
                g[stop[j]].push_back(stop[k]);
            }
    }

    bfs();

    if (st[n])
        cout << st[n] - 2 << endl;
    else
        cout << "NO" << endl;
}
