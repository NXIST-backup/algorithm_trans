/*
  Problem Name:观光之旅
  algorithm tag:求最小环,floyd,集合划分
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
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
//#define x first
//#define y second
#define iosf ios::sync_with_stdio(false), cin.tie(0), cout << fixed

const int N = 105;

int n, m;
int g[N][N], d[N][N];
int path[N], cnt;
int pos[N][N];

void get_path(int i, int j)
{
    if (!pos[i][j])
        return;
    int k = pos[i][j];
    get_path(i, k);
    path[cnt++] = k;
    get_path(k, j);
}
int main()
{
    iosf;
    cin >> n >> m;
    memset(g, 0x3f, sizeof g);
    for (int i = 1; i <= m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        g[a][b] = g[b][a] = min(g[a][b], c);
    }

    memcpy(d, g, sizeof d);
    int res = INF;
    for (int k = 1; k <= n; k++) {
        //求最小环路径以及经过的点
        for (int i = 1; i < k; i++) {
            for (int j = i + 1; j < k; j++) {
                if ((ll)d[i][j] + g[i][k] + g[k][j] < res) {
                    res = d[i][j] + g[i][k] + g[k][j];
                    cnt = 0;
                    path[cnt++] = k;
                    path[cnt++] = i;
                    get_path(i, j);
                    path[cnt++] = j;
                }
            }
        }
        //求最短路
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (d[i][j] > d[i][k] + d[k][j]) {
                    d[i][j] = d[i][k] + d[k][j];
                    pos[i][j] = k;
                }
            }
        }
    }

    if (res == INF)
        cout << "No solution.";
    else
        for (int i = 0; i < cnt; i++)
            cout << path[i] << " ";
    puts("");
}