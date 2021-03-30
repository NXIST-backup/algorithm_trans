/*
  Problem Name:排书
  algorithm tag:IDA*
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

const int N = 15;

int n;
int q[N];
int w[5][N];

int f()
{
    int tot = 0;
    for (int i = 0; i + 1 < n; i++)
        if (q[i + 1] != q[i] + 1)
            tot++;
    return (tot + 2) / 3;
}

bool dfs(int dep, int mx_dep)
{
    if (dep + f() > mx_dep)
        return false;
    if (f() == 0)
        return true;

    for (int len = 1; len <= n; len++) {
        for (int l = 0; l + len - 1 < n; l++) {
            int r = l + len - 1;

            for (int k = r + 1; k < n; k++) {
                memcpy(w[dep], q, sizeof q);
                int y = l;
                for (int x = r + 1; x <= k; x++, y++)
                    q[y] = w[dep][x];
                for (int x = l; x <= r; x++, y++)
                    q[y] = w[dep][x];
                if (dfs(dep + 1, mx_dep))
                    return true;
                memcpy(q, w[dep], sizeof q);
            }
        }
    }
    return false;
}

int main()
{
    int T;

    cin >> T;

    while (T--) {
        cin >> n;

        for (int i = 0; i < n; i++)
            cin >> q[i];

        int dep = 0;

        while (dep < 5 && !dfs(0, dep))
            dep++;

        if (dep >= 5)
            puts("5 or more");
        else
            cout << dep << endl;
    }
}
