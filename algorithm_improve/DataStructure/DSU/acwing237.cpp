/*
  Problem Name:程序自动分析
  algorithm tag:并查集
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
const double eps = 1e-4;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
//#define x first
//#define y second
#define iosf ios::sync_with_stdio(false), cin.tie(0), cout << fixed

const int N = 2e5 + 50;
map<int, int> mp;
int n;
int p[N];

int find(int x)
{
    if (p[x] != x)
        p[x] = find(p[x]);
    return p[x];
}

struct Condition
{
    int a, b, type;

    bool const operator<(const Condition &W)
    {
        return type > W.type;
    }
} condi[N];

int main()
{
    iosf;
    int _;
    cin >> _;
    while (_--) {
        int n;
        cin >> n;
        bool flag = false;
        for (int i = 1; i <= N - 1; i++)
            p[i] = i;
        int idx = 0;
        mp.clear();
        for (int i = 1; i <= n; i++) {
            int a, b, t;
            cin >> a >> b >> t;
            if (!mp[a])
                mp[a] = ++idx;
            if (!mp[b])
                mp[b] = ++idx;
            condi[i] = {mp[a], mp[b], t};
        }
        sort(condi + 1, condi + 1 + n);
        for (int i = 1; i <= n; i++) {
            int a = condi[i].a, b = condi[i].b, t = condi[i].type;
            a = find(a);
            b = find(b);
            if (t && a != b)
                p[a] = b;
            else if (!t && a == b) {
                flag = true;
                break;
            }
        }
        if (flag)
            cout << "NO" << endl;
        else
            cout << "YES" << endl;
    }
}
