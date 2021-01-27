/*
  Problem Name:Rotate and Flip
  algorithm tag:仿射变换,线性变换
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
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int N = 2e5 + 5;

struct XOY
{
    pll x;
    pll y;
    pll o;
} xoy[N];

vector<pii> pos;
int n, m, q;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed;

    cin >> n;
    for (int i = 1; i <= n; i++) {
        int x, y;
        cin >> x >> y;
        pos.push_back({x, y});
    }
    cin >> m;
    xoy[0] = {{1, 0}, {0, 1}, {0, 0}};
    for (int i = 1; i <= m; i++) {
        int op;
        cin >> op;
        pll x = xoy[i - 1].x;
        pll y = xoy[i - 1].y;
        pll o = xoy[i - 1].o;
        if (op == 1) {
            xoy[i].x.first = x.second;
            xoy[i].x.second = -x.first;

            xoy[i].y.first = y.second;
            xoy[i].y.second = -y.first;

            xoy[i].o.first = o.second;
            xoy[i].o.second = -o.first;
            continue;
        }
        if (op == 2) {
            xoy[i].x.first = -x.second;
            xoy[i].x.second = x.first;

            xoy[i].y.first = -y.second;
            xoy[i].y.second = y.first;

            xoy[i].o.first = -o.second;
            xoy[i].o.second = o.first;
            continue;
        }
        if (op == 3) {
            ll p;
            cin >> p;

            xoy[i].x.first = 2 * p - x.first;
            xoy[i].x.second = x.second;
            xoy[i].y.first = 2 * p - y.first;
            xoy[i].y.second = y.second;
            xoy[i].o.first = 2 * p - o.first;
            xoy[i].o.second = o.second;
            continue;
        }
        if (op == 4) {
            ll p;
            cin >> p;
            xoy[i].x.second = 2 * p - x.second;
            xoy[i].x.first = x.first;
            xoy[i].y.second = 2 * p - y.second;
            xoy[i].y.first = y.first;
            xoy[i].o.second = 2 * p - o.second;
            xoy[i].o.first = o.first;
        }
    }
    // for (int i = 0; i <= m; i++) {
    //     cout << "---" << endl;
    //     cout << xoy[i].x.first << " " << xoy[i].x.second << endl;
    //     cout << xoy[i].y.first << " " << xoy[i].y.second << endl;
    //     cout << xoy[i].o.first << " " << xoy[i].o.second << endl;
    // }
    cin >> q;

    while (q--) {
        int op, piece;
        cin >> op >> piece;
        piece--;

        ll x = pos[piece].first;
        ll y = pos[piece].second;

        ll x1 = xoy[op].x.first;
        ll y1 = xoy[op].x.second;
        ll x2 = xoy[op].y.first;
        ll y2 = xoy[op].y.second;
        ll x3 = xoy[op].o.first;
        ll y3 = xoy[op].o.second;

        x1 = x1 - x3;
        y1 = y1 - y3;
        x2 = x2 - x3;
        y2 = y2 - y3;

        //[x1,x2,x3][x]
        //[y1,y2,y3][y]=
        //[ 0, 0, 1][1]
        ll ansx = x1 * x + x2 * y + x3;
        ll ansy = y1 * x + y2 * y + y3;
        cout << ansx << " " << ansy << endl;
    }
}