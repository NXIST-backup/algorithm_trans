/*
  Problem Name:加成数列
  algorithm tag:DFS,迭代加深
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

const int N = 105;

int n;
int path[N];

bool dfs(int u, int dep)
{
    if (u > dep)
        return false;
    if (path[u - 1] == n)
        return true;

    bool st[N] = {0};

    for (int i = u - 1; i >= 0; i--) {
        for (int j = i; j >= 0; j--) {
            int s = path[i] + path[j];
            if (s > n || s < path[u - 1] || st[s])
                continue;
            st[s] = 1;
            path[u] = s;
            if (dfs(u + 1, dep))
                return true;
        }
    }
    return false;
}

int main()
{
    iosf;
    path[0] = 1;
    while (cin >> n, n) {
        int dep = 1;
        while (!dfs(1, dep))
            dep++;
        for (int i = 0; i < depth; i++)
            cout << path[i] << " ";
        cout << endl;
    }
}