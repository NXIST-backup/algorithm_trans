/*
  Problem Name:信使
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
//#define x first
//#define y second
#define iosf ios::sync_with_stdio(false), cin.tie(0), cout << fixed

const int N = 105, M = 205;

int n, m;
vector<pii> g[N];

int main()
{
    iosf;
    cin >> n >> m;

    for (int i = 1; i <= m; i++) {
        int a, b, c;
        cin >> a >> b >> c;

        g[a].push_back({c, b});
        g[b].push_back({c, a});
    }
}