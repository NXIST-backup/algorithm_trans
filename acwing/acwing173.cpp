/*
  Problem Name:
  algorithm tag:
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

const int N = 1005;

int n, m;
string s[N];
int g[N][N];
int st[N][N];

pii q[N * N];
int hh, tt;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int main()
{
    iosf;
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            g[i + 1][j + 1] = s[i][j] - '0';
            if (g[i + 1][j + 1] == 1) {
                q[++tt] = {i + 1, j + 1};
                st[i + 1][j + 1] = 1;
            }
        }
    }

    while (hh <= tt) {
        pii t = q[hh++];

        for (int i = 0; i < 4; i++) {
            int x = t.first + dx[i], y = t.second + dy[i];

            if (st[x][y] || x <= 0 || y <= 0 || x > n || y > m)
                continue;

            q[++tt] = {x, y};
            st[x][y] += st[t.first][t.second] + 1;
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cout << st[i][j] - 1 << " ";
        }
        cout << endl;
    }
}