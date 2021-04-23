/*
  Problem Name:奇偶游戏
  algorithm tag:带权并查集
*/

#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <unordered_map>
#include <vector>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;
const double eps = 1e-4;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
//#define x first
//#define y second
#define iosf ios::sync_with_stdio(false), cin.tie(0), cout << fixed

const int N = 2e4 + 5;
int n, m;
int p[N], d[N], Size[N];
map<int, int> mp;
set<int> st;
int find(int x)
{
    if (p[x] != x) {
        int t = find(p[x]);
        d[x] += d[p[x]];
        p[x] = t;
    }

    return p[x];
}
struct Condition
{
    int a, b, type;
} condi[N];
int main()
{
    iosf;
    cin >> n >> m;

    for (int i = 1; i <= N - 1; i++)
        p[i] = i, Size[i] = 1;
    int idx = 0;
    for (int i = 1; i <= m; i++) {
        int a, b, c;
        char op[4];
        cin >> a >> b;
        scanf("%s", op);
        if (op[0] == 'e')
            c = 1;
        else
            c = 0;
        condi[i] = {a, b, c};
        st.insert(a);
        st.insert(b);
    }

    for (auto item : st)
        mp[item] = ++idx;
}