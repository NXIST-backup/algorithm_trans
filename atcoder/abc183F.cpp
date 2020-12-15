/*
  Problem Name:Confluence
  algorithm tag:并查集,STL map
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
const int mod = 1e9 + 7;
typedef pair<int, int> pii;

const int N = 2e5 + 5;
int n, q;
int f[N];
int sz[N];
int find(int x)
{
    if (f[x] != x) {
        f[x] = find(f[x]);
    }
    return f[x];
}

int main()
{
    cin >> n >> q;
    vector<map<int, int>> mp(n + 1);
    std::fill(sz + 1, sz + n + 1, 1);
    for (int i = 1; i <= n; i++) {
        int c;
        cin >> c;
        f[i] = i;
        mp[i][c] = 1;
    }
    while (q--) {
        int op, a, b;
        cin >> op >> a >> b;
        if (op == 1) {
            int fa = find(a), fb = find(b);
            if (fa == fb)
                continue;
            if (sz[fa] < sz[fb]) //小的合并大的
                swap(fa, fb);
            sz[fa] += sz[fb], f[fb] = fa;
            for (auto item : mp[fb]) {
                mp[fa][item.first] += item.second;
            }
            mp[fb].clear();
        } else {
            int g = find(a);
            cout << mp[g][b] << endl;
        }
    }
}