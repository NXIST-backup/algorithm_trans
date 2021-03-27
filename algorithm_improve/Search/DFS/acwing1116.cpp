/*
  Problem Name:马走日
  algorithm tag:DFS
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

int n, m;
int xa, ya;
int T;
int cnt;
int ans;
int st[10][10];
int dx[8] = {1, 1, -1, -1, 2, 2, -2, -2};
int dy[8] = {2, -2, 2, -2, 1, -1, 1, -1};

void dfs(int xa, int ya)
{
    if (cnt == n * m) {
        ans++;
        return;
    }
    st[xa][ya] = 1;
    cnt++;
    for (int i = 0; i < 8; i++) {
        int x = xa + dx[i], y = ya + dy[i];

        if (st[x][y] || x < 0 || y < 0 || x >= n || y >= m)
            continue;
        dfs(x, y);
    }
    cnt--;
    st[xa][ya] = 0;
}

int main()
{
    scanf("%d", &T);

    while (T--) {
        cnt = 1;
        ans = 0;
        memset(st, 0, sizeof st);
        scanf("%d%d%d%d", &n, &m, &xa, &ya);

        dfs(xa, ya);

        cout << ans << endl;
    }
}