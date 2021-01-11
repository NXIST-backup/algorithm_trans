/*
  Problem Name:
  algorithm tag:区间离散
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

map<int, int> mp, mp2;
ll pre[2 * N];
int n;
struct qujian
{
    int a, b, c;
} list[N];
vector<int> pos;
int main()
{
    ll C = 0;
    cin >> n >> C;
    int idx = 0;
    for (int i = 1; i <= n; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        b++;
        list[i] = {a, b, c};
        pos.push_back(a);
        pos.push_back(b);
    }
    sort(pos.begin(), pos.end());

    for (auto item : pos) {
        if (!mp[item]) {
            mp[item] = ++idx;
            mp2[idx] = item;
        }
    }
    for (int i = 1; i <= n; i++) {
        pre[mp[list[i].a]] += list[i].c;
        pre[mp[list[i].b]] -= list[i].c;
    }
    ll ans = 0;
    for (int i = 1; i <= idx; i++) {
        pre[i] += pre[i - 1];
    }
    for (int i = 1; i < idx; i++) {
        if (pre[i] > C) {
            ans += (ll)(mp2[i + 1] - mp2[i]) * C;
        } else {
            ans += (ll)(mp2[i + 1] - mp2[i]) * pre[i];
        }
    }

    cout << ans << endl;
}
