/*
  Problem Name:抓住那头牛
  algorithm tag:BFS
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

const int N = 1e5 + 5;

int n, k;
int st[N];
int q[N];

void bfs(int u)
{
    st[u] = 1;
    q[0] = n;
    int hh = 0, tt = 0;

    while (hh <= tt) {
        int t = q[hh++];
        if (t == k)
            return;

        if (!st[t - 1] && t - 1 >= 0) {
            st[t - 1] += st[t] + 1;
            q[++tt] = t - 1;
        }
        if (!st[t + 1] && t + 1 < N) {
            st[t + 1] += st[t] + 1;
            q[++tt] = t + 1;
        }
        if (!st[t * 2] && t * 2 < N) {
            st[t * 2] += st[t] + 1;
            q[++tt] = t * 2;
        }
    }
}

int main()
{
    iosf;
    cin >> n >> k;

    if (n < k) {
        bfs(n);
        cout << st[k] - 1 << endl;
    } else
        cout << n - k << endl;
}